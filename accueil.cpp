#include "accueil.h"
#include "login.h"
#include "ui_accueil.h"
#include "userslist.h"
#include "dblist.h"

Accueil::Accueil(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Accueil)
{
    ui->setupUi(this);
}

/**
 * @brief Constructeur de Accueil utilisé en pratique
 * @param parent    Fenetre parent
 * @param session   Pointeur vers session en cours
 */
Accueil::Accueil(QWidget *parent, Session *session)
    : QDialog(parent)
    , ui(new Ui::Accueil)
{
    ui->setupUi(this);
    this->session = session;

    ui->label_2->setText(QString::fromStdString(session->getUsedUser()->getId()));
    ui->label_2->repaint();
    ui->profilsButton->setVisible(false);
    ui->readButton->setVisible(false);
    ui->writeButton->setVisible(false);

    if(session->getUsedProfil() != NULL){
        // le bouton des privilèges n'apparaissent que si le profil actuel a les droits
        ui->profilsButton->setVisible(session->getUsedProfil()->hasRight(Droits::Manage_profils));
        ui->readButton->setVisible(session->getUsedProfil()->hasRight(Droits::Read));
        ui->writeButton->setVisible(session->getUsedProfil()->hasRight(Droits::Write));
        //ui->userButton->setVisible(session->getUsedProfil().hasRight(Droits::Create_profils));
    }


    for(Profil* profil : session->getUsedUser()->getListProfils()){
        ui->profilCombo->addItem(QString::fromStdString(profil->getName()));
    }
}


/**
 * @brief Selectionne le profil à utiliser
 */
void Accueil::on_validateButton_clicked(){
    int selected_profile_index = ui->profilCombo->currentIndex();
    session->setUsedProfil(session->getUsedUser()->getListProfils()[selected_profile_index]);
    ui->profilsButton->setVisible(session->getUsedProfil()->hasRight(Droits::Manage_profils));
    ui->readButton->setVisible(session->getUsedProfil()->hasRight(Droits::Read));
    ui->writeButton->setVisible(session->getUsedProfil()->hasRight(Droits::Write));
    //ui->userButton->setVisible(session->getUsedProfil().hasRight(Droits::Create_profils));
}

/**
 * @brief Quand le bouton deconnexion est clique, on supprime la session et on renvoie à la page de login
 */
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

void Accueil::on_readButton_clicked(){

    // Mise a jour des droits de lecture et d'ecriture dans la session
    session->setCanRead(true);
    session->setCanWrite(false);

    DBList* databasesList = new DBList(nullptr, session);
    databasesList->show();
    this->close();
}

void Accueil::on_writeButton_clicked()
{
    // Mise a jour des droits de lecture et d'ecriture dans la session
    session->setCanRead(true);
    session->setCanWrite(true);

    DBList* databasesList = new DBList(nullptr, session);
    databasesList->show();
    this->close();
}

Accueil::~Accueil()
{
    delete ui;
}



