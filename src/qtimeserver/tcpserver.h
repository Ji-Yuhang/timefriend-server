#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
class BaseController;
class TcpServer : public QObject
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = 0);
    ~TcpServer();
    void init();
    bool regController(BaseController* controller);
    void send(const QByteArray& data);

signals:

public Q_SLOTS:
    void newConnection();
    void acceptError(QAbstractSocket::SocketError socketError);

    void onMessage();
private:
    QTcpServer server_;
    QMap<QString, BaseController*> controllerlMap_;
};

#endif // TCPSERVER_H
