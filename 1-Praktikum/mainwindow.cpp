#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tile.h"


#include <qlabel.h>

MainWindow::MainWindow(GraphicalUI *currentGui, QWidget *parent) :
    QMainWindow(parent),ui(new Ui::MainWindow),fieldLabel{}, currentGui{currentGui}
{
    ui->setupUi(this);
//    fieldLabel.at(r).at(c) = l;
//    ui->gridLayout->addWidget(l, r, c);






}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::draw(Level *level)
{
    Tile* stageVectorContent{nullptr};
    for (int i{}; i<level->getMaxRow();i++){
        for (int j{}; j<level->getMaxColumn();j++){
            stageVectorContent = level->getStageVector().at(i).at(j);


        }
    }
}

void MainWindow::setCurrentGui(GraphicalUI *newCurrentGui)
{
    currentGui = newCurrentGui;
}
