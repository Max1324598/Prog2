#ifndef NPC_H
#define NPC_H
#include "character.h"
#include "abstractcontroller.h"
class Npc : public Character
{
public:
    Npc(std::string texture, Tile* tile,AbstractController* controller);
    AbstractController* getController() const;
    void setCurrentController(AbstractController *newCurrentController);

private:
    AbstractController* currentController;

};

#endif // NPC_H
