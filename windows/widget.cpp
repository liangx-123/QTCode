#include "widget.h"
#include <QPushButton>
#include<student.h>
#include<teacher.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{//创建按钮
    QPushButton *btn = new QPushButton("按钮",this);
    //也是设置按钮文本  btn->setText("按钮");


    //重置窗口大小
    resize(600,400);
    //窗口标题
    setWindowTitle("窗口");
    //设置固定窗口大小
    setFixedSize(600,400);
    //点击按钮关闭窗口
connect(btn,&QPushButton::clicked,this,&Widget::close);

//创建对象  要先在大类里创建指针
this->zt = new Teacher(this);
this->st = new Student(this);


//重载 用指针指向之前填的方法  前一个要有作用域  后一个传值类型
//在 .h 里定义的可以只写void 名字(Qstring)

void(Teacher:: *Teachersign)(QString) = &Teacher::hungry;
void(Student:: *Studentsign)(QString) = &Student::treat;
    connect(zt,Teachersign,st,Studentsign);

    classover();



}

void Widget::classover(){
    emit zt->hungry("重载实现");
    emit zt->hungry();
}

Widget::~Widget()
{

}
