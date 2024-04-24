#pragma once

#include <Bee/Entity.hpp>
#include <Bee/Math/Vector2f.hpp>

class TestEntity : public Entity
{
public:
    TestEntity(float x, float y, float rotation);
    virtual void update();
};