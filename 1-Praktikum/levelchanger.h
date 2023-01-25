#ifndef LEVELCHANGER_H
#define LEVELCHANGER_H

#include "active.h"
#include "portal.h"

class Level;

class LevelChanger: public Active, public Portal{
public:
    LevelChanger(int row,int column, bool isExit, Level* level);
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;
    void detach(Passive*) override;;


    bool getIsExit() const;

    Level *getLevel() const;

    void setIsExit(bool newIsExit);

private:
    bool isExit;
    Level* level;

};

#endif // LEVELCHANGER_H
