#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMessageBox>
#include <QtXml>


namespace Ui {
class Login;
}

/**
 * @brief Classe Controller de la vue Login
 */
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

};

#endif // LOGIN_H
