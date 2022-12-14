#include "character.h"



Character::Character()
    : texture {"C"}, tile{nullptr}
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

int Character::getLastMovingDir() const
{
    return lastMovingDir;
}

void Character::setLastMovingDir(int newLastMovingDir)
{
    lastMovingDir = newLastMovingDir;
}

