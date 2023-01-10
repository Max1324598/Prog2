#ifndef LOOTCHEST_H
#define LOOTCHEST_H

#include <active.h>
#include <tile.h>



class LootChest : public Tile,public Active
{
public:
    LootChest(int row, int col, Character* character);
    void detach(Passive *passiveObject);

    void activate();
    Tile *onEnter(Tile *fromTile, Character *who);
    Tile *onLeave(Tile *destTile, Character *who);
};

#endif // LOOTCHEST_H
