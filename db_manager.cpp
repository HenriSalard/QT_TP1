#include "db_manager.h"

#include <QDebug>

db_manager::db_manager(const QString& path, bool canwrite)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");


    if(!canwrite){
        m_db.setConnectOptions("QSQLITE_OPEN_READONLY");
    }
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}
