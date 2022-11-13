#ifndef GAME_H
#define GAME_H

#include "game_level.h"
#include <glad/glad.h>
#include "GLFW/glfw3.h"

enum GameState 
{
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

const glm::vec2 PLAYER_SIZE(100.0f, 20.0f);
const float PLAYER_VELOCITY(500.0f);

const glm::vec2 INITIAL_BALL_VELOCITY(100.0f, -350.0f);
const float BALL_RADIUS = 12.5f;


class Game
{
public:
    GameState state;
    bool keys[1024];
    unsigned int width, height;
    Game(unsigned int width, unsigned int height);
    ~Game();

    std::vector<GameLevel> levels;
    unsigned int level;

    void init();
    void processInput(float dt);
    void update(float dt);
    void render();
    
};

#endif