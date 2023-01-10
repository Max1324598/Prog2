#include "endscreen.h"
#include "ui_endscreen.h"
#include "graphicalui.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

EndScreen::EndScreen(GraphicalUI* gui,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndScreen),
    graphicalUi(gui)
{
    ui->setupUi(this);
    //ui->textBrowser->showFullScreen();
    QPixmap backGroundTexture = QPixmap("../textures/startscreen.png");





    connect(ui->test, &QPushButton::clicked, qApp, &QApplication::quit);
    ui->label->setPixmap(backGroundTexture);
}

EndScreen::~EndScreen()
{
    delete ui;
}
void EndScreen::winMessage()
{
QMessageBox::information(this,"WIN","YOU WON");
}

void EndScreen::loseMessage()
{
QMessageBox::information(this,"LOSE","YOU LOST");
}

void EndScreen::setGraphicalUi(GraphicalUI *newGraphicalUi)
{
    graphicalUi = newGraphicalUi;
}

void EndScreen::onButtonClicked()
{
    graphicalUi->switchWindow();
}



