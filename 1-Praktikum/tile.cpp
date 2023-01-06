#include "tile.h"
#include "character.h"

//ctor
Tile::Tile (int row, int column, const string& texture, Character* character)
    : row {row}, column{column}, texture {texture}, character {character}
{}



//Methoden
bool Tile::moveTo(Tile *destTile, Character *who)
{
    Tile* onEnterResult = destTile->onEnter(this,who);

    if (this->onLeave(destTile,who) == nullptr) return false;
    if (onEnterResult == nullptr) return false;


    this->setCharacter(nullptr);
    who->setTile(onEnterResult);
    onEnterResult->setCharacter(who);
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

Character* Tile::getCharacter() const
{
    return character;
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


void Tile::setTexture(std::string s){
    texture = s;

}


