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
    if (Input::isButtonDown(BUTTON_RIGHT))
    {
        setAnimation("walking_right");
    }
    else if (Input::isButtonDown(BUTTON_LEFT))
    {
        setAnimation("walking_left");
    }
    else if (Input::isButtonDown(BUTTON_DOWN))
    {
        setAnimation("walking_down");
    }
    else if (Input::isButtonDown(BUTTON_UP))
    {
        setAnimation("walking_up");
    }
    else
    {
        setAnimation("standing_down");
    }

    float headingAngle = getHeading();

    if (Input::isButtonDown(BUTTON_UP) || Input::isButtonDown(BUTTON_LEFT) || Input::isButtonDown(BUTTON_DOWN) || Input::isButtonDown(BUTTON_RIGHT))
    {
        velocity.x = sinf(headingAngle * M_PI / 180) * 5;
        velocity.y = cosf(headingAngle * M_PI / 180) * 5;
    }

    moveOffset(velocity * Bee::getDeltaTime());

    for (Intersection i : getIntersections())
    {
        moveOffset(i.mtv);
    }
}

float ExampleEntity::getHeading()
{
    if (Input::isButtonDown(BUTTON_UP) && Input::isButtonDown(BUTTON_RIGHT))
        return 135;
    
    if (Input::isButtonDown(BUTTON_UP) && Input::isButtonDown(BUTTON_LEFT))
        return 225;

    if (Input::isButtonDown(BUTTON_DOWN) && Input::isButtonDown(BUTTON_RIGHT))
        return 45;

    if (Input::isButtonDown(BUTTON_DOWN) && Input::isButtonDown(BUTTON_LEFT))
        return 315;

    if (Input::isButtonDown(BUTTON_UP))
        return 180;

    if (Input::isButtonDown(BUTTON_RIGHT))
        return 90;

    if (Input::isButtonDown(BUTTON_DOWN))
        return 0;

    if (Input::isButtonDown(BUTTON_LEFT))
        return 270;
}

ExampleEntity::~ExampleEntity()
{

}