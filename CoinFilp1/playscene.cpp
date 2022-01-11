#include "playscene.h"
#include<QDebug>
#include<QMenuBar>
#include<QPainter>
#include<QTimer>
#include<mypushbotton.h>
#include<QLabel>
#include <QFont>
#include<mycoin.h>
#include"dataconfig.h"
//PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
//{

//}
PlayScene::PlayScene(int levelNum) {

    this->levelIndex = levelNum;
    QString str =QString("进入了%1").arg(levelNum);
    qDebug()<<str;

    this->setFixedSize(320,588);
    this->setWindowIcon(QPixmap(":/Coin0001.png"));
    this->setWindowTitle("翻金币场景");

    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    QMenu *startMenu = bar->addMenu("开始");

     QAction *quitAction = startMenu->addAction("退出");
     connect(quitAction,&QAction::triggered,[=](){

         this->close();
     }) ;



     MyPushBotton *backBtn = new MyPushBotton(":/BackButton.png",":/BackButtonSelected.png");
     backBtn->setParent(this);
     backBtn->move(this->width() - backBtn->width(),this->height() - backBtn->height());
     connect(backBtn,&MyPushBotton::clicked,[=](){
qDebug()<<"点击了playback按钮";
QTimer::singleShot(500,this,[=](){

   emit this->chooseSceneBack();
});

});

QLabel *label = new QLabel;
label->setParent(this);
QFont font;
font.setFamily("华文新魏");
font.setPointSize(20);
QString str1 = QString("level: %1").arg(this->levelIndex);

label->setFont(font);

label->setText(str1);
label->setGeometry(30,this->height()-50,120,50);


dataConfig config;
for(int i =0;i<4;i++){
    for(int j = 0;j<4;j++){

this->gameArray[i][j]=config.mData[this->levelIndex][i][j];

    }

}





//显示金币背景图案
for(int i = 0;i<4;i++){
    for(int j =0;j<4;++j){

        QLabel *label = new QLabel;
        label->setGeometry(0,0,50,50);
        label->setPixmap(QPixmap(":/BoardNode(1).png"));
        label->setParent(this);
        label->move(57+i*50,200+j*50);



//创建金币
QString str;
if(this->gameArray[i][j] == 1){

    str = ":/Coin0001.png";
}else {
     str = ":/Coin0008.png";
}

MyCoin *coin = new  MyCoin(str);
coin->setParent(this);
coin->move(57+i*50,200+j*50);

//给金币赋值
coin->posX = i;
coin->poxY = j;
coin->flag = this->gameArray[i][j];

connect(coin,&MyCoin::clicked,[=](){

coin->changeFlag();

this->gameArray[i][j] = this->gameArray[i][j] == 0?1:0;

});



    }
}





}

void PlayScene::paintEvent(QPaintEvent *){

    QPainter painter(this);
    QPixmap pix;
    pix.load(":/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //加载标题
    pix.load(":/Title.png");
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);



}
