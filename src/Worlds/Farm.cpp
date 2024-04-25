#include "Farm.hpp"

#include <Bee/Bee.hpp>

#include "Globals.hpp"

void Farm::init()
{
    loadTilemap("Stardew");
    addEntity(player = new Player(14.5f, 20.0f));
    addEntity(teleporter = new Teleporter(14.f, 10.0f));
}

void Farm::onLoad()
{

}

void Farm::onUnload()
{

}

void Farm::update()
{
    Vector2f playerPosition = player->getPosition();
    Renderer::setCameraPosition(playerPosition);

    if (Keyboard::isKeyDown(Key::a1))
    {
        Global::viewportScale += 0.5f * Bee::getDeltaTime();
    }
    else if (Keyboard::isKeyDown(Key::a2))
    {
        Global::viewportScale -= 0.5f * Bee::getDeltaTime();
    }

    Renderer::setViewportSize(16 * Global::viewportScale, 9 * Global::viewportScale);
}

Farm::~Farm()
{
    deleteAllEntities();
    deleteAllHUDObjects();
}