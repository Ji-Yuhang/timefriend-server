#include <QCoreApplication>
#include "test.h"
#include "application.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList arguments = a.arguments();
    if (arguments.contains("test")) {
        Test test;
        test.testDB();
    }
    Application app;
    app.init();



    return a.exec();
}

