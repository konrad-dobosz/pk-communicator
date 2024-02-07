#include "mainwindow.h"
#include "addfriendwindow.h"
#include "chatwindow.h"
#include "settingswindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(ChatWindow *chatw, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _chatw(chatw)
{
    ui->setupUi(this);
    ui->lineEdit_friendIp->setInputMask("999.900.900.900");
    ui->lineEdit_serverIp->setInputMask("999.900.900.900");
    ui->lineEdit_username->setInputMask("Xxxxxxxxxxxxxxxxx");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
//{
//    _chatw->show();
//}

//void MainWindow::on_btn_settings_clicked()
//{
//    SettingsData data;
//    SettingsWindow *settingsWindow = new SettingsWindow(data);

//    if (settingsWindow->exec()) {
//        emit updateSettings(data);
//    }
//}

//void MainWindow::on_btn_add_friend_clicked()
//{
//    AddFriendData data;
//    AddFriendWindow *addFriendWindow = new AddFriendWindow(data);

//    if (addFriendWindow->exec()) {
//        emit addFriend(data.friendIP);
//    }
//}


void MainWindow::on_btn_write_clicked()
{
    //_chatw->setFriendIpAddress(QHostAddress("::ffff:" + ui->lineEdit_friendip->text()));
    QString serverIp = "::ffff:" + ui->lineEdit_serverIp->text().simplified();
    QString friendIp = "::ffff:" + ui->lineEdit_friendIp->text().simplified();

    QHostAddress serverAddress(serverIp);
    QHostAddress friendAddress(friendIp);

    if (!serverAddress.isNull() && !friendAddress.isNull()) {
        emit connectToFriend(ui->lineEdit_username->text(),serverAddress, friendAddress);
        _chatw->show();
    }
}

