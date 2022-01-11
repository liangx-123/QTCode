#include "mainscene.h"
#include "ui_mainscene.h"
#include<QAction>
#include<QPainter>
#include<mypushbotton.h>
#include<QDebug>
#include<QPushButton>
#include<QTimer>
#include<QSound>

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);
    setFixedSize(320,588);
      setWindowIcon(QIcon(":/Coin0001.png"));
      setWindowTitle("翻金币主场景");

      connect(ui->actionQuit,&QAction::triggered,[=](){
          this->close();
      });




QSound *startSound = new QSound(":/TapButtonSound.wav",this);

      MyPushBotton *startBtn = new MyPushBotton(":/MenuSceneStartButton.png");
      startBtn->setParent(this);
      startBtn->move(this->width()*0.5 - startBtn->width() * 0.5,this->height() * 0.7);

     chooseScene =  new ChooseLevelScene;

     connect(chooseScene,&ChooseLevelScene::chooseSceneBack,[=](){
         this->setGeometry(chooseScene->geometry());
         chooseScene->hide();
         this->show();});


      connect(startBtn,&MyPushBotton::clicked,[=](){

         qDebug() <<"点击了";
         startSound->play();
         startBtn->zoom1();
         startBtn->zoom2();

         QTimer::singleShot(500,this,[=](){
             chooseScene->setGeometry(this->geometry());
             this->hide();
             chooseScene->show();

             });


         });









}



void MainScene::paintEvent(QPaintEvent *){

    QPainter painter(this)   ;
    QPixmap pix;
    pix.load(":/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

   pix.load(":/Title.png");
   //缩放
   pix = pix.scaled(pix.width() * 0.5,pix.height() * 0.5);

    painter.drawPixmap(10,30,pix);
}

MainScene::~MainScene()
{
    delete ui;
}
