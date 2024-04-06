#ifndef DB_MANAGER_H
#define DB_MANAGER_H

#include <QString>
#include <QSqlDatabase>

class db_manager
{
public:
    db_manager(const QString& path, bool canwrite);
private:
    QSqlDatabase m_db;
};

#endif // DB_MANAGER_H
