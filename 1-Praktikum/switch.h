#ifndef SWITCH_H
#define SWITCH_H
#include "tile.h"
#include "active.h"

class Switch : public Tile, public Active
{
public:
    ~Switch();
    Switch(int row, int column,Character* character);
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* fromTile, Character* who) override;

};


#endif // SWITCH_H
