#include <iostream>
using std::cout;
#include <exception>

#include "terminalUI.h"
#include "level.h"
#include "tile.h"
#include "dungeoncrawler.h"


TerminalUI::TerminalUI()
{

}

void TerminalUI::draw(Level * currentLvl){
    int input{0};


    while(true){

        for(int i = 0; i < currentLvl->getMaxRow(); i++){
                   for (int j = 0; j < currentLvl-> getMaxColumn(); j++) {

                       cout <<  currentLvl-> getStageVector().at(i).at(j)->getTexture();

                   }
                    cout << std::endl;
         }


        cout << std::endl <<"Bewegungsrichtung angeben (numbad)\n"
                "Beenden des Programmes durch '0'" << std::endl;

        std::cin >> input;
        if (!std::cin) throw std::runtime_error{"Ungueltige Eingabe!"};

        //Beenden des Programms durch "0"
        if (input == 0){
            cout << "Programm beendet";
            return;
        }

        getCurrentDungeonCrawler()->turn(input);
    }

}
