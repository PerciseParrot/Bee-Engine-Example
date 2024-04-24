#pragma once

#include <Bee/Entity.hpp>

class Teleporter : public Entity
{
public:
    Teleporter(float x, float y);
    virtual void update();

private:
};