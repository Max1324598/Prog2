#include "abstractUI.h"

AbstractUI::AbstractUI()
    : currentDungeonCrawler{nullptr}
{

}

AbstractUI::AbstractUI(DungeonCrawler *currentDungeonCrawler)
    : currentDungeonCrawler(currentDungeonCrawler)
{

}

void AbstractUI::setCurrentDungeonCrawler(DungeonCrawler *newCurrentDungeonCrawler)
{
    currentDungeonCrawler = newCurrentDungeonCrawler;
}

DungeonCrawler *AbstractUI::getCurrentDungeonCrawler() const
{
    return currentDungeonCrawler;
}
