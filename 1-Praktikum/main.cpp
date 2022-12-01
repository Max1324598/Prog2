#include <iostream>
#include <exception>
#include <vector>



#include "level.h"
#include "terminalUI.h"
#include "dungeoncrawler.h"

int main() try
{
    Level* level{new Level()};
    TerminalUI* ui = new TerminalUI();
    Character* player = new Character();
    level->placeCharacter(player,1,1);
    DungeonCrawler* dg = new DungeonCrawler(level, ui ,player);
    ui->draw(level);

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
