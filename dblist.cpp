#include "dblist.h"
#include "ui_dblist.h"
#include "accueil.h"
#include "gestxml.h"
#include "dbview.h"
#include <QFileDialog>
#include <QMessageBox>

DBList::DBList(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DBList)
{
    ui->setupUi(this);
}

DBList::~DBList()
{
    delete ui;
}

DBList::DBList(QWidget *parent, Session *session)
    : QDialog(parent)
    , ui(new Ui::DBList)
{
    ui->setupUi(this);
    this->session = session;

    vPathes = GestXML::GetDbProfil(session->getUsedUser(), session->getUsedProfil());
    fillTable(vPathes);
    };

/**
* @brief Remplit la table avec la liste de bases de données
* @param pathes : QVector<QString> : La liste des chemins vers les bases de données
*/
void DBList::fillTable(const QVector<QString> pathes){
    ui->tableWidget->setRowCount(pathes.size());
    ui->tableWidget->setColumnCount(2); // Une colonne pour le nom et une colonne pour supprimer

    // On definit aussi la largeur des colonnes
    ui->tableWidget->setColumnWidth(0, 300);
    ui->tableWidget->setColumnWidth(1, 200);

    // remplissage du tableau
    for (int i = 0; i < pathes.size(); ++i) {
        QString path_i = pathes[i];
        QFileInfo fi(path_i);

        // Ajout de la base, on pourra y accéder en cliquant dessus
        QTableWidgetItem *item = new QTableWidgetItem(fi.fileName());
        ui->tableWidget->setItem(i, 0, item);

        // Ajout du bouton supprimer à coté de la base
        QTableWidgetItem *itemSup = new QTableWidgetItem("Supprimer");

        // on met "Supprimer" en rouge et en gras
        itemSup->setData(Qt::ForegroundRole, QBrush(Qt::red));
        itemSup->setData(Qt::FontRole, QFont("Arial", 0, QFont::Bold, true));

        ui->tableWidget->setItem(i, 1, itemSup);
    }


}

/**
* @brief Gere le clic sur un element du tableau
* @param item  L'element sur lequel on a cliqué
*/
void DBList::onTableItemClicked(QTableWidgetItem *item) {
    if (item) {
        int row = item->row();
        int column = item->column();

        // Cas de clic sur une base
        if(column == 0){
            QString selectedString = vPathes[row];

            // Ouvrir une nouvelle fenêtre en passant le nom de la base sélectionnée
            DbView* DbViewWindow = new DbView(nullptr, session, selectedString);
            DbViewWindow->show();
            this->close();
        }

        // cas de clic sur "supprimer"
        else{

            // Affichage d'une demande de confirmation
            QMessageBox::StandardButton warning;
            QString message = "Etes-vous sûr de vouloir supprimer la base? \n La base ne sera pas supprimée de votre ordinateur";
            warning = QMessageBox::question(this, "Test", message,
                                          QMessageBox::Yes|QMessageBox::No);

            // si l'utilisateur appuie sur "oui" on supprime la base du profil
            if (warning == QMessageBox::Yes) {

                session->getUsedProfil()->removeDB(row);

                // Mise a jour du XML
                GestXML::ChangeUserProfil(*session->getUsedUser());

                // Mise à jour du tableau
                vPathes = GestXML::GetDbProfil(session->getUsedUser(), session->getUsedProfil());
                fillTable(vPathes);


            } else {
                return;
            }
        }

    }
}

/**
* @brief Gere le clic sur le bouton d'ajout de base
* Ouvre un QFileDialog qui permet d'ajouter un fichier SQLite
*/
void DBList::on_pushButton_clicked(){

    // Ajout du path de la bdd au profil


    QString fileName = QFileDialog::getOpenFileName(this,
                  tr("Open database"), "..", tr("*.sqlite *.sqlite3 *.db *.db3 *.s3db *.sl3"));

    if(!fileName.isEmpty()){

        // On verrifie que la base est pas déjà enregistré sur le profil
        for(QString path : vPathes){
            if(path == fileName){
                QMessageBox::warning(this,"Erreur", "Cette base de données est déjà enregistrée sur votre profil");
                return;
            }
        }


        session->getUsedProfil()->addListDB(fileName);
        qDebug() << fileName;

        // Mise a jour du profil dans le xml (ajout de la base)
        GestXML::ChangeUserProfil(*session->getUsedUser());


        // Affichage d'une fenetre de confirmation
        QFileInfo fi(fileName);
        QMessageBox::information(this, "Ajouter une base", fi.fileName() + " a bien été ajouté.");

        // Mise à jour du tableau
        vPathes = GestXML::GetDbProfil(session->getUsedUser(), session->getUsedProfil());
        fillTable(vPathes);

    }



}


/**
* @brief Clic sur le bouton retour
*/
void DBList::on_pushButton_2_clicked()
{
    Accueil *accueil = new Accueil(nullptr, session);
    accueil->show();
    this->close();
}

/**
* @brief Gere le clic sur un element du tableau (ouverture d'une base ou "supprimer")
* @param item : QTableWidgetItem : L'item sur lequel on clique
*/
void DBList::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    if (item) {
        int row = item->row();
        int column = item->column();

        // Cas de clic sur une base
        if(column == 0){
            QString selectedString = vPathes[row];

            // Ouvrir une nouvelle fenêtre en passant le nom de la base sélectionnée
            DbView* DbViewWindow = new DbView(nullptr, session, selectedString);
            DbViewWindow->show();
            this->close();
        }

        // cas de clic sur "supprimer"
        else{

            // Affichage d'une demande de confirmation
            QMessageBox::StandardButton warning;
            QString message = "Etes-vous sûr de vouloir supprimer la base? \n La base ne sera pas supprimée de votre ordinateur";
            warning = QMessageBox::question(this, "Test", message,
                                            QMessageBox::Yes|QMessageBox::No);

            // si l'utilisateur appuie sur "oui" on supprime la base du profil
            if (warning == QMessageBox::Yes) {

                session->getUsedProfil()->removeDB(row);

                // Mise a jour du XML
                GestXML::ChangeUserProfil(*session->getUsedUser());

                // Mise à jour du tableau
                vPathes = GestXML::GetDbProfil(session->getUsedUser(), session->getUsedProfil());
                fillTable(vPathes);


            } else {
                return;
            }
        }

    }
}

