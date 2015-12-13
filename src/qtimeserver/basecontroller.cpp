#include "basecontroller.h"
#include "tcpserver.h"
#include <QJsonDocument>
BaseController::BaseController()
{

}

void BaseController::render(const QJsonObject& json, Session session)
{
    QJsonDocument doc;
    doc.setObject(json);
    QByteArray data = doc.toJson(QJsonDocument::Compact);
    session.socket->write(data.toBase64() + "\n");
}

