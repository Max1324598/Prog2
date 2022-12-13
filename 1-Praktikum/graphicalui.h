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

    QPixmap getRandomFloorTexture();


private:
    StartScreen* startScreen;
    MainWindow* mainWindow;

    std::vector<QPixmap> floorTextures;
    std::vector<QPixmap> portalTextures;
    std::vector<QPixmap> doorTextures;


    QPixmap wallTexture{QPixmap(QPixmap("../textures/portal/portal1.png"))};
    QPixmap switchTexture{QPixmap(QPixmap("../textures/switch.png"))};
    QPixmap rampTexture{QPixmap(QPixmap("../textures/ramp.png"))};
    QPixmap pitTexture{QPixmap(QPixmap("../textures/pit.png"))};


};

#endif // GRAPHICALUI_H
