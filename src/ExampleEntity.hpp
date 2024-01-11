#pragma once

#include "Bee/Entity.hpp"

#include <string>

class ExampleEntity : public Entity
{
public:
    ExampleEntity();
    virtual void update();
    virtual ~ExampleEntity();

private:
    std::string currentAnimation;
    Vector2f velocity;
};