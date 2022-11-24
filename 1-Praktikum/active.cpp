#include "passive.h"

void Active::activate(){
    for(auto& n : passiveObjects){
        n->notify(this);
    }
}

void Active::attach(Passive* newPassiveObject){
    bool alreadyListed = false;
    for(auto &n : passiveObjects){
        if(n == newPassiveObject)
            alreadyListed = true;
    }
    if(!alreadyListed)
        passiveObjects.emplace_back(newPassiveObject);
}

void Active::detach(Passive* passiveObject){
    for(unsigned int i{0}; i < passiveObjects.size(); i++){
        if(passiveObjects.at(i) == passiveObject)
            passiveObjects.erase(passiveObjects.begin()+i);
    }
}
