#include "dungeoncrawler.h"
#include "mainwindow.h"
#include "tile.h"
#include "level.h"
#include "character.h"
#include "abstractUI.h"
#include "levelchanger.h"
#include "graphicalui.h"
#include <iostream>

DungeonCrawler::DungeonCrawler()
    : currentAbstractUI{currentAbstractUI}
{
    Level* level1 = new Level();
    Level* level2 = new Level();

    Character* player = new Character();
    level1->placeCharacter(player,1,1);

    level1->setLevelChanger(2,2);
    level2->setLevelChanger(2,7);
    LevelChanger* lc1 = dynamic_cast<LevelChanger*>(level1->getStageVector().at(2).at(2));
    LevelChanger* lc2 = dynamic_cast<LevelChanger*>(level2->getStageVector().at(2).at(7));

    lc1->setDestination(lc2);
    lc1->attach(this);
    levelVector.push_back(level1);

    lc2->attach(this);
    levelVector.push_back(level2);

    currentLevel = level1;
    currentCharacter = currentLevel->getPlayerCharacter();


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
            currentChar->setLastMovingDir(1);
        } break;

    }
        //move down
    case 2:{
        if (currentTile->getRow() < currentLevel->getMaxRow()-1) {
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() + 1).at(currentTile->getColumn());

            currentTile->moveTo(nextTile, currentChar);
            currentChar->setLastMovingDir(2);
        }

        break;
    }

    case 3:{
        if ((currentTile->getRow() < currentLevel->getMaxRow()-1)  && (currentTile->getColumn()  < currentLevel->getMaxColumn()-1)) {
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() + 1).at(currentTile->getColumn()+1);

            currentTile->moveTo(nextTile, currentChar);
            currentChar->setLastMovingDir(3);
        } break;
    }

        //move left
    case 4:{
        if (currentTile->getColumn()  > 0 ){
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() ).at(currentTile->getColumn()-1);

            currentTile->moveTo(nextTile, currentChar);
            currentChar->setLastMovingDir(4);
        }
        break;}

        //stand still
    case 5:{
        std::cout << "Diese Runde wurde ausgesetzt.\n\n";
        currentChar->setLastMovingDir(5);
        break;
    }


        //move right
    case 6:{
        if (currentTile->getColumn()  < currentLevel->getMaxColumn() -1){
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() ).at(currentTile->getColumn()+1);

            currentTile->moveTo(nextTile, currentChar);
            currentChar->setLastMovingDir(6);

        }

        break;
    }

    case 7:{
        if ((currentTile->getColumn()  > 0 ) && (currentTile->getRow() > 0)){
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() -1 ).at(currentTile->getColumn()-1);

            currentTile->moveTo(nextTile, currentChar);
            currentChar->setLastMovingDir(7);
        }
        break;}



        //move up
    case 8:{
        if (currentTile->getRow() > 0) {
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() - 1).at(currentTile->getColumn());

            currentTile->moveTo(nextTile, currentChar);
            currentChar->setLastMovingDir(8);

        }
        break;
    }

    case 9:{
        if ((currentTile->getRow() > 0) &&(currentTile->getColumn()  < currentLevel->getMaxColumn()-1)) {
            nextTile = currentLevel->getStageVector().at(currentTile->getRow() - 1).at(currentTile->getColumn()+1);

            currentTile->moveTo(nextTile, currentChar);
            currentChar->setLastMovingDir(9);

        }
        break;



    default:{
            std::cout << "Keine gültige Eingabe. Eingabe nur zwischen 1-9!\n\n";
            break;
        }


        }

    }
}

void DungeonCrawler::setLevel(Level * newLevel)
{
    currentLevel = newLevel;
    GraphicalUI* currentUI = dynamic_cast<GraphicalUI*>(currentAbstractUI);
    currentUI->setCurrentLevel(newLevel);
}

void DungeonCrawler::notify(Active *source)
{
    GraphicalUI* currentUI = dynamic_cast<GraphicalUI*>(currentAbstractUI);
    setLevel(levelVector.at(1));
    LevelChanger* lc = dynamic_cast<LevelChanger*>(source);

    levelVector.at(1)->placeCharacter(currentCharacter,lc->getDestination()->getRow(), lc->getDestination()->getColumn() );
    currentUI->getMainWindow()->reBuild();

    for (int i{}; i<levelVector.size();i++){
//        if(levelVector.at(i) == currentLevel){
//            setLevel(levelVector.at(i+1));
//
//            break;
       // }
    }
}

void DungeonCrawler::saveLevels()
{
    Level* level1 = new Level();

}

Level *DungeonCrawler::getCurrentLevel() const
{
    return currentLevel;
}

void DungeonCrawler::setCurrentAbstractUI(AbstractUI *newCurrentAbstractUI)
{
    currentAbstractUI = newCurrentAbstractUI;
    currentAbstractUI->setCurrentDungeonCrawler(this);

}


