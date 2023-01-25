#ifndef LEVEL_H
#define LEVEL_H


#include <string>
#include <vector>
#include "graph.h"
#include "levelchanger.h"
#include "json.h"
#include "door.h"
using std::vector;

class Tile;
class Character;

class Level
{
public:
    Level();
    Level (int row, int col);
    Level (nlohmann::json level);
    ~Level();

    //Methoden
    bool isBoundary(int currentRow, int currentColumn) const;
    void createGraph();
    void createEmptyLevel(int rows, int columns);
    void createStringLevel (int rows, int columns, std::string string);
    void createCharacter (int row, int col);
    void createNpc(int row, int col, std::vector<int> pattern);
    void createAttackNpc(int row, int col);
    Tile* createTileFromString(std::string tileToCreate, int row, int col);
    void setPortals(int row1, int column1, int row2, int column2, int type);
    void setDoor(int row, int column);
    void setSwitch(int row, int column);
    void createDoorSwitch(int row1,int col1, int row2, int col2);
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



    const vector<vector<int> > &getPortalPairs() const;

    vector<vector<int> > &getDoorSwitchPairs();

    const vector<LevelChanger *> &getLevelChangers() const;

    void setPlayerCharacter(Character *newPlayerCharacter);

    void placePlayerCharacter(Character *c, int row, int col);
    const vector<Door *> &getDoorVector() const;
    void addToLcVector(LevelChanger*);

private:
    int maxRow;
    int maxColumn;
    Graph graph;
    vector<std::vector<Tile*>> stageVector;
    vector<Character*> characterVector;
    vector<vector<int>> portalPairs;
    vector<vector<int>> doorSwitchPairs;
    vector<LevelChanger*> levelChangers;
    vector<Door*>doorVector;
    Character* playerCharacter = nullptr;

};

#endif // LEVEL_H
