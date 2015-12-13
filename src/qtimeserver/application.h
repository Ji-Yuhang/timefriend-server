#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include "tcpserver.h"
class Application : public QObject
{
    Q_OBJECT
public:
    explicit Application(QObject *parent = 0);
    void init();

signals:

public slots:
private:
    TcpServer tcp_;

};

#endif // APPLICATION_H
