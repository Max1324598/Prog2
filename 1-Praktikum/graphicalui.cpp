#include "graphicalui.h"
#include "startscreen.h"
#include "mainwindow.h"



GraphicalUI::GraphicalUI()
{
    floors.push_back(QPixmap("../textures/floor/floor1.png"));
    floors.push_back(QPixmap("../textures/floor/floor2.png"));
    floors.push_back(QPixmap("../textures/floor/floor3.png"));
    floors.push_back(QPixmap("../textures/floor/floor4.png"));
    floors.push_back(QPixmap("../textures/floor/floor5.png"));

    portals.push_back(QPixmap("../textures/portal/portal1.png"));
    portals.push_back(QPixmap("../textures/portal/portal2.png"));
    portals.push_back(QPixmap("../textures/portal/portal3.png"));

    startScreen = new StartScreen();
    startScreen->setGraphicalUi(this);

    mainWindow = new MainWindow(this);
    mainWindow->setCurrentGui(this);

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
