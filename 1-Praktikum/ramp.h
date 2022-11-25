#ifndef RAMP_H
#define RAMP_H
#include "tile.h"

class Ramp : public Tile
{
public:
    virtual ~Ramp() = default;
    Ramp(int row, int column, Character* character);
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;
};

#endif // RAMP_H
