#include <iostream>

#include "Bee/Bee.hpp"

#include "TestRoom.hpp"

int main()
{
    Bee::init(1280, 720);
    Bee::setWorld(new TestRoom);
    Bee::run();
    Bee::cleanUp();
    return 0;
}