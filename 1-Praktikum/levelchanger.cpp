#include "levelchanger.h"
#include "level.h"
#include "npc.h"

#include <pit.h>

LevelChanger::LevelChanger(int row, int column, bool isExit, Level* level)
    : Portal{row, column, nullptr,nullptr,0} , isExit {isExit}, level {level}
{

}

Tile *LevelChanger::onEnter(Tile *fromTile, Character *who)
{

    if (typeid(*who) != typeid(Npc)){

    activate();
    return destination;
    }
    return this;
}

Tile *LevelChanger::onLeave(Tile *destTile, Character *who)
{
    return this;
}

void LevelChanger::detach(Passive* passiveObject){
    for(unsigned int i{0}; i < passiveObjects.size(); i++){
        if(passiveObjects.at(i) == passiveObject)
            passiveObjects.erase(passiveObjects.begin()+i);
    }
}

bool LevelChanger::getIsExit() const
{
    return isExit;
}

Level *LevelChanger::getLevel() const
{
    return level;
}

void LevelChanger::setIsExit(bool newIsExit)
{
    isExit = newIsExit;
}

