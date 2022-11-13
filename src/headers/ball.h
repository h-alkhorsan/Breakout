#ifndef BALL_H
#define BALL_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include "game_object.h"
#include "texture.h"


class Ball : public GameObject
{
public:
    float radius;
    bool stuck;

    Ball();
    Ball(glm::vec2 pos, float radius, glm::vec2 velocity, Texture2D sprite);

    glm::vec2 move(float dt, unsigned int windowWidth);
    void reset(glm::vec2 position, glm::vec2 velocity);

};

#endif