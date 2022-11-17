//Floor ---

#ifndef FLOOR_H
#define FLOOR_H

#include "tile.h"

class Floor : public Tile
{
public:
    Floor() = delete;
    Floor(int row,int column, Character* character);
     ~Floor() override = default;

    //Virtual-Override
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;


private:

};

#endif // FLOOR_H
