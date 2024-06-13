#pragma once

#include <Bee/Bee.hpp>

class Player : public Entity
{
public:
    Player(float x, float y);
    void update() override;

private:
    std::string currentAnimation;
    Vector2f velocity;
};