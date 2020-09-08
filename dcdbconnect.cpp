#include "dcdbconnect.h"

dcDbConnect::dcDbConnect(QObject *parent) : QObject(parent)
{

}


bool    dcDbConnect::dcDbOpenConn()
{
    bool bRetVal = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("acidalia");
    db.setDatabaseName("customdb");
    db.setUserName("mojito");
    db.setPassword("J0a1m8");
    bRetVal = db.open();

    return bRetVal;
}
