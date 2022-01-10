#ifndef MYEVENT_H
#define MYEVENT_H

#include <QLabel>

class myEvent : public QLabel
{
    Q_OBJECT
public:
    explicit myEvent(QWidget *parent = nullptr);
    //void enterEvent(QEvent *event);
    //void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
bool event(QEvent *e);
signals:

public slots:
};

#endif // MYEVENT_H
