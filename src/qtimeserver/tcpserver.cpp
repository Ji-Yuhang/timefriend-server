#include "tcpserver.h"
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QByteArray>
#include "basecontroller.h"

TcpServer::TcpServer(QObject *parent) : QObject(parent)
{
    connect(&server_, &QTcpServer::acceptError, this, &TcpServer::acceptError);
    connect(&server_, &QTcpServer::newConnection, this, &TcpServer::newConnection);

}

TcpServer::~TcpServer()
{
    qDeleteAll(controllerlMap_);
}

void TcpServer::init()
{
    if (!server_.listen(QHostAddress::Any,5200)) {
        qDebug() << "cannot listen port 5200";
        qApp->quit();
        return;
    }


}

bool TcpServer::regController(BaseController *controller)
{
    QMap<QString, BaseController*>::iterator it = controllerlMap_.insert(controller->controllerName(), controller);
    if (it != controllerlMap_.end())
        return true;
    else
        return false;
}

void TcpServer::send(const QByteArray &data)
{

}

void TcpServer::newConnection()
{
    QTcpSocket* socket = server_.nextPendingConnection();
    connect(socket, &QTcpSocket::readyRead, this, &TcpServer::onMessage);
    qDebug() << "new connection"<< socket->peerAddress()<<socket->peerName()<<socket->peerPort();
}

void TcpServer::acceptError(QAbstractSocket::SocketError socketError)
{

}

void TcpServer::onMessage()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    if(!socket) return;
    QByteArray alldata = socket->readAll();
    qDebug() << "onMessage"<<alldata;
    QList<QByteArray> datalist = alldata.split('\n');
    Q_FOREACH(QByteArray base64data, datalist) {
        base64data = base64data.trimmed();
        if (base64data.isEmpty()) continue;
        QByteArray data = QByteArray::fromBase64(base64data);
        qDebug() << "onMessage frombase64"<<data;

//{"controller":"add","action":"add","userid":"jiyuhang","data":{"starttime":123123,"endtime":123123,"type":1,"event":"base64"}}
        QJsonParseError error;
        QJsonDocument dom = QJsonDocument::fromJson(data, &error);
        if (error.error) {
            qDebug() << "cannot parse json "<<error.errorString();
            continue;
        }
        QJsonObject json = dom.object();
        QString method = json["controller"].toString();
        BaseController* contorll = controllerlMap_.value(method,0);
        if (contorll) {
            Session session;
            session.socket = socket;
            contorll->onMessage(json, session);
        }
    }
}

