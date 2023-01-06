#ifndef LEVELCHANGER_H
#define LEVELCHANGER_H
#include "tile.h"
#include "level.h"
class LevelChanger : public Tile
{
public:
    LevelChanger(int row, int col,Level* currentLevel ,Level* linkedLevel);
    Level* getLinkedLevel() const;

    Tile* onEnter(Tile* fromTile, Character* who);
    Tile* onLeave(Tile* destTile, Character* who) override;
private:
    Level* currentLevel;
    Level* linkedLevel;
};

#endif // LEVELCHANGER_H
