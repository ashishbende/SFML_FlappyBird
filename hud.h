#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include "definitions.h"
#include "mygame.h"

namespace Game {
class Hud
{
public:
    Hud(GameDataRef data);
    void Draw();
    void UpdateScore(int score);
private:
    GameDataRef _data;
    sf::Text _scoreText;
};
}
#endif // HUD_H
