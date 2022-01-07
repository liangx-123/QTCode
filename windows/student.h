#ifndef STUDENT_H
#define STUDENT_H
#include<QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots:
    //需要声明和实现,可以重载
    void treat(QString);
    void treat();
};

#endif // STUDENT_H
