#ifndef DBLIST_H
#define DBLIST_H

#include <QDialog>
#include "qtablewidget.h"
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
    void fillTable(const QVector<QString> pathes);
    ~DBList();

    void fillTable();

    /**
     * @brief Gere le clic sur un element du tableau
     * @param item  L'element sur lequel on a cliqué
     */
    void onTableItemClicked(QTableWidgetItem *item);


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



private:
    Ui::DBList *ui;
    Session *session;
    QVector<QString> vPathes; // Les chemins des fichiers bdd
};

#endif // DBLIST_H
