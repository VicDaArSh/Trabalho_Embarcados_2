#include "server.h"
#include <QTcpSocket>
#include <QTextStream>

Server::Server(QObject *parent) :
    QTcpServer(parent)
{
    mSocket = nullptr;

    connect(this, &Server::newConnection, [&]() {
        mSocket = nextPendingConnection();
    });
}

void Server::sendMessage(const QString &Ms)
{
    if (mSocket) {
        QTextStream T(mSocket);
        T << Ms;
        mSocket ->flush();

    }
}
