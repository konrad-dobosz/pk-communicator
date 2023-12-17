#include "socketservice.h"

QDataStream &operator<< (QDataStream &ds, SocketDataType data) {
    return ds << (quint8)data;
}

QDataStream &operator>> (QDataStream &ds, SocketDataType data) {
    quint8 val;
    ds >> val;
    if (ds.status() == QDataStream::Ok) {
        data = SocketDataType(val);
    }

    return ds;
}

SocketService::SocketService(QObject *parent):
    QObject(parent),
    _socket(this),
    _mainw(MainWindow()),
    _loginw(LoginWindow())
{

    _loginw.show();

    connect(&_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(&_loginw, SIGNAL(login(QString&, QString&)), this, SLOT(onLogin(QString&, QString&)));
    connect(&_mainw, SIGNAL(sendMessage(QByteArray&)), this, SLOT(onSendMessage(QByteArray&)));
}

void SocketService::onLogin(QString& username, QString& password) {
    _socket.connectToHost(QHostAddress("127.0.0.1"), 4242);

    QByteArray data = QByteArray(username.toUtf8());
    write(_socket, data, SocketDataType::loginRequest);
}

void SocketService::onReadyRead() {
    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
    QDataStream readStream(sender);

    quint16 sizeRead;
    quint8 type;
    QByteArray msg;

    readStream >> sizeRead;

    if (sender->bytesAvailable() < sizeRead) return;

    readStream >> type;
    readStream >> msg;

    QString message = QString(msg);

    switch (SocketDataType(type)) {
    case SocketDataType::loginResponse:
        qDebug() << "LR";
        _loginw.hide();
        _mainw.show();
        break;
    case SocketDataType::message:
        qDebug() << "MSG";
        _mainw.appendMessage(message);
        break;
    default:
        qDebug() << "Got someting else?";
        break;
    }
}

void SocketService::write(QTcpSocket &socket, QByteArray &data, SocketDataType type) {
    QByteArray streamData;
    QDataStream writeStream(&streamData, QIODevice::WriteOnly);
    writeStream <<  quint16(0) << type;
    writeStream << data;
    writeStream.device()->seek(0);
    writeStream << quint16(streamData.size() - sizeof(quint16));

    socket.write(streamData);
    socket.waitForBytesWritten();
}

void SocketService::onSendMessage(QByteArray &msg_data) {
    write(_socket, msg_data, SocketDataType::message);
}
