#include <iostream>

#include "Bee/Bee.hpp"
#include "Bee/Graphics/Renderer.hpp"

#include "TestRoom.hpp"

int main()
{
    Bee::init(1280, 720);
    Renderer::setWindowIcon("./assets/icon.png");
    Bee::setWorld(new TestRoom);
    Bee::run();
    Bee::cleanUp();
    return 0;
}