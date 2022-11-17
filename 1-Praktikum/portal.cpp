#include "portal.h"

//ctor
Portal::Portal(int row,int column, Character *character, Tile *destination)
    : Tile{row, column, "O", character}, destination {destination}
{}



//virtuelle Methoden
Tile *Portal::onEnter(Tile *fromTile, Character *who)
{

       return destination;
}

Tile *Portal::onLeave(Tile *destTile, Character *who)
{
    return this;
}


//setter
void Portal::setDestination(Tile *newDestination)
{
    destination = newDestination;
}
