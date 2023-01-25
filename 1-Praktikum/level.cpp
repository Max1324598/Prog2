#include "level.h"
#include "door.h"
#include "guardcontroller.h"
#include "npc.h"
#include "tile.h"
#include "floor.h"
#include "wall.h"
#include "portal.h"
#include "character.h"
#include "switch.h"
#include "pit.h"
#include "ramp.h"
#include "door.h"
#include "levelchanger.h"
#include <algorithm>
#include "attackcontroller.h"
#include <iostream>
#include <limits>
#include <lootchest.h>
#include <queue>
Level::Level()
    : maxRow{10}, maxColumn{10}, stageVector{}, characterVector{}, graph(maxRow, maxColumn)
{
    std::string levelString {
        "##########"
        "#........#"
        "#...<....#"
        "#..___...#"
        "#..___...#"
        "#........#"
        "#######X##"
        "#........#"
        "#...?....#"
        "##########"};
    createStringLevel(maxRow,maxColumn, levelString);

    createDoorSwitch(6,7,8,4);

    createGraph();
    createAttackNpc(5,5);


    setPortals(1,8,8,1,1);
}

Level::Level(int row, int col)
    : maxRow{row}, maxColumn{col}, stageVector{}, characterVector{},graph(maxRow,maxColumn)
{
}

Level::Level(nlohmann::json level)
    : maxRow{10}, maxColumn{10}, stageVector{}, characterVector{},graph(maxRow,maxColumn)
{
    this->maxRow = level["maxrows"];
    this->maxColumn = level["maxcols"];

    for (int i{}; i<maxRow; i++){
        stageVector.emplace_back();
        for (int j{}; j<maxColumn; j++){
            std::string tmpstring = level["field"][i][j];
            auto tmpTile = createTileFromString(tmpstring, i, j);
            this->stageVector.at(i).push_back(tmpTile);
        }
    }



    graph = Graph(maxRow,maxColumn);

    for(const auto& jplayer : level["player"] ){
        if(jplayer["hasPlayer"] == "1"){

            Character* player = new Character();
            player->setHitPoints(jplayer["hitpoints"]);
            player->setStamina(jplayer["stamina"]);
            player->setStrength(jplayer["strength"]);
            placePlayerCharacter(player, jplayer["row"], jplayer["col"]);
        }

    }

    for(const auto& jcharacter: level["character"]){

        AttackController* npcController = new AttackController(this);
        Npc* npc = new Npc("N", nullptr, npcController);
        npcController->setNpc(npc);
        npc->setStamina(jcharacter["stamina"]);
        npc->setStrength(jcharacter["strength"]);
        npc->setHitPoints(jcharacter["hitpoints"]);
        placeCharacter(npc, jcharacter["row"], jcharacter["col"]);
        characterVector.push_back(npc);

    }


    for(const auto& jportal : level["portalpairs"] ){
        setPortals(jportal["row1"],jportal["column1"],jportal["row2"],jportal["column2"],1);
    }

    for (const auto& jdoorSwitch: level["doorswitchpairs"]) {
        createDoorSwitch(jdoorSwitch["row1"],jdoorSwitch["column1"],jdoorSwitch["row2"],jdoorSwitch["column2"]);
    }

     for (const auto& jdoor: level["doors"]) {
         Tile* doorTile = stageVector.at(jdoor["row"]).at(jdoor["column"]);
         Door* door = dynamic_cast<Door*>(doorTile);
         door->setIsOpen(jdoor["isOpen"]);
     }


    graph = Graph(maxRow,maxColumn);
    createGraph();
}






Level::~Level()
{
    for (std::vector<Tile*>& vec: stageVector) {
        for (Tile*& tile : vec) {

            delete tile;
            tile = nullptr;
        }
    }

    for (Character*& ch : characterVector){
        delete ch;
        ch = nullptr;
    }
}


//Methoden
bool Level::isBoundary(int currentRow, int currentColumn) const
{
    if (currentRow == 0 || currentRow == maxRow-1) return true;
    else if (currentColumn == 0 || currentColumn == maxColumn-1) return true;
    else return false;
}

