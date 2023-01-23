#include "attackcontroller.h"
#include "level.h"
#include "character.h"
#include "npc.h"
AttackController::AttackController(Level *level): level(level)
{

}

int AttackController::move()
{
    Tile* charTile = level->getPlayerCharacter()->getTile();
    Node* targetNode = level->getGraph().getNodeVector().at(charTile->getRow()).at(charTile->getColumn());

    Tile* npcTile = npc->getTile();
    Node* sourceNode = level->getGraph().getNodeVector().at(npcTile->getRow()).at(npcTile->getColumn());

    auto path = level->getPath(sourceNode,targetNode);

    //1
    if (path.at(0) == level->getStageVector().at(npcTile->getRow()+1).at(npcTile->getColumn()-1)) return 1;
    //2
    if (path.at(0) == level->getStageVector().at(npcTile->getRow()+1).at(npcTile->getColumn())) return 2;
    //3
    if (path.at(0) == level->getStageVector().at(npcTile->getRow()+1).at(npcTile->getColumn()+1)) return 3;
    //4
    if (path.at(0) == level->getStageVector().at(npcTile->getRow()).at(npcTile->getColumn()-1)) return 4;
    //6
    if (path.at(0) == level->getStageVector().at(npcTile->getRow()).at(npcTile->getColumn()+1)) return 6;
    //7
    if (path.at(0) == level->getStageVector().at(npcTile->getRow()-1).at(npcTile->getColumn()-1)) return 7;
    //8
    if (path.at(0) == level->getStageVector().at(npcTile->getRow()-1).at(npcTile->getColumn())) return 8;
    //9
    if (path.at(0) == level->getStageVector().at(npcTile->getRow()-1).at(npcTile->getColumn()+1)) return 9;

    return 5;


}

void AttackController::setNpc(Npc *newNpc)
{
    npc = newNpc;
}
