#include "newuser.h"
#include "ui_newuser.h"
#include "user.h"
#include "login.h"
using namespace std;

newUser::newUser(QWidget *parent, bool isFirstConnection )
    : QDialog(parent)
    , ui(new Ui::newUser)
{
    ui->setupUi(this);
    ui->backButton->setVisible(!isFirstConnection);
    std::cout<<"test " << isFirstConnection<<"\n";
}


newUser::~newUser()
{
    delete ui;
}


void newUser::on_pushButton_clicked(){
    QString newPassword = ui->passwordTextField->text();
    QString newId = ui->idTextField->text();

    if(newPassword.isEmpty() || newId.isEmpty()){
        ui->labelError->setText("Erreur, veuillez remplir tous les champs");
    }
    else{
        User newUser = User(newId.toStdString(), newPassword.toStdString());


    }
}



void newUser::on_backButton_clicked()
{
    Login* nu = new Login();
    nu->show();
    this->setVisible(false);
}

