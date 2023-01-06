/********************************************************************************
** Form generated from reading UI file 'startscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTSCREEN_H
#define UI_STARTSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StartScreen
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *dialogLayout;
    QLabel *backGroundLabel;
    QPushButton *newGameButton;

    void setupUi(QDialog *StartScreen)
    {
        if (StartScreen->objectName().isEmpty())
            StartScreen->setObjectName("StartScreen");
        StartScreen->resize(951, 451);
        gridLayout = new QGridLayout(StartScreen);
        gridLayout->setObjectName("gridLayout");
        dialogLayout = new QVBoxLayout();
        dialogLayout->setObjectName("dialogLayout");
        dialogLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        backGroundLabel = new QLabel(StartScreen);
        backGroundLabel->setObjectName("backGroundLabel");

        dialogLayout->addWidget(backGroundLabel);

        newGameButton = new QPushButton(StartScreen);
        newGameButton->setObjectName("newGameButton");

        dialogLayout->addWidget(newGameButton);


        gridLayout->addLayout(dialogLayout, 0, 0, 1, 1);


        retranslateUi(StartScreen);

        QMetaObject::connectSlotsByName(StartScreen);
    } // setupUi

    void retranslateUi(QDialog *StartScreen)
    {
        StartScreen->setWindowTitle(QCoreApplication::translate("StartScreen", "Dialog", nullptr));
        backGroundLabel->setText(QCoreApplication::translate("StartScreen", "TextLabel", nullptr));
        newGameButton->setText(QCoreApplication::translate("StartScreen", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartScreen: public Ui_StartScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTSCREEN_H
