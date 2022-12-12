#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlabel.h>
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

    void draw(Level* level);

    void setCurrentGui(GraphicalUI *newCurrentGui);

private:
    Ui::MainWindow *ui;
    std::vector<std::vector<QLabel*>> fieldLabel;
    GraphicalUI* currentGui;

};

#endif // MAINWINDOW_H
