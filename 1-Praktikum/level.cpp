#include "level.h"
#include "door.h"
#include "guardcontroller.h"
#include "npc.h"
#include "tile.h"
#include "floor.h"
#include "wall.h"
#include "portal.h"
#include "character.h"
#include "switch.h"
#include "pit.h"
#include "ramp.h"
#include "door.h"
Level::Level()
    : maxRow{10}, maxColumn{10}, stageVector{}, characterVector{}
{
    createStringLevel(maxRow,maxColumn);
    Switch* sp = dynamic_cast<Switch*>(stageVector.at(8).at(4));
    Door* dp = dynamic_cast<Door*>(stageVector.at(6).at(7));
    sp->attach(dp);

    createNpc(5,5, {6,6,2,2,4,4,8,8});
    createNpc(8,8, {8,8,8,2,2,2});

    setPortals(1,8,8,1,3);
}



Level::~Level()
{
    for (std::vector<Tile*>& vec: stageVector) {
        for (Tile*& tile : vec) {

            delete tile;
            tile = nullptr;
        }
    }

    for (Character*& ch : characterVector){
        delete ch;
        ch = nullptr;
    }
}


//Methoden
bool Level::isBoundary(int currentRow, int currentColumn) const
{
    if (currentRow == 0 || currentRow == maxRow-1) return true;
    else if (currentColumn == 0 || currentColumn == maxColumn-1) return true;
    else return false;
}



void Level::createEmptyLevel(int rows, int columns)
{

    for (int i{0}; i <= rows; i++) {

        stageVector.emplace_back(std::vector<Tile*>{});

        for (int j{0}; j <= columns; j++) {
            if (isBoundary(i, j)) {

                stageVector.at(i).emplace_back(new Wall(i, j, nullptr));

            } else {
                stageVector.at(i).emplace_back(new Floor(i, j,nullptr));
            }
        }

    }

}

void Level::createStringLevel(int rows, int columns)
{
    const std::string lev = {
        "##########"
        "#........#"
        "#...<....#"
        "#..___...#"
        "#..___...#"
        "#........#"
        "#######X##"
        "#........#"
        "#...?....#"
        "##########" };



    int k{0};


    for (int i{0}; i < rows; i++) {

        stageVector.emplace_back();


        for (int j{0}; j < columns; j++) {

            if (lev.at(k) == '#') {
                stageVector.at(i).push_back(new Wall(i, j, nullptr));
            }
            if (lev.at(k) == '.') {
                stageVector.at(i).push_back(new Floor(i, j, nullptr));
            }
            if (lev.at(k) == '_') {
                stageVector.at(i).push_back(new Pit(i, j, nullptr));
            }
            if (lev.at(k) == '<') {
                stageVector.at(i).push_back(new Ramp(i, j, nullptr));
            }
            if (lev.at(k)== '?'){
                stageVector.at(i).push_back(new Switch(i,j,nullptr));
            }
            if (lev.at(k)== 'X'){
                stageVector.at(i).push_back(new Door(i,j,nullptr));
            }
            k++;
        }
    }
}





void Level::setPortals(int row1, int column1, int row2, int column2, int type)
{
    Portal* newPortal1 = new Portal (row1, column1, nullptr, nullptr, type);
    Portal* newPortal2 = new Portal (row2, column2, nullptr, nullptr, type);
    newPortal1 ->setDestination(newPortal2);
    newPortal2 ->setDestination(newPortal1);

    delete stageVector.at(row1).at(column1);
    delete stageVector.at(row2).at(column2);

    stageVector.at(row1).at(column1) = newPortal1;
    stageVector.at(row2).at(column2) = newPortal2;
}

void Level::setDoor(int row, int column)
{
    Door* newDoor = new Door (row,column, nullptr);
    delete stageVector.at(row).at(column);
    stageVector.at(row).at(column) = newDoor;
}

void Level::setSwitch(int row, int column)
{
    Switch* newSwitch = new Switch (row,column, nullptr);
    delete stageVector.at(row).at(column);
    stageVector.at(row).at(column) = newSwitch;
}

void Level::setPit(int row, int column)
{
    Pit* newPit = new Pit (row,column, nullptr);
    delete stageVector.at(row).at(column);
    stageVector.at(row).at(column) = newPit;
}

void Level::setRamp(int row, int column)
{
    Ramp* newRamp = new Ramp (row,column, nullptr);
    delete stageVector.at(row).at(column);
    stageVector.at(row).at(column) = newRamp;
}



void Level::placeCharacter(Character *c, int row, int col)
{
    c->setTile(getTile(row,col));
    stageVector.at(row).at(col)->setCharacter(c);
    playerCharacter = c;
}

void Level::createNpc(int row, int col, std::vector<int> pattern) {
    GuardController* npcController = new GuardController(pattern);
    Npc* npc = new Npc("N", nullptr, npcController);
    npc->setCurrentController(npcController);
    placeCharacter(npc, row, col);
    characterVector.push_back(npc);
}


void Level::createCharacter(int row, int col)
{
    characterVector.push_back(new Character());
    placeCharacter(characterVector.at(characterVector.size()-1),row, col);
}

//getter
Tile *Level::getTile(int row, int col)
{
    return stageVector.at(row).at(col);
}

const Tile *Level::getTile(int row, int col) const
{
    return stageVector.at(row).at(col);
}

const vector<std::vector<Tile *> >& Level::getStageVector() const
{
    return stageVector;
}

int Level::getMaxRow() const
{
    return maxRow;
}

int Level::getMaxColumn() const
{
    return maxColumn;
}

const vector<Character *> &Level::getCharacterVector() const
{
    return characterVector;
}

Character *Level::getPlayerCharacter() const
{
    return playerCharacter;
}

