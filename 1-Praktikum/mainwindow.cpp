#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <qlabel.h>

MainWindow::MainWindow(GraphicalUI *currentGui, QWidget *parent) :
    QMainWindow(parent),ui(new Ui::MainWindow),fieldLabel{}, currentGui{currentGui}
{
    ui->setupUi(this);





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::draw(Level *level)
{
    for (int i{}; i<level->getMaxRow();i++){
        for (int j{}; j<level->getMaxColumn();j++){

        }
    }
}

void MainWindow::setCurrentGui(GraphicalUI *newCurrentGui)
{
    currentGui = newCurrentGui;
}
