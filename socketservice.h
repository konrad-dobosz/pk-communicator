#ifndef SOCKETSERVICE_H
#define SOCKETSERVICE_H

#include <QObject>
#include <QTcpSocket>

#include "mainwindow.h"
#include "loginwindow.h"

enum class SocketDataType: quint8 {
    loginRequest,
    loginResponse,
    message
};

Q_DECLARE_METATYPE(SocketDataType);

class SocketService : QObject
{
    Q_OBJECT
public:
    SocketService(QObject *parent = nullptr);

    void write(QTcpSocket &socket, QByteArray &data, SocketDataType type);

public slots:
    void onReadyRead();
    void onSendMessage(QByteArray &data);

private slots:
    void onLogin(QString&, QString&);

private:
    QTcpSocket _socket;
    MainWindow _mainw;
    LoginWindow _loginw;
};

#endif // SOCKETSERVICE_H
