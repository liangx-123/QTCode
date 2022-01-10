#include "myevent.h"
#include<QDebug>
#include<QMouseEvent>
myEvent::myEvent(QWidget *parent) : QLabel(parent)
{

}
//void myEvent::enterEvent(QEvent *event){
  //  qDebug()<<"鼠标进入";

//}
//void myEvent::leaveEvent(QEvent *event){
    //qDebug()<<"鼠标离开";
//}
void myEvent::mousePressEvent(QMouseEvent *ev){

    QString str = QString("x = %1 y = %2 globalx = %3 globaly = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
 qDebug()<<"鼠标按下了"<<str;
}
void myEvent::mouseReleaseEvent(QMouseEvent *ev){
    qDebug()<<"鼠标释放了了";

}void myEvent::mouseMoveEvent(QMouseEvent *ev){
    qDebug()<<"鼠移动下了";

}
//拦截操作
bool myEvent::event(QEvent *e){
    if(e->type() == QEvent::MouseButtonPress){
        QMouseEvent *ev = static_cast<QMouseEvent *>(e);
      QString str = QString("拦截了x = %1 y = %2 globalx = %3 globaly = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug()<<str;
        return true;
    }
    return QLabel::event(e);
}
