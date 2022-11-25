#include "ramp.h"

Ramp::Ramp(int row,int column, Character* character)
    :Tile{row,column,"<",character}{}

Tile* Ramp::onEnter(Tile* fromTile, Character* who){
    return this;
}
Tile* Ramp::onLeave(Tile* destTile, Character* who) {
    return this;
}
