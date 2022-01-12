#ifndef MYCOIN_H
#define MYCOIN_H
#include<QTimer>
#include <QPushButton>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
  //  explicit MyCoin(QWidget *parent = nullptr);

    MyCoin(QString);
    //金币属性
    bool flag;
    int posX,posY;
    void changeFlag();
    QTimer *timer1;
    QTimer *timer2;
    int min = 1,max = 8;
    bool isAnimation = false;
    void mousePressEvent(QMouseEvent *e);
bool isWin = false;

signals:

public slots:
};

#endif // MYCOIN_H
