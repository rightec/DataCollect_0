#ifndef DCDBCONNECT_H
#define DCDBCONNECT_H

#include <QObject>
#include <QSqlDatabase>

class dcDbConnect : public QObject
{
    Q_OBJECT
public:
    /** METHODS*/
    explicit dcDbConnect(QObject *parent = nullptr);
    /**
     * @brief dcDbOpenConn: Connect to the given db
     * @return true if the connection is OK false if not
     */
    bool    dcDbOpenConn();

    /** ATTRIBUTES*/

signals:

public slots:
};

#endif // DCDBCONNECT_H
