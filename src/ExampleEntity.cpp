#include "ExampleEntity.hpp"

#include <cmath>
#include <iostream>

#include "Bee/Bee.hpp"
#include "Bee/Input.hpp"

ExampleEntity::ExampleEntity()
{
    loadSpriteSheet("Link");
    setPosition(14.5f, 1.5f);
    setHitboxScale(0.5f, 0.5f);
}

void ExampleEntity::update()
{
    velocity.x = 0;
    velocity.y = 0;
    currentAnimation == "standing_down";

    if (Input::isButtonDown(BUTTON_DOWN))
    {
        velocity.y = 1;
        currentAnimation = "walking_down";
    }
    if (Input::isButtonDown(BUTTON_UP))
    {
        velocity.y = -1;
        currentAnimation = "walking_up";
    }
    if (Input::isButtonDown(BUTTON_RIGHT))
    {
        velocity.x = 1;
        currentAnimation = "walking_right";
    }
    if (Input::isButtonDown(BUTTON_LEFT))
    {
        velocity.x = -1;
        currentAnimation = "walking_left";
    }

    velocity.normalize();

    setAnimation(currentAnimation);
    moveOffset(velocity * 5 * Bee::getDeltaTime());

    for (Intersection i : getIntersections())
    {
        moveOffset(i.mtv);
    }
}

ExampleEntity::~ExampleEntity()
{

}