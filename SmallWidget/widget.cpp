#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //按钮设置值
    connect(ui->setv,QPushButton::clicked,[=](){

        ui->widget->set(50);

    });
    //按钮获得值
    connect(ui->getv,QPushButton::clicked,[=](){
        qDebug()<<ui->widget->get();//不知为何是widget
    });
}

Widget::~Widget()
{
    delete ui;
}
