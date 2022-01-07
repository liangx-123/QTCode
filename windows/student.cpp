#include "student.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent)
{


}//记得加Qobject
void  Student::treat(QString testStr){
qDebug()<<"学生方法已实现"<<testStr;}

void  Student::treat(){
qDebug()<<"学生方法已实现";}
