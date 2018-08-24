#ifndef GAMESHATE_HPP
#define GAMESHATE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "state.h"
#include "mygame.h"
#include "pipe.h"
#include "land.h"
#include "bird.h"
#include "collision.h"
#include "flash.h"
#include "hud.h"


namespace Game {
class GameState: public State
{
public:
    GameState(GameDataRef data);
    void Init();
    void HandleInput();
    void Update(float dt); // dt - time diff between frames
    void Draw(float dt);

private:
    GameDataRef _data;

    sf::Sprite _background;
    sf::Clock _clock;

    sf::SoundBuffer _hitSoundBuffer;
    sf::SoundBuffer _pointSoundBuffer;
    sf::SoundBuffer _wingSoundBuffer;

    sf::Sound _hitSound;
    sf::Sound _pointSound;
    sf::Sound _wingSound;

    Pipe *pipe;
    Land *land;
    Bird *bird;
    Collision collision;
    Flash *flash;
    Hud *hud;
    int _gameState;
    int _score;
};
}

#endif // GAMESHATE_HPP
