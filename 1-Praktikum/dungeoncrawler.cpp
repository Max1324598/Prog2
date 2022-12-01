#include "dungeoncrawler.h"
#include "tile.h"
#include "level.h"
#include "character.h"
#include "abstractUI.h"
#include <iostream>

DungeonCrawler::DungeonCrawler(Level *currentLevel, AbstractUI *currentAbcractUI,Character* currentCharacter)
    : currentLevel {currentLevel}, currentAbstractUI{currentAbcractUI}, currentCharacter{currentCharacter}
{
    currentAbcractUI->setCurrentDungeonCrawler(this);
}

void DungeonCrawler::turn(int movingDir)
{
    turnMove(movingDir,currentCharacter);
    for(auto& character : currentLevel->getCharacterVector()){
        Npc* currentNPC = dynamic_cast<Npc*>(character);
        int movingDir = currentNPC->getController()->move();
        turnMove(movingDir,currentNPC);
    }

}

void DungeonCrawler::turnMove(int movingDir,Character* character)
{

    Tile* currentTile{character->getTile()};
    Tile* nextTile{nullptr};
    Character* currentChar{character};



    switch (movingDir) {
    //move down and left
    case 1:{
        if ((currentTile->getRow() < currentLevel->getMaxRow()-1) && (currentTile->getColumn()  > 0 )){
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() +1).at(currentTile->getColumn()-1);

            currentTile->moveTo(nextTile, currentChar);
        } break;

    }
        //move down
    case 2:{
        if (currentTile->getRow() < currentLevel->getMaxRow()-1) {
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() + 1).at(currentTile->getColumn());

            currentTile->moveTo(nextTile, currentChar);
        }

        break;
    }

    case 3:{
        if ((currentTile->getRow() < currentLevel->getMaxRow()-1)  && (currentTile->getColumn()  < currentLevel->getMaxColumn()-1)) {
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() + 1).at(currentTile->getColumn()+1);

            currentTile->moveTo(nextTile, currentChar);
        } break;
    }

        //move left
    case 4:{
        if (currentTile->getColumn()  > 0 ){
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() ).at(currentTile->getColumn()-1);

            currentTile->moveTo(nextTile, currentChar);
        }
        break;}

        //stand still
    case 5:{
        std::cout << "Diese Runde wurde ausgesetzt.\n\n";
        break;
    }


        //move right
    case 6:{
        if (currentTile->getColumn()  < currentLevel->getMaxColumn() -1){
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() ).at(currentTile->getColumn()+1);

            currentTile->moveTo(nextTile, currentChar);

        }

        break;
    }

    case 7:{
        if ((currentTile->getColumn()  > 0 ) && (currentTile->getRow() > 0)){
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() -1 ).at(currentTile->getColumn()-1);

            currentTile->moveTo(nextTile, currentChar);
        }
        break;}



        //move up
    case 8:{
        if (currentTile->getRow() > 0) {
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() - 1).at(currentTile->getColumn());

            currentTile->moveTo(nextTile, currentChar);

        }
        break;
    }

    case 9:{
        if ((currentTile->getRow() > 0) &&(currentTile->getColumn()  < currentLevel->getMaxColumn()-1)) {
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() - 1).at(currentTile->getColumn()+1);

            currentTile->moveTo(nextTile, currentChar);

        }
        break;



    default:{
            std::cout << "Keine gültige Eingabe. Eingabe nur zwischen 1-9!\n\n";
            break;
        }


        }

    }
}


