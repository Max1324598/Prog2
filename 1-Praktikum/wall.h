//derived from Tile

#ifndef WALL_H
#define WALL_H
#include "tile.h"

class Wall : public Tile
{
public:
    Wall() = delete;
    Wall(int row, int column, Character* character);
    ~Wall() override = default;

    //virtuelle Methoden
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;
};

#endif // WALL_H
