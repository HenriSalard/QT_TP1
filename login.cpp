#include "login.h"
#include "newuser.h"
#include "ui_login.h"
#include <iostream>



Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ReadUser();
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::ReadUser(){
    QDomDocument userXML;
    QFile xmlFile("C:/Users/Registered user/Documents/QT_TP1/myXML/myXML.xml");
    if (!xmlFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Failed to open the file for reading.";
    }
    userXML.setContent(&xmlFile);
    xmlFile.close();

    QDomElement root = userXML.documentElement();
    QDomElement node = root.firstChild().toElement();

    while(node.isNull() == false)
    {

        if(node.tagName() == "User"){
            while(!node.isNull()){
                qDebug() << node.tagName();
                QString id = node.attribute("ID");
                QString password = node.attribute("Password");

                User user = User(id.toStdString(),password.toStdString());

                vUser.append(user);

                node = node.nextSibling().toElement();
            }
        }
        node = node.nextSibling().toElement();
    }
}

void Login::on_loginButton_clicked()
{

    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    bool find = false;

    for(User us : vUser){
        if(username.toStdString() ==  us.getId() && password.toStdString() == us.getPassword()) {
            QMessageBox::information(this, "Login", "Username and password is correct");
            find = true;
        }
    }
    if(!find)   QMessageBox::warning(this,"Login", "Username and password is not correct");
}


void Login::on_createButton_clicked()
{
    newUser* nu = new newUser();
    nu->show();
    this->setVisible(false);
}

