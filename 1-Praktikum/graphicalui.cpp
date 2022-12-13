#include "graphicalui.h"
#include "startscreen.h"
#include "mainwindow.h"
#include <cstdlib>



GraphicalUI::GraphicalUI()
{
    floorTextures.push_back(QPixmap("../textures/floor/floor1.png"));
    floorTextures.push_back(QPixmap("../textures/floor/floor2.png"));
    floorTextures.push_back(QPixmap("../textures/floor/floor3.png"));
    floorTextures.push_back(QPixmap("../textures/floor/floor4.png"));
    floorTextures.push_back(QPixmap("../textures/floor/floor5.png"));

    portalTextures.push_back(QPixmap("../textures/portal/portal1.png"));
    portalTextures.push_back(QPixmap("../textures/portal/portal2.png"));
    portalTextures.push_back(QPixmap("../textures/portal/portal3.png"));

    doorTextures.push_back(QPixmap("../textures/doors/door1.png"));
    doorTextures.push_back(QPixmap("../textures/doors/door2.png"));



    startScreen = new StartScreen();
    startScreen->setGraphicalUi(this);

    mainWindow = new MainWindow(this);
   // mainWindow->setCurrentGui(this);

    startScreen->show();

}

void GraphicalUI::draw(Level* level)
{
    mainWindow->draw(level);
}

void GraphicalUI::switchWindow()
{
    startScreen->hide();
    mainWindow->show();
}

QPixmap GraphicalUI::getRandomFloorTexture()
{
    int randomNumber = rand()%5;
    QPixmap randomFloorTexture = floorTextures.at(randomNumber);
    return randomFloorTexture;
}
