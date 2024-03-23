#include "TestRoom.hpp"

#include <iostream>

#include "Bee/Audio.hpp"
#include "Bee/Bee.hpp"
#include "Bee/Entity.hpp"
#include "Bee/Input/Controller.hpp"
#include "Bee/Input/Keyboard.hpp"
#include "Bee/Graphics/HUDObject.hpp"
#include "Bee/Graphics/Renderer.hpp"
#include "Bee/World/World.hpp"

#include "ExampleEntity.hpp"
#include "TestEntity.hpp"

TestRoom::TestRoom()
{
    loadTilemap("Large");
    addEntity(new TestEntity(14.5f, 8.0f, 0));
    addEntity(new TestEntity(14.5f, 9.5f, 0));
    addEntity(new TestEntity(14.5f, 11.0f, 0));
    addEntity(new TestEntity(14.5f, 12.5f, 0));
    addEntity(entity = new ExampleEntity);

    addHUDObject(textHUD = new HUDObject);
    textHUD->setFont("DTM_Mono", 100);
    textHUD->setText("0", 255, 255, 255, 255);
}

void TestRoom::onLoad()
{
    Audio::loadSound("boom");
    Audio::loadSound("test");
    Audio::playSound("test");
    //Audio::loadMusic("muscle");
    //Audio::playMusic("muscle", 10);
}

void TestRoom::onUnload()
{
    Audio::stopMusic();
}

void TestRoom::update()
{
    Vector2f pos = entity->getPosition();
    pos.x += 0.5f;
    pos.y += 0.5f;
    Renderer::setCameraPosition(pos);

    if (Keyboard::isKeyPressed(Key::b))
    {
        loadTilemap("Farm");
    }

    if (Keyboard::isKeyPressed(Key::null) || Controller::isButtonPressed(ControllerButton::a))
    {
        Vector2f stick = Controller::getLeftStick();
        Audio::playSound("boom");
    }

    textHUD->setText(std::to_string(Bee::getDeltaTime() * 1000) + "ms", 255, 255, 255, 255);
    Vector2i textSize = textHUD->getSize();
    textHUD->setPosition(1280 - textSize.x, 0);
}

TestRoom::~TestRoom()
{
    delete entity;
    delete textHUD;
}