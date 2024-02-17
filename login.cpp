#include "login.h"
#include "gestxml.h"
#include "newuser.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_loginButton_clicked()
{

    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username.isEmpty() || password.isEmpty()) QMessageBox::warning(this,"Login", "At least one field is empty.");
    else{
        User userVerif = User(username.toStdString(),password.toStdString());

        if(!GestXML::FindUserXML(userVerif)){
            QMessageBox::warning(this,"Login", "Username and password are not correct");
        }
        else{
            QMessageBox::information(this, "Login", "Username and password is correct");
            //TODO page d'accueil
        }
    }

}


void Login::on_createButton_clicked()
{

    if(vUser.length() <= 1){
        newUser* nu = new newUser(this, true);
        nu->show();
        this->setVisible(false);
    }
    else{
        newUser* nu = new newUser(this, false);
        nu->show();
        this->setVisible(false);
    }

}

