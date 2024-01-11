#include <iostream>

#include "Bee/Bee.hpp"

#include "TestRoom.hpp"

int main(int argc, char* argv[])
{
    Bee::init(1920, 1080);
    Bee::setWorld(new TestRoom);
    Bee::run();
    Bee::cleanUp();
    return 0;
}