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
    virtual ~Character() = default;
    //getter
    string getTexture() const {return texture;}
    virtual Tile *getTile() const;
    //setter
    void setTile(Tile *newTile);

    int getLastMovingDir() const;
    void setLastMovingDir(int newLastMovingDir);

private:
    string texture;
    Tile* tile;
    int lastMovingDir = 5;
};

#endif // CHARACTER_H
