#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "character.h"
#include "npc.h"
#include "passive.h"
#include <vector>
#include "mylist.h"
class AbstractUI;
class Level;

class DungeonCrawler: public Passive
{
public:

    DungeonCrawler();

    //Methoden
    void turn(int movingDir);
    void turnMove(int movingDir,Character* character);
    void revertMove(Character* character);
    void setLevel(Level*);
    virtual void notify(Active* source) override;
    void saveLevels();
    bool checkForFights();
    Character* getEnemy() const;
    void battlePhase(Character* attacker, Character* defender);
    void showEndScreen(bool b);
    Level *getCurrentLevel() const;

    void setCurrentAbstractUI(AbstractUI *newCurrentAbstractUI);

    void getEnemy(bool fight);
    void gameOver();
private:
    Level* currentLevel;
    MyList levelList;
    AbstractUI* currentAbstractUI;
    Character* currentCharacter;


};

#endif // DUNGEONCRAWLER_H
