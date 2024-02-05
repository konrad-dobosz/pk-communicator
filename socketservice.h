#ifndef SOCKETSERVICE_H
#define SOCKETSERVICE_H

#include <QObject>
#include <QWidget>

#include <QTcpServer>
#include <QTcpSocket>

#include "chatwindow.h"
#include "mainwindow.h"
#include "loginwindow.h"
#include "socketdata/socketdata.h"

class SocketService : QObject
{
    Q_OBJECT
public:
    SocketService(QObject *parent = nullptr);

    void write(QTcpSocket &socket, SocketData &data);

public slots:
    void onReadyRead();
    void onSendMessage(SocketMessage &msg);
    void onConnectToFriend(QString username, QHostAddress serverIp, QHostAddress friendIp);

private slots:
    void onLogin(QString&, QString&);

private:
    QTcpSocket _socket;
    MainWindow _mainw;
    LoginWindow _loginw;
    ChatWindow _chatw;
};

#endif // SOCKETSERVICE_H