void Level::createGraph()
{
    Character* testNpc = new Npc("N", nullptr, nullptr);

    for (int row{}; row<maxRow; row++){
        for (int col{}; col<maxColumn; col++){
            graph.addNode(new Node{stageVector.at(row).at(col),row,col,0,nullptr,false});
        }
    }

    for (int row{}; row<maxRow; row++){
        for (int col{}; col<maxColumn; col++){
            Node* currentNode = graph.getNodeVector().at(row).at(col);
            testNpc->setTile(currentNode->tile);
            Tile* nextTile;

            //1
            if ((currentNode->row < this->getMaxRow()-1) && (currentNode->col  > 0 )){
                nextTile = stageVector.at(row+1).at(col-1)->onEnter(currentNode->tile,testNpc);
                if (nextTile != nullptr && currentNode->tile->onLeave(nextTile,testNpc)){
                    Node* nextNode = graph.getNodeVector().at(nextTile->getRow()).at(nextTile->getColumn());
                    graph.addEdge(new Edge{currentNode,nextNode});
                }

            }

            //2
            if (currentNode->row < this->getMaxRow()-1){
                nextTile = stageVector.at(row+1).at(col)->onEnter(currentNode->tile,testNpc);
                if (nextTile != nullptr && currentNode->tile->onLeave(nextTile,testNpc)){
                    Node* nextNode = graph.getNodeVector().at(nextTile->getRow()).at(nextTile->getColumn());
                    graph.addEdge(new Edge{currentNode,nextNode});
                }
            }
            //3
            if ((currentNode->row < this->getMaxRow()-1) && (currentNode->col < this->getMaxColumn()-1 )){
                nextTile = stageVector.at(row+1).at(col+1)->onEnter(currentNode->tile,testNpc);
                if (nextTile != nullptr && currentNode->tile->onLeave(nextTile,testNpc)){
                    Node* nextNode = graph.getNodeVector().at(nextTile->getRow()).at(nextTile->getColumn());
                    graph.addEdge(new Edge{currentNode,nextNode});
                }
            }
            //4
            if ((currentNode->col > 0)){
                nextTile = stageVector.at(row).at(col-1)->onEnter(currentNode->tile,testNpc);
                if (nextTile != nullptr && currentNode->tile->onLeave(nextTile,testNpc)){
                    Node* nextNode = graph.getNodeVector().at(nextTile->getRow()).at(nextTile->getColumn());
                    graph.addEdge(new Edge{currentNode,nextNode});
                }
            }
            //6
            if (currentNode->col < this->getMaxColumn()-1){
                nextTile = stageVector.at(row).at(col+1)->onEnter(currentNode->tile,testNpc);
                if (nextTile != nullptr && currentNode->tile->onLeave(nextTile,testNpc)){
                    Node* nextNode = graph.getNodeVector().at(nextTile->getRow()).at(nextTile->getColumn());
                    graph.addEdge(new Edge{currentNode,nextNode});
                }
            }
            //7
            if ((currentNode->row > 0) && (currentNode->col  > 0 )){
                nextTile = stageVector.at(row-1).at(col-1)->onEnter(currentNode->tile,testNpc);
                if (nextTile != nullptr && currentNode->tile->onLeave(nextTile,testNpc)){
                    Node* nextNode = graph.getNodeVector().at(nextTile->getRow()).at(nextTile->getColumn());
                    graph.addEdge(new Edge{currentNode,nextNode});
                }
            }
            //8
            if (currentNode->row > 0){
                nextTile = stageVector.at(row-1).at(col)->onEnter(currentNode->tile,testNpc);
                if (nextTile != nullptr && currentNode->tile->onLeave(nextTile,testNpc)){
                    Node* nextNode = graph.getNodeVector().at(nextTile->getRow()).at(nextTile->getColumn());
                    graph.addEdge(new Edge{currentNode,nextNode});
                }
            }
            //9
            if ((currentNode->row > 0) && (currentNode->col  < this->getMaxColumn()-1)){
                nextTile = stageVector.at(row-1).at(col+1)->onEnter(currentNode->tile,testNpc);
                if (nextTile != nullptr && currentNode->tile->onLeave(nextTile,testNpc)){
                    Node* nextNode = graph.getNodeVector().at(nextTile->getRow()).at(nextTile->getColumn());
                    graph.addEdge(new Edge{currentNode,nextNode});
                }
            }
        }
    }
}



void Level::createEmptyLevel(int rows, int columns)
{

    for (int i{0}; i <= rows; i++) {

        stageVector.emplace_back(std::vector<Tile*>{});

        for (int j{0}; j <= columns; j++) {
            if (isBoundary(i, j)) {

                stageVector.at(i).emplace_back(new Wall(i, j, nullptr));

            } else {
                stageVector.at(i).emplace_back(new Floor(i, j,nullptr));
            }
        }

    }

}

