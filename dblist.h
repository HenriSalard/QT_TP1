#ifndef DBLIST_H
#define DBLIST_H

#include <QDialog>

namespace Ui {
class DBList;
}

class DBList : public QDialog
{
    Q_OBJECT

public:
    explicit DBList(QWidget *parent = nullptr);
    ~DBList();

private:
    Ui::DBList *ui;
};

#endif // DBLIST_H
