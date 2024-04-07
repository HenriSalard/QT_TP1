#ifndef DBVIEW_H
#define DBVIEW_H

#include "qsqldatabase.h"
#include "session.h"
#include <QDialog>
#include <QSqlTableModel>
#include <dblist.h>

namespace Ui {
class DbView;
}

class DbView : public QDialog
{
    Q_OBJECT

public:
    explicit DbView(QWidget *parent = nullptr, Session *session = nullptr,
                    QString name = "Test");
    ~DbView();
    
protected:
    /**
     * @brief Remplit la table des noms des tables de la base de données
     */
    void fillTable();

private slots:
    void on_pushButton_clicked();

    void on_dbTable_cellPressed(int row, int column);

    void on_pushButton_2_clicked();

private:
    Ui::DbView *ui;
    Session * session;
    QSqlDatabase db;
    QSqlTableModel *model;
};

#endif // DBVIEW_H
