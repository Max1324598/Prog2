#include "mainwindow.h"
#include "door.h"
#include "floor.h"
#include "portal.h"
#include "ui_mainwindow.h"
#include "tile.h"
#include "graphicalui.h"
#include "wall.h"


#include <Pit.h>
#include <Switch.h>
#include <iostream>
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



    Tile* stageVectorContent{nullptr};


    ui->levelLayout->setContentsMargins(0,0,0,0);
    ui->levelLayout->setSpacing(0);

    for (int i{}; i<level->getMaxRow();i++){
        fieldLabel.resize(level->getMaxRow(), std::vector<QLabel*>(level->getMaxColumn(), nullptr));

        for (int j{}; j<level->getMaxColumn();j++){
            stageVectorContent = level->getStageVector().at(i).at(j);
            auto* label = new QLabel(ui->centralwidget);

            if(stageVectorContent->hasCharacter()){
                label->setPixmap(currentGui->getCharacterTexture());
                label->setScaledContents(true);
                label->setMinimumSize(30,30);


                fieldLabel.at(i).at(j) = label;
                ui->levelLayout->addWidget(label,i,j);
            }
            else{
                if(dynamic_cast<Floor*>(level->getStageVector().at(i).at(j))){
                    label->setPixmap(currentGui->getRandomFloorTexture());
                    label->setScaledContents(true);
                    label->setMinimumSize(30,30);


                    fieldLabel.at(i).at(j) = label;
                    ui->levelLayout->addWidget(label,i,j);
                }
                if(dynamic_cast<Wall*>(level->getStageVector().at(i).at(j))){
                    label->setPixmap(currentGui->getWallTexture());
                    label->setScaledContents(true);
                    label->setMinimumSize(30,30);


                    fieldLabel.at(i).at(j) = label;
                    ui->levelLayout->addWidget(label,i,j);
                }

                if(dynamic_cast<Door*>(level->getStageVector().at(i).at(j))){
                    Door* d = dynamic_cast<Door*>(level->getStageVector().at(i).at(j));
                    if (d->getIsOpen() == false){
                        label->setPixmap(currentGui->getDoorTextures().at(0));
                    }
                    else{
                        label->setPixmap(currentGui->getDoorTextures().at(1));
                    }
                    label->setScaledContents(true);
                    label->setMinimumSize(30,30);


                    fieldLabel.at(i).at(j) = label;
                    ui->levelLayout->addWidget(label,i,j);
                }
                if(dynamic_cast<Pit*>(level->getStageVector().at(i).at(j))){
                    label->setPixmap(currentGui->getPitTexture());
                    label->setScaledContents(true);
                    label->setMinimumSize(30,30);

                    fieldLabel.at(i).at(j) = label;
                    ui->levelLayout->addWidget(label,i,j);
                }

                if(dynamic_cast<Ramp*>(level->getStageVector().at(i).at(j))){
                    label->setPixmap(currentGui->getRampTexture());
                    label->setScaledContents(true);
                    label->setMinimumSize(30,30);


                    fieldLabel.at(i).at(j) = label;
                    ui->levelLayout->addWidget(label,i,j);
                }

                if(dynamic_cast<Portal*>(level->getStageVector().at(i).at(j))){
                    label->setPixmap(currentGui->getPortalTextures().at(0));
                    label->setScaledContents(true);
                    label->setMinimumSize(30,30);

                    fieldLabel.at(i).at(j) = label;
                    ui->levelLayout->addWidget(label,i,j);
                }
                if(dynamic_cast<Switch*>(level->getStageVector().at(i).at(j))){
                    label->setPixmap(currentGui->getSwitchTexture());
                    label->setScaledContents(true);
                    label->setMinimumSize(30,30);


                    fieldLabel.at(i).at(j) = label;
                    ui->levelLayout->addWidget(label,i,j);
                }
            }
        }
    }

}

void MainWindow::setCurrentGui(GraphicalUI *newCurrentGui)
{
    currentGui = newCurrentGui;
}
