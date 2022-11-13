#include "headers/game.h"
#include "headers/resource_manager.h"
#include "headers/sprite_renderer.h"
#include "headers/game_object.h"
#include "headers/ball.h"

SpriteRenderer *sRenderer;
GameObject *player;
Ball *playerBall;

// constructor
Game::Game(const unsigned int width, const unsigned int height)
    : state(GAME_ACTIVE), keys(), width(width), height(height){}


// destructor
Game::~Game()
{
    delete sRenderer;
    delete player;
    delete playerBall;
}

void Game::init()
{
    // load shaders
    ResourceManager::loadShader("shaders/sprite.vs", "shaders/sprite.frag", nullptr, "sprite");

    // configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->width), static_cast<float>(this->height), 0.0f, -1.0f, 1.0f);
    ResourceManager::getShader("sprite").use().setInt("image", 0);
    ResourceManager::getShader("sprite").setMatrix4("projection", projection);

    Shader shader;
    shader = ResourceManager::getShader("sprite");
    sRenderer = new SpriteRenderer(shader);

    ResourceManager::loadTexture("textures/background.png", false, "background");
    ResourceManager::loadTexture("textures/awesomeface.png", true, "face");
    ResourceManager::loadTexture("textures/block.png", false, "block");
    ResourceManager::loadTexture("textures/block_solid.png", false, "block_solid");
    ResourceManager::loadTexture("textures/paddle.png", true, "paddle");

    GameLevel one;
    one.load("levels/one.lvl", this->width, this->height/2);
    GameLevel two;
    two.load("levels/two.lvl", this->width, this->height/2);
    GameLevel three;
    three.load("levels/three.lvl", this->width, this->height/2);
    GameLevel four;
    four.load("levels/four.lvl", this->width, this->height/2);

    this->levels.push_back(one);
    this->levels.push_back(two);
    this->levels.push_back(three);
    this->levels.push_back(four);
    this->level = 0;

    glm::vec2 playerPos = glm::vec2(this->width / 2.0f - PLAYER_SIZE.x, this->height - PLAYER_SIZE.y);
    Texture2D playerTex = ResourceManager::getTexture("paddle");
    player = new GameObject(playerPos, PLAYER_SIZE, playerTex);

    // check why this is
    glm::vec2 ballPos = playerPos + glm::vec2(PLAYER_SIZE.x / 2.0f - BALL_RADIUS, -BALL_RADIUS * 2.0f);
    Texture2D ballTex = ResourceManager::getTexture("face");
    playerBall = new Ball(ballPos, BALL_RADIUS, INITIAL_BALL_VELOCITY, ballTex);

}


void Game::processInput(float dt)
{
    if (this->state == GAME_ACTIVE)
    {
        float velocity = PLAYER_VELOCITY * dt;
        // move playerboard
        if (this->keys[GLFW_KEY_A])
        {
            if (player->position.x >= 0.0f)
            {
                player->position.x -= velocity;
                if (playerBall->stuck)
                    playerBall->position.x -= velocity;
            }
        }
        if (this->keys[GLFW_KEY_D])
        {
            if (player->position.x <= this->width - player->size.x)
            {
                player->position.x += velocity;
                if (playerBall->stuck)
                    playerBall->position.x += velocity;
            }
        }
        if (this->keys[GLFW_KEY_SPACE])
            playerBall->stuck = false;
    }

}

void Game::update(float dt)
{
    playerBall->move(dt, this->width);
}

void Game::render()
{
    if (this->state == GAME_ACTIVE)
    {
        Texture2D background = ResourceManager::getTexture("background");
        sRenderer->drawSprite(background, glm::vec2(0.0f, 0.0f), glm::vec2(this->width, this->height), 0.0f);

        this->levels[this->level].draw(*sRenderer);
        player->draw(*sRenderer);
        playerBall->draw(*sRenderer);
    }
}