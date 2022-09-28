#ifndef LOGICS_H
#define LOGICS_H

#include <QObject>
#include <QList>
#include "buttonstate.h"

class Logics
{
public:
    explicit Logics();
    ~Logics();

    void generateRandomNumber(int size, QList <ButtonState*>& buttonList);
    bool checkButtonState(QPushButton* sender, QList <ButtonState*>& buttonList);

signals:

private:
    int activeButtonsCount;
    QTimer* timer;

    void disableButtons(QList <ButtonState*> &buttonList);
    void resetButtons (QList <ButtonState*> &buttonList);

};

#endif // LOGICS_H
