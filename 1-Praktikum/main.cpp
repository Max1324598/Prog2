#include <iostream>
#include <exception>
#include <vector>
#include <QApplication>



#include "level.h"
#include "terminalUI.h"
#include "graphicalui.h"
#include "dungeoncrawler.h"

int main(int argc, char *argv[]) try
{
    QApplication QApplication(argc, argv);


    Level* level{new Level()};
    //TerminalUI* ui = new TerminalUI();
    GraphicalUI* ui = new GraphicalUI();
    Character* player = new Character();
    //level->placeCharacter(player,1,1);
    DungeonCrawler* dg = new DungeonCrawler(level, ui ,player);
    ui->setCurrentDungeonCrawler(dg);
    level->placeCharacter(player,1,1);
    ui->setCurrentLevel(level);
    ui->draw(level);



    return QApplication.exec();

    delete level;
    delete ui;
    delete dg;

    level = nullptr;
    ui = nullptr;
    dg = nullptr;
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
