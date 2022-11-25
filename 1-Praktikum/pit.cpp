#include "pit.h"

Pit::Pit(int row, int column, Character* character)
    :Tile{row,column,"_",character}{}

Tile *Pit::onEnter(Tile *fromTile, Character *who)
{
    return this;
}

Tile *Pit::onLeave(Tile *destTile, Character *who){
    if(dynamic_cast<Ramp*>(destTile) != nullptr || dynamic_cast<Pit*>(destTile) != nullptr)
        return this;

    else{
        return nullptr;
    }
};



