#include "Teleporter.hpp"

#include <Bee/Bee.hpp>

#include "Globals.hpp"

Teleporter::Teleporter(float x, float y)
{
    setName("Teleporter");
    setFont("DTM_Mono", 200);
    setPosition(x, y);
    setScale(2);
    setHitboxScale(2);
}

void Teleporter::update()
{
    if (isCursorOnMe())
    {
        setText(" CLick to\n Teleport ", 255, 0, 0, 255);
        setScale(2);
        setHitboxScale(2);

        if (Mouse::isButtonPressed(MouseButton::left))
        {
            if (Bee::getCurrentWorld() == Global::farm)
            {
                Bee::setWorld(Global::testWorld);
            }
            else if (Bee::getCurrentWorld() == Global::testWorld)
            {
                Bee::setWorld(Global::farm);
            }
        }
    }
    else
    {
        setText("CLick to\nTeleport", 255, 255, 255, 255);
        setScale(2);
        setHitboxScale(2);
    }
}