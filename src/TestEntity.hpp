#pragma once

#include "Bee/Entity.hpp"

#include <string>

#include "Bee/Math/Vector2f.hpp"

class TestEntity : public Entity
{
public:
    TestEntity(float x, float y, std::string animation, float rotation);
    virtual void update();
    virtual ~TestEntity();
};