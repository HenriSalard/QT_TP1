#include "newuser.h"
#include "ui_newuser.h"
#include "user.h"
#include "login.h"
#include "gestxml.h"
using namespace std;

newUser::newUser(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::newUser)
{
    ui->setupUi(this);
}

newUser::~newUser()
{
    delete ui;
}

void newUser::savetoXML(User user){

    if(!GestXML::FindUserXML(user)){

        switch(GestXML::SaveUserXML(user)){
            case 1 : QMessageBox::critical(this,"Erreur","Impossible d'ouvrir le ficher XML");
            case 2 : QMessageBox::critical(this,"Erreur","Impossible d'écrire dans le document XML");
            default:
                QMessageBox::information(this,"User","L'utilisateur a bien été ajouté");
        }
    }
    else{
        QMessageBox::warning(this,"Create", "This user aready exists!");
    }

}


void newUser::on_pushButton_clicked(){
    QString newPassword = ui->passwordTextField->text();
    QString newId = ui->idTextField->text();

    if(newPassword.isEmpty() || newId.isEmpty()){
        ui->labelError->setText("Erreur, veuillez remplir tous les champs");
    }
    else{
        savetoXML(User(newId.toStdString(), newPassword.toStdString()));

    }
}



void newUser::on_backButton_clicked()
{
    Login* nu = new Login();
    nu->show();
    this->setVisible(false);
}

