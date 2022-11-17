#include "wall.h"

//ctor
Wall::Wall(int row, int column, Character *character)
    :Tile{row,column, "#", character}
{ }



//virtuelle Methoden
Tile *Wall::onEnter(Tile *fromTile, Character *who)
{
    return nullptr;
}

Tile *Wall::onLeave(Tile *destTile, Character *who)
{
    return this;
}


