#include "door.h"
#include "level.h"

Door::Door(int row, int column, Character* character, Level* level)
    :Tile{row,column,"X",character}
{
    isOpen = false;
    currentLevel = level;
}

Tile* Door::onEnter(Tile* fromTile, Character* who){
    if(isOpen)
        return this;
    else
        return nullptr;
}

Tile* Door::onLeave(Tile* fromTile, Character* who){
    return this;
}

void Door::notify(Active* source){

    if(!isOpen){
        this->texture = "/";
        isOpen = true;
    }
    else{
        this->texture = "X";
        isOpen = false;
    }

    currentLevel->rebuildGraph();

}

bool Door::getIsOpen() const
{
    return isOpen;
}

void Door::setIsOpen(bool newIsOpen)
{
    isOpen = newIsOpen;
}

