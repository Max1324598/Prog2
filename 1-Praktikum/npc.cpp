#include "npc.h"



Npc::Npc(std::string texture, Tile* tile, AbstractController* controller):
    Character(texture,tile),currentController{controller}{}

AbstractController *Npc::getController() const
{
    return currentController;
}

