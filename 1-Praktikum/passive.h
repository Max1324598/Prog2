#ifndef PASSIVE_H
#define PASSIVE_H
#include "active.h"
class Active;
class Passive
{
public:
    virtual void notify(Active* source) = 0;

};

#endif // PASSIVE_H