void Level::createStringLevel(int rows, int columns, std::string string)
{
    const std::string lev = string;

    int k{0};


    for (int i{0}; i < rows; i++) {

        stageVector.emplace_back();


        for (int j{0}; j < columns; j++) {

            if (lev.at(k) == '#') {
                stageVector.at(i).push_back(new Wall(i, j, nullptr));
            }
            if (lev.at(k) == '.') {
                stageVector.at(i).push_back(new Floor(i, j, nullptr));
            }
            if (lev.at(k) == '_') {
                stageVector.at(i).push_back(new Pit(i, j, nullptr));
            }
            if (lev.at(k) == '<') {
                stageVector.at(i).push_back(new Ramp(i, j, nullptr));
            }
            if (lev.at(k)== '?'){
                stageVector.at(i).push_back(new Switch(i,j,nullptr,this));
            }
            if (lev.at(k)== 'X'){
                stageVector.at(i).push_back(new Door(i,j,nullptr,this));
            }
            if (lev.at(k)== '$'){
                stageVector.at(i).push_back(new LootChest(i,j,nullptr));
            }
            k++;
        }
    }
}





void Level::setPortals(int row1, int column1, int row2, int column2, int type)
{
    Portal* newPortal1 = new Portal (row1, column1, nullptr, nullptr, type);
    Portal* newPortal2 = new Portal (row2, column2, nullptr, nullptr, type);
    newPortal1 ->setDestination(newPortal2);
    newPortal2 ->setDestination(newPortal1);

    delete stageVector.at(row1).at(column1);
    delete stageVector.at(row2).at(column2);

    stageVector.at(row1).at(column1) = newPortal1;
    stageVector.at(row2).at(column2) = newPortal2;

    vector<int> portalpair {row1,column1,row2,column2};
    portalPairs.push_back(portalpair);
}

void Level::setDoor(int row, int column)
{
    Door* newDoor = new Door (row,column, nullptr,this);
    delete stageVector.at(row).at(column);
    stageVector.at(row).at(column) = newDoor;
}

void Level::setSwitch(int row, int column)
{
    Switch* newSwitch = new Switch (row,column, nullptr,this);
    delete stageVector.at(row).at(column);
    stageVector.at(row).at(column) = newSwitch;
}

void Level::createDoorSwitch(int row1, int col1, int row2, int col2)
{
    auto door = new Door(row1, col1,nullptr,this);
    auto leaver =new Switch(row2, col2,nullptr,this);
    leaver->attach(door);

    delete stageVector.at(row1).at(col1);
    delete stageVector.at(row2).at(col2);

    stageVector.at(row1).at(col1) = door;
    stageVector.at(row2).at(col2) = leaver;

    doorVector.push_back(door);
    doorSwitchPairs.push_back({row1,col1,row2,col2});

}

void Level::setPit(int row, int column)
{
    Pit* newPit = new Pit (row,column, nullptr);
    delete stageVector.at(row).at(column);
    stageVector.at(row).at(column) = newPit;
}

void Level::setRamp(int row, int column)
{
    Ramp* newRamp = new Ramp (row,column, nullptr);
    delete stageVector.at(row).at(column);
    stageVector.at(row).at(column) = newRamp;
}

void Level::setLevelChanger(int row, int column, bool isExit)
{
    LevelChanger* newLevelChanger = new LevelChanger(row,column,isExit,this);
    delete stageVector.at(row).at(column);
    stageVector.at(row).at(column) = newLevelChanger;
    levelChangers.push_back(newLevelChanger);
}



void Level::placeCharacter(Character *c, int row, int col)
{
    c->setTile(getTile(row,col));
    stageVector.at(row).at(col)->setCharacter(c);

}

void Level::placePlayerCharacter(Character *c, int row, int col)
{
    c->setTile(getTile(row,col));
    stageVector.at(row).at(col)->setCharacter(c);
    playerCharacter = c;
}

const vector<Door *> &Level::getDoorVector() const
{
    return doorVector;
}

void Level::placeLootChest(int row, int column)
{
    LootChest* lootChest = new LootChest(row,column,nullptr);
    delete stageVector.at(row).at(column);
    stageVector.at(row).at(column) = lootChest;

}

