#include "TestRoom.hpp"

#include <iostream>

#include "Bee/Audio.hpp"
#include "Bee/Bee.hpp"
#include "Bee/Entity.hpp"
#include "Bee/Log.hpp"
#include "Bee/Input/Controller.hpp"
#include "Bee/Input/Keyboard.hpp"
#include "Bee/Graphics/HUDObject.hpp"
#include "Bee/Graphics/Renderer.hpp"
#include "Bee/World/World.hpp"

#include "Player.hpp"
#include "TestEntity.hpp"

TestRoom::TestRoom()
{
    loadTilemap("Farm");
    addEntity(new TestEntity(14.5f, 8.0f, 0));
    addEntity(new TestEntity(14.5f, 9.5f, 0));
    addEntity(new TestEntity(14.5f, 11.0f, 0));
    addEntity(new TestEntity(14.5f, 12.5f, 0));
    addEntity(new TestEntity(16.5f, 12.5f, 45));
    addEntity(player = new Player);

    addHUDObject(frameTimeHUD = new HUDObject);
    frameTimeHUD->setFont("DTM_Mono", 50);

    addHUDObject(xPosHUD = new HUDObject);
    xPosHUD->setFont("DTM_Mono", 50);
    xPosHUD->setText("X: 0", 255, 255, 255, 255);
    xPosHUD->setPosition(0, 0);

    addHUDObject(yPosHUD = new HUDObject);
    yPosHUD->setFont("DTM_Mono", 50);
    yPosHUD->setText("Y: 0", 255, 255, 255, 255);
    yPosHUD->setPosition(0, xPosHUD->getSize().y);

    addHUDObject(tileDataHUD = new HUDObject);
    tileDataHUD->setFont("DTM_Mono", 50);
    tileDataHUD->setPosition(0, xPosHUD->getSize().y + xPosHUD->getSize().y);
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
    Vector2f playerPosition = player->getPosition();
    Renderer::setCameraPosition(playerPosition);

    if (Keyboard::isKeyPressed(Key::b) || (Controller::isButtonPressed(ControllerButton::left) && Controller::isButtonDown(ControllerButton::start)))
    {
        loadTilemap("Farm");
    }

    if (Keyboard::isKeyPressed(Key::n) || (Controller::isButtonPressed(ControllerButton::up) && Controller::isButtonDown(ControllerButton::start)))
    {
        loadTilemap("Large");
    }

    if (Keyboard::isKeyPressed(Key::m) || (Controller::isButtonPressed(ControllerButton::right) && Controller::isButtonDown(ControllerButton::start)))
    {
        loadTilemap("TestWorld");
    }

    if (Keyboard::isKeyPressed(Key::space) || Controller::isButtonPressed(ControllerButton::a))
    {
        Audio::playSound("boom");
    }

    frameTimeHUD->setText(std::to_string(Bee::getDeltaTime() * 1000) + "ms", 255, 255, 255, 255);
    frameTimeHUD->setPosition(Renderer::getScreenSize().x - frameTimeHUD->getSize().x, 0);

    xPosHUD->setText("X: " + std::to_string(playerPosition.x), 255, 255, 255, 255);
    yPosHUD->setText("Y: " + std::to_string(playerPosition.y), 255, 255, 255, 255);

    tileDataHUD->setText(getTileData(player->getPosition(), "type"), 255, 255, 255, 255);
}

TestRoom::~TestRoom()
{
    deleteAllEntities();
    deleteAllHUDObjects();
}