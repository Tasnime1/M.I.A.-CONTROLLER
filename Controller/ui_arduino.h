/********************************************************************************
** Form generated from reading UI file 'arduino.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARDUINO_H
#define UI_ARDUINO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Arduino
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Arduino)
    {
        if (Arduino->objectName().isEmpty())
            Arduino->setObjectName(QString::fromUtf8("Arduino"));
        Arduino->resize(789, 222);
        centralwidget = new QWidget(Arduino);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_5 = new QHBoxLayout(centralwidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Georgia"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit1 = new QLineEdit(centralwidget);
        lineEdit1->setObjectName(QString::fromUtf8("lineEdit1"));

        horizontalLayout->addWidget(lineEdit1);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        lineEdit2 = new QLineEdit(centralwidget);
        lineEdit2->setObjectName(QString::fromUtf8("lineEdit2"));

        horizontalLayout_2->addWidget(lineEdit2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_3->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        Arduino->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Arduino);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 789, 26));
        Arduino->setMenuBar(menubar);
        statusbar = new QStatusBar(Arduino);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Arduino->setStatusBar(statusbar);

        retranslateUi(Arduino);

        QMetaObject::connectSlotsByName(Arduino);
    } // setupUi

    void retranslateUi(QMainWindow *Arduino)
    {
        Arduino->setWindowTitle(QCoreApplication::translate("Arduino", "Arduino", nullptr));
        label->setText(QCoreApplication::translate("Arduino", "Vertical:       ", nullptr));
        label_2->setText(QCoreApplication::translate("Arduino", "Horizontal:", nullptr));
        label_3->setText(QCoreApplication::translate("Arduino", "Command: ", nullptr));
        label_5->setText(QCoreApplication::translate("Arduino", "command  will appear here", nullptr));
        label_4->setText(QCoreApplication::translate("Arduino", "Sensors' readings...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Arduino: public Ui_Arduino {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARDUINO_H
