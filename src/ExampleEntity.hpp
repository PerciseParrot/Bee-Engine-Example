#pragma once

#include "Bee/Entity.hpp"

class ExampleEntity : public Entity
{
public:
    ExampleEntity();
    virtual void update();
    virtual ~ExampleEntity();

private:
    Vector2f velocity;
    float getHeading();
};