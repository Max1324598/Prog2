#include "switch.h"
#include "npc.h"


Switch::Switch(int row, int column, Character* character)
    : Tile{row, column, "?",character},Active(){}


Tile* Switch::onEnter(Tile* fromTile,Character* who){

    if (typeid(*who) != typeid(Npc)){

        for(auto& n : passiveObjects){
            activate();
        }
    }
    return this;
}

Tile* Switch::onLeave(Tile* fromTile,Character* who){
    return this;
}

void Switch::detach(Passive* passiveObject){
    for(unsigned int i{0}; i < passiveObjects.size(); i++){
        if(passiveObjects.at(i) == passiveObject)
            passiveObjects.erase(passiveObjects.begin()+i);
    }
}


