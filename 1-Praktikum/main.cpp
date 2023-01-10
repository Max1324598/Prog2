#include <iostream>
#include <exception>
#include <vector>
#include <QApplication>
#include "level.h"
#include "graphicalui.h"
#include "dungeoncrawler.h"
int main(int argc, char *argv[]) try
{
    srand(time(NULL));
    QApplication QApplication(argc, argv);


    DungeonCrawler* dg = new DungeonCrawler();
    GraphicalUI* ui = new GraphicalUI(dg->getCurrentLevel());
    dg->setCurrentAbstractUI(ui);


    int r=QApplication.exec();

    delete ui;
    delete dg;



    return r;

}

catch (std::exception& e)
{
    std::cerr << "Fehler: " << e.what() << std::endl;

    return -2;

}

catch (...)
{

std::cerr << "Unbekannte Ausnahme! " << std::endl;

return -3;


}
