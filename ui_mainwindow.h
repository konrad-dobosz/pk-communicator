/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_username;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_serverIp;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLineEdit *lineEdit_friendIp;
    QPushButton *btn_write;
    QPushButton *btn_settings;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(289, 290);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        lineEdit_username = new QLineEdit(centralwidget);
        lineEdit_username->setObjectName("lineEdit_username");

        verticalLayout->addWidget(lineEdit_username);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        lineEdit_serverIp = new QLineEdit(centralwidget);
        lineEdit_serverIp->setObjectName("lineEdit_serverIp");

        verticalLayout_2->addWidget(lineEdit_serverIp);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout_3->addWidget(label);

        lineEdit_friendIp = new QLineEdit(centralwidget);
        lineEdit_friendIp->setObjectName("lineEdit_friendIp");

        verticalLayout_3->addWidget(lineEdit_friendIp);

        btn_write = new QPushButton(centralwidget);
        btn_write->setObjectName("btn_write");

        verticalLayout_3->addWidget(btn_write);


        gridLayout->addLayout(verticalLayout_3, 1, 0, 1, 1);

        btn_settings = new QPushButton(centralwidget);
        btn_settings->setObjectName("btn_settings");
        btn_settings->setEnabled(false);

        gridLayout->addWidget(btn_settings, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 289, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Komunikator", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Nazwa u\305\274ytkownika", nullptr));
        lineEdit_username->setText(QCoreApplication::translate("MainWindow", "Student1", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Adres IP serwera", nullptr));
        lineEdit_serverIp->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        lineEdit_serverIp->setPlaceholderText(QCoreApplication::translate("MainWindow", "Np.: 127.0.0.1", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Adres IP drugiej instancji", nullptr));
        lineEdit_friendIp->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        lineEdit_friendIp->setPlaceholderText(QCoreApplication::translate("MainWindow", "Np.: 127.0.0.1", nullptr));
        btn_write->setText(QCoreApplication::translate("MainWindow", "Pisz", nullptr));
        btn_settings->setText(QCoreApplication::translate("MainWindow", "Ustawienia", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
