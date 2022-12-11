#include "startscreen.h"
#include "ui_startscreen.h"
#include "graphicalui.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

StartScreen::StartScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartScreen)
{
    ui->setupUi(this);

    QPixmap backGroundTexture("../textures/startscreen.png");
    QPixmap buttonTexture("../textures/new_game_button.png");
    QWidget::setStyleSheet("background-color: black;");


    QIcon ButtonIcon(buttonTexture);

    ui->newGameButton->setIcon(ButtonIcon);
    ui->newGameButton->setIconSize(buttonTexture.rect().size());

    ui->backGroundLabel->setPixmap(backGroundTexture);

    connect(ui->newGameButton, &QPushButton::clicked, this, &StartScreen::onButtonClicked);







}

StartScreen::~StartScreen()
{
    delete ui;
}

void StartScreen::setGraphicalUi(GraphicalUI *newGraphicalUi)
{
    graphicalUi = newGraphicalUi;
}

void StartScreen::onButtonClicked()
{
    graphicalUi->switchWindow();
}



