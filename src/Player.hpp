#pragma once

#include "Bee/Entity.hpp"

#include <string>

class Player : public Entity
{
public:
    Player();
    virtual void update();
    virtual ~Player();

private:
    std::string currentAnimation;
    Vector2f velocity;
};