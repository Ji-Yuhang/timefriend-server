#include "usercontroller.h"
#include "database.h"
UserController::UserController()
{

}

QString UserController::controllerName()
{
    return QString("user");
}

void UserController::onMessage(const QJsonObject &json, Session session)
{
    //{"controller":"user","action":"login","userid":"jiyuhang","data":{"starttime":123123,"endtime":123123,"type":1,"event":"base64"}}

    QString account = json["account"].toString();
    QString password = json["password"].toString();
    User::UserInfo info = user_.login(account, password);
    if (info.userid > 0) {
        QJsonObject userjson;
        userjson["userid"] = info.userid;
        userjson["uuid"] = info.uuid;
        userjson["realname"] = info.realname;
        render(userjson, session);
    }
}

