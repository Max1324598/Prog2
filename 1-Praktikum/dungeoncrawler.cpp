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
#include "door.h"
#include "floor.h"
#include "json.h"
#include "pit.h"
#include "switch.h"
#include "wall.h"
#include <fstream>

DungeonCrawler::DungeonCrawler()
    : currentAbstractUI{currentAbstractUI}
{
    saveLevels();
    //loadFromJson();

    auto it = levelList.begin();
    currentLevel = *it;
    currentCharacter = currentLevel->getPlayerCharacter();
    saveLevelsJson();

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


        currentLevel->setPlayerCharacter(nullptr);
        setLevel(*it);
        (*it)->placePlayerCharacter(currentCharacter,lc->getDestination()->getRow(), lc->getDestination()->getColumn() );

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
    Character* player = new Character();
    level1->placePlayerCharacter(player,1,1);
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
    level2->createAttackNpc(1,8);

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

    level2->createGraph();
    level3->createGraph();



}

void DungeonCrawler::saveLevelsJson()
{
    nlohmann::json j;
    std::ofstream file;
    file.open("../Levels.json", std::ios::out);



    j["count"] = levelList.size();
    j["levels"] = nlohmann::json::array();

    auto it = levelList.begin();
    int i = 0;

    while(it != levelList.end()){
        auto level = *it;
        nlohmann::json jlevel;

        jlevel["maxrows"] = level->getMaxRow();
        jlevel["maxcols"] = level->getMaxColumn();

        jlevel["player"] = nlohmann::json::array();
        nlohmann::json jplayer;
        if(level->getPlayerCharacter() == nullptr){
            jplayer["hasPlayer"] = "0";
        }
        else {
            jplayer["hasPlayer"] = "1";
            jplayer["row"] = level->getPlayerCharacter()->getTile()->getRow();
            jplayer["col"] = level->getPlayerCharacter()->getTile()->getColumn();
            jplayer["stamina"] = level->getPlayerCharacter()->getStamina();
            jplayer["strength"] = level->getPlayerCharacter()->getStrength();
            jplayer["hitpoints"] = level->getPlayerCharacter()->getHitPoints();
        }
        jlevel["player"].push_back(jplayer);


        i = 0;
        for(auto row : level->getStageVector()){
            for(auto tile : row){
                jlevel["field"][i].push_back(getTileType(tile));
            }
            i++;
        }

        jlevel["portalpairs"] = nlohmann::json::array();
        for (vector<int> portalPair : level->getPortalPairs()){
            nlohmann::json jportal;
            jportal["row1"] = portalPair.at(0);
            jportal["column1"] = portalPair.at(1);
            jportal["row2"] = portalPair.at(2);
            jportal["column2"] = portalPair.at(3);
            jlevel["portalpairs"].push_back(jportal);
        }

        jlevel["doorswitchpairs"] = nlohmann::json::array();
        for (vector<int> doorSwitchPair : level->getDoorSwitchPairs()){
            nlohmann::json jdoorSwitch;
            jdoorSwitch["row1"] = doorSwitchPair.at(0);
            jdoorSwitch["column1"] = doorSwitchPair.at(1);
            jdoorSwitch["row2"] = doorSwitchPair.at(2);
            jdoorSwitch["column2"] = doorSwitchPair.at(3);

            jlevel["doorswitchpairs"].push_back(jdoorSwitch);
        }

        jlevel["doors"] = nlohmann::json::array();
        for (Door* door : level->getDoorVector()){
            nlohmann::json jdoor;
            jdoor["isOpen"] = door->getIsOpen();
            jdoor["row"] = door->getRow();
            jdoor["column"] = door->getColumn();

            jlevel["doors"].push_back(jdoor);
        }

        jlevel["levelchangers"] = nlohmann::json::array();
        for (LevelChanger* levelChanger : level->getLevelChangers()){
            nlohmann::json jlevelChanger;
            jlevelChanger["row"] = levelChanger->getRow();
            jlevelChanger["column"] = levelChanger->getColumn();
            jlevelChanger["isExit"] = levelChanger->getIsExit();


            jlevel["levelchangers"].push_back(jlevelChanger);
        }

        jlevel["character"] = nlohmann::json::array();
        i = 0;
        for(auto Npc : level->getCharacterVector()){

            nlohmann::json jchar;

            jchar["row"] = Npc->getTile()->getRow();
            jchar["col"] = Npc->getTile()->getColumn();
            jchar["stamina"] = Npc->getStamina();
            jchar["strength"] = Npc->getStrength();
            jchar["hitpoints"] = Npc->getHitPoints();

            jlevel["character"].push_back(jchar);
        }
        ++it;
        j["levels"].push_back(jlevel);
    }



    file << j.dump(2);
    file.close();


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

void DungeonCrawler::loadFromJson()
{

    std::ifstream fileLevel;
    fileLevel.open("../Levels.json", std::ios::in);
    nlohmann::json jlevels;
    fileLevel >> jlevels;
    //int levelcount = jlevels["count"]
    for(const auto& level : jlevels["levels"]){

        auto tmpLVL = new Level(level);

        levelList.push_back(tmpLVL);

    }

    auto it = levelList.begin();

    std::tuple<int,int,bool,int> levelChanger;
    std::vector<std::tuple<int,int,bool,int>> levelChangerTuples;
    int levelCounter = 1;

    for(const auto& level : jlevels["levels"]){
        auto currentLevel = *it;

        for(const auto& levelChanger : level["levelchangers"]){
            levelChangerTuples.push_back({levelChanger["row"],levelChanger["column"],levelChanger["isExit"], levelCounter});

            auto currentTile = currentLevel->getStageVector().at(levelChanger["row"]).at(levelChanger["column"]);
            LevelChanger* currentLevelChanger = dynamic_cast<LevelChanger*>(currentTile);
            if (levelChanger["isExit"] == true){
                currentLevelChanger->setIsExit(true);
            }
            else currentLevelChanger->setIsExit(false);

        }
        ++it;
        levelCounter++;
    }

    it = levelList.begin();

    levelCounter = 1;

    for(const auto& level : jlevels["levels"]){
        auto currentLevel = *it;
        for(const auto& levelChanger : level["levelchangers"]){
            auto currentTile = currentLevel->getStageVector().at(levelChanger["row"]).at(levelChanger["column"]);
            LevelChanger* currentLevelChanger = dynamic_cast<LevelChanger*>(currentTile);

            LevelChanger* nextLevelChanger = nullptr;
            std::tuple<int,int,bool,int> nextLevelChangerTuple;

            if(currentLevelChanger->getIsExit() == true){
                ++it;
                levelCounter++;
                auto nextLevel = *it;
                --it;
                for(int i{}; i<levelChangerTuples.size();i++){
                    if(std::get<3>(levelChangerTuples.at(i)) == levelCounter && std::get<2>(levelChangerTuples.at(i)) == false){
                        nextLevelChangerTuple = levelChangerTuples.at(i);
                        break;
                    }
                }

                Tile* nextTile = nextLevel->getStageVector().at(std::get<0>(nextLevelChangerTuple)).at(std::get<1>(nextLevelChangerTuple));
                nextLevelChanger = dynamic_cast<LevelChanger*>(currentTile);
                currentLevelChanger->attach(this);
                currentLevelChanger->setDestination(nextTile);

                levelCounter--;
            }
            if(currentLevelChanger->getIsExit() == false){
                --it;
                levelCounter--;
                Level* previousLevel = *it;
                ++it;
                for(int i{}; i<levelChangerTuples.size();i++){
                    if(std::get<3>(levelChangerTuples.at(i)) == levelCounter && std::get<2>(levelChangerTuples.at(i)) == true){
                        nextLevelChangerTuple = levelChangerTuples.at(i);
                        break;
                    }
                }

                Tile* nextTile = previousLevel->getStageVector().at(std::get<0>(nextLevelChangerTuple)).at(std::get<1>(nextLevelChangerTuple));
                nextLevelChanger = dynamic_cast<LevelChanger*>(currentTile);
                currentLevelChanger->attach(this);
                currentLevelChanger->setDestination(nextTile);

                levelCounter++;
            }


        }
        ++it;
        levelCounter++;
    }



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

string DungeonCrawler::getTileType(Tile* tile) const
{
    if (typeid(*tile) == typeid(Door)){
        return "door";
    }
    else if (typeid(*tile) == typeid(Floor)){
        return "floor";
    }
    else if (typeid(*tile) == typeid(LevelChanger)){
        return "levelchanger";
    }
    else if (typeid(*tile) == typeid(LootChest)){
        return "lootchest";
    }
    else if (typeid(*tile) == typeid(Pit)){
        return "pit";
    }
    else if (typeid(*tile) == typeid(Portal)){
        return "portal";
    }
    else if (typeid(*tile) == typeid(Ramp)){
        return "ramp";
    }
    else if (typeid(*tile) == typeid(Switch)){
        return "switch";
    }
    else if (typeid(*tile) == typeid(Wall)){
        return "wall";
    } else {
        return "invalid tile";
    }

}


