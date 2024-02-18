#include "userslist.h"
#include "ui_userslist.h"
#include "session.h"
#include "user.h"
#include "gestxml.h"
#include "profils_manager.h"
#include "accueil.h"
#include "login.h"

UsersList::UsersList(QWidget *parent, Session *session)
    : QDialog(parent)
    , ui(new Ui::UsersList)
{
    ui->setupUi(this);
    this->session = session;

    QVector<User> vUsers = GestXML::GetAllUsers();

    fillTable(vUsers);

    // gere le clic sur l'utilisateur en ouvrant la fenêtre correspondante
    connect(ui->tableWidget, &QTableWidget::itemClicked, this, [this, vUsers](QTableWidgetItem *item){
        onTableItemClicked(item, vUsers);
    });


}



void UsersList::fillTable(const QVector<User> users) {
    ui->tableWidget->setRowCount(users.size());
    ui->tableWidget->setColumnCount(1); // Une seule colonne car on affiche que les noms

    // remplissage du tableau
    for (int i = 0; i < users.size(); ++i) {
        User user = users[i];
        QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(user.getId()));
        ui->tableWidget->setItem(i, 0, item);
    }
}

void UsersList::onTableItemClicked(QTableWidgetItem *item, QVector<User> users) {
    if (item) {
        int row = item->row();
        User selectedUser = users[row];

        // Ouvrir une nouvelle fenêtre en passant l'utilisateur sélectionné
        profils_manager *profilsWindow = new profils_manager(nullptr, session, selectedUser);
        profilsWindow->show();
        this->close();
    }
}

void UsersList::on_accueilButton_clicked(){
    Accueil *accueil = new Accueil(nullptr, session);
    accueil->show();
    this->close();

}
void UsersList::on_logOutButton_clicked(){
    Login *login = new Login();
    login->show();
    delete session;
    this->close();
}




UsersList::~UsersList()
{
    delete ui;
}
