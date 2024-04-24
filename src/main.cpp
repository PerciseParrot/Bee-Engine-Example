#include <iostream>

#include <Bee/Bee.hpp>
#include <Bee/Graphics/Renderer.hpp>

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
}

int main()
{
    Bee::onInit(init);
    Bee::run();
    delete Global::farm;
    delete Global::testWorld;
    return 0;
}