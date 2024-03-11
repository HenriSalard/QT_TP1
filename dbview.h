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
    explicit DbView(QWidget *parent = nullptr,Session * session = nullptr);
    ~DbView();

private:
    Ui::DbView *ui;
    Session * session;
};

#endif // DBVIEW_H
