#include "graphicalui.h"
#include "startscreen.h"
#include "mainwindow.h"
#include <cstdlib>



GraphicalUI::GraphicalUI(Level *currentLevel): currentLevel{currentLevel}
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

    startScreen->show();

}

GraphicalUI::~GraphicalUI()
{
    delete startScreen;

    delete mainWindow;

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

const std::vector<QPixmap> &GraphicalUI::getPortalTextures() const
{
    return portalTextures;
}

const std::vector<QPixmap> &GraphicalUI::getDoorTextures() const
{
    return doorTextures;
}

const QPixmap &GraphicalUI::getWallTexture() const
{
    return wallTexture;
}

const QPixmap &GraphicalUI::getPitTexture() const
{
    return pitTexture;
}

const QPixmap &GraphicalUI::getSwitchTexture() const
{
    return switchTexture;
}

const QPixmap &GraphicalUI::getRampTexture() const
{
    return rampTexture;
}

const QPixmap &GraphicalUI::getCharacterTextureDown() const
{
    return characterTextureDown;
}

void GraphicalUI::setCurrentLevel(Level *newCurrentLevel)
{
    currentLevel = newCurrentLevel;
}

Level *GraphicalUI::getCurrentLevel() const
{
    return currentLevel;
}

const QPixmap &GraphicalUI::getCharacterTextureUp() const
{
    return characterTextureUp;
}

const QPixmap &GraphicalUI::getCharacterTextureRight() const
{
    return characterTextureRight;
}

const QPixmap &GraphicalUI::getCharacterTextureLeft() const
{
    return characterTextureLeft;
}

const QPixmap &GraphicalUI::getZombieRight() const
{
    return zombieRight;
}

const QPixmap &GraphicalUI::getZombieLeft() const
{
    return zombieLeft;
}

MainWindow *GraphicalUI::getMainWindow() const
{
    return mainWindow;
}

const QPixmap &GraphicalUI::getLevelChangerTexture() const
{
    return levelChangerTexture;
}
