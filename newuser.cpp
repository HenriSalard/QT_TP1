#include "newuser.h"
#include "ui_newuser.h"
#include "user.h"
#include "login.h"
#include "gestxml.h"
#include "Accueil.h"
#include "Session.h"

using namespace std;

/**
 * @brief newUser::newUser  Controller de la page de creation d'utilisateur
 * @param parent
 * @param isFirstConnection Booleen qui permet de savoir si c'est la premiere connexion ou non
 */

newUser::newUser(QWidget *parent, bool isFirstConnection )
    : QDialog(parent)
    , ui(new Ui::newUser)
{
    ui->setupUi(this);
    ui->backButton->setVisible(!isFirstConnection);
}


newUser::~newUser()
{
    delete ui;
}

void newUser::savetoXML(User user){

    // On verifie si l'utilisateur n'existe pas deja
    if(!GestXML::UserExistsXML(user)){

        // TODO ajouter un role de base

        // On verifie si on arrive à acceder au fichier xml et on sauvegarde l'utilisateur
        switch(GestXML::SaveUserXML(user)){
            case 1 : QMessageBox::critical(this,"Erreur","Impossible d'ouvrir le ficher XML");
            case 2 : QMessageBox::critical(this,"Erreur","Impossible d'écrire dans le document XML");
            default:
                QMessageBox::information(this,"User","L'utilisateur a bien été ajouté");

                User *newUser = new User(user.getId(), user.getPassword());
                Session *session = new Session(newUser);

                Accueil* accueil = new Accueil(nullptr, session);
                accueil->show();
                this->close();
        }
    }
    else{
        QMessageBox::warning(this,"Create", "This user aready exists!");
    }

}


void newUser::on_pushButton_clicked(){
    QString newPassword = ui->passwordTextField->text();
    QString newId = ui->idTextField->text();

    // Si le mot de passe ou l'identifiant est vide -> erreur
    if(newPassword.isEmpty() || newId.isEmpty()){
        ui->labelError->setText("Erreur, veuillez remplir tous les champs");
    }
    else{
        User newUser = User(newId.toStdString(), newPassword.toStdString());
        savetoXML(newUser);
        GestXML::AddUserProfil(newUser,newUser.getProfil("base"));

    }

}



void newUser::on_backButton_clicked()
{
    Login* nu = new Login();
    nu->show();
    this->close();
}

