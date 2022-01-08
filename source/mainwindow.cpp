#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionnew->setIcon(QIcon(":/new/prefix1/src=http___b-ssl.duitang.com_uploads_item_201707_31_20170731201409_4NT5y.jpeg&refer=http___b-ssl.duitang.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
