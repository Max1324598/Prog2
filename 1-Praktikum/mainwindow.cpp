#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tile.h"
#include "graphicalui.h"


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


    QLabel* label = new QLabel;
    label->setScaledContents(true);
    Tile* stageVectorContent{nullptr};

    label->setPixmap(currentGui->getRandomFloorTexture());
    label->setMaximumSize(20,20);
    ui->levelLayout->addWidget(label,0,0);
    ui->levelLayout->addWidget(label,0,1);
    ui->levelLayout->addWidget(label,0,2);
    ui->levelLayout->addWidget(label,1,2);

    for (int i{}; i<level->getMaxRow();i++){
        fieldLabel.resize(level->getMaxRow(), std::vector<QLabel*>(level->getMaxColumn(), nullptr));

        for (int j{}; j<level->getMaxColumn();j++){
            stageVectorContent = level->getStageVector().at(i).at(j);

            label->setPixmap(currentGui->getRandomFloorTexture());
            label->setMaximumSize(20,20);
            ui->levelLayout->addWidget(label,i,j);


            //            if(typeid(stageVectorContent) == typeid (floor)) {
            //                fieldLabel.at(i).at(j)->setPixmap(currentGui->getRandomFloorTexture());
            //               ui->levelLayout->addWidget(fieldLabel.at(i).at(j),i,j);


            //           }
        }
    }
}

void MainWindow::setCurrentGui(GraphicalUI *newCurrentGui)
{
    currentGui = newCurrentGui;
}
