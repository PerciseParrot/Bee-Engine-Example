#include <iostream>

#include "Bee/Bee.hpp"
#include "Bee/Graphics/Renderer.hpp"

#include "TestWorld.hpp"

void init()
{
    Renderer::setWindowTitle("Example Game");
    Renderer::setWindowIcon("./assets/icon.png");
}

int main()
{
    Bee::onInit(init);
    Bee::setWorld(new TestWorld);
    Bee::run();
    return 0;
}