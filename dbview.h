#ifndef DBVIEW_H
#define DBVIEW_H

#include "session.h"
#include <QDialog>

namespace Ui {
class DbView;
}

class DbView : public QDialog
{
    Q_OBJECT

public:
    void extracted(Session *&session);
    explicit DbView(QWidget *parent = nullptr, Session *session = nullptr,
                    string name = "Test");
    ~DbView();

protected:
    void fillTable(string dbname);

private slots:
    void on_pushButton_clicked();

private:
    Ui::DbView *ui;
    Session * session;
};

#endif // DBVIEW_H
