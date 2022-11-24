#include "dungeoncrawler.h"
#include "tile.h"
#include "level.h"
#include "character.h"
#include "abstractUI.h"
#include <iostream>

DungeonCrawler::DungeonCrawler(Level *currentLevel, AbstractUI *currentAbcractUI)
    : currentLevel {currentLevel}, currentAbstractUI{currentAbcractUI}
{
    currentAbcractUI->setCurrentDungeonCrawler(this);
}

void DungeonCrawler::turn(int movingDir)
{

    Tile* currentTile{currentLevel->getCharacterVector().at(0)->getTile()};
    Tile* nextTile{nullptr};
    Character* currentChar{currentLevel->getCharacterVector().at(0)};



    switch (movingDir) {
    //move down and left
    case 1:{
        if ((currentTile->getRow() < currentLevel->getMaxRow()) && (currentTile->getColumn()  > 0 )){
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() +1).at(currentTile->getColumn()-1);

            currentTile->moveTo(nextTile, currentChar);
        } break;

    }
        //move down
    case 2:{
        if (currentTile->getRow() < currentLevel->getMaxRow()) {
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() + 1).at(currentTile->getColumn());

            if(nextTile->getRow() < currentLevel->getMaxRow() && nextTile->getColumn() < currentLevel->getMaxColumn())
                currentTile->moveTo(nextTile, currentChar);

        }

        break;
    }

    case 3:{
        if ((currentTile->getRow() < currentLevel->getMaxRow()) && (currentTile->getColumn()  < currentLevel->getMaxColumn())) {
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() + 1).at(currentTile->getColumn()+1);

            if(nextTile->getRow() < currentLevel->getMaxRow() && nextTile->getColumn() < currentLevel->getMaxColumn())
                currentTile->moveTo(nextTile, currentChar);
        } break;
    }

        //move left
    case 4:{
        if (currentTile->getColumn()  > 0 ){
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() ).at(currentTile->getColumn()-1);

            if(nextTile->getRow() < currentLevel->getMaxRow() && nextTile->getColumn() < currentLevel->getMaxColumn())
                currentTile->moveTo(nextTile, currentChar);
        }
        break;}

        //stand still
    case 5:{
        break;
    }


        //move right
    case 6:{
        if (currentTile->getColumn()  < currentLevel->getMaxColumn() ){
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() ).at(currentTile->getColumn()+1);
            if(nextTile->getRow() < currentLevel->getMaxRow() && nextTile->getColumn() < currentLevel->getMaxColumn())
                currentTile->moveTo(nextTile, currentChar);

        }

        break;
    }

    case 7:{
        if ((currentTile->getColumn()  > 0 ) && (currentTile->getRow() > 0)){
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() -1 ).at(currentTile->getColumn()-1);
            if(nextTile->getRow() < currentLevel->getMaxRow() && nextTile->getColumn() < currentLevel->getMaxColumn())
                currentTile->moveTo(nextTile, currentChar);
        }
        break;}



        //move up
    case 8:{
        if (currentTile->getRow() > 0) {
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() - 1).at(currentTile->getColumn());
            if(nextTile->getRow() < currentLevel->getMaxRow() && nextTile->getColumn() < currentLevel->getMaxColumn())
                currentTile->moveTo(nextTile, currentChar);

        }
        break;
    }

    case 9:{
        if ((currentTile->getRow() > 0) &&(currentTile->getColumn()  < currentLevel->getMaxColumn()) ) {
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() - 1).at(currentTile->getColumn()+1);
            if(nextTile->getRow() < currentLevel->getMaxRow() && nextTile->getColumn() < currentLevel->getMaxColumn())
                currentTile->moveTo(nextTile, currentChar);

        }
        break;


    default:{
            break;
        }


        }

    }
}


