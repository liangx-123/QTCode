#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QAction>
#include<QDebug>
#include<QDialog>
#include<QMessageBox>
#include<QListWidgetItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //对话框
    //模态:其他不能动 非模态:其他能动
    //关闭的时候才往下执行
        connect(ui->actionNew,&QAction::triggered,[=](){
    //        QDialog dlg(this);
    //        dlg.exec();

    //        qDebug()<<"模态对话框弹出";



        //非模态
//        QDialog *newdlg = new QDialog(this);
//        newdlg->show();
//        newdlg->setAttribute(Qt::WA_DeleteOnClose);


//第四个参数是选项值 第五个是默认选择值
        QMessageBox::critical(this,"标题","文本")    ;

    });
       /*
        * 用Qlistwidgetitem写诗
        * QListWidgetItem *item = new QListWidgetItem("写诗");
放进去
ui->listWidget->addItem(item);
   居中
     item->setTextAlignment(Qt::AlignCenter);

*/
   //     QStringList list;
    //    list<<""<<""<<"";
     //   ui->listWidget->addItem(list);



        /*

*/
}

MainWindow::~MainWindow()
{
    delete ui;
}
