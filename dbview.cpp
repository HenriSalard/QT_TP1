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

        ui->tableView->setEditTriggers(QTableView::NoEditTriggers);

        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(dbname);
        if(!session->getCanWrite()){
            db.setConnectOptions("QSQLITE_OPEN_READONLY");
        }
        //db.setDatabaseName("C:/Users/Registered user/Desktop/Hector.SQLite");
        db.open();

        if (!db.open()) {
            QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
                                  QObject::tr("Unable to establish a database connection.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
            return;
        }



        fillTable();
}

DbView::~DbView()
{
    QString connectionName = db.connectionName();

    db.close();
    db = QSqlDatabase();
    QSqlDatabase::removeDatabase(connectionName);
    delete ui;
}

void DbView::fillTable(){

    //TODO Recuperer la table dbname dans sqlite
    QStringList ListTable = db.tables(QSql::Tables);

    for(QString table : ListTable){
        if(table.startsWith("sqlite_")){
            ListTable.removeOne(table);
        }
    }


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
    QString requete = ui->textEdit->toPlainText();

    QSqlQuery query(db);

    QElapsedTimer timer;
    timer.start();

    /* Execute the query */
    if (!query.exec(requete)) {

        QMessageBox::critical(nullptr, QObject::tr("Requete érronée : ") + query.lastError().nativeErrorCode(),
                              "Erreur : \n" + query.lastError().databaseText() +
                              "\n" + query.lastError().driverText(), QMessageBox::Ok);
        return;
    }

    model = new QSqlTableModel();
    model->setQuery(std::move(query));
    model->select();

    ui->tableView->setModel(model);

    ui->label->setText("Temps d'éxécution : " + QString::number(timer.elapsed()) + "ms");


}


void DbView::on_dbTable_cellPressed(int row, int column)
{

    qDebug() << row << " : " << column;

    model = new QSqlTableModel(this, db);
    model->setTable(ui->dbTable->selectedItems().at(0)->text());
    model->select();

    ui->tableView->setModel(model);
}


void DbView::on_pushButton_2_clicked()
{
    QString dbname = db.databaseName();
    db.close();
    QSqlDatabase::removeDatabase(dbname);
    DBList *dblist = new DBList(nullptr, session);
    dblist->show();
    this->close();
}

