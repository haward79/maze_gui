/********************************************************************************
** Form generated from reading UI file 'InputSize.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTSIZE_H
#define UI_INPUTSIZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputSize
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *vBoxLayout_main;
    QLabel *label_title;
    QHBoxLayout *hBoxLayout_height;
    QLabel *label_height;
    QLineEdit *lineEdit_height;
    QHBoxLayout *hBoxLayout_width;
    QLabel *label_width;
    QLineEdit *lineEdit_width;
    QPushButton *pushButton_ok;
    QStatusBar *statusbar_message;

    void setupUi(QMainWindow *InputSize)
    {
        if (InputSize->objectName().isEmpty())
            InputSize->setObjectName(QString::fromUtf8("InputSize"));
        InputSize->resize(365, 185);
        InputSize->setMinimumSize(QSize(365, 185));
        InputSize->setMaximumSize(QSize(365, 185));
        centralwidget = new QWidget(InputSize);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 341, 142));
        vBoxLayout_main = new QVBoxLayout(verticalLayoutWidget);
        vBoxLayout_main->setObjectName(QString::fromUtf8("vBoxLayout_main"));
        vBoxLayout_main->setContentsMargins(0, 0, 0, 0);
        label_title = new QLabel(verticalLayoutWidget);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(17);
        font.setBold(true);
        font.setWeight(75);
        label_title->setFont(font);

        vBoxLayout_main->addWidget(label_title);

        hBoxLayout_height = new QHBoxLayout();
        hBoxLayout_height->setObjectName(QString::fromUtf8("hBoxLayout_height"));
        label_height = new QLabel(verticalLayoutWidget);
        label_height->setObjectName(QString::fromUtf8("label_height"));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label_height->setFont(font1);

        hBoxLayout_height->addWidget(label_height);

        lineEdit_height = new QLineEdit(verticalLayoutWidget);
        lineEdit_height->setObjectName(QString::fromUtf8("lineEdit_height"));
        QFont font2;
        font2.setPointSize(12);
        lineEdit_height->setFont(font2);

        hBoxLayout_height->addWidget(lineEdit_height);


        vBoxLayout_main->addLayout(hBoxLayout_height);

        hBoxLayout_width = new QHBoxLayout();
        hBoxLayout_width->setObjectName(QString::fromUtf8("hBoxLayout_width"));
        label_width = new QLabel(verticalLayoutWidget);
        label_width->setObjectName(QString::fromUtf8("label_width"));
        label_width->setFont(font1);

        hBoxLayout_width->addWidget(label_width);

        lineEdit_width = new QLineEdit(verticalLayoutWidget);
        lineEdit_width->setObjectName(QString::fromUtf8("lineEdit_width"));
        lineEdit_width->setFont(font2);

        hBoxLayout_width->addWidget(lineEdit_width);


        vBoxLayout_main->addLayout(hBoxLayout_width);

        pushButton_ok = new QPushButton(verticalLayoutWidget);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setMinimumSize(QSize(0, 30));

        vBoxLayout_main->addWidget(pushButton_ok);

        InputSize->setCentralWidget(centralwidget);
        statusbar_message = new QStatusBar(InputSize);
        statusbar_message->setObjectName(QString::fromUtf8("statusbar_message"));
        InputSize->setStatusBar(statusbar_message);

        retranslateUi(InputSize);

        QMetaObject::connectSlotsByName(InputSize);
    } // setupUi

    void retranslateUi(QMainWindow *InputSize)
    {
        InputSize->setWindowTitle(QApplication::translate("InputSize", "Input size - Maze Solver", nullptr));
        label_title->setText(QApplication::translate("InputSize", "Input maze size : ", nullptr));
        label_height->setText(QApplication::translate("InputSize", "Height : ", nullptr));
        label_width->setText(QApplication::translate("InputSize", "Width : ", nullptr));
        pushButton_ok->setText(QApplication::translate("InputSize", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InputSize: public Ui_InputSize {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTSIZE_H
