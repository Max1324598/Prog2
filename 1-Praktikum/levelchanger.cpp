#include "levelchanger.h"


LevelChanger::LevelChanger(int row, int col, Level *cl, Level *ll)
    : Tile{row,col,"L",nullptr},currentLevel{cl},linkedLevel{ll}{}

Level *LevelChanger::getLinkedLevel() const
{
    return linkedLevel;
}

Tile* LevelChanger::onEnter(Tile *fromTile, Character *who)
{
    return this;
}

Tile* LevelChanger::onLeave(Tile *destTile, Character *who)
{
    return this;
}
