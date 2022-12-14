#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
using std::vector;

class Tile;
class Character;

class Level
{
public:
    Level();
    ~Level();

    //Methoden
    bool isBoundary(int currentRow, int currentColumn) const;
    void createEmptyLevel(int rows, int columns);
    void createStringLevel (int rows, int columns);
    void createCharacter (int row, int col);
    void createNpc(int row, int col, std::vector<int> pattern);
    void setPortals(int row1, int column1, int row2, int column2, int type);
    void setDoor(int row, int column);
    void setSwitch(int row, int column);
    void setPit(int row, int column);
    void setRamp (int row, int column);
    void placeCharacter(Character *c, int row, int col);

    Tile *getTile(int row, int col);
    const Tile *getTile(int row, int col) const;

    //getter

    const vector<std::vector<Tile *> > &getStageVector() const;
    int getMaxRow() const;
    int getMaxColumn() const;

    const vector<Character *> &getCharacterVector() const;


    Character *getPlayerCharacter() const;

private:
    int maxRow;
    int maxColumn;
    vector<std::vector<Tile*>> stageVector;
    vector<Character*> characterVector;
    Character* playerCharacter = nullptr;

};

#endif // LEVEL_H
