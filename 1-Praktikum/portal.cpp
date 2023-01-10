#include "portal.h"
#include "character.h"
#include "npc.h"

//ctor
Portal::Portal(int row,int column, Character *character, Tile *destination,int portalType)
    : Tile{row, column, "O", character}, destination {destination}, portalType{portalType}
{}



//virtuelle Methoden
Tile *Portal::onEnter(Tile *fromTile, Character *who)
{
    if (typeid(*who) != typeid(Npc)){
        return destination;
    }
    return this;
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

int Portal::getPortalType() const
{
    return portalType;
}

Tile *Portal::getDestination() const
{
    return destination;
}
