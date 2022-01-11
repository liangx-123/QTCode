#ifndef MYPUSHBOTTON_H
#define MYPUSHBOTTON_H

#include <QPushButton>

class MyPushBotton : public QPushButton
{
    Q_OBJECT
public:
   // explicit MyPushBotton(QWidget *parent = nullptr);

    MyPushBotton(QString normalImg ,QString  pressImg = "");
    QString normalImgPath,pressImPath;
void zoom1();
void zoom2();
//重写按钮事件
void mousePressEvent(QMouseEvent *e);
void mouseReleaseEvent(QMouseEvent *e);

signals:

public slots:
};

#endif // MYPUSHBOTTON_H
