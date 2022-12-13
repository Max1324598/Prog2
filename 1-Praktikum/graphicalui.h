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


    const std::vector<QPixmap> &getPortalTextures() const;

    const std::vector<QPixmap> &getDoorTextures() const;

    const QPixmap &getWallTexture()const;
    const QPixmap &getPitTexture() const;

    const QPixmap &getSwitchTexture() const;

    const QPixmap &getRampTexture() const;

    const QPixmap &getCharacterTexture() const;

private:
    StartScreen* startScreen;
    MainWindow* mainWindow;

    std::vector<QPixmap> floorTextures;
    std::vector<QPixmap> portalTextures;
    std::vector<QPixmap> doorTextures;

    QPixmap characterTexture = QPixmap("../textures/char/front/char_front_1.png");
    QPixmap wallTexture = QPixmap("../textures/wall/wall1.png");
    QPixmap switchTexture= QPixmap ("../textures/switch.png");
    QPixmap rampTexture = QPixmap("../textures/ramp.png");
    QPixmap pitTexture = QPixmap("../textures/pit.png");


};

#endif // GRAPHICALUI_H
