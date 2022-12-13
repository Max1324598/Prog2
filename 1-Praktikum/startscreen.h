#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QDialog>

class GraphicalUI;

namespace Ui {
class StartScreen;
}

class StartScreen : public QDialog
{
    Q_OBJECT

public:
    explicit StartScreen(QWidget *parent = nullptr);
    ~StartScreen();


    void LayoutUi();
    void setGraphicalUi(GraphicalUI *newGraphicalUi);

private slots:
    void onButtonClicked();

private:
    Ui::StartScreen *ui;
    GraphicalUI* graphicalUi;
};

#endif // STARTSCREEN_H
