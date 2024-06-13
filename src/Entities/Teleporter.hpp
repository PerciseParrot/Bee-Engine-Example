#pragma once

#include <Bee/Bee.hpp>

class Teleporter : public Entity
{
public:
    Teleporter(float x, float y);
    void update() override;

private:
};