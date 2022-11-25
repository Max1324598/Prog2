#ifndef PIT_H
#define PIT_H
#include "tile.h"
#include "ramp.h"
class Pit : public Tile
{
public:
    ~Pit() override = default;
    Pit(int row, int column, Character* character);
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;
};

#endif // PIT_H
