#include "Farm.hpp"

#include <Bee/Bee.hpp>

#include "Globals.hpp"

Farm::Farm()
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
    const Vector2f playerPosition = player->getPosition();
    Renderer::setCameraPosition(playerPosition);

    if (Keyboard::isKeyDown(Key::a1))
    {
        Global::viewportScale += 0.5f * Bee::getDeltaTime();
    }
    else if (Keyboard::isKeyDown(Key::a2))
    {
        Global::viewportScale -= 0.5f * Bee::getDeltaTime();
    }

    if (Keyboard::isKeyPressed(Key::f4))
    {
        Global::fullscreen = !Global::fullscreen;
        Renderer::setFullscreen(Global::fullscreen);
    }

    Renderer::setViewportSize(16 * Global::viewportScale, 9 * Global::viewportScale);
}

Farm::~Farm()
{
    deleteAllEntities();
    deleteAllHUDObjects();
}