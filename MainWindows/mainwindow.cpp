#include "mainwindow.h"
#include<QMenuBar>
#include<QToolBar>
#include<QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include<QTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{ //创建菜单栏
    QMenuBar *bar = menuBar();
    //将菜单栏放在窗口
    setMenuBar(bar);
   //创建菜单
    QMenu *fileMenu = bar->addMenu("文件");

    //创建菜单项
    fileMenu->addAction("新建");
    fileMenu->addSeparator();
    fileMenu->addAction("编辑");

//工具栏
  QToolBar *toolBar = new QToolBar(this);

    //设置位置
addToolBar(Qt::LeftToolBarArea,toolBar);

    toolBar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);
/*创建工具栏菜单
    也可以拿指针指向前面的菜单栏,然后调用
    QAction *newAction = fileMenu->addAction("新建");    fileMenu->addSeparator();
   toolBar->addAction("newAction");
*/
    toolBar->addAction("编辑");

    //设置浮动
     toolBar->setFloatable(false);
//添加按钮
     QPushButton *btn = new QPushButton("aa",this);
     toolBar->addWidget(btn);

     //状态栏
     QStatusBar *stBar = statusBar();
     setStatusBar(stBar);
     //添加标签
     QLabel *label = new QLabel("左侧",this);
     stBar->addWidget(label);
     QLabel *label1 = new QLabel("右侧",this);
     stBar->addPermanentWidget(label1);


     //浮动窗口(铆接部件)
     QDockWidget *dockWidget = new QDockWidget("浮动",this);
     addDockWidget(Qt::BottomDockWidgetArea,dockWidget);

     //只允许上下
     addDockWidget(Qt::BottomDockWidgetArea\Qt::TopDockWidgetArea);

     //设置中心部件
     QTextEdit *edit = new QTextEdit(this);
     setCentralWidget(edit);

}


MainWindow::~MainWindow()
{

}
