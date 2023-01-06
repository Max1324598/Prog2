#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
using std::string;

class Tile;

class Character
{
public:
    Character();
    Character(const string& texture, Tile* tile, int strength, int stamina);
    virtual ~Character() = default;
    //getter
    string getTexture() const {return texture;}
    virtual Tile *getTile() const;
    //setter
    void setTile(Tile *newTile);

    int getLastMovingDir() const;
    void setLastMovingDir(int newLastMovingDir);
    int getMaxHP();
    int getStrength() const;

    int getStamina() const;

private:
    string texture;
    Tile* tile;
    int lastMovingDir = 5;
    int strength;
    int stamina;
    int hitPoints;
};

#endif // CHARACTER_H
