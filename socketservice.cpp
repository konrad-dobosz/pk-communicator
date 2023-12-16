#include "socketservice.h"

SocketService::SocketService(QObject *parent):
    QObject(parent),
    _socket(this),
    _mainw(MainWindow()),
    _loginw(LoginWindow())
{

    _loginw.show();

    connect(&_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(&_loginw, SIGNAL(login()), this, SLOT(onLogin()));
    connect(&_mainw, SIGNAL(sendMessage(QByteArray&)), this, SLOT(onSendMessage(QByteArray&)));
}

void SocketService::onLogin() {
    _socket.connectToHost(QHostAddress("127.0.0.1"), 4242);
    _loginw.hide();
    _mainw.show();
}

void SocketService::onReadyRead() {
    QByteArray datas = _socket.readAll();
    qDebug() << datas;
    //_socket.write(QByteArray("ok !\n"));
    //ui->textBrowser->append(datas);
}

void SocketService::onSendMessage(QByteArray &data) {
    _socket.write(data);
    _socket.waitForBytesWritten();
}
