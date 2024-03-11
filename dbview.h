#ifndef DBVIEW_H
#define DBVIEW_H

#include <QDialog>

namespace Ui {
class DbView;
}

class DbView : public QDialog
{
    Q_OBJECT

public:
    explicit DbView(QWidget *parent = nullptr);
    ~DbView();

private:
    Ui::DbView *ui;
};

#endif // DBVIEW_H
