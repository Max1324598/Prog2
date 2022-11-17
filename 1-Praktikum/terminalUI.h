#ifndef TERMINALUI_H
#define TERMINALUI_H
#include "abstractUI.h"


class TerminalUI : public AbstractUI
{
public:
    TerminalUI();
    ~TerminalUI() override  = default;

    //virtuelle Methoden
    void draw (Level*) override;

private:
};

#endif // TERMINALUI_H
