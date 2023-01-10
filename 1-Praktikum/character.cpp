#include "character.h"



Character::Character()
    : texture {"C"}, tile{nullptr},strength{20},stamina{20},hitPoints{getMaxHP()}
{}

Character::Character(const std::string &texture, Tile *tile, int str, int sta)
    : texture{texture}, tile{tile}, strength{str},stamina{sta},hitPoints{getMaxHP()}
{}



Tile *Character::getTile() const
{
    return tile;
}

void Character::setTile(Tile *newTile)
{
    tile = newTile;
}

bool Character::isDead()
{
    if(getHitPoints() <= 0)
        return true;
    else
        return false;

}

int Character::getLastMovingDir() const
{
    return lastMovingDir;
}

void Character::setLastMovingDir(int newLastMovingDir)
{
    lastMovingDir = newLastMovingDir;
}

int Character::getMaxHP(){
    int maxHP = (stamina * 5) + 20;
    return maxHP;
}

int Character::getStrength() const
{
    return strength;
}

int Character::getStamina() const
{
    return stamina;
}

void Character::setHitPoints(int newHitPoints)
{
    hitPoints = newHitPoints;
}

int Character::getHitPoints() const
{
    return hitPoints;
}

void Character::setStrength(int newStrength)
{
    strength = newStrength;
}

