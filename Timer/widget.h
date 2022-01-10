#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void timerEvent(QTimerEvent *ev);
    int id1;
    int id2;
    ~Widget();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
