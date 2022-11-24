#ifndef ACTIVE_H
#define ACTIVE_H
#include <vector>
class Passive;
class Active
{
public:
    virtual ~Active() = 0;
    std::vector<Passive*> passiveObjects;
    void attach(Passive*);
    void detach(Passive*);
    void activate();
};

#endif // ACTIVE_H
