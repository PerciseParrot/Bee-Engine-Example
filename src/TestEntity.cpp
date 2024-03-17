#include "TestEntity.hpp"

#include <iostream>
#include <sstream>
#include <string>

#include "Bee/Bee.hpp"
#include "Bee/Math/Vector2f.hpp"

TestEntity::TestEntity(float x, float y, float rotation)
{
    const void * address = static_cast<const void*>(this);
    std::stringstream ss;
    ss << address;
    setPosition(x, y);
    setRotation(rotation);
    loadSpriteSheet("saul");
    setName("saul " + ss.str());
    setHitboxScale(1.5f, 1.5f);
    setScale(1.5f, 1.5f);
}

void TestEntity::update()
{
    for (Intersection i : getIntersections())
    {
        moveOffset(i.mtv);
    }
}

TestEntity::~TestEntity()
{

}