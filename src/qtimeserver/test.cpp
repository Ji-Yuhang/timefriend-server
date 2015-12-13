#include "test.h"
#include "database.h"
Test::Test(QObject *parent) : QObject(parent)
{

}

int Test::testDB()
{
    DataBase* db = DataBase::instance();
    db->init();
}

