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
    void createCharacter (int row, int col);
    void setPortals(int row1, int column1, int row2, int column2);
    void placeCharacter(Character *c, int row, int col);
    void placeNPC(Character* npc);
    void testLevel(int row, int columns);

    Tile *getTile(int row, int col);
    const Tile *getTile(int row, int col) const;

    //getter

    const vector<std::vector<Tile *> > &getStageVector() const;
    int getMaxRow() const;
    int getMaxColumn() const;

    const vector<Character *> &getCharacterVector() const;

private:
    int maxRow;
    int maxColumn;
    vector<std::vector<Tile*>> stageVector;
    vector<Character*> characterVector;

};

#endif // LEVEL_H
