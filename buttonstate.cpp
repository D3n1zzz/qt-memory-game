#include "buttonstate.h"
#include <QDebug>

ButtonState::ButtonState(int value, QPushButton* button, bool isPressed, bool isDisabled):
    value(value), button(button), isPressed(isPressed), isDisabled(isDisabled)
{

}

ButtonState::~ButtonState()
{
    qInfo () << "ButtonState destructed";
}
