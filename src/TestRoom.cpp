#include "TestRoom.hpp"

#include <iostream>

#include "Bee/Bee.hpp"
#include "Bee/Entity.hpp"
#include "Bee/Input.hpp"
#include "Bee/Graphics/Renderer.hpp"
#include "Bee/World/World.hpp"

#include "ExampleEntity.hpp"
#include "TestEntity.hpp"

TestRoom::TestRoom()
{
    loadTilemap("Farm");
    //addEntity(new TestEntity(3, 1, "animation1", 45));
    //addEntity(new TestEntity(1, 0, "animation2", 90));
    //addEntity(new TestEntity(2.5, 0, "animation3", 135));
    //addEntity(new TestEntity(2.5, 1.5, "animation3", 180));
    //addEntity(new TestEntity(2.0f, 0, "animation1", 0));
    addEntity(entity = new ExampleEntity);
}

void TestRoom::onLoad()
{
    Audio::loadSound("test");
    Audio::playSound("test");
    //Audio::loadMusic("muscle");
    //Audio::playMusic("muscle", 10);
}

void TestRoom::onUnload()
{

}

void TestRoom::update()
{
    Vector2f pos = entity->getPosition();
    pos.x += 0.5f;
    pos.y += 0.5f;
    Renderer::setCameraPosition(pos);

    if (Input::isButtonPressed(BUTTON_INTERACT))
    {
        loadTilemap("Farm");
    }
}

TestRoom::~TestRoom()
{
    
}