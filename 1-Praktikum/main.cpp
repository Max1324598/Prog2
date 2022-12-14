#include <iostream>
#include <exception>
#include <vector>
#include <QApplication>
#include "level.h"
#include "graphicalui.h"
#include "dungeoncrawler.h"

int main(int argc, char *argv[]) try
{
    QApplication QApplication(argc, argv);


    Level* level{new Level()};
    Character* player = new Character();
    level->placeCharacter(player,1,1);
    GraphicalUI* ui = new GraphicalUI(level);
    ui->setCurrentLevel(level);
    DungeonCrawler* dg = new DungeonCrawler(level, ui ,player);
    ui->setCurrentDungeonCrawler(dg);


    return QApplication.exec();

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
