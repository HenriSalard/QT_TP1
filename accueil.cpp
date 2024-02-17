#include "accueil.h"
#include "ui_accueil.h"

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
    ui->profils_button->setVisible(session->getUsedProfil().hasRight(Droits::Manage_users));



    for(Profil profil : session->getUsedUser()->getListProfils()){
        ui->profilCombo->addItem(QString::fromStdString(profil.getName()));
    }
}



void Accueil::on_validateButton_clicked(){
    int selected_profile_index = ui->profilCombo->currentIndex();
    session->setUsedProfil(session->getUsedUser()->getListProfils()[selected_profile_index]);
    ui->profils_button->setVisible(session->getUsedProfil().hasRight(Droits::Manage_users));
}


Accueil::~Accueil()
{
    delete ui;
}
