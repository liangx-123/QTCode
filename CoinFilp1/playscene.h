#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
   // explicit PlayScene(QWidget *parent = nullptr);
PlayScene(int);

int levelIndex;

void paintEvent(QPaintEvent *);

int gameArray[4][4];



signals:
void chooseSceneBack();

public slots:
};

#endif // PLAYSCENE_H
