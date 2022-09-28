#include "logics.h"
#include <QDebug>
#include <QList>
#include <QRandomGenerator>
#include <QPushButton>
#include <QTimer>

Logics::Logics()
{
    timer = new QTimer();
    activeButtonsCount = 0;
}

Logics::~Logics()
{
    delete timer;
    qInfo () << "Logics destroyed";
}

void Logics::generateRandomNumber(int size, QList <ButtonState*>& buttonList)
// Assign random values to the randomly picked buttons.
{
    QList <int> randNumbers;
    QList <int> randIndex;

    while (randNumbers.length() < size)
    {
        int rand = QRandomGenerator::global()->bounded(1, 10);
        if (!randNumbers.contains(rand))
        {
            randNumbers.append(rand);
        }
    }

    //Making the copy of numbers
    foreach (int i, randNumbers)
    {
        randNumbers.append(i);
    }

    while (randIndex.length() < size * 2)
    {
        int randIndexNum = QRandomGenerator::global()->bounded(0, buttonList.length());
        if (!randIndex.contains(randIndexNum))
        {
            randIndex.append(randIndexNum);
        }
    }

    int i = 0;
    foreach (int randIndex, randIndex)
    {
        buttonList[randIndex]->value = randNumbers[i];
        i++;
    }
    qInfo() << randNumbers;
    qInfo() << randIndex;
}

bool Logics::checkButtonState(QPushButton* sender, QList <ButtonState*> &buttonList)
{

    foreach(ButtonState* buttonState, buttonList)
    {
        if (buttonState->button == sender)
        {
            buttonState->isPressed = true;
            activeButtonsCount++;
            sender->setText(QString::number(buttonState->value));
        }
    }
    if (activeButtonsCount == 2)
    {
        qInfo() << "Girdi";
        int value1 = -1, value2 = -1;

        foreach (ButtonState* buttonState, buttonList) {
            if (buttonState->isPressed)
            {
                if (value1 == -1) value1 = buttonState->value;
                else value2 = buttonState->value;

                if (value1 == value2)
                {
                    qInfo() << value1 << value2;
                    disableButtons(buttonList);
                    activeButtonsCount = 0;
                    return true;
                }
            }
        }
        qInfo() << value1 << value2;
        resetButtons(buttonList);
        activeButtonsCount = 0;
    }
    return false;
}

void Logics::disableButtons(QList<ButtonState*> &buttonList)
{
    foreach(ButtonState* buttonState, buttonList)
    {
        if (buttonState->isPressed)
        {
            buttonState->button->setDisabled(true);
            buttonState->isDisabled = true;
            buttonState->isPressed = false;
            buttonState->button->setText(QString::number(buttonState->value));
        }
    }
}

void Logics::resetButtons(QList <ButtonState*> &buttonList)
{
    foreach(ButtonState* buttonState, buttonList)
    {
        if (!buttonState->isDisabled)
        {
            buttonState->isPressed = false;
            buttonState->button->setText("?");
        }
    }
}







