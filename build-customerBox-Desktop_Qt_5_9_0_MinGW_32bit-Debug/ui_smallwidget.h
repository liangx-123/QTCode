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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include <samallwidget.h>

QT_BEGIN_NAMESPACE

class Ui_smallWidget
{
public:
    samallwidget *widget;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;

    void setupUi(QWidget *smallWidget)
    {
        if (smallWidget->objectName().isEmpty())
            smallWidget->setObjectName(QStringLiteral("smallWidget"));
        smallWidget->resize(400, 300);
        widget = new samallwidget(smallWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(150, 40, 120, 80));
        horizontalSlider = new QSlider(smallWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(180, 180, 160, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        spinBox = new QSpinBox(smallWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(90, 180, 42, 22));

        retranslateUi(smallWidget);

        QMetaObject::connectSlotsByName(smallWidget);
    } // setupUi

    void retranslateUi(QWidget *smallWidget)
    {
        smallWidget->setWindowTitle(QApplication::translate("smallWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class smallWidget: public Ui_smallWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMALLWIDGET_H
