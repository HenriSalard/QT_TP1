#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMessageBox>
#include <QtXml>
#include "user.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_loginButton_clicked();

    void on_createButton_clicked();

private:
    Ui::Login *ui;
    QVector<User> vUser;

protected:
    void ReadUser();
};

#endif // LOGIN_H
