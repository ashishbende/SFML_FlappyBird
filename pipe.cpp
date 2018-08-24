#include "pipe.h"
#include<iostream>
#include<ctime>
#include<cstdlib>

namespace Game {

Pipe::Pipe(GameDataRef data)
    : _data(data)
{
    _landHeight = _data->assets.GetTexture("Land").getSize().y;
    _pipeSpawnYOffSet = 0;
}

void Pipe::DrawPipes()
{
    for (unsigned short int i = 0; i < pipeSprites.size(); i++)
    {
        _data->window.draw(pipeSprites.at(i));
    }
}

void Pipe::SpawnTopPipe()
{
    sf::Sprite sprite(_data->assets.GetTexture("Pipe Down"));
    sprite.setPosition(_data->window.getSize().x, -_pipeSpawnYOffSet);
    pipeSprites.push_back(sprite);
}
void Pipe::SpawnBottomPipe()
{
    sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));
    sprite.setPosition(_data->window.getSize().x,
                       _data->window.getSize().y - sprite.getGlobalBounds().height - _pipeSpawnYOffSet);
    pipeSprites.push_back(sprite);
}

void Pipe::SpawnInvisiblePipe()
{
    sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));
    sprite.setPosition(_data->window.getSize().x,
                       _data->window.getSize().y - sprite.getGlobalBounds().height);
    sprite.setColor(sf::Color(0, 0, 0, 0));
    pipeSprites.push_back(sprite);
}

void Pipe::SpawnScoringPipe()
{
    sf::Sprite sprite(_data->assets.GetTexture("Scoring Pipe"));
    sprite.setPosition(_data->window.getSize().x, 0);
    scoringPipes.push_back(sprite);
}

void Pipe::MovePipes(float dt)
{
    for (unsigned short int i = 0; i < pipeSprites.size(); i++)
    {
        // remove pipes from memory that are not visible on screen
        if (pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getGlobalBounds().width)
        {
            pipeSprites.erase(pipeSprites.begin() + i);
        }
        else
        {
            float movement = PIPE_MOVEMENT_SPEED * dt;
            pipeSprites.at(i).move(-movement, 0);
        }
    }

    for (unsigned short int i = 0; i < scoringPipes.size(); i++)
    {
        // remove pipes from memory that are not visible on screen
        if (scoringPipes.at(i).getPosition().x < 0 - scoringPipes.at(i).getGlobalBounds().width)
        {
            scoringPipes.erase(scoringPipes.begin() + i);
        }
        else
        {
            float movement = PIPE_MOVEMENT_SPEED * dt;
            scoringPipes.at(i).move(-movement, 0);
        }
    }
}
void Pipe::RandomisePipeOffset()
{
    _pipeSpawnYOffSet = rand() % (_landHeight + 1);
}

const std::vector<sf::Sprite> &Pipe::GetSprites()const
{
    return pipeSprites;
}

std::vector<sf::Sprite> &Pipe::GetScoringPipes()
{
    return scoringPipes;
}
}
