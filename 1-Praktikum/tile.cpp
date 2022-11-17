#include "tile.h"
#include "character.h"

//ctor
Tile::Tile (int row, int column, const string& texture, Character* character)
    : row {row}, column{column}, texture {texture}, character {character}
{}



//Methoden
bool Tile::moveTo(Tile *destTile, Character *who)
{

   if (this->onLeave(destTile,who) == nullptr) return false;
   if (destTile->onEnter(this,who) == nullptr) return false;


    this->setCharacter(nullptr);
               who->setTile(destTile->onEnter(this, who));
               destTile->onEnter(this, who)->setCharacter(who);
    return true;
}
//getter
string Tile::getTexture() const{
    if (hasCharacter() == true) return character->getTexture();
   else return texture ;

}

//setter

void Tile::setCharacter(Character *newCharacter)
{
    character = newCharacter;
}

int Tile::getRow() const
{
    return row;
}

int Tile::getColumn() const
{
    return column;
}

bool Tile::hasCharacter() const{
    if  (character == nullptr) return false;
    else return true;
}


