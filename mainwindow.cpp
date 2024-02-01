#include "mainwindow.h"
#include "addfriendwindow.h"
#include "chatwindow.h"
#include "settingswindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QHostAddress>
#include <QAbstractSocket>
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    ChatWindow *chatWindow = new ChatWindow();

    chatWindow->show();
}

void MainWindow::on_btn_settings_clicked()
{
    SettingsData data;
    SettingsWindow *settingsWindow = new SettingsWindow(data);

    if (settingsWindow->exec()) {
        emit updateSettings(data);
    }
}

void MainWindow::on_btn_add_friend_clicked()
{
    AddFriendData data;
    AddFriendWindow *addFriendWindow = new AddFriendWindow(data);

    if (addFriendWindow->exec()) {
        emit addFriend(data.friendIP);
    }
}

