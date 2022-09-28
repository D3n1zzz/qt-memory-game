#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logics.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Logics* logic;


private:
    int size = 2;
    Ui::MainWindow *ui;
    QList <ButtonState*> buttonList;

    void disableSpinBox();
    void generateButtons();
    void restart();
    void checkButtonState();
};
#endif // MAINWINDOW_H
