#include "mainwindow.h"
#include "door.h"
#include "floor.h"
#include "pit.h"
#include "portal.h"
#include "qdialog.h"
#include "switch.h"
#include "ui_mainwindow.h"
#include "tile.h"
#include "graphicalui.h"
#include "wall.h"
#include "npc.h"

#include <qlabel.h>

MainWindow::MainWindow(GraphicalUI *currentGui, QWidget *parent) :
    QMainWindow(parent),ui(new Ui::MainWindow),fieldLabel{}, currentGui{currentGui}
{
    ui->setupUi(this);

    connect(ui->direction1, &QPushButton::clicked, this, &MainWindow::buttonOneMove);
    connect(ui->direction2, &QPushButton::clicked, this, &MainWindow::buttonTwoMove);
    connect(ui->direction3, &QPushButton::clicked, this, &MainWindow::buttonThreeMove);
    connect(ui->direction4, &QPushButton::clicked, this, &MainWindow::buttonFourMove);
    connect(ui->direction5, &QPushButton::clicked, this, &MainWindow::buttonFiveMove);
    connect(ui->direction6, &QPushButton::clicked, this, &MainWindow::buttonSixMove);
    connect(ui->direction7, &QPushButton::clicked, this, &MainWindow::buttonSevenMove);
    connect(ui->direction8, &QPushButton::clicked, this, &MainWindow::buttonEightMove);
    connect(ui->direction9, &QPushButton::clicked, this, &MainWindow::buttonNineMove);



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





                if(stageVectorContent->getTexture() != "C"){
                    if(stageVectorContent->getCharacter()->getLastMovingDir() == 1)
                        label->setPixmap(currentGui->getZombieLeft());
                    if(stageVectorContent->getCharacter()->getLastMovingDir() == 2)
                        label->setPixmap(currentGui->getZombieLeft());

                    if(stageVectorContent->getCharacter()->getLastMovingDir() == 3)
                        label->setPixmap(currentGui->getZombieRight());
                    if(stageVectorContent->getCharacter()->getLastMovingDir() == 4)
                        label->setPixmap(currentGui->getZombieLeft());
                    if(stageVectorContent->getCharacter()->getLastMovingDir() == 5)
                        label->setPixmap(currentGui->getZombieRight());

                    if(stageVectorContent->getCharacter()->getLastMovingDir() == 6)
                        label->setPixmap(currentGui->getZombieRight());
                    if(stageVectorContent->getCharacter()->getLastMovingDir() == 7)
                        label->setPixmap(currentGui->getZombieLeft());
                    if(stageVectorContent->getCharacter()->getLastMovingDir() == 8)
                        label->setPixmap(currentGui->getZombieRight());

                    if(stageVectorContent->getCharacter()->getLastMovingDir() == 9)
                        label->setPixmap(currentGui->getZombieRight());


                    label->setParent(fieldLabel.at(i).at(j));
                    label->raise();
                    label->setScaledContents(true);
                    label->setMinimumSize(30,30);
                    fieldLabel.at(i).at(j) = label;
                    ui->levelLayout->addWidget(label,i,j);
                }

                else {


                    if(stageVectorContent->getCharacter()->getLastMovingDir() == 2)
                        label->setPixmap(currentGui->getCharacterTextureDown());
                    else if(stageVectorContent->getCharacter()->getLastMovingDir() == 1)
                        label->setPixmap(currentGui->getCharacterTextureLeft());
                    else if(stageVectorContent->getCharacter()->getLastMovingDir() == 3)
                        label->setPixmap(currentGui->getCharacterTextureRight());

                    else if(stageVectorContent->getCharacter()->getLastMovingDir() == 4)
                        label->setPixmap(currentGui->getCharacterTextureLeft());
                    else if(stageVectorContent->getCharacter()->getLastMovingDir() == 5)
                        label->setPixmap(currentGui->getCharacterTextureDown());

                    else if(stageVectorContent->getCharacter()->getLastMovingDir() == 6)
                        label->setPixmap(currentGui->getCharacterTextureRight());
                    else if(stageVectorContent->getCharacter()->getLastMovingDir() == 7)
                        label->setPixmap(currentGui->getCharacterTextureLeft());

                    else if(stageVectorContent->getCharacter()->getLastMovingDir() == 8)
                        label->setPixmap(currentGui->getCharacterTextureUp());
                    else if(stageVectorContent->getCharacter()->getLastMovingDir() == 9)
                        label->setPixmap(currentGui->getCharacterTextureRight());




                    label->setScaledContents(true);
                    label->setMinimumSize(30,30);

                    fieldLabel.at(i).at(j) = label;
                    ui->levelLayout->addWidget(label,i,j);
                }
            }
            else{
                if(dynamic_cast<Floor*>(stageVectorContent) != nullptr){
                    label->setPixmap(currentGui->getRandomFloorTexture());
                    label->setScaledContents(true);
                    label->setMinimumSize(30,30);

                    fieldLabel.at(i).at(j) = label;
                    ui->levelLayout->addWidget(label,i,j);
                }
                if(dynamic_cast<Wall*>(stageVectorContent) != nullptr){
                    label->setPixmap(currentGui->getWallTexture());
                    label->setScaledContents(true);
                    label->setMinimumSize(30,30);

                    fieldLabel.at(i).at(j) = label;
                    ui->levelLayout->addWidget(label,i,j);
                }

                if(dynamic_cast<Door*>(stageVectorContent) != nullptr){
                    Door* door = dynamic_cast<Door*>(stageVectorContent);
                    if(!door->getIsOpen())
                        label->setPixmap(currentGui->getDoorTextures().at(0));
                    else
                        label->setPixmap(currentGui->getDoorTextures().at(1));
                    label->setScaledContents(true);
                    label->setMinimumSize(30,30);

                    fieldLabel.at(i).at(j) = label;
                    ui->levelLayout->addWidget(label,i,j);
                }
                if(dynamic_cast<Pit*>(stageVectorContent) != nullptr){
                    label->setPixmap(currentGui->getPitTexture());
                    label->setScaledContents(true);
                    label->setMinimumSize(30,30);



                    fieldLabel.at(i).at(j) = label;
                    ui->levelLayout->addWidget(label,i,j);
                }

                if(dynamic_cast<Ramp*>(stageVectorContent) != nullptr){
                    label->setPixmap(currentGui->getRampTexture());
                    label->setScaledContents(true);
                    label->setMinimumSize(30,30);

                    fieldLabel.at(i).at(j) = label;
                    ui->levelLayout->addWidget(label,i,j);
                }

                if(dynamic_cast<Portal*>(stageVectorContent) != nullptr){
                    Portal* portal = dynamic_cast<Portal*>(stageVectorContent);
                    if(portal->getPortalType() == 1)
                        label->setPixmap(currentGui->getPortalTextures().at(0));
                    if(portal->getPortalType() == 2)
                        label->setPixmap(currentGui->getPortalTextures().at(1));
                    if(portal->getPortalType() == 3)
                        label->setPixmap(currentGui->getPortalTextures().at(2));

                    label->setScaledContents(true);
                    label->setMinimumSize(30,30);

                    fieldLabel.at(i).at(j) = label;
                    ui->levelLayout->addWidget(label,i,j);
                }
                if(dynamic_cast<Switch*>(stageVectorContent) != nullptr){
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

void MainWindow::buttonOneMove(){
    currentGui->getCurrentDungeonCrawler()->turn(1);
    currentGui->draw(currentGui->getCurrentLevel());
}


void MainWindow::buttonTwoMove(){
    currentGui->getCurrentDungeonCrawler()->turn(2);
    currentGui->draw(currentGui->getCurrentLevel());
}

void MainWindow::buttonThreeMove(){
    currentGui->getCurrentDungeonCrawler()->turn(3);
    currentGui->draw(currentGui->getCurrentLevel());
}

void MainWindow::buttonFourMove(){
    currentGui->getCurrentDungeonCrawler()->turn(4);
    currentGui->draw(currentGui->getCurrentLevel());
}

void MainWindow::buttonFiveMove(){
    currentGui->getCurrentDungeonCrawler()->turn(5);
    currentGui->draw(currentGui->getCurrentLevel());
}

void MainWindow::buttonSixMove(){
    currentGui->getCurrentDungeonCrawler()->turn(6);
    currentGui->draw(currentGui->getCurrentLevel());
}

void MainWindow::buttonSevenMove(){
    currentGui->getCurrentDungeonCrawler()->turn(7);
    currentGui->draw(currentGui->getCurrentLevel());
}

void MainWindow::buttonEightMove(){
    currentGui->getCurrentDungeonCrawler()->turn(8);
    currentGui->draw(currentGui->getCurrentLevel());
}

void MainWindow::buttonNineMove(){
    currentGui->getCurrentDungeonCrawler()->turn(9);
    currentGui->draw(currentGui->getCurrentLevel());
}




void MainWindow::setCurrentGui(GraphicalUI *newCurrentGui)
{
    currentGui = newCurrentGui;
}
