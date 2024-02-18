#include "accueil.h"
#include "login.h"
#include "ui_accueil.h"
#include "userslist.h"

Accueil::Accueil(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Accueil)
{
    ui->setupUi(this);
}

Accueil::Accueil(QWidget *parent, Session *session)
    : QDialog(parent)
    , ui(new Ui::Accueil)
{
    ui->setupUi(this);
    this->session = session;
    ui->label_2->setText(QString::fromStdString(session->getUsedUser()->getId()));
    ui->label_2->repaint();

    // le bouton pour ouvrir la gestion des profils n'apparait que si le profil actuel a le droit
    ui->profilsButton->setVisible(session->getUsedProfil().hasRight(Droits::Manage_profils));



    for(Profil profil : session->getUsedUser()->getListProfils()){
        ui->profilCombo->addItem(QString::fromStdString(profil.getName()));
    }
}



void Accueil::on_validateButton_clicked(){
    int selected_profile_index = ui->profilCombo->currentIndex();
    session->setUsedProfil(session->getUsedUser()->getListProfils()[selected_profile_index]);
    ui->profilsButton->setVisible(session->getUsedProfil().hasRight(Droits::Manage_profils));
}

void Accueil::on_disconnectButton_clicked(){
    Login *login = new Login();
    login->show();
    delete session;
    this->close();
}

/**
 * @brief Lance la fenêtre de liste des utilisateurs, et ferme la fenêtre courrante
 */
void Accueil::on_profilsButton_clicked(){
    UsersList *userList = new UsersList(nullptr, session);
    userList->show();
    this->close();
}


Accueil::~Accueil()
{
    delete ui;
}
