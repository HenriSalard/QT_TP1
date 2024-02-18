#ifndef USERSLIST_H
#define USERSLIST_H

#include <QDialog>
#include "session.h"
#include "QTableWidgetItem"

namespace Ui {

/**
 * Classe controller de la vue UserList
 */

class UsersList;
}

class UsersList : public QDialog
{
    Q_OBJECT

public:
    explicit UsersList(QWidget *parent = nullptr,Session *session = nullptr);
    ~UsersList();

    void fillTable(const QVector<User> users);
    void onTableItemClicked(QTableWidgetItem *item, QVector<User> users);

private slots:
    void on_accueilButton_clicked();
    void on_logOutButton_clicked();

private:
    Ui::UsersList *ui;
    Session *session;
};

#endif // USERSLIST_H
