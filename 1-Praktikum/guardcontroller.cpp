#include "guardcontroller.h"

GuardController::GuardController(std::vector<int> initPattern)
    :pattern{initPattern},patternCounter{0}{}



int GuardController::move()
{

    if(patternCounter == pattern.size())
        patternCounter = 0;
    int movingDir = pattern.at(patternCounter);
    patternCounter++;
    return movingDir;



}
