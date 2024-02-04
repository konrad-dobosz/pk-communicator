#include "socketservice.h"
#include "socketdata/socketlogin.h"

SocketService::SocketService(QObject *parent):
    QObject(parent),
    _socket(QTcpSocket()),
    _mainw(MainWindow(&_chatw)),
    _loginw(LoginWindow()),
    _chatw(ChatWindow())
{
    _socket.connectToHost(QHostAddress("127.0.0.1"), 4242);

    _loginw.show();
    _mainw.show();

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

    qDebug() << "TYPE READ: " << type;

    if (SocketDataType(type) == SocketDataType::loginResponse) {
        //SocketLogin sl;

        qDebug() << "Login Response";

        //_loginw.hide();
        //_mainw.show();

    } else if (SocketDataType(type) == SocketDataType::message) {
        qDebug() << "MSG";
        SocketMessage data;

        readStream >> data;

        _chatw.appendMessage(data.getUsername(), data.getMessage());

    }
}

void SocketService::write(QTcpSocket &socket, SocketData &data) {
    QByteArray streamData;
    QDataStream writeStream(&streamData, QIODevice::WriteOnly);
    writeStream <<  quint16(0) << data.type();
    writeStream << data;
    writeStream.device()->seek(0);
    writeStream << quint16(streamData.size() - sizeof(quint16));

    qDebug() << "WRITE TYPE: " << (int)data.type();

    socket.write(streamData);
    socket.waitForBytesWritten();
}

void SocketService::onLogin(QString& username, QString& password) {
    //_socket.connectToHost(QHostAddress("127.0.0.1"), 4242);

    SocketLogin sLogin = SocketLogin(username, password);
    write(_socket, sLogin);
}

void SocketService::onSendMessage(SocketMessage &msg) {
    write(_socket, msg);
}
