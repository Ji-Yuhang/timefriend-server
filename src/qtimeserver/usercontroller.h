#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include "basecontroller.h"
#include "user.h"
class UserController : public BaseController
{
public:
    UserController();
    virtual QString controllerName();
    virtual void onMessage(const QJsonObject& json, Session session);

private:
    User user_;
};

#endif // USERCONTROLLER_H
