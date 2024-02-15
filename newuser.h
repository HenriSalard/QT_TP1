#ifndef NEWUSER_H
#define NEWUSER_H

#include <QDialog>

namespace Ui {
class newUser;
}

class newUser : public QDialog
{
    Q_OBJECT

public:
    explicit newUser(QWidget *parent = nullptr, bool isFirstConnection = false);
    ~newUser();

private:
    Ui::newUser *ui;

private slots:
    void on_pushButton_clicked();

    void on_backButton_clicked();
};




#endif // NEWUSER_H
