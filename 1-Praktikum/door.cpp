#include "door.h"

Door::Door(int row, int column, Character* character)
    :Tile{row,column,"X",character}{isOpen = false;}

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
}

bool Door::getIsOpen() const
{
    return isOpen;
}

