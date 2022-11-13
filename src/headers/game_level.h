#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H

#include <vector>
#include "game_object.h"

class GameLevel
{
public:
    std::vector<GameObject> bricks;
    GameLevel(){}
    void load(const char *file, unsigned int levelWidth, unsigned int levelHeight);
    void draw(SpriteRenderer &renderer);

    bool isCompleted();

private:
    void init(std::vector<std::vector<unsigned int>> tileData, unsigned int levelWidth, unsigned int levelHeight);
};

#endif