void Level::rebuildGraph()
{
    for(int i{}; i<graph.getNodeVector().size();i++){
        for (int j{}; j<graph.getNodeVector().at(i).size();j++){
            delete graph.getNodeVector().at(i).at(j);
        }
    }

    auto adjacencyList = graph.getAdjacencyList();
    auto it = adjacencyList.begin();
    while (it != adjacencyList.end()){
        adjacencyList.erase(it);
        it++;
    }

    createGraph();
}

void Level::createNpc(int row, int col, std::vector<int> pattern) {
    GuardController* npcController = new GuardController(pattern);
    Npc* npc = new Npc("N", nullptr, npcController);
    npc->setCurrentController(npcController);
    placeCharacter(npc, row, col);
    characterVector.push_back(npc);
}

void Level::createAttackNpc(int row, int col)
{
    AttackController* npcController = new AttackController(this);
    Npc* npc = new Npc("N", nullptr, npcController);
    npcController->setNpc(npc);
    placeCharacter(npc, row, col);
    characterVector.push_back(npc);
}

Tile *Level::createTileFromString(std::string tileToCreate, int row, int col)
{
    if (tileToCreate == "door") {
        return new Door(row, col,nullptr,this);
    } else if (tileToCreate == "floor") {
        return new Floor(row, col,nullptr);
    } else if (tileToCreate == "levelchanger") {
        return new LevelChanger(row, col,0,this);
    } else if (tileToCreate == "lootchest") {
        return new LootChest(row, col,nullptr);
    } else if (tileToCreate == "pit") {
        return new Pit(row, col,nullptr);
    } else if (tileToCreate == "portal") {
        return new Portal(row, col, nullptr, nullptr, 0);
    } else if (tileToCreate == "ramp") {
        return new Ramp(row, col,nullptr);
    } else if (tileToCreate == "switch") {
        return new Switch(row, col,nullptr,this);
    } else if (tileToCreate == "wall") {
        return new Wall(row, col,nullptr);
    }

}


void Level::createCharacter(int row, int col)
{
    characterVector.push_back(new Character());
    placeCharacter(characterVector.at(characterVector.size()-1),row, col);
}

//getter
Tile *Level::getTile(int row, int col)
{
    return stageVector.at(row).at(col);
}

const Tile *Level::getTile(int row, int col) const
{
    return stageVector.at(row).at(col);
}

const vector<std::vector<Tile *> >& Level::getStageVector() const
{
    return stageVector;
}

int Level::getMaxRow() const
{
    return maxRow;
}

int Level::getMaxColumn() const
{
    return maxColumn;
}

vector<Tile*> Level::getPath(Node* source, Node* target)
{
    vector<Tile*> result;
    auto currentNodeVector = graph.getNodeVector();

    for(int i{}; i<currentNodeVector.size(); i++){
        for(int j{}; j<currentNodeVector.at(i).size(); j++){
            Node* currentNode = currentNodeVector.at(i).at(j);
            currentNode->distance = std::numeric_limits<int>::max();
            currentNode->parent = nullptr;
        }
    }
    source->distance = 0;

    std::queue<Node *> q;
    q.push(source);

    while (!q.empty()){
        auto *u = q.front();
        q.pop();

        std::vector<Node*> connected = graph.getConnections(u);

        for (Node* v : connected) {

            if(u->distance+1 < v->distance){
                v->distance = u->distance + 1;
                v->parent = u;
                q.push(v);
            }
        }
    }

    Node* pathNodes = target;


    if (target->distance > 1000) return result;

    while (pathNodes->distance > 1){
        result.push_back(pathNodes->parent->tile);
        pathNodes = pathNodes->parent;
    }





    std::reverse(result.begin(), result.end());


    return result;
}

const vector<Character *> &Level::getCharacterVector() const
{
    return characterVector;
}

Character *Level::getPlayerCharacter() const
{
    return playerCharacter;
}

const Graph &Level::getGraph() const
{
    return graph;
}

const vector<vector<int> > &Level::getPortalPairs() const
{
    return portalPairs;
}

vector<vector<int>> &Level::getDoorSwitchPairs()
{
    return doorSwitchPairs;
}

const vector<LevelChanger *> &Level::getLevelChangers() const
{
    return levelChangers;
}

void Level::setPlayerCharacter(Character *newPlayerCharacter)
{
    playerCharacter = newPlayerCharacter;
}

