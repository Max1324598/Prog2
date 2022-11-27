#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
using std::string;

class Tile;

class Character
{
public:
    Character();
    Character(const string& texture, Tile* tile);

    //getter
    string getTexture() const {return texture;}
    virtual Tile *getTile() const;
    //setter
    void setTile(Tile *newTile);

private:
    string texture;
    Tile* tile;

};

#endif // CHARACTER_H
