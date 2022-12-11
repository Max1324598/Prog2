#include "graphicalui.h"
#include "startscreen.h"
#include "mainwindow.h"



GraphicalUI::GraphicalUI()
{
    startScreen = new StartScreen();
    startScreen->setGraphicalUi(this);
    mainWindow = new MainWindow();
    startScreen->show();

}

void GraphicalUI::draw(Level *)
{

}

void GraphicalUI::switchWindow()
{
    startScreen->hide();
    mainWindow->show();
}
