#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
//信号返回值void,不需要实现,可重载
    void hungry();
    void hungry(QString);

public slots:
};

#endif // TEACHER_H
