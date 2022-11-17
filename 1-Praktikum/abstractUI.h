#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H

class DungeonCrawler;

class Level;

class AbstractUI
{
public:
    AbstractUI();
    AbstractUI(DungeonCrawler* currentDungeonCrawler);
    virtual ~AbstractUI() = default;
    virtual void draw(Level*) = 0;

    void setCurrentDungeonCrawler(DungeonCrawler *newCurrentDungeonCrawler);

    DungeonCrawler *getCurrentDungeonCrawler() const;

private:
    DungeonCrawler* currentDungeonCrawler;
};

#endif // ABSTRACTUI_H
