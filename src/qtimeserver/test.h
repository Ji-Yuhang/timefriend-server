#ifndef TEST_H
#define TEST_H

#include <QObject>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = 0);
    int testDB();

signals:

public slots:
};

#endif // TEST_H
