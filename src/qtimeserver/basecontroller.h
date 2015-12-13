#ifndef BASECONTROLLER_H
#define BASECONTROLLER_H

#include <QObject>
#include <QJsonObject>
#include <QPointer>
class QTcpSocket;
struct Session {
    QTcpSocket* socket;
};

class BaseController : public QObject
{
    Q_OBJECT
public:
    explicit BaseController();

    virtual QString controllerName() = 0;
    virtual void onMessage(const QJsonObject& json, Session session) = 0;

protected:
    void render(const QJsonObject& json, Session session);
signals:

public slots:
private:
};

#endif // BASECONTROLLER_H
