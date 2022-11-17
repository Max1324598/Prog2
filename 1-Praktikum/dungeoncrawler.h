#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H

class AbstractUI;
class Level;

class DungeonCrawler
{
public:
    DungeonCrawler() = delete;
    DungeonCrawler(Level* currentLevel, AbstractUI* currentAbcractUI);

    //Methoden
    void turn(int movingDir);

private:
    Level* currentLevel;
    AbstractUI* currentAbstractUI;


};

#endif // DUNGEONCRAWLER_H
