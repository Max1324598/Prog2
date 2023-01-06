#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "character.h"
#include "npc.h"
#include "passive.h"
#include <vector>
class AbstractUI;
class Level;

class DungeonCrawler: public Passive
{
public:

    DungeonCrawler();

    //Methoden
    void turn(int movingDir);
    void turnMove(int movingDir,Character* character);
    void setLevel(Level*);
    virtual void notify(Active* source) override;
    void saveLevels();

    Level *getCurrentLevel() const;

    void setCurrentAbstractUI(AbstractUI *newCurrentAbstractUI);

private:
    Level* currentLevel;
    std::vector<Level*> levelVector;
    AbstractUI* currentAbstractUI;
    Character* currentCharacter;


};

#endif // DUNGEONCRAWLER_H
