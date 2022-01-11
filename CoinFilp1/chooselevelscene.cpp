#include "chooselevelscene.h"
#include <QMenuBar>
#include<QAction>
#include<QPainter>
#include<mypushbotton.h>
#include <QPushButton>
#include<QDebug>
#include<QTimer>
#include<QLabel>
#include<QSound>
ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{

    this->setFixedSize(320,588);
    this->setWindowIcon(QPixmap(":/Coin0001.png"));
    this->setWindowTitle("选择关卡");
    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    QMenu *startMenu = bar->addMenu("开始");

     QAction *quitAction = startMenu->addAction("退出");
     connect(quitAction,&QAction::triggered,[=](){

         this->close();
     }) ;

QSound *chooseSound = new QSound(":/TapButtonSound.wav",this);
QSound *backSound = new QSound(":/BackButtonSound.wav",this);




//返回按钮
     MyPushBotton *backBtn = new MyPushBotton(":/BackButton.png",":/BackButtonSelected.png");
     backBtn->setParent(this);
     backBtn->move(this->width() - backBtn->width(),this->height() - backBtn->height());
     connect(backBtn,&MyPushBotton::clicked,[=](){
backSound->play();
qDebug()<<"点击了返回";

QTimer::singleShot(500,this,[=](){

emit this->chooseSceneBack();
});




     });


      //选择关卡按钮
     for(int i = 0;i<20;i ++){

         MyPushBotton *menuBtn = new MyPushBotton(":/LevelIcon.png");
         menuBtn->setParent(this);
         menuBtn->move(25+i%4 * 70,130+i/4*70);


         //按钮监听


         QLabel *label = new QLabel;
         label->setParent(this);
         label->setFixedSize(menuBtn->width(),menuBtn->height());
         label->setText(QString::number(i+1));
         label->move(25+i%4 * 70,130+i/4*70);
         label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
//鼠标穿透
label->setAttribute(Qt::WA_TransparentForMouseEvents);

         connect(menuBtn,&MyPushBotton::clicked,[=](){

             chooseSound->play();
             QString str = QString("第%1关").arg(i+1);
            qDebug()<<str;


            //进入游戏场景
            this->hide();
            play = new PlayScene(i+1);
            play->show();

            play->setGeometry(this->geometry());

            connect(play,&PlayScene::chooseSceneBack,[=](){
this->setGeometry(play->geometry());
                this->show();
                delete play;
                play = NULL;
            });

         });
     }


}

void ChooseLevelScene::paintEvent(QPaintEvent *){

    QPainter painter(this);
    QPixmap pix;
    pix.load(":/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pix.load(":/Title.png");
    painter.drawPixmap((this->width() - pix.width()) * 0.5,30,pix.width(),pix.height(),pix);


}
