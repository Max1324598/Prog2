#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlabel.h>
#include "dungeoncrawler.h"
#include "level.h"

class GraphicalUI;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(GraphicalUI* currentGui, QWidget *parent = nullptr);
    ~MainWindow();

    void reBuild();
    void draw(Level* level);

    void setCurrentGui(GraphicalUI *newCurrentGui);

    void getCharacterTexture(QLabel* characterLabel, Tile* stageVectorContent);
    void setCharacterLabelTexture(QLabel* characterLabel,Character* playerCharacter);
    void setNpcLabelTexture(QLabel* npcLabel, Character* currentNpc);
    void showEndScreen();
    void setStatusBar(Level *level);

    void initLevel();

public slots:
    void buttonOneMove();
    void buttonTwoMove();
    void buttonThreeMove();
    void buttonFourMove();
    void buttonFiveMove();
    void buttonSixMove();
    void buttonSevenMove();
    void buttonEightMove();
    void buttonNineMove();

private:
    Ui::MainWindow *ui;
    std::vector<std::vector<QLabel*>> fieldLabel;
    std::vector<QLabel*> npcLabels;
    QLabel* playerLabel;
    GraphicalUI* currentGui;

};

#endif // MAINWINDOW_H
