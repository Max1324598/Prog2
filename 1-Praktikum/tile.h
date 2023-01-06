//Abstract Class Tile

#ifndef TILE_H
#define TILE_H
#include <typeinfo>
#include <string>
using std::string;

class Character;

class Tile
{
public:
    Tile() = delete;
    Tile(int row, int column, const string& texture, Character* character);
    virtual ~Tile() = default;


    bool hasCharacter() const;
    bool moveTo(Tile* destTile, Character* who);

    //getter
    string getTexture() const;
    int getRow() const;
    int getColumn() const;
    void setTexture(std::string s);

    //setter


    //vitual-Methoden
    virtual Tile* onEnter(Tile* fromTile, Character* who) = 0;
    virtual Tile* onLeave(Tile* destTile, Character* who) = 0;
    void setCharacter(Character *newCharacter);



    Character *getCharacter() const;

protected:
    int row;
    int column;
    string texture;
    Character* character;

};



#endif // TILE_H
