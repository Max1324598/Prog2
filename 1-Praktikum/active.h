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
    void detach(Passive*);
    virtual void activate();
};

#endif // ACTIVE_H
