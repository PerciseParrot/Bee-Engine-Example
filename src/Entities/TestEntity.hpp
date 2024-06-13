#pragma once

#include <Bee/Bee.hpp>

class TestEntity : public Entity
{
public:
    TestEntity(float x, float y, float rotation);
    void update() override;
};