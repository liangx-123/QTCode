#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>
#include<QFile>
#include<QTextCodec>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString path = QFileDialog::getOpenFileName(this,"打开","D:\\Users\\Administrator\\Desktop\\New Folder");
        ui->lineEdit->setText(path);
        QFile file(path);
        file.open(QIODevice::ReadOnly);
        QByteArray array = file.readAll();

        ui->textEdit->setText(array);
        file.close();
//	用gbk打开
  //      QTextCodec *code = QTextCodec::codecForName("gbk");
   //    ui->textEdit->setText(code->toUnicode(array));
//			按行追加
        //while(!file.atEnd())
    });
}

Widget::~Widget()
{
    delete ui;
}
