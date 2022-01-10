#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
id1 = startTimer(1000);
id2 = startTimer(2000);
}


void Widget::timerEvent(QTimerEvent *ev){
   if(ev->timerId() == id1){ static int num = 1;
    ui->label->setText(QString::number(num++));
   }

   if(ev->timerId() == id2){
       static int num1 = 1;
       ui->label_2->setText(QString::number(num1++));
   }
}

Widget::~Widget()
{
    delete ui;
}
