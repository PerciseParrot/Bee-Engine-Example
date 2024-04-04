#include "TestEntity.hpp"

#include "Bee/Bee.hpp"
#include "Bee/Math/Vector2f.hpp"

TestEntity::TestEntity(float x, float y, float rotation)
{
    setPosition(x, y);
    setRotation(rotation);
    loadSpriteSheet("saul");
    setName("Saul");
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