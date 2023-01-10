#include "dungeoncrawler.h"
#include "mainwindow.h"
#include "tile.h"
#include "level.h"
#include "character.h"
#include "abstractUI.h"
#include "levelchanger.h"
#include "graphicalui.h"
#include "mylist.h"
#include <iostream>
#include <lootchest.h>
#include <vector>

DungeonCrawler::DungeonCrawler()
    : currentAbstractUI{currentAbstractUI}
{
    saveLevels();

    auto it = levelList.begin();
    currentLevel = *it;
    currentCharacter = currentLevel->getPlayerCharacter();


}

void DungeonCrawler::turn(int movingDir)
{

    turnMove(movingDir,currentCharacter);//Bewegung des Spielers
    if(checkForFights())
        //test andersrum battlePhase(currentCharacter,getEnemy());
        battlePhase(currentCharacter,getEnemy());

    for(auto& character : currentLevel->getCharacterVector()){
        Npc* currentNPC = dynamic_cast<Npc*>(character);
        int movingDir = currentNPC->getController()->move();
        turnMove(movingDir,currentNPC);
        if(checkForFights())
            battlePhase(getEnemy(),currentCharacter);

        for (int i{}; i<currentLevel->getCharacterVector().size();i++){ //NPC conflict
            if(currentNPC != currentLevel->getCharacterVector().at(i)) {
                if(currentNPC->getTile() == currentLevel->getCharacterVector().at(i)->getTile()) revertMove(currentNPC);
            }
        }

    }
    if(currentCharacter->isDead())
        showEndScreen(0);

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

void DungeonCrawler::revertMove(Character *character)
{
    int movingDir = character->getLastMovingDir();
    switch(movingDir){
    case 1:
        turnMove(9, character);
        break;
    case 2:
        turnMove(8, character);
        break;
    case 3:
        turnMove(7, character);
        break;
    case 4:
        turnMove(6, character);
        break;
    case 5:
        turnMove(5, character);
        break;
    case 6:
        turnMove(4, character);
        break;
    case 7:
        turnMove(3, character);
        break;
    case 8:
        turnMove(2, character);
        break;
    case 9:
        turnMove(1, character);
        break;
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
    if(dynamic_cast<LevelChanger*>(source) != nullptr)
    {
        GraphicalUI* currentUI = dynamic_cast<GraphicalUI*>(currentAbstractUI);
        LevelChanger* lc = dynamic_cast<LevelChanger*>(source);
        auto it = levelList.begin();
        for(unsigned int i{1}; i<levelList.size(); i++){

            if(lc->getLevel() == *it){
                if (lc->getIsExit() == true){
                    ++it;
                }

                break;
            }
                ++it;
        }

        if (lc->getIsExit() == false) --it;



        setLevel(*it);
        (*it)->placeCharacter(currentCharacter,lc->getDestination()->getRow(), lc->getDestination()->getColumn() );
        currentUI->getMainWindow()->reBuild();
    }
    if(dynamic_cast<LootChest*>(source) != nullptr){
        showEndScreen(1);
    }


}

void DungeonCrawler::saveLevels()
{
    //1.Level
    Level* level1 = new Level();
    level1->createNpc(1,2, {2});
    Character* player = new Character();
    level1->placeCharacter(player,1,1);
    levelList.push_back(level1);

    level1->setLevelChanger(2,2,true);
    LevelChanger* level1Exit = dynamic_cast<LevelChanger*>(level1->getStageVector().at(2).at(2));

    level1Exit->attach(this);
    //2.Level
    Level* level2 = new Level (8,10);
    std::string level2String{
        "##########"
        "#........#"
        "#........#"
        "#........#"
        "#........#"
        "#........#"
        "#........#"
        "##########"
    };
    level2->createStringLevel(8,10,level2String);
    level2->setLevelChanger(6,6,false);
    level2->setLevelChanger(3,3,true);

    level2->createNpc(1,1, {2,2,2,2,2});
    level2->createNpc(1,8, {4});
    level2->placeLootChest(1,5);
    LootChest* lootChest = dynamic_cast<LootChest*>(level2->getTile(1,5));
    lootChest->attach(this);

    LevelChanger* level2Entrance = dynamic_cast<LevelChanger*>(level2->getStageVector().at(6).at(6));
    LevelChanger* level2Exit = dynamic_cast<LevelChanger*>(level2->getStageVector().at(3).at(3));
    level2Entrance->attach(this);
    level2Exit->attach(this);

    levelList.push_back(level2);

    //3.Level
    Level* level3 = new Level (15,15);
    std::string level3String{
        "###############"
        "#.............#"
        "#.............#"
        "#.............#"
        "#.............#"
        "#.............#"
        "#.............#"
        "#.............#"
        "#.............#"
        "#.............#"
        "#.............#"
        "#.............#"
        "#.............#"
        "#.............#"
        "###############"
    };
    level3->createStringLevel(15,15,level3String);
    level3->setLevelChanger(8,8,false);

    LevelChanger* level3Entrance = dynamic_cast<LevelChanger*>(level3->getStageVector().at(8).at(8));
    level3Entrance->attach(this);

    levelList.push_back(level3);




    level2Entrance->setDestination(level1Exit);
    level1Exit->setDestination(level2Entrance);

    level3Entrance->setDestination(level2Exit);
    level2Exit->setDestination(level3Entrance);



}

bool DungeonCrawler::checkForFights()
{
    bool fight = false;

    for(int i{0} ; i < currentLevel->getCharacterVector().size() ; i++){
        if(currentCharacter->getTile() == currentLevel->getCharacterVector().at(i)->getTile())
        {
            fight = true;
        }
    }
    return fight;

}

Character *DungeonCrawler::getEnemy() const
{
    for(int i{0} ; i < currentLevel->getCharacterVector().size() ; i++){
        if(currentCharacter->getTile() == currentLevel->getCharacterVector().at(i)->getTile())
        {
            return currentLevel->getCharacterVector().at(i);
        }

    }
    return nullptr;
}

void DungeonCrawler::gameOver()
{
    std::cout << "lost";
}
void DungeonCrawler::battlePhase(Character *attacker, Character *defender)
{

    defender->setHitPoints(defender->getHitPoints() - attacker->getStrength());
    if(!defender->isDead()){
        attacker->setHitPoints(attacker->getHitPoints()-defender->getStrength());
        revertMove(attacker);
    }


    if(dynamic_cast<Npc*>(defender) != nullptr){
        Npc* npc = dynamic_cast<Npc*>(defender);
        std::cout << "npc wouldve been dead";
        std::vector<Character*> temp = currentLevel->getCharacterVector();
        if(defender->isDead())
            defender->setStrength(0);

    }
    else
        gameOver();
}

void DungeonCrawler::showEndScreen(bool b)
{
    GraphicalUI* gui = dynamic_cast<GraphicalUI*>(this->currentAbstractUI);
    gui->showEndScreen(b);
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


