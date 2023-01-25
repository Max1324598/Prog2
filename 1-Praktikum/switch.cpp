#include "switch.h"
#include "npc.h"
#include "level.h"
#include "door.h"
#include <iostream>



Switch::Switch(int row, int column, Character* character, Level* level)
    : Tile{row, column, "?",character},Active(),level{level}
{ }

void Switch::attach(Passive* newPassiveObject)
{
    bool alreadyListed = false;
    for(auto &listedObject : passiveObjects){
        if(listedObject == newPassiveObject)
            alreadyListed = true;
    }
    if(!alreadyListed)
        passiveObjects.emplace_back(newPassiveObject);

}



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


