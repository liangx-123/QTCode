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






			QMainWindos类
			

			
菜单栏  QMenuBar    menu()方法  创建菜单项要先用指针    只能有一个

设置中心部件(只能一个)    setCentralWidget(edit);

状态栏  QStatusBar  statusBar()  只能有一个

工具栏   QToolBar   new对象    可以有几个

浮动窗口  QDockWidget   new

文字编辑  QEditText new

标签多个 new 

能有多个就new,只能一个就用方法

 

一般都是 QLabel 指针 = new QLabel("文字",this);

一个大类就要加一个头文件




   
   
   
               资源类(Source)
			   
			   
添加资源包   复制文件夹到工程目录下,右键添加文件-->QT-->QT Resource  添加
然后 添加前缀 然后添加文件全选  
ui->actionnew->setIcon(QIcon(":/new/prefix1/文件名")    :+前缀+文件名带尾缀   (可以直接复制Path)
			   
			   
			   
			对话框(QDialog)



模态:用方法 dlg.exec()

非模态: new  用指针接   newdlg->show()   要用newdlg->setAttribute(Qt::WA_DeleteOnClose);回收对象避免内存溢出

消息的对话框  QMessageBox

其他对话框: 颜色 文件 字体

布局:  ui界面选择widget放进去然后点上面那行水平布局    按钮就放horizontal spacer(弹簧)  栅格布局  垂直策略:fixed
			echomode:password
			
			
			
			
			
			布局

TOOlButtom 放图标
radio button 单选图标  默认选中: ui->对象->setChecked(true);
check box  多选   2 选中  1半选  0未选中 
QListWidget  new  整齐排列文本框
QString    整齐排列文本框   用法: QStringList list;
								list<<""<<""<<"";
								ui->listWidget->addItem(list);
        




				QTreeWidge类(tree)

先添加ui:Tree Widget

QTreeWidgeItem    项目  new     子项目 addChild(对象)
 
 
				QTableWidget(table)表


ui选  tablewidget

这些部件一般用QStringList()创建文字

setItem(第几行,第几列,new QTableWidgetItem("文本"));


		其他部件
		
scroll area 滚动
Stacked widget  切换



                    自定义信号控件(SmallWidget)





先创建一个QT设计师界面widget  ,之后在里面布局,然后在大ui界面放一个widget部件提升为刚创建的类名.qspinbox要用指针  

set get声明写在小类的public,  然后在小类.c里写方法,  在widget里connect调用  ui->widget->set   (为什么是widget我也不知道)





