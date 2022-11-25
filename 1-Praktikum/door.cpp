#include "door.h"

Door::Door(int row, int column, Character* character)
    :Tile{row,column,"X",character}{open = false;}

Tile* Door::onEnter(Tile* fromTile, Character* who){
    if(open)
        return this;
    else
        return nullptr;
}

Tile* Door::onLeave(Tile* fromTile, Character* who){
    return this;
}

void Door::notify(Active* source){

    if(!open){
        this->texture = "/";
        open = true;
    }
    else{
        this->texture = "X";
        open = false;
    }
}

