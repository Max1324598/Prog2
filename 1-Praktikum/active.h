#ifndef ACTIVE_H
#define ACTIVE_H
#include <vector>
class Passive;
class Active
{
public:
    virtual ~Active() = default;
    std::vector<Passive*> passiveObjects;
    void attach(Passive*);
    virtual void detach(Passive*) = 0;
    virtual void activate();

};

#endif // ACTIVE_H
