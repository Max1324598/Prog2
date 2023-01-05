//derived from Tile
#ifndef PORTAL_H
#define PORTAL_H
#include "tile.h"


class Portal : public Tile
{
public:
    Portal(int row,int column, Character* character, Tile* destination, int PortalType);
    ~Portal() override = default;

    //virtuelle Methoden
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;

    //setter
    void setDestination(Tile *newDestination);

    int getPortalType() const;

private:
    Tile* destination;
    int portalType;
};

#endif // PORTAL_H
