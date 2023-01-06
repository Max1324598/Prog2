#ifndef LEVELCHANGER_H
#define LEVELCHANGER_H

#include "active.h"
#include "portal.h"

class Level;

class LevelChanger: public Active, public Portal{
public:
    LevelChanger(int row,int column, Character* character, Tile* destination,Level* nextLevel);
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;
    void detach(Passive*) override;;


private:
    Level* nextLevel;

};

#endif // LEVELCHANGER_H
