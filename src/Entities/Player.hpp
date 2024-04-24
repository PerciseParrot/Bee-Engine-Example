#pragma once

#include <Bee/Entity.hpp>

class Player : public Entity
{
public:
    Player(float x, float y);
    virtual void update();
    virtual ~Player();

private:
    std::string currentAnimation;
    Vector2f velocity;
};