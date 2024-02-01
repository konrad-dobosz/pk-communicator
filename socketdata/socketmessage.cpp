#include "socketmessage.h"

QDataStream &operator<< (QDataStream &ds, SocketMessage &data) {
    return ds << data.getMessage();
}

SocketMessage::SocketMessage () {}

SocketDataType SocketMessage::type() {
    return SocketDataType::message;
}

QString SocketMessage::getMessage() {
    return message;
}

void SocketMessage::setMessage(QString &msg) {
    this->message = msg;
}
