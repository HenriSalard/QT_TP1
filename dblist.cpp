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

void DBList::fillTable(const QVector<QString> pathes){
    ui->tableWidget->setRowCount(pathes.size());
    ui->tableWidget->setColumnCount(2); // Une colonne pour le nom et une colonne pour supprimer


    // remplissage du tableau
    for (int i = 0; i < pathes.size(); ++i) {
        QString path_i = pathes[i];
        QFileInfo fi(path_i);
        QTableWidgetItem *item = new QTableWidgetItem(fi.fileName());
        ui->tableWidget->setItem(i, 0, item);
    }
}

void DBList::onTableItemClicked(QTableWidgetItem *item) {
    if (item) {
        int row = item->row();
        QString selectedString = vPathes[row];

        // Ouvrir une nouvelle fenêtre en passant l'utilisateur sélectionné
        DbView* DbViewWindow = new DbView(nullptr, session, selectedString);
        DbViewWindow->show();
        this->close();
    }
}

void DBList::on_pushButton_clicked(){

    // Ajout du path de la bdd au profil


    QString fileName = QFileDialog::getOpenFileName(this,
                  tr("Open database"), "..", tr("*.sqlite *.sqlite3 *.db *.db3 *.s3db *.sl3"));

    if(!fileName.isEmpty()){
        session->getUsedProfil()->addListDB(fileName);
        qDebug() << fileName;

        GestXML::ChangeUserProfil(*session->getUsedUser());


        // Affichage d'une fenetre de confirmation
        QFileInfo fi(fileName);
        QMessageBox::information(this, "Ajouter une base", fi.fileName() + " a bien été ajouté.");
    }



}



void DBList::on_pushButton_2_clicked()
{
    Accueil *accueil = new Accueil(nullptr, session);
    accueil->show();
    this->close();
}

