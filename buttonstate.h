#ifndef BUTTONSTATE_H
#define BUTTONSTATE_H
#include <QPushButton>

class ButtonState
{
public:
    ButtonState(int value, QPushButton* button, bool isPressed = false, bool isDisabled = false);
    ~ButtonState();

    int value;
    bool isPressed;
    bool isDisabled;
    QPushButton* button;
};

#endif // BUTTONSTATE_H
