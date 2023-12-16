#ifndef SOCKETSERVICE_H
#define SOCKETSERVICE_H

#include <QObject>
#include <QTcpSocket>

#include "mainwindow.h"
#include "loginwindow.h"

class SocketService : QObject
{
    Q_OBJECT
public:
    SocketService(QObject *parent = nullptr);

    void write(QByteArray &data);

public slots:
    void onReadyRead();
    void onSendMessage(QByteArray &data);

private slots:
    void onLogin();

private:
    QTcpSocket _socket;
    MainWindow _mainw;
    LoginWindow _loginw;
};

#endif // SOCKETSERVICE_H
