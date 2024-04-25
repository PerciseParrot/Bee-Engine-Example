#include <Bee/Bee.hpp>

#include "Globals.hpp"
#include "Worlds/Farm.hpp"
#include "Worlds/TestWorld.hpp"

void init()
{
    Renderer::setWindowTitle("Example Game");
    Renderer::setWindowIcon("./assets/icon.png");
    Global::farm = new Farm;
    Global::testWorld = new TestWorld;
    Bee::setWorld(Global::testWorld);
    Mouse::createCustomCursor("./assets/Crosshair.bmp", 25, 25);
}

int main()
{
    Bee::onInit(init);
    Bee::run();
    delete Global::farm;
    delete Global::testWorld;
    return 0;
}