#include "inputmanager.h"

namespace Game{
  bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window){
    if(sf::Mouse::isButtonPressed(button)){
        // check if button press  collides with sprite
        float objXPosition = object.getPosition().x;
        float objYPoistion = object.getPosition().y;
        float objWidth = object.getGlobalBounds().width;
        float objHeight = object.getGlobalBounds().height;
        sf::IntRect objButtonRect(objXPosition, objYPoistion, objWidth, objHeight);
        if(objButtonRect.contains(sf::Mouse::getPosition(window))){
            return true;
          }
      }
    return false;
  }

  sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window){
    return sf::Mouse::getPosition(window);
  }
}
