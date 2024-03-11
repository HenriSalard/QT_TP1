#ifndef DBLIST_H
#define DBLIST_H

#include <QDialog>
#include "session.h"

namespace Ui {
class DBList;
}

class DBList : public QDialog
{
    Q_OBJECT

public:
    explicit DBList(QWidget *parent = nullptr);
    explicit DBList(QWidget *parent = nullptr,  Session *session = nullptr);
    ~DBList();

    void fillTable();


private slots:
    void on_pushButton_clicked();

private:
    Ui::DBList *ui;
    Session *session;
};

#endif // DBLIST_H
