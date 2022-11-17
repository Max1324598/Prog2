#include "character.h"



Character::Character()
    : texture {"X"}, tile{nullptr}
{}

Character::Character(const std::string &texture, Tile *tile)
    : texture{texture}, tile{tile}
{}



Tile *Character::getTile() const
{
    return tile;
}

void Character::setTile(Tile *newTile)
{
    tile = newTile;
}


