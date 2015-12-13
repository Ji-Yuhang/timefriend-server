#include "application.h"
#include "usercontroller.h"
Application::Application(QObject *parent) : QObject(parent)
{

}

void Application::init()
{
    tcp_.init();
//    UserController* user = new UserController;
    tcp_.regController(new UserController);


}

