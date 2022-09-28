#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "logics.h"
#include "buttonstate.h"
#include <QList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    logic = new Logics();

    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::disableSpinBox);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::generateButtons);
    connect(ui->restartButton, &QPushButton::clicked, this, &MainWindow::restart);

    qInfo () << buttonList;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete logic;
    foreach (ButtonState* buttonState, buttonList)
    {
        delete buttonState;
    }
}

void MainWindow::disableSpinBox()
{
    ui->spinBox->setDisabled(true);
    size = ui->spinBox->value();
}

void MainWindow::generateButtons()
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            QString name = QString::number(count);
            QPushButton* button = new QPushButton(name, this);
            button->setText("?");
            button->setStyleSheet("font-size: 20px");
            ButtonState *buttonState = new ButtonState(0, button);
            this->buttonList.append(buttonState);
            ui->gridLayout->addWidget(buttonState->button, i, j);
            count++;
            connect(button, &QPushButton::clicked, this, &MainWindow::checkButtonState);
        }
    }

    logic->generateRandomNumber(size, buttonList);
    ui->startButton->setDisabled(true);
}

void MainWindow::restart()
{
    QLayoutItem* item;
    while ((item = ui->gridLayout->takeAt(0)) != NULL)
    {
        ui->gridLayout->removeItem(item);
        delete item->widget();
    }
    ui->spinBox->setEnabled(true);
    ui->startButton->setEnabled(true);
    ui->scoreNum->setText("0");
    buttonList.clear();
}

void MainWindow::checkButtonState()
{
   int score = ui->scoreNum->text().toInt();
   bool result = logic->checkButtonState(qobject_cast<QPushButton*>(QObject::sender()), buttonList);
   if (result) ui->scoreNum->setText(QString::number(++score));
}









