#ifndef DOOR_H
#define DOOR_H
#include "tile.h"
#include "passive.h"
class Level;

class Door : public Tile, public Passive
{
public:
    Door(int row, int column, Character* character,Level* level);
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* fromTile, Character* who) override;
    void notify(Active* source) override;

    bool getIsOpen() const;

private:
     bool isOpen;
     Level* currentLevel;
};

#endif // DOOR_H
