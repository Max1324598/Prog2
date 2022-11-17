#include "floor.h"

//ctor
Floor::Floor(int row,int column, Character *character)
    : Tile{row, column, ".", character}
{}


//virtual Methoden
Tile *Floor::onEnter(Tile *fromTile, Character *who)
{
    return this;
}

Tile *Floor::onLeave(Tile *destTile, Character *who)
{
    return this;
}

