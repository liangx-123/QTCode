#include "mypushbotton.h"
#include <QDebug>
#include <QPushButton>
#include<QPropertyAnimation>
//MyPushBotton::MyPushBotton(QWidget *parent) : QPushButton(parent)


MyPushBotton::MyPushBotton(QString normalImg,QString pressImg ){



    this->normalImgPath = normalImg;
    this->pressImPath = pressImg;

    QPixmap pix;
 bool ret = pix.load(normalImg)  ;
 if(ret ==false){

     qDebug()<<"加载失败";
     return;

 }
  this->setFixedSize( pix.width(),pix.height());
 this->setStyleSheet("QPushButtom{border:0px;}");
    this->setIcon(pix);


 this->setIconSize(QSize(pix.width(),pix.height()));


}
void MyPushBotton::zoom1(){

    QPropertyAnimation *animation = new QPropertyAnimation(this,"geoetry");
    //动画时间间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
            animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));

            //弹跳曲线
            animation->setEasingCurve(QEasingCurve::OutBounce);
            animation->start();



}
void MyPushBotton::zoom2(){


    QPropertyAnimation *animation = new QPropertyAnimation(this,"geoetry");
    //动画时间间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
            animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));

            //弹跳曲线
            animation->setEasingCurve(QEasingCurve::OutBounce);
            animation->start();


}
void MyPushBotton::mousePressEvent(QMouseEvent *e){

    if(this->pressImPath != ""){




        QPixmap pix;
     bool ret = pix.load(this->pressImPath)  ;
     if(ret ==false){

         qDebug()<<"加载失败";
         return;

     }
      this->setFixedSize( pix.width(),pix.height());
     this->setStyleSheet("QPushButtom{border:0px;}");
        this->setIcon(pix);




    }
    return QPushButton::mousePressEvent(e);
}

void MyPushBotton::mouseReleaseEvent(QMouseEvent *e){


    if(this->pressImPath!=""){
    QPixmap pix;
 bool ret = pix.load(this->normalImgPath)  ;
 if(ret ==false){

     qDebug()<<"加载失败";
     return;

 }
  this->setFixedSize( pix.width(),pix.height());
 this->setStyleSheet("QPushButtom{border:0px;}");
    this->setIcon(pix);

    }

    return QPushButton::mouseReleaseEvent(e);
}

