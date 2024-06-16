#include "TestEntity.hpp"

#include <Bee/Bee.hpp>

TestEntity::TestEntity(const float x, const float y, const float rotation)
{
    setPosition(x, y);
    setRotation(rotation);
    setSprite("saul");
    setName("Saul");
    setHitboxScale(1.5f, 1.5f);
    setScale(1.5f, 1.5f);
}

void TestEntity::update()
{
    for (const Intersection& i : getIntersections())
    {
        moveOffset(i.mtv);
    }
}