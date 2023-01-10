/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *levelLayout;
    QWidget *gridLayoutWidget_2;
    QGridLayout *buttonLayout;
    QPushButton *direction9;
    QPushButton *direction2;
    QPushButton *direction3;
    QPushButton *direction4;
    QPushButton *direction5;
    QPushButton *direction6;
    QPushButton *direction8;
    QPushButton *direction1;
    QPushButton *direction7;
    QLabel *label;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 694);
        MainWindow->setMinimumSize(QSize(40, 0));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setAutoFillBackground(false);
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, -10, 1301, 711));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0)"));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(40, 70, 861, 521));
        levelLayout = new QGridLayout(gridLayoutWidget);
        levelLayout->setObjectName("levelLayout");
        levelLayout->setVerticalSpacing(8);
        levelLayout->setContentsMargins(0, 11, 0, 0);
        gridLayoutWidget_2 = new QWidget(groupBox);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(940, 340, 256, 181));
        buttonLayout = new QGridLayout(gridLayoutWidget_2);
        buttonLayout->setObjectName("buttonLayout");
        buttonLayout->setContentsMargins(0, 0, 0, 0);
        direction9 = new QPushButton(gridLayoutWidget_2);
        direction9->setObjectName("direction9");
        QIcon icon;
        icon.addFile(QString::fromUtf8("../textures/arrows/arrow_up_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        direction9->setIcon(icon);
        direction9->setIconSize(QSize(40, 40));
        direction9->setFlat(true);

        buttonLayout->addWidget(direction9, 0, 2, 1, 1);

        direction2 = new QPushButton(gridLayoutWidget_2);
        direction2->setObjectName("direction2");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../textures/arrows/arrow_down.png"), QSize(), QIcon::Normal, QIcon::Off);
        direction2->setIcon(icon1);
        direction2->setIconSize(QSize(40, 40));
        direction2->setFlat(true);

        buttonLayout->addWidget(direction2, 2, 1, 1, 1);

        direction3 = new QPushButton(gridLayoutWidget_2);
        direction3->setObjectName("direction3");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../textures/arrows/arrow_down_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        direction3->setIcon(icon2);
        direction3->setIconSize(QSize(40, 40));
        direction3->setFlat(true);

        buttonLayout->addWidget(direction3, 2, 2, 1, 1);

        direction4 = new QPushButton(gridLayoutWidget_2);
        direction4->setObjectName("direction4");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../textures/arrows/arrow_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        direction4->setIcon(icon3);
        direction4->setIconSize(QSize(40, 40));
        direction4->setFlat(true);

        buttonLayout->addWidget(direction4, 1, 0, 1, 1);

        direction5 = new QPushButton(gridLayoutWidget_2);
        direction5->setObjectName("direction5");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../textures/arrows/arrow_skip.png"), QSize(), QIcon::Normal, QIcon::Off);
        direction5->setIcon(icon4);
        direction5->setIconSize(QSize(40, 40));
        direction5->setFlat(true);

        buttonLayout->addWidget(direction5, 1, 1, 1, 1);

        direction6 = new QPushButton(gridLayoutWidget_2);
        direction6->setObjectName("direction6");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../textures/arrows/arrow_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        direction6->setIcon(icon5);
        direction6->setIconSize(QSize(40, 40));
        direction6->setFlat(true);

        buttonLayout->addWidget(direction6, 1, 2, 1, 1);

        direction8 = new QPushButton(gridLayoutWidget_2);
        direction8->setObjectName("direction8");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../textures/arrows/arrow_up.png"), QSize(), QIcon::Normal, QIcon::Off);
        direction8->setIcon(icon6);
        direction8->setIconSize(QSize(40, 40));
        direction8->setFlat(true);

        buttonLayout->addWidget(direction8, 0, 1, 1, 1);

        direction1 = new QPushButton(gridLayoutWidget_2);
        direction1->setObjectName("direction1");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../textures/arrows/arrow_down_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        direction1->setIcon(icon7);
        direction1->setIconSize(QSize(40, 40));
        direction1->setFlat(true);

        buttonLayout->addWidget(direction1, 2, 0, 1, 1);

        direction7 = new QPushButton(gridLayoutWidget_2);
        direction7->setObjectName("direction7");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(direction7->sizePolicy().hasHeightForWidth());
        direction7->setSizePolicy(sizePolicy);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("../textures/arrows/arrow_up_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        direction7->setIcon(icon8);
        direction7->setIconSize(QSize(40, 40));
        direction7->setCheckable(false);
        direction7->setAutoDefault(false);
        direction7->setFlat(true);

        buttonLayout->addWidget(direction7, 0, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(0, -20, 1200, 701));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,0)"));
        label->setPixmap(QPixmap(QString::fromUtf8("../textures/bloody_frame.png")));
        label->setWordWrap(false);
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(910, 80, 104, 70));
        textEdit->setAutoFillBackground(false);
        textEdit->setFrameShape(QFrame::NoFrame);
        textEdit->setLineWidth(1);
        textEdit_2 = new QTextEdit(groupBox);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(910, 170, 104, 70));
        textEdit_2->setFrameShape(QFrame::NoFrame);
        textEdit_3 = new QTextEdit(groupBox);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(910, 250, 104, 70));
        textEdit_3->setFrameShape(QFrame::NoFrame);
        label->raise();
        gridLayoutWidget->raise();
        gridLayoutWidget_2->raise();
        textEdit->raise();
        textEdit_2->raise();
        textEdit_3->raise();
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 25));
        MainWindow->setMenuBar(menubar);
        QWidget::setTabOrder(direction7, direction8);
        QWidget::setTabOrder(direction8, direction9);
        QWidget::setTabOrder(direction9, direction4);
        QWidget::setTabOrder(direction4, direction5);
        QWidget::setTabOrder(direction5, direction6);
        QWidget::setTabOrder(direction6, direction1);
        QWidget::setTabOrder(direction1, direction2);
        QWidget::setTabOrder(direction2, direction3);

        retranslateUi(MainWindow);

        direction7->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        direction9->setText(QString());
        direction2->setText(QString());
        direction3->setText(QString());
        direction4->setText(QString());
        direction5->setText(QString());
        direction6->setText(QString());
        direction8->setText(QString());
        direction1->setText(QString());
        direction7->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
