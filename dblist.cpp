#include "dblist.h"
#include "ui_dblist.h"
#include "accueil.h"
#include "gestxml.h"
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

    QVector<QString> vPathes = GestXML::GetDbProfil(session->getUsedUser(), session->getUsedProfil());
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

void DBList::on_pushButton_clicked(){

    // Ajout du path de la bdd au profil
    QString fileName = QFileDialog::getOpenFileName(this,
                  tr("Open database"), "..", tr("*.sqlite *.sqlite3 *.db *.db3 *.s3db *.sl3"));
    session->getUsedProfil().addListDB(fileName);
    qDebug() << fileName;

    GestXML::ChangeUserProfil(*session->getUsedUser());


    // Affichage d'une fenetre de confirmation
    QFileInfo fi(fileName);
    QMessageBox::information(this, "Ajouter une base", fi.fileName() + " a bien été ajouté.");

}



void DBList::on_pushButton_2_clicked()
{
    Accueil *accueil = new Accueil(nullptr, session);
    accueil->show();
    this->close();
}

