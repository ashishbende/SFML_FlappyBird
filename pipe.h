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
    void SpawnScoringPipe();
    void MovePipes(float dt);
    void RandomisePipeOffset();
    const std::vector<sf::Sprite> &GetSprites()const;
    std::vector<sf::Sprite> &GetScoringPipes();
private:
    GameDataRef _data;
    std::vector<sf::Sprite> pipeSprites;
    std::vector<sf::Sprite> scoringPipes;
    int _landHeight;
    int _pipeSpawnYOffSet;
};

}

#endif // PIPE_H
