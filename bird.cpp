#include "bird.h"

namespace Game {

Bird::Bird(GameDataRef data)
    : _data(data)
{
    _animationIterator = 0;
    _birdState = BIRD_STATE_STILL;
    _rotation = 0;
    _birdAnimationFrames.push_back(data->assets.GetTexture("Bird Frame 1"));
    _birdAnimationFrames.push_back(data->assets.GetTexture("Bird Frame 2"));
    _birdAnimationFrames.push_back(data->assets.GetTexture("Bird Frame 3"));
    _birdAnimationFrames.push_back(data->assets.GetTexture("Bird Frame 4"));

    _birdSprite.setTexture(_birdAnimationFrames.at(_animationIterator));
    // initial position
    _birdSprite.setPosition(
        (_data->window.getSize().x / 4) - (_birdSprite.getGlobalBounds().width / 2),
        (_data->window.getSize().y / 2) - (_birdSprite.getGlobalBounds().height / 2));

    // get flappy's origin information for rotation tranformation
    sf::Vector2f origin = sf::Vector2f(_birdSprite.getGlobalBounds().width / 2,
                                       _birdSprite.getGlobalBounds().height / 2);
    _birdSprite.setOrigin(origin);
}
void Bird::Draw()
{
    _data->window.draw(_birdSprite);
}

void Bird::Animate(float dt)
{
    if (_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _birdAnimationFrames.size())
    {
        if (_animationIterator < _birdAnimationFrames.size() - 1)
        {
            _animationIterator++;
        }
        else
        {
            _animationIterator = 0;
        }
        _birdSprite.setTexture(_birdAnimationFrames.at(_animationIterator));
        _clock.restart();
    }
}

void Bird::Update(float dt)
{
    if (BIRD_STATE_FALLING == _birdState)
    {
        _birdSprite.move(0, GRAVITY * dt);
        _rotation += ROTATION_SPEED * dt;
        // prevent circling
        if (_rotation > ROTATION_LIMIT)
        {
            _rotation = ROTATION_LIMIT;
        }
        _birdSprite.setRotation(_rotation);
    }
    else if (BIRD_STATE_FLYING == _birdState)
    {
        _birdSprite.move(0, -FLYING_SPEED * dt);
        _rotation -= ROTATION_SPEED * dt;
        if (_rotation < - ROTATION_LIMIT)
        {
            _rotation = - ROTATION_LIMIT;
        }
        _birdSprite.setRotation(_rotation);
    }

    if (_movementClock.getElapsedTime().asSeconds() > FLYING_DURATION)
    {
        _movementClock.restart();
        _birdState = BIRD_STATE_FALLING;
    }
}

void Bird::Tap()
{
    _movementClock.restart();
    _birdState = BIRD_STATE_FLYING;
}

const sf::Sprite &Bird::GetSprite()const
{
    return _birdSprite;
}

}
