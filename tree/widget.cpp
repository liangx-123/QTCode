#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    //设置顶标签
 ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄介绍");
 //创建项目
QTreeWidgetItem *liItem = new QTreeWidgetItem(QStringList()<<"力量");
QTreeWidgetItem *miItem = new QTreeWidgetItem(QStringList()<<"敏捷");
QTreeWidgetItem *zhiItem = new QTreeWidgetItem(QStringList()<<"智力");

//放进去
ui->treeWidget->addTopLevelItem(miItem);
ui->treeWidget->addTopLevelItem(liItem);
ui->treeWidget->addTopLevelItem(zhiItem);
//添加子项目
QStringList hero;
hero<<"1"<<"2";
QTreeWidgetItem *q = new QTreeWidgetItem(hero);
liItem->addChild(q);
}

Widget::~Widget()
{
    delete ui;
}
