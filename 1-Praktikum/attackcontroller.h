#ifndef ATTACKCONTROLLER_H
#define ATTACKCONTROLLER_H
#include "abstractcontroller.h"

class Level;
class Npc;

class AttackController : public AbstractController
{
public:
    AttackController(Level* level);
    int move() override;

    void setNpc(Npc *newNpc);

private:
    int movingDir;
    Level* level;
    Npc* npc;
    int counter;
};

#endif // ATTACKCONTROLLER_H
