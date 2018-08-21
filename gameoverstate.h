#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include <SFML/Graphics.hpp>
#include "state.h"
#include "mygame.h"

namespace Game{
  class GameOverState:public State{
  public:
    GameOverState(GameDataRef data);
    void Init();
    void HandleInput();
    void Update(float dt); // dt - time diff between frames
    void Draw(float dt);

  private:
    GameDataRef _data;
    sf::Texture _backgroundTexture;
    sf::Sprite _background;
  };
}

#endif // GAMEOVERSTATE_H
