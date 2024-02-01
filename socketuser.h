#ifndef SOCKETUSER_H
#define SOCKETUSER_H

#include "socketdata/socketdata.h"

class SocketUser : public SocketData
{
public:
    SocketUser();

    QString username;
};

#endif // SOCKETUSER_H
