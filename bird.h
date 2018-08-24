#ifndef BIRD_H
#define BIRD_H

#include<SFML/Graphics.hpp>
#include "definitions.h"
#include "mygame.h"
#include <vector>

namespace Game {
class Bird
{
public:
    Bird(GameDataRef data);
    void Draw();
    void Animate(float dt);
    void Update(float dt);
    void Tap();
    const sf::Sprite &GetSprite()const;

private:
    GameDataRef _data;
    sf::Sprite _birdSprite;
    std::vector<sf::Texture> _birdAnimationFrames;
    unsigned int _animationIterator;
    sf::Clock _clock;
    sf::Clock _movementClock;
    int _birdState;
    float _rotation;
};
}
#endif // BIRD_H
