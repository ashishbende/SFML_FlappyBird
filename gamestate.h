#ifndef GAMESHATE_HPP
#define GAMESHATE_HPP

#include <SFML/Graphics.hpp>
#include "state.h"
#include "mygame.h"


namespace Game{
  class GameState:public State{
  public:
    GameState(GameDataRef data);
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

#endif // GAMESHATE_HPP
