#include "dbview.h"
#include "qelapsedtimer.h"
#include "qmessagebox.h"
#include "qsqldatabase.h"
#include "session.h"
#include "ui_dbview.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>
#include <QFileDialog>
#include <QSqlError>
#include <QSqlQueryModel>

DbView::DbView(QWidget *parent, Session* session, QString dbname)
    : QDialog(parent)
    , ui(new Ui::DbView)
{
        ui->setupUi(this);
        this->session = session;
        QFileInfo fi(dbname);
        ui->dbnameLabel->setText(fi.fileName());
        ui->label->setText("Pas encore de requête");

        //Les tables ne seront pas directement modifiés dans l'application
        ui->tableView->setEditTriggers(QTableView::NoEditTriggers);
        ui->dbTable->setEditTriggers(QTableView::NoEditTriggers);

        //On prépare la connexion à la base de données
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(dbname);

        //On prends garde aux droitsde l'utilisateur
        if(!session->getCanWrite()){
            db.setConnectOptions("QSQLITE_OPEN_READONLY");
        }

        //On ouvre la connexion à la base de données
        //Si la connexion échoue
        if (!db.open()) {

            //On prévient l'utilisateur
            QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
                                  QObject::tr("Unable to establish a database connection.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
            return;
        }

        //On liste toutes les tables de la base de données
        fillTable();
}

DbView::~DbView()
{
    QString connectionName = db.connectionName();

    //On ferme la BDD et on ferme la page
    db.close();
    db = QSqlDatabase();
    QSqlDatabase::removeDatabase(connectionName);
    delete ui;
}

void DbView::fillTable(){

    //Recupere le nom de toutes les tables de dbname
    QStringList ListTable = db.tables(QSql::Tables);

    //Pour tous ces noms
    for(QString table : ListTable){

        //On enlève les tables que l'utilisateur n'est pas sensé voir
        if(table.startsWith("sqlite_")){
            ListTable.removeOne(table);
        }

    }

    //On remplit le tableau de ces noms
    ui->dbTable->setRowCount(ListTable.length());
    ui->dbTable->setColumnCount(1);

    for(int table = 0; table < ListTable.length();table++){
        if(!ListTable.at(table).startsWith("sqlite_")){
            QTableWidgetItem *item = new QTableWidgetItem(ListTable.at(table));
            ui->dbTable->setItem(table, 0, item);
        }
    }
}

void DbView::on_pushButton_clicked()
{

    //On récupère la requête de l'user
    QString requete = ui->textEdit->toPlainText();

    QSqlQuery query(db);

    //On lance le chrono
    QElapsedTimer timer;
    timer.start();

    //On execute la requête
    if (!query.exec(requete)) {

        //S'il y a un problème, on prévient l'user
        QMessageBox::critical(nullptr, QObject::tr("Requete érronée : ") + query.lastError().nativeErrorCode(),
                              "Erreur : \n" + query.lastError().databaseText() +
                              "\n" + query.lastError().driverText(), QMessageBox::Ok);
        return;
    }

    //On récupère des informations sur la requête
    bool isSelect = query.isSelect();
    int affected = query.numRowsAffected();

    //On remplit la table des résultats de la requête
    model = new QSqlTableModel();
    model->setQuery(std::move(query));
    model->select();
    ui->tableView->setModel(model);

    //On termine le chrono
    ui->label->setText("Temps d'éxécution : " + QString::number(timer.elapsed()) + "ms");

    //Pour prévenir l'user dans le cas d'une modification
    if(!isSelect){

        QMessageBox::information(nullptr, QObject::tr("Requete terminée"),
                              "Votre requete a bien été réalisé.\n"
                                 "Ligne(s) modifiée(s) : " + QString::number(affected), QMessageBox::Ok);
        ui->dbTable->clear();
        fillTable();
    }


}


void DbView::on_dbTable_cellPressed(int row, int column)
{

    qDebug() << row << " : " << column;

    //On remplit la table des résultats avec le contenu de la table sélectionnée
    model = new QSqlTableModel(this, db);
    model->setTable(ui->dbTable->selectedItems().at(0)->text());
    model->select();

    ui->tableView->setModel(model);
}

/**
 * @brief Retour à la page précédente
 */
void DbView::on_pushButton_2_clicked()
{
    QString dbname = db.databaseName();
    db.close();
    db = QSqlDatabase();
    QSqlDatabase::removeDatabase(dbname);
    DBList *dblist = new DBList(nullptr, session);
    dblist->show();
    this->close();
}

