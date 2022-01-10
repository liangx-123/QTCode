#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);
    //联动调节
    void(QSpinBox:: *spinSignal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox,spinSignal,ui->horizontalSlider,&QSlider::setValue);
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);


}

void SmallWidget::set(int num){
    ui->spinBox->setValue(50);

}
int SmallWidget::get(){
    return ui->spinBox->value();
}

SmallWidget::~SmallWidget()
{
    delete ui;
}
