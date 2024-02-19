#include "profils_manager.h"
#include "ui_profils_manager.h"
#include "user.h"
#include "gestxml.h"
#include "profil.h"
#include "accueil.h"
#include "login.h"
#include "userslist.h"

profils_manager::profils_manager(QWidget *parent, Session * session, User selectedUser)
    : QDialog(parent)
    , ui(new Ui::profils_manager)
{
    ui->setupUi(this);
    this->session = session;

    ui->label->setText(QString("Profils actuels de ")
                       + QString::fromStdString(selectedUser.getId()));
    QVector<Profil> vProfils = selectedUser.getListProfils();
    fillTable(vProfils);
}

profils_manager::~profils_manager()
{
    delete ui;
}



void profils_manager::fillTable(const QVector<Profil> profils){
    ui->tableWidget->setRowCount(profils.size());
    ui->tableWidget->setColumnCount(5); // nombre de droits existants + 1

    // remplissage du tableau
    for (int i = 0; i < profils.size(); ++i) {
        Profil profil = profils[i];
        QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(profil.getName()));
        ui->tableWidget->setItem(i, 0, item);

        // Definition des droits du profil
        if(profil.getListDroits().contains(Droits::Read)){
            QTableWidgetItem *item = new QTableWidgetItem(QString("YES"));
            ui->tableWidget->setItem(i, 1, item);
        }
        else{
            QTableWidgetItem *item = new QTableWidgetItem(QString("NO"));
            ui->tableWidget->setItem(i, 1, item);
        }

        if(profil.getListDroits().contains(Droits::Write)){
            QTableWidgetItem *item = new QTableWidgetItem(QString("YES"));
            ui->tableWidget->setItem(i, 2, item);
        }
        else{
            QTableWidgetItem *item = new QTableWidgetItem(QString("NO"));
            ui->tableWidget->setItem(i, 2, item);
        }

        if(profil.getListDroits().contains(Droits::Manage_profils)){
            QTableWidgetItem *item = new QTableWidgetItem(QString("YES"));
            ui->tableWidget->setItem(i, 3, item);
        }
        else{
            QTableWidgetItem *item = new QTableWidgetItem(QString("NO"));
            ui->tableWidget->setItem(i, 3, item);
        }

        if(profil.getListDroits().contains(Droits::Create_profils)){
            QTableWidgetItem *item = new QTableWidgetItem(QString("YES"));
            ui->tableWidget->setItem(i, 4, item);
        }
        else{
            QTableWidgetItem *item = new QTableWidgetItem(QString("NO"));
            ui->tableWidget->setItem(i, 4, item);
        }
    }


    // Définition des noms des colonnes
    QStringList headerLabels;
    headerLabels << "Profil" << "Read" << "Write" << "Manage profiles" << "Create profiles";
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);



}


void profils_manager::on_accueilButton_clicked(){
    Accueil *accueil = new Accueil(nullptr, session);
    accueil->show();
    this->close();

}
void profils_manager::on_logOutButton_clicked(){
    Login *login = new Login();
    login->show();
    delete session;
    this->close();
}

void profils_manager::on_backButton_clicked()
{
    UsersList *userslist = new UsersList(nullptr,session);
    userslist->show();
    this->close();
}

