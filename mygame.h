#ifndef MYGAME_H
#define MYGAME_H

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "statemachine.h"
#include "inputmanager.h"
#include "assetmanager.h"

namespace Game{

  struct GameData
  {
    StateMachine machine;
    sf::RenderWindow window;
    AssetManager assets;
    InputManager input;
  };


  typedef std::shared_ptr<GameData> GameDataRef;

  class MyGame{
  public:
    MyGame(int width, int height, std::string name);
  private:
    const float dt = 1.0f/60.0f; // framerate;
    sf::Clock _clock;
    GameDataRef _data = std::make_shared<GameData>();
    void Run();
  };
}
#endif // MYGAME_H
