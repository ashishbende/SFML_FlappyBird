﻿#include<iostream>
#include<sstream>
#include "definitions.h"
#include "gamestate.h"
#include "gameoverstate.h"

namespace Game {
GameState::GameState(GameDataRef data)
    : _data(data) {}

void GameState::Init()
{
    if (!_hitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH))
    {
        std::cerr << "Error loading hit sound effect." << std::endl;
    }
    if (!_pointSoundBuffer.loadFromFile(POINT_SOUND_FILEPATH))
    {
        std::cerr << "Error loading point sound effect." << std::endl;
    }
    if (!_wingSoundBuffer.loadFromFile(WING_SOUND_FILEPATH))
    {
        std::cerr << "Error loading wing sound effect." << std::endl;
    }

    _hitSound.setBuffer(_hitSoundBuffer);
    _pointSound.setBuffer(_pointSoundBuffer);
    _wingSound.setBuffer(_wingSoundBuffer);

    _data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
    _data->assets.LoadTexture("Pipe Up", PIPE_UP_BACKGROUND_FILEPATH);
    _data->assets.LoadTexture("Pipe Down", PIPE_DOWN_BACKGROUND_FILEPATH);
    _data->assets.LoadTexture("Scoring Pipe", SCORING_PIPE_FILEPATH);
    _data->assets.LoadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
    _data->assets.LoadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
    _data->assets.LoadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
    _data->assets.LoadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);
    _data->assets.LoadTexture("Land", LAND_FILEPATH);
    _data->assets.LoadFont("Flappy Font", FLAPPY_FONT_FILEPATH);

    pipe = new Pipe(_data);
    land = new Land(_data);
    bird = new Bird(_data);
    flash = new Flash(_data);
    hud = new Hud(_data);

    _background.setTexture(this->_data->assets.GetTexture("Game Background"));
    // _background.setTexture(this->_data->assets.GetTexture("Pipe Up Background"));
    //_background.setTexture(this->_data->assets.GetTexture("Pipe Down Background"));
    _gameState = GameStates::eReady;
    _score = 0;
    hud->UpdateScore(_score);
}

void GameState::HandleInput()
{
    sf::Event event;
    while (_data->window.pollEvent(event))
    {

        if (sf::Event::Closed == event.type)
        {
            _data->window.close();
            //_data->machine.AddState(StateRef(new GameOverState(_data)),true);
        }

        if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window))
        {
            if (GameStates::eGameOver != _gameState)
            {
                _gameState = GameStates::ePlaying;
                bird->Tap();
                _wingSound.play();
            }
        }
    }
}

void GameState::Update(float dt)
{
    if (GameStates::eGameOver != _gameState)
    {
        bird->Animate(dt);
        land ->MoveLand(dt);
    }
    if (GameStates::ePlaying == _gameState)
    {
        pipe ->MovePipes(dt);
        if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
        {
            pipe->RandomisePipeOffset();
            pipe->SpawnInvisiblePipe();
            pipe->SpawnBottomPipe();
            pipe->SpawnTopPipe();
            pipe->SpawnScoringPipe();
            _clock.restart();
        }
        bird->Update(dt);
        std::vector<sf::Sprite> landSprites = land->GetSprites();
        for (int i = 0; i < landSprites.size(); i++)
        {
            if (collision.CheckSpriteCollision(bird->GetSprite(), 0.7f, landSprites.at(i), 1.0f))
            {
                _gameState = GameStates::eGameOver;
                _clock.restart();
                _hitSound.play();
            }

        }

        std::vector<sf::Sprite> pipeSprites = pipe->GetSprites();
        for (int i = 0; i < pipeSprites.size(); i++)
        {
            if (collision.CheckSpriteCollision(bird->GetSprite(), 0.625f, pipeSprites.at(i), 1.0f))
            {
                _gameState = GameStates::eGameOver;
                _clock.restart();
                _hitSound.play();
            }

        }

        if (GameStates::ePlaying == _gameState)
        {
            std::vector<sf::Sprite> &scoringPipes = pipe->GetScoringPipes();
            for (int i = 0; i < scoringPipes.size(); i++)
            {
                if (collision.CheckSpriteCollision(bird->GetSprite(), 0.625f, scoringPipes.at(i), 1.0f))
                {
                    _score++;
                    hud->UpdateScore(_score);
                    scoringPipes.erase(scoringPipes.begin() + i);
                    _pointSound.play();
                }

            }
        }
    }
    if (GameStates::eGameOver == _gameState)
    {
        flash->Show(dt);
        if (_clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
        {
            _data->machine.AddState(StateRef(new GameOverState(_data, _score)), true);
        }
    }
}

void GameState::Draw(float dt)
{
    _data->window.clear();
    _data->window.draw(_background);
    pipe->DrawPipes();
    land->DrawLand();
    bird->Draw();
    flash->Draw();
    hud->Draw();
    _data->window.display();
}
}

