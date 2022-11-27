#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "character.h"
#include "npc.h"
class AbstractUI;
class Level;

class DungeonCrawler
{
public:
    DungeonCrawler() = delete;
    DungeonCrawler(Level* currentLevel, AbstractUI* currentAbcractUI,Character* currentCharacter);

    //Methoden
    void turn(int movingDir);
    void turnMove(int movingDir,Character* character);

private:
    Level* currentLevel;
    AbstractUI* currentAbstractUI;
    Character* currentCharacter;


};

#endif // DUNGEONCRAWLER_H
