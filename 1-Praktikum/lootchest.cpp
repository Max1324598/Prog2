#include "lootchest.h"
#include "passive.h"

#include <npc.h>

LootChest::LootChest(int row, int col, Character *character)
    : Tile(row,col,"$",character)
{

}

void LootChest::detach(Passive* passiveObject){
    for(unsigned int i{0}; i < passiveObjects.size(); i++){
        if(passiveObjects.at(i) == passiveObject)
            passiveObjects.erase(passiveObjects.begin()+i);
    }
}



void LootChest::activate(){
    for(auto& n : passiveObjects){
        n->notify(this);
    }
}

Tile *LootChest::onEnter(Tile *fromTile, Character *who)
{
    if(dynamic_cast<Npc*>(who) == nullptr){
        activate();
    }
    return this;
}

Tile *LootChest::onLeave(Tile *destTile, Character *who)
{
    return this;
}

