#ifndef ENDSCREEN_H
#define ENDSCREEN_H


#include <QDialog>

class GraphicalUI;

namespace Ui {
class EndScreen;
}

class EndScreen : public QDialog
{
    Q_OBJECT

public:
    explicit EndScreen(GraphicalUI* gui,QWidget *parent = nullptr);
    ~EndScreen();

    void winMessage();
    void loseMessage();
    void LayoutUi();
    void setGraphicalUi(GraphicalUI *newGraphicalUi);

private slots:
    void onButtonClicked();

private:
    Ui::EndScreen *ui;
    GraphicalUI* graphicalUi;
};


#endif // ENDSCREEN_H
