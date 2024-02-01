#include "socketservice.h"
#include "socketdata/socketlogin.h"

SocketService::SocketService(QObject *parent):
    QObject(parent),
    _socket(this),
    _mainw(MainWindow()),
    _loginw(LoginWindow()),
    _chatw(ChatWindow())
{
    _loginw.show();

    connect(&_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(&_loginw, SIGNAL(login(QString&,QString&)), this, SLOT(onLogin(QString&,QString&)));
    connect(&_chatw, SIGNAL(sendMessage(SocketMessage&)), this, SLOT(onSendMessage(SocketMessage&)));
}

void SocketService::onReadyRead() {
    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
    QDataStream readStream(sender);

    quint16 size;
    quint8 type;

    readStream >> size;

    if (sender->bytesAvailable() < size) return;

    readStream >> type;

    if (SocketDataType(type) == SocketDataType::loginResponse) {
        SocketLogin sl;
        QString test;

        readStream >> test;
        qDebug() << test;

        _loginw.hide();
        _mainw.show();

    } else if (SocketDataType(type) == SocketDataType::message) {
        qDebug() << "MSG";
        QByteArray msg;

        readStream >> msg;

        QString message = QString(msg);
        QString username = "Ktoś";
        _chatw.appendMessage(username, message);

    }
}

void SocketService::write(QTcpSocket &socket, SocketData &data) {
    QByteArray streamData;
    QDataStream writeStream(&streamData, QIODevice::WriteOnly);
    writeStream <<  quint16(0) << data.type();
    writeStream << data;
    writeStream.device()->seek(0);
    writeStream << quint16(streamData.size() - sizeof(quint16));

    socket.write(streamData);
    socket.waitForBytesWritten();
}

void SocketService::onLogin(QString& username, QString& password) {
    _socket.connectToHost(QHostAddress("127.0.0.1"), 4242);

    SocketLogin sLogin = SocketLogin(username, password);

    qDebug() << "U: " << sLogin.getUsername() << ", P: " << sLogin.getPassword();
    write(_socket, sLogin);
}

void SocketService::onSendMessage(SocketMessage &msg) {
    write(_socket, msg);
}
