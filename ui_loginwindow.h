/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit_username;
    QLabel *label_2;
    QLineEdit *lineEdit_password;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_register;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(270, 298);
        gridLayout = new QGridLayout(LoginWindow);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(LoginWindow);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        lineEdit_username = new QLineEdit(LoginWindow);
        lineEdit_username->setObjectName("lineEdit_username");

        verticalLayout->addWidget(lineEdit_username);

        label_2 = new QLabel(LoginWindow);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        lineEdit_password = new QLineEdit(LoginWindow);
        lineEdit_password->setObjectName("lineEdit_password");

        verticalLayout->addWidget(lineEdit_password);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(LoginWindow);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pushButton_register = new QPushButton(LoginWindow);
        pushButton_register->setObjectName("pushButton_register");

        verticalLayout->addWidget(pushButton_register);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Logowanie", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "Nazwa u\305\274ytkownika", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "Has\305\202o", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginWindow", "Zaloguj", nullptr));
        pushButton_register->setText(QCoreApplication::translate("LoginWindow", "Zarejestruj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
