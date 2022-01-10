/********************************************************************************
** Form generated from reading UI file 'smallwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMALLWIDGET_H
#define UI_SMALLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SmallWidget
{
public:
    QSpinBox *spinBox;
    QSlider *horizontalSlider;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *SmallWidget)
    {
        if (SmallWidget->objectName().isEmpty())
            SmallWidget->setObjectName(QStringLiteral("SmallWidget"));
        SmallWidget->resize(291, 52);
        spinBox = new QSpinBox(SmallWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(10, 10, 130, 20));
        horizontalSlider = new QSlider(SmallWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(160, 10, 160, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        widget = new QWidget(SmallWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(100, 130, 132, 24));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(SmallWidget);

        QMetaObject::connectSlotsByName(SmallWidget);
    } // setupUi

    void retranslateUi(QWidget *SmallWidget)
    {
        SmallWidget->setWindowTitle(QApplication::translate("SmallWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SmallWidget: public Ui_SmallWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMALLWIDGET_H
