#ifndef FLASH_H
#define FLASH_H

#include <SFML/Graphics.hpp>
#include "mygame.h"
#include "definitions.h"

namespace Game {
class Flash
{
public:
    Flash(GameDataRef data);
    void Show(float dt);
    void Draw();

private:
    GameDataRef _data;
    sf::RectangleShape _shape;
    bool _flashOn;
};
}
#endif // FLASH_H
