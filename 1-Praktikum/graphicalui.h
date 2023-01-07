#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H
#include "abstractUI.h"

#include <QPixmap>

class StartScreen;
class MainWindow;


class GraphicalUI :public AbstractUI
{
public:
    GraphicalUI(Level* currentLevel);
    ~GraphicalUI();

    void draw(Level* level) override;
    void switchWindow();

    void setCurrentLevel(Level *newCurrentLevel);
    Level *getCurrentLevel() const;

    //Texture-Getter
    QPixmap getRandomFloorTexture();
    const std::vector<QPixmap> &getPortalTextures() const;
    const std::vector<QPixmap> &getDoorTextures() const;
    const QPixmap &getWallTexture()const;
    const QPixmap &getPitTexture() const;
    const QPixmap &getSwitchTexture() const;
    const QPixmap &getRampTexture() const;
    const QPixmap &getCharacterTextureDown() const;
    const QPixmap &getCharacterTextureUp() const;
    const QPixmap &getCharacterTextureRight() const;
    const QPixmap &getCharacterTextureLeft() const;
    const QPixmap &getZombieRight() const;
    const QPixmap &getZombieLeft() const;

    MainWindow *getMainWindow() const;

    const QPixmap &getLevelChangerTexture() const;

private:
    StartScreen* startScreen;
    MainWindow* mainWindow;
    Level* currentLevel;

    std::vector<QPixmap> floorTextures;
    std::vector<QPixmap> portalTextures;
    std::vector<QPixmap> doorTextures;

    QPixmap characterTextureDown = QPixmap("../textures/char/front/char_front_1.png");
    QPixmap characterTextureLeft = QPixmap("../textures/char/left/char_left_1.png");
    QPixmap characterTextureRight = QPixmap("../textures/char/right/char_right_1.png");
    QPixmap characterTextureUp = QPixmap("../textures/char/back/char_back_1.png");


    QPixmap wallTexture = QPixmap("../textures/wall/wall1.png");
    QPixmap levelChangerTexture = QPixmap("../textures/levelchanger.png");
    QPixmap switchTexture= QPixmap ("../textures/switch.png");
    QPixmap rampTexture = QPixmap("../textures/ramp.png");
    QPixmap pitTexture = QPixmap("../textures/pit.png");
    QPixmap zombieLeft = QPixmap("../textures/zombie/zombie_left.png");
    QPixmap zombieRight = QPixmap("../textures/zombie/zombie_right.png");


};

#endif // GRAPHICALUI_H
