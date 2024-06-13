#include "Player.hpp"

#include <Bee/Bee.hpp>

Player::Player(const float x, const float y)
{
    setSprite("alttp-link");
    setName("Player");
    setPosition(x, y);
    setHitboxScale(0.9f, 1.25f);
    setScale(1.5f);
}

void Player::update()
{
    velocity.x = 0;
    velocity.y = 0;
    currentAnimation = "standing_down";

    if (Keyboard::isKeyDown(Key::s) || Controller::isButtonDown(0, ControllerButton::down))
    {
        velocity.y = 1;
        currentAnimation = "walking_down";
    }
    if (Keyboard::isKeyDown(Key::w) || Controller::isButtonDown(0, ControllerButton::up))
    {
        velocity.y = -1;
        currentAnimation = "walking_up";
    }
    if (Keyboard::isKeyDown(Key::d) || Controller::isButtonDown(0, ControllerButton::right))
    {
        velocity.x = 1;
        currentAnimation = "walking_right";
    }
    if (Keyboard::isKeyDown(Key::a) || Controller::isButtonDown(0, ControllerButton::left))
    {
        velocity.x = -1;
        currentAnimation = "walking_left";
    }

    if (Keyboard::isKeyDown(Key::space))
    {
        currentAnimation = "drinking";
    }

    velocity.normalize();

    if (Keyboard::isKeyDown(Key::leftShift))
        velocity *= 1.5f;

    if (const Vector2f stick = Controller::getLeftStick(1); stick.getLength() > 0.01f)
        velocity = stick;

    setAnimation(currentAnimation);
    moveOffset(velocity * 5 * Bee::getDeltaTime());

    for (const Intersection& i : getIntersections())
    {
        if (i.worldObject)
        {
            moveOffset(i.mtv);
        }
    }
}