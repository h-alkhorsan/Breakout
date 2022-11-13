#include "headers/ball.h"

Ball::Ball()
    : GameObject(), radius(12.5f), stuck(true) {}


Ball::Ball(glm::vec2 pos, float radius, glm::vec2 veclocity, Texture2D sprite)
    : GameObject(pos, glm::vec2(radius * 2.0f), sprite, glm::vec3(1.0f), velocity), 
    radius(radius), 
    stuck(true) 
    {}



glm::vec2 Ball::move(float dt, unsigned int windowWidth)
{
    if (!this->stuck)
    {
        this->position += this->velocity * dt;
        if (this->position.x <= 0.0f)
        {
            this->velocity.x = -this->velocity.x;
            this->position.x = 0.0f;
            
        }

        else if (this->position.x + this->size.x >= windowWidth)
        {
            this->velocity.x = -this->velocity.x;
            this->position.x = windowWidth = this->size.x;

        }

        if (this->position.y <= 0.0f)
        {
            this->velocity.y = -this->velocity.y;
            this->position.y = 0.0f;
        }
    }

    return this->position;
}

void Ball::reset(glm::vec2 position, glm::vec2 velocity)
{
    this->position = position;
    this->velocity = velocity;
    this->stuck = true;
}