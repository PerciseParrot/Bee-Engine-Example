#include "Farm.hpp"

#include <Bee/Graphics/Renderer.hpp>

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
}

Farm::~Farm()
{
    deleteAllEntities();
    deleteAllHUDObjects();
}