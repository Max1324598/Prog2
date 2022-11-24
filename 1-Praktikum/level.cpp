#include "level.h"
#include "door.h"
#include "tile.h"
#include "floor.h"
#include "wall.h"
#include "portal.h"
#include "character.h"
#include "switch.h"

Level::Level()
    : maxRow{10}, maxColumn{15}, stageVector{}, characterVector{}
{

    createEmptyLevel(maxRow, maxColumn);
    setPortals(1,2,8,8);
    createCharacter(1,1);
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
        stageVector.at(5).at(2) = door;
        stageVector.at(2).at(1) = swit;
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
