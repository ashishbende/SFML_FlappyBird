#ifndef GAMESHATE_HPP
#define GAMESHATE_HPP

#include <SFML/Graphics.hpp>
#include "state.h"
#include "mygame.h"
#include "pipe.h"
#include "land.h"
#include "bird.h"


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
    Pipe *pipe;
    Land *land;
    Bird *bird;
};
}

#endif // GAMESHATE_HPP
