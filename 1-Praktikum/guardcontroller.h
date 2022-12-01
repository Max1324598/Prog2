#ifndef GUARDCONTROLLER_H
#define GUARDCONTROLLER_H
#include "abstractcontroller.h"
#include <vector>
class GuardController : public AbstractController
{
public:
    GuardController(std::vector<int> initPattern);
    int move() override;
private:
    std::vector<int> pattern;
    int patternCounter;
};

#endif // GUARDCONTROLLER_H
