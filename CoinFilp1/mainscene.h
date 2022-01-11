#ifndef MAINSCENE_H
#define MAINSCENE_H
#include<chooselevelscene.h>
#include <QMainWindow>

namespace Ui {
class MainScene;
}

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = 0);
    ~MainScene();

    void paintEvent(QPaintEvent *);
    ChooseLevelScene *chooseScene = NULL;

private:
    Ui::MainScene *ui;
};

#endif // MAINSCENE_H
