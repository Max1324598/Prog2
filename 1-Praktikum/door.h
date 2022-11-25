#ifndef DOOR_H
#define DOOR_H
#include "tile.h"
#include "passive.h"
class Door : public Tile, public Passive
{
public:
    Door(int row, int column, Character* character);
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* fromTile, Character* who) override;
    bool open;
    void notify(Active* source) override;
};

#endif // DOOR_H
