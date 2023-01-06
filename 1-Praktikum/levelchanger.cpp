#include "levelchanger.h"

LevelChanger::LevelChanger(int row, int column, Character *character, Tile *destination, Level* nextLevel)
    : Portal{row, column, character,destination,3} , nextLevel {nextLevel}
{

}

Tile *LevelChanger::onEnter(Tile *fromTile, Character *who)
{
    activate();
    return destination;
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
