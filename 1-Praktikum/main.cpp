#include <iostream>
#include <exception>
#include <vector>



#include "level.h"
#include "terminalUI.h"
#include "dungeoncrawler.h"

int main() try
{
    Level* test1{new Level()};
    TerminalUI* test2 = new TerminalUI();
    DungeonCrawler* dg = new DungeonCrawler(test1, test2);
    test2->draw(test1);

    delete test1;
    delete test2;
    delete dg;

    test1 = nullptr;
    test2 = nullptr;
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
