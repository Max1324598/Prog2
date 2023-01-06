#include "mainwindow.h"
#include "door.h"
#include "floor.h"
#include "pit.h"
#include "portal.h"
#include "switch.h"
#include "ui_mainwindow.h"
#include "tile.h"
#include "graphicalui.h"
#include "wall.h"
#include "levelchanger.h"
#include <iostream>
#include <qlabel.h>
#include <QStatusBar>
MainWindow::MainWindow(GraphicalUI *currentGui, QWidget *parent) :
    QMainWindow(parent),ui(new Ui::MainWindow),fieldLabel{}, currentGui{currentGui}
{
    ui->setupUi(this);

    ui->label->raise();
    ui->gridLayoutWidget_2->raise();


    Tile* stageVectorContent{nullptr};


    ui->levelLayout->setContentsMargins(0,0,0,0);
    ui->levelLayout->setSpacing(0);

    Level* level = currentGui->getCurrentLevel();

    setStatusBar(level);

    initLevel();


    //TODO: Eigene Button Klasse
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

void MainWindow::initLevel()
{
    Level* level = currentGui->getCurrentLevel();
    Tile* stageVectorContent{nullptr};

    for (int i{}; i<level->getMaxRow();i++){
        fieldLabel.push_back(vector<QLabel*>());

        for (int j{}; j<level->getMaxColumn();j++){
            stageVectorContent = level->getStageVector().at(i).at(j);
            bool hasCharacter = level->getStageVector().at(i).at(j)->hasCharacter();


            fieldLabel.at(i).push_back(new QLabel());
            auto* label = fieldLabel.at(i).at(j);
            label->setMinimumSize(30,30);
            label->setScaledContents(true);


            if(dynamic_cast<Floor*>(stageVectorContent) != nullptr){
                label->setPixmap(currentGui->getRandomFloorTexture());
                ui->levelLayout->addWidget(label,i,j);
            }
            if(dynamic_cast<Wall*>(stageVectorContent) != nullptr){
                label->setPixmap(currentGui->getWallTexture());
                ui->levelLayout->addWidget(label,i,j);
            }

            if(dynamic_cast<Door*>(stageVectorContent) != nullptr){
                Door* door = dynamic_cast<Door*>(stageVectorContent);
                if(!door->getIsOpen())
                    label->setPixmap(currentGui->getDoorTextures().at(0));
                else
                    label->setPixmap(currentGui->getDoorTextures().at(1));

                ui->levelLayout->addWidget(label,i,j);
            }
            if(dynamic_cast<Pit*>(stageVectorContent) != nullptr){
                label->setPixmap(currentGui->getPitTexture());
                ui->levelLayout->addWidget(label,i,j);
            }

            if(dynamic_cast<Ramp*>(stageVectorContent) != nullptr){
                label->setPixmap(currentGui->getRampTexture());
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

                ui->levelLayout->addWidget(label,i,j);
            }

            if(dynamic_cast<LevelChanger*>(stageVectorContent) != nullptr){
                label->setPixmap(currentGui->getPortalTextures().at(2));
                ui->levelLayout->addWidget(label,i,j);
            }
            if(dynamic_cast<Switch*>(stageVectorContent) != nullptr){
                label->setPixmap(currentGui->getSwitchTexture());
                ui->levelLayout->addWidget(label,i,j);
            }


            if(hasCharacter){
                bool isNPC = false;
                if(dynamic_cast<Npc*>(level->getStageVector().at(i).at(j)->getCharacter()) != nullptr) // dynamic_cast funktioniert nicht "character is not polyphormic"
                    isNPC = true;

                if(isNPC){
                    QLabel* npcLabel = new QLabel(this);
                    npcLabel->setPixmap(currentGui->getZombieRight());
                    npcLabel->setScaledContents(true);
                    npcLabel->setMinimumSize(30,30);
                    npcLabel->setStyleSheet("background-color: rgba(0,0,0,0)");
                    fieldLabel.at(i).at(j)->lower();
                    npcLabel->raise();
                    ui->levelLayout->addWidget(npcLabel, i, j);
                    npcLabels.push_back(npcLabel);
                }
                else{
                    QLabel* characterLabel = new QLabel(this);
                    characterLabel->setPixmap(currentGui->getCharacterTextureDown());
                    ui->levelLayout->addWidget(characterLabel, i, j);
                    characterLabel->setScaledContents(true);
                    characterLabel->setMinimumSize(30,30);
                    characterLabel->setStyleSheet("background-color: rgba(0,0,0,0)");
                    fieldLabel.at(i).at(j)->lower();
                    characterLabel->raise();
                    playerLabel = characterLabel;
                }
            }
        }
    }
}

void MainWindow::reBuild()
{

    for (int i {}; i<fieldLabel.size();i++){
        for (int j{}; j<fieldLabel.at(i).size();j++){
            delete fieldLabel.at(i).at(j);
            ui->levelLayout->removeWidget(fieldLabel.at(i).at(j));
        }
    }
    for(unsigned int i = 0; i < npcLabels.size(); i++){ //nicht aktuelle npcs löschen
        ui->levelLayout->removeWidget(npcLabels.at(i));
        delete npcLabels.at(i);
    }
    npcLabels.clear();
    fieldLabel.clear();
    ui->levelLayout->removeWidget(playerLabel);
    delete playerLabel;

    initLevel();

}


void MainWindow::draw(Level *level)
{

    Tile* stageVectorContent{nullptr};

    setStatusBar(level);

    for (int i{}; i<level->getMaxRow();i++){
        for (int j{}; j<level->getMaxColumn();j++){

            stageVectorContent = level->getStageVector().at(i).at(j);
            bool hasCharacter = stageVectorContent->hasCharacter();


            if(dynamic_cast<Door*>(stageVectorContent) != nullptr)
            {
                auto* tmp_door = dynamic_cast<Door*>(stageVectorContent);
                if(!tmp_door->getIsOpen())
                {
                    QLabel* closedDoor = fieldLabel.at(i).at(j);
                    closedDoor->setPixmap(currentGui->getDoorTextures().at(0));
                }
                if(tmp_door->getIsOpen())
                {
                    QLabel* openedDoor =fieldLabel.at(i).at(j);
                    openedDoor->setPixmap(currentGui->getDoorTextures().at(1));
                }
            }
        }
    }


    if(!level->getCharacterVector().empty()){

        for(unsigned int i = 0; i < npcLabels.size(); i++){ //nicht aktuelle npcs löschen
            ui->levelLayout->removeWidget(npcLabels.at(i));
            delete npcLabels.at(i);
        }
        npcLabels.clear();
        for(int k = 0; k < level->getCharacterVector().size(); k++){
            QLabel* npcLabel = new QLabel();
            npcLabel->setScaledContents(true);
            npcLabel->raise();
            npcLabel->setMinimumSize(30,30);
            npcLabel->setStyleSheet("background-color: rgba(0,0,0,0)");

            int row = level->getCharacterVector().at(k)->getTile()->getRow();
            int col = level->getCharacterVector().at(k)->getTile()->getColumn();
            fieldLabel.at(row).at(col)->lower();

            setNpcLabelTexture(npcLabel, level->getStageVector().at(row).at(col));


            ui->levelLayout->addWidget(npcLabel, row, col);
            npcLabels.push_back(npcLabel);
            if(dynamic_cast<Pit*>(level->getStageVector().at(row).at(col)) != nullptr){
                fieldLabel.at(row).at(col)->raise();
                fieldLabel.at(row).at(col)->setStyleSheet("background-color: rgba(0,0,0,0)");
            }
        }
    }

    ui->levelLayout->removeWidget(playerLabel);
    delete playerLabel;


    QLabel* characterLabel = new QLabel(this);
    characterLabel->setScaledContents(true);
    characterLabel->raise();
    characterLabel->setMinimumSize(30,30);
    characterLabel->setStyleSheet("background-color: rgba(0,0,0,0)");

    int row = level->getPlayerCharacter()->getTile()->getRow();
    int col = level->getPlayerCharacter()->getTile()->getColumn();

    setCharacterLabelTexture(level->getStageVector().at(row).at(col), characterLabel);

    ui->levelLayout->addWidget(characterLabel, row, col);
    playerLabel = characterLabel;

    if(dynamic_cast<Pit*>(level->getStageVector().at(row).at(col)) != nullptr){
        fieldLabel.at(row).at(col)->raise();
        fieldLabel.at(row).at(col)->setStyleSheet("background-color: rgba(0,0,0,0)");
    }

}

void MainWindow::setStatusBar(Level *level)
{
    ui->textEdit->setTextColor(QColorConstants::White);
    ui->textEdit_2->setTextColor(QColorConstants::White);
    ui->textEdit_3->setTextColor(QColorConstants::White);
    QString stamina = "Stamina: ";
    QString hp = "Hitpoints: ";
    QString strength = "Strength: ";
    QString stamFull = stamina + QString::number(level->getPlayerCharacter()->getStamina());
    QString hpFull = hp + QString::number(level->getPlayerCharacter()->getMaxHP());
    QString strengthFull = strength + QString::number(level->getPlayerCharacter()->getStrength());
    ui->textEdit->setText(stamFull);
    ui->textEdit->setAlignment(Qt::AlignCenter);
    ui->textEdit_3->setText(hpFull);
    ui->textEdit_3->setAlignment(Qt::AlignCenter);
    ui->textEdit_2->setText(strengthFull);
    ui->textEdit_2->setAlignment(Qt::AlignCenter);
}
void MainWindow::setCharacterLabelTexture(Tile* stageVectorContent, QLabel* characterLabel)
{
    if(stageVectorContent->getCharacter()->getLastMovingDir() == 2)
        characterLabel->setPixmap(currentGui->getCharacterTextureDown());
    else if(stageVectorContent->getCharacter()->getLastMovingDir() == 1)
        characterLabel->setPixmap(currentGui->getCharacterTextureLeft());
    else if(stageVectorContent->getCharacter()->getLastMovingDir() == 3)
        characterLabel->setPixmap(currentGui->getCharacterTextureRight());

    else if(stageVectorContent->getCharacter()->getLastMovingDir() == 4)
        characterLabel->setPixmap(currentGui->getCharacterTextureLeft());
    else if(stageVectorContent->getCharacter()->getLastMovingDir() == 5)
        characterLabel->setPixmap(currentGui->getCharacterTextureDown());

    else if(stageVectorContent->getCharacter()->getLastMovingDir() == 6)
        characterLabel->setPixmap(currentGui->getCharacterTextureRight());
    else if(stageVectorContent->getCharacter()->getLastMovingDir() == 7)
        characterLabel->setPixmap(currentGui->getCharacterTextureLeft());

    else if(stageVectorContent->getCharacter()->getLastMovingDir() == 8)
        characterLabel->setPixmap(currentGui->getCharacterTextureUp());
    else if(stageVectorContent->getCharacter()->getLastMovingDir() == 9)
        characterLabel->setPixmap(currentGui->getCharacterTextureRight());
}

void MainWindow::setNpcLabelTexture(QLabel* npcLabel, Tile* stageVectorContent)
{
    if(stageVectorContent->getCharacter()->getLastMovingDir() == 1)
        npcLabel->setPixmap(currentGui->getZombieLeft());
    if(stageVectorContent->getCharacter()->getLastMovingDir() == 2)
        npcLabel->setPixmap(currentGui->getZombieLeft());
    if(stageVectorContent->getCharacter()->getLastMovingDir() == 3)
        npcLabel->setPixmap(currentGui->getZombieRight());
    if(stageVectorContent->getCharacter()->getLastMovingDir() == 4)
        npcLabel->setPixmap(currentGui->getZombieLeft());

    if(stageVectorContent->getCharacter()->getLastMovingDir() == 5)
        npcLabel->setPixmap(currentGui->getZombieRight());
    if(stageVectorContent->getCharacter()->getLastMovingDir() == 6)
        npcLabel->setPixmap(currentGui->getZombieRight());
    if(stageVectorContent->getCharacter()->getLastMovingDir() == 7)
        npcLabel->setPixmap(currentGui->getZombieLeft());
    if(stageVectorContent->getCharacter()->getLastMovingDir() == 8)
        npcLabel->setPixmap(currentGui->getZombieRight());
    if(stageVectorContent->getCharacter()->getLastMovingDir() == 9)
        npcLabel->setPixmap(currentGui->getZombieRight());
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
