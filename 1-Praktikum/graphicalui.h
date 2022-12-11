#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H
#include "abstractUI.h"

class StartScreen;
class MainWindow;


class GraphicalUI :public AbstractUI
{
public:
    GraphicalUI();
    ~GraphicalUI() override  = default;

    void draw(Level*) override;
    void switchWindow();


private:
    StartScreen* startScreen;
    MainWindow* mainWindow;
};

#endif // GRAPHICALUI_H
