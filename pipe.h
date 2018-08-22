#ifndef PIPE_H
#define PIPE_H

#include<SFML/Graphics.hpp>
#include <vector>
#include "mygame.h"
#include "definitions.h"

namespace Game {
class Pipe
{
public:
    Pipe(GameDataRef data);
    void DrawPipes();
    void SpawnTopPipe();
    void SpawnBottomPipe();
    void SpawnInvisiblePipe();
    void MovePipes(float dt);
    void RandomisePipeOffset();

private:
    GameDataRef _data;
    std::vector<sf::Sprite> pipeSprites;
    int _landHeight;
    int _pipeSpawnYOffSet;
};

}

#endif // PIPE_H
