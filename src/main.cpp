#include <iostream>

#include "Bee/Bee.hpp"
#include "Bee/Graphics/Renderer.hpp"

#include "TestWorld.hpp"

int main()
{
    Bee::init(1280, 720);
    Renderer::setWindowIcon("./assets/icon.png");
    Bee::setWorld(new TestWorld);
    Bee::run();
    return 0;
}