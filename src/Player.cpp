#include "Player.hpp"

#include <cmath>
#include <iostream>

#include "Bee/Bee.hpp"
#include "Bee/Log.hpp"
#include "Bee/Input/Controller.hpp"
#include "Bee/Input/Keyboard.hpp"

Player::Player()
{
    loadSpriteSheet("Link");
    setPosition(14.5f, 1.5f);
    setHitboxScale(0.75f, 0.75f);
}

void Player::update()
{
    velocity.x = 0;
    velocity.y = 0;
    currentAnimation = "standing_down";

    if (Keyboard::isKeyDown(Key::s) || Controller::isButtonDown(ControllerButton::down))
    {
        velocity.y = 1;
        currentAnimation = "walking_down";
    }
    if (Keyboard::isKeyDown(Key::w) || Controller::isButtonDown(ControllerButton::up))
    {
        velocity.y = -1;
        currentAnimation = "walking_up";
    }
    if (Keyboard::isKeyDown(Key::d) || Controller::isButtonDown(ControllerButton::right))
    {
        velocity.x = 1;
        currentAnimation = "walking_right";
    }
    if (Keyboard::isKeyDown(Key::a) || Controller::isButtonDown(ControllerButton::left))
    {
        velocity.x = -1;
        currentAnimation = "walking_left";
    }

    velocity.normalize();

    Vector2f stick = Controller::getLeftStick();

    if (stick.getLength() > 0.01f)
        velocity = stick;

    setAnimation(currentAnimation);
    moveOffset(velocity * 5 * Bee::getDeltaTime());

    for (Intersection i : getIntersections())
    {
        if (i.worldObject)
        {
            moveOffset(i.mtv);
        }
    }
}

Player::~Player()
{
    
}