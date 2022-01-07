F4 同名文件跳转
F1 帮助文档





                
				
				Widget类(工程名:window)

在widget.cpp里编写程序

从低级向高级回收(对象树)

按钮要new对象  QPushButton *btn = new QPushButton("按钮",this);

connet第二个是大类要用::作用域 用&

创建对象 this->zt = new Teacher(this);


创建类头文件记得该加QObject就加

public slots 是槽,要实现
signals 是信号 可以不实现

在头文件里声明,然后在 .cpp里写函数

额外函数写在Widget外面

重载  用指针指向之前填的方法  前一个要有作用域  后一个传值类型 void(Teacher:: *Teachersign)(QString) = &Teacher::hungry;


qDebug方法输出会带冒号  可以 名字.toUtf8().data()
 lambda   [=](){写方法}


