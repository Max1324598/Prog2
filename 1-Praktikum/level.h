#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include "graph.h"
#include "passive.h"
using std::vector;

class Tile;
class Character;

class Level
{
public:
    Level();
    Level (int row, int col);
    ~Level();

    //Methoden
    bool isBoundary(int currentRow, int currentColumn) const;
    void createGraph();
    void createEmptyLevel(int rows, int columns);
    void createStringLevel (int rows, int columns, std::string string);
    void createCharacter (int row, int col);
    void createNpc(int row, int col, std::vector<int> pattern);
    void createAttackNpc(int row, int col);
    void setPortals(int row1, int column1, int row2, int column2, int type);
    void setDoor(int row, int column);
    void setSwitch(int row, int column);
    void setPit(int row, int column);
    void setRamp (int row, int column);
    void setLevelChanger(int row, int column,bool isExit);
    void placeCharacter(Character *c, int row, int col);
    void placeLootChest(int row, int column);
    void rebuildGraph();
    Tile *getTile(int row, int col);
    const Tile *getTile(int row, int col) const;


    //getter

    const vector<std::vector<Tile *> > &getStageVector() const;
    int getMaxRow() const;
    int getMaxColumn() const;
    vector<Tile*> getPath(Node *source, Node *target);

    const vector<Character *> &getCharacterVector() const;


    Character *getPlayerCharacter() const;

    const Graph &getGraph() const;

private:
    int maxRow;
    int maxColumn;
    Graph graph;
    vector<std::vector<Tile*>> stageVector;
    vector<Character*> characterVector;
    Character* playerCharacter = nullptr;

};

#endif // LEVEL_H
