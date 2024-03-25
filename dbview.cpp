#include "dbview.h"
#include "gestxml.h"
#include "session.h"
#include "ui_dbview.h"

DbView::DbView(QWidget *parent, Session* session, string dbname)
    : QDialog(parent)
    , ui(new Ui::DbView)
{
        ui->setupUi(this);
        this->session = session;
        ui->dbnameLabel->setText(QString::fromStdString(dbname));
        fillTable(dbname);
}

DbView::~DbView()
{
    delete ui;
}

void DbView::fillTable(string dbname){

    //TODO Recuperer la table dbname dans sqlite
    ui->dbTable->setRowCount(1);
    ui->dbTable->setColumnCount(1);

    QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(dbname));
    ui->dbTable->setItem(0, 0, item);

    //TODO Créer une table avec le bon nombre de colonne et ligne qui correspond aux attributs des tables de la base

    //TODO Remplir la table

}

void DbView::on_pushButton_clicked()
{
    QString requete = ui->textEdit->toPlainText();

    //TODO Verifier que l'on puisse faire la requete et l'executer

    ui->resultTable->setRowCount(1);
    ui->resultTable->setColumnCount(1);

    QTableWidgetItem *item = new QTableWidgetItem(requete);
    ui->resultTable->setItem(0, 0, item);

    //TODO Afficher la table des résultats ou une erreur
}

