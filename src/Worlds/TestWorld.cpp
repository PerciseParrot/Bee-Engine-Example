#include "TestWorld.hpp"

#include <Bee/Bee.hpp>

#include "Globals.hpp"
#include "Entities/Player.hpp"
#include "Entities/TestEntity.hpp"
#include "Entities/Teleporter.hpp"

TestWorld::TestWorld()
{
    loadTilemap("Farm");
    addEntity(new TestEntity(14.5f, 8.0f, 0));
    addEntity(new TestEntity(14.5f, 9.5f, 0));
    addEntity(new TestEntity(14.5f, 11.0f, 0));
    addEntity(new TestEntity(14.5f, 12.5f, 0));
    addEntity(new TestEntity(16.5f, 12.5f, 45));
    addEntity(player = new Player(14.5f, 1.5f));

    addEntity(teleporter = new Teleporter(14.5f, 17.5f));

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

void TestWorld::onLoad()
{
    Audio::playSound("test");
}

void TestWorld::onUnload()
{
    Audio::stopMusic();
}

void TestWorld::update()
{
    const Vector2f playerPosition = player->getPosition();
    Renderer::setCameraPosition(playerPosition);

    if (Keyboard::isKeyPressed(Key::b) || (Controller::isButtonPressed(0, ControllerButton::left) && Controller::isButtonDown(0, ControllerButton::start)))
    {
        loadTilemap("Farm");
    }

    if (Keyboard::isKeyPressed(Key::n) || (Controller::isButtonPressed(0, ControllerButton::up) && Controller::isButtonDown(0, ControllerButton::start)))
    {
        loadTilemap("Large");
    }

    if (Keyboard::isKeyPressed(Key::m) || (Controller::isButtonPressed(0, ControllerButton::right) && Controller::isButtonDown(0, ControllerButton::start)))
    {
        loadTilemap("TestWorld");
    }

    if (Keyboard::isKeyPressed(Key::space) || Controller::isButtonPressed(0, ControllerButton::a))
    {
        Audio::playSound("boom");
    }

    if (Keyboard::isKeyPressed(Key::escape))
    {
        Bee::stop();
    }

    if (Keyboard::isKeyPressed(Key::f4))
    {
        Global::fullscreen = !Global::fullscreen;
        Renderer::setFullscreen(Global::fullscreen);
    }

    if (Keyboard::isKeyDown(Key::a1))
    {
        Global::viewportScale += 0.5f * Bee::getDeltaTime();
    }
    else if (Keyboard::isKeyDown(Key::a2))
    {
        Global::viewportScale -= 0.5f * Bee::getDeltaTime();
    }

    if (Bee::getTime() > lastHUDUpdateTime + 200)
    {
        const Vector2f mousePos = Mouse::getMouseWorldPosition();
        lastHUDUpdateTime = Bee::getTime();

        xPosHUD->setText("X: " + std::to_string(playerPosition.x), 255, 255, 255, 255);
        yPosHUD->setText("Y: " + std::to_string(playerPosition.y), 255, 255, 255, 255);

        tileDataHUD->setText(getTileData(mousePos, "type"), 255, 255, 255, 255);
        if (frameTimeHUD->isCursorOnMe())
        {
            frameTimeHUD->setText(std::to_string(Bee::getDeltaTime() * 1000) + "ms", 255, 0, 0, 255);
        }
        else
        {
            frameTimeHUD->setText(std::to_string(Bee::getDeltaTime() * 1000) + "ms", 255, 255, 255, 255);
        }
        frameTimeHUD->setPosition(Renderer::getScreenSize().x - frameTimeHUD->getSize().x, 0);
    }

    Renderer::setViewportSize(16 * Global::viewportScale, 9 * Global::viewportScale);
}

TestWorld::~TestWorld()
{
    deleteAllEntities();
    deleteAllHUDObjects();
}