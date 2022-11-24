#include "switch.h"
Switch::~Switch(){
    for(auto& n : passiveObjects){
        delete n;
        n = nullptr;
    }
    delete this;
}

Switch::Switch(int row, int column, Character* character)
    : Tile{row, column, "?",character},Active(){}


Tile* Switch::onEnter(Tile* fromTile,Character* who){
    for(auto& n : passiveObjects){
        activate();
    }
    return this;
}

Tile* Switch::onLeave(Tile* fromTile,Character* who){
    return this;
}
