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
Level::Level()
    : maxRow{0}, maxColumn{0}, stageVector{}, characterVector{}
{

    //createEmptyLevel(maxRow, maxColumn);
    testLevel(maxRow,maxColumn);
    //setPortals(1,2,8,8);

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




    Door* door = new Door(5,2,nullptr);
    Switch* swit = new Switch(2,1,nullptr);
    swit->attach(door);
    Pit* pit = new Pit(7,7,nullptr);
    Pit* pit2 = new Pit(7,6,nullptr);
    Ramp* ramp = new Ramp(7,8,nullptr);
    GuardController* controller = new GuardController(std::vector<int>{6,6,2,2,4,4,8,8});
    GuardController* controller2 = new GuardController(std::vector<int>{8,8,8,2,2,2});
    Npc* npc1 = new Npc("N",stageVector.at(5).at(5),controller);
    Npc* npc2 = new Npc("B",stageVector.at(9).at(9),controller2);
    placeNPC(npc1);
    placeNPC(npc2);
    stageVector.at(5).at(2) = door;
    stageVector.at(2).at(1) = swit;
    stageVector.at(7).at(7) = pit;
    stageVector.at(7).at(6) = pit2;
    stageVector.at(7).at(8) = ramp;
}




void Level::placeNPC(Character* npc){
    characterVector.push_back(npc);
    int row = npc->getTile()->getRow();
    int col = npc->getTile()->getColumn();
    placeCharacter(npc,row,col);
}


void Level::setPortals(int row1, int column1, int row2, int column2)
{
    Portal* newPortal1 = new Portal (row1, column1, nullptr, nullptr);
    Portal* newPortal2 = new Portal (row2, column2, nullptr, nullptr);
    newPortal1 ->setDestination(newPortal2);
    newPortal2 ->setDestination(newPortal1);

    delete stageVector.at(row1).at(column1);
    delete stageVector.at(row2).at(column2);

    stageVector.at(row1).at(column1) = newPortal1;
    stageVector.at(row2).at(column2) = newPortal2;
}



void Level::placeCharacter(Character *c, int row, int col)
{
    c->setTile(getTile(row,col));
    stageVector.at(row).at(col)->setCharacter(c);
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

void Level::testLevel(int row, int columns){

    int c{0};
    const std :: string l = {
        "##########"
        "#O.......#"
        "#...<....#"
        "#..___...#"
        "#..___...#"
        "#........#"
        "#######X##"
        "#O.......#"
        "#...?....#"
        "##########" };

    for (int i{0}; i < row; i++) {

        stageVector.emplace_back(std::vector<Tile*>());

        for (int j{0}; j < columns; j++) {

            if(l.at(c) == '#')
                stageVector.at(i).emplace_back(new Wall(i,j,nullptr));
            if(l.at(c) == 'O')
                stageVector.at(i).emplace_back(new Portal(i,j,nullptr,nullptr));
            if(l.at(c) == '<')
                stageVector.at(i).emplace_back(new Ramp(i,j,nullptr));
            if(l.at(c) == '_')
                stageVector.at(i).emplace_back(new Pit(i,j,nullptr));
            if(l.at(c) == 'X')
                stageVector.at(i).emplace_back(new Door(i,j,nullptr));
            if(l.at(c) == '.')
                stageVector.at(i).emplace_back(new Floor(i,j,nullptr));

            c++;

        }

    }

}







