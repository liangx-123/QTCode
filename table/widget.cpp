#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置列数
    ui->tableWidget->setColumnCount(3);
    //设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"1"<<"2");
    //设置行数
    ui->tableWidget->setRowCount(5);
    QStringList namelist;

    //0行0列 名称
    //ui->tableWidget->setItem(0,0,new QTableWidgetItem("1"));
    namelist<<"1"<<"2"<<"3"<<"4"<<"5";
    QList<QString> sexList;
    sexList<<"男"<<"男"<<"nan"<<"2"<<"3";
    //循环赋值
    for(int i = 0;i<5;++i){
        int col = 0;
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(namelist[i]));
          ui->tableWidget->setItem(i,col++,new QTableWidgetItem(sexlist.at(i)));
          //QString 转int
            ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(i+18)));
    }
}

Widget::~Widget()
{
    delete ui;
}
