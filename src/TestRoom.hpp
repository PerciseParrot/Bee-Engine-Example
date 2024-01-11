#pragma once

#include "Bee/World/World.hpp"

#include "ExampleEntity.hpp"

class TestRoom : public World
{
public:
    TestRoom();
    virtual void onLoad();
    virtual void onUnload();
    virtual void update();
    virtual ~TestRoom();

private:
    ExampleEntity* p_entity;
};