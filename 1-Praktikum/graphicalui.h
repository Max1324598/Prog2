#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H
#include "abstractUI.h"

#include <QPixmap>

class StartScreen;
class MainWindow;


class GraphicalUI :public AbstractUI
{
public:
    GraphicalUI();
    ~GraphicalUI() override  = default;

    void draw(Level* level) override;
    void switchWindow();


private:
    StartScreen* startScreen;
    MainWindow* mainWindow;

    std::vector<QPixmap> floors;
    std::vector<QPixmap> portals;
    std::vector<QPixmap> others;
};

#endif // GRAPHICALUI_H
