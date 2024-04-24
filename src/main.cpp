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
    Globals::farm = new Farm;
    Globals::testWorld = new TestWorld;
    Bee::setWorld(Globals::testWorld);
}

int main()
{
    Bee::onInit(init);
    Bee::run();
    delete Globals::farm;
    delete Globals::testWorld;
    return 0;
}