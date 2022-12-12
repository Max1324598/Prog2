#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qlabel.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

  // this->setStyleSheet("background-color: black;");
   // QPixmap backGroundTexture("../textures/bloody_frame.png");



//    QLabel *backGroundLabel = new QLabel();
//    backGroundLabel->setPixmap(backGroundTexture);
//    backGroundLabel->setScaledContents(true);
//    ui->horizontalLayout->addWidget(backGroundLabel);



}

MainWindow::~MainWindow()
{
    delete ui;
}
