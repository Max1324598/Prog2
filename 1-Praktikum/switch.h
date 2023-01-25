#ifndef SWITCH_H
#define SWITCH_H
#include "tile.h"
#include "active.h"

class Level;

class Switch : public Tile, public Active
{
public:
    ~Switch() override = default;
    Switch(int row, int column,Character* character, Level* level);
    void attach(Passive*) override;
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* fromTile, Character* who) override;
    void detach(Passive*) override;

private:
    Level* level;

};


#endif // SWITCH_H
