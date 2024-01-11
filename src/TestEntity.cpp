#include "TestEntity.hpp"

#include <string>

#include "Bee/Bee.hpp"
#include "Bee/Math/Vector2f.hpp"

TestEntity::TestEntity(float x, float y, std::string animation, float rotation)
{
    setPosition(x, y);
    setRotation(rotation);
    loadSpriteSheet("TestSprite");
    setAnimation(animation);
}

void TestEntity::update()
{

}

TestEntity::~TestEntity()
{

}