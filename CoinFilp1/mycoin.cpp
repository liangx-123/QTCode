#include "mycoin.h"
#include<QDebug>
//MyCoin::MyCoin(QWidget *parent) : QWidget(parent)
//{

//}

MyCoin::MyCoin(QString  btnImg){
    
    QPixmap pix;
            bool ret = pix.load(btnImg);
            if(!ret){
                qDebug()<<"图片加载失败";
            return;    
            }
            
            this->setFixedSize(pix.width(),pix.height());
            this->setStyleSheet("QPushButton{border:0px;}");
            this->setIcon(pix);
            this->setIconSize(QSize(pix.width(),pix.height()));
            timer1 = new QTimer(this);
            timer2 = new QTimer(this);
            //监听正面
            connect(timer1,&QTimer::timeout,[=](){


               QPixmap	 pix;
               QString str = QString(":/Coin000%1.png").arg(this->min++);

               pix.load(str);
               this->setFixedSize(pix.width(),pix.height());
               this->setStyleSheet("QPushButtom{border:0px;}");
               this->setIcon(pix);
               this->setIconSize(QSize(pix.width(),pix.height()));
               if(this->min>this->max){
                   this->min = 1;
                   isAnimation = false;
                   timer1->stop();
               }
            });



            //监听反面
            connect(timer2,&QTimer::timeout,[=](){


               QPixmap	 pix;
               QString str = QString(":/Coin000%1.png").arg(this->max--);

               pix.load(str);
               this->setFixedSize(pix.width(),pix.height());
               this->setStyleSheet("QPushButtom{border:0px;}");
               this->setIcon(pix);
               this->setIconSize(QSize(pix.width(),pix.height()));
               if(this->min>this->max){
                   this->max = 8;
                   isAnimation = false;
                   timer2->stop();
               }
            });
}

void MyCoin::mousePressEvent(QMouseEvent *e){

    if(this->isAnimation){
        return;
    }else {
        QPushButton::mousePressEvent(e);
    }

}
void MyCoin::changeFlag(){

    if(this->flag){
        timer1->start(30);
        isAnimation = true;
        this->flag = false;
    }
    else {
        timer2->start(50);
          isAnimation = true;
        this->flag = true;
    }
}

