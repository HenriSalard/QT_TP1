#include "dbview.h"
#include "qmessagebox.h"
#include "qsqldatabase.h"
#include "session.h"
#include "ui_dbview.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>
#include <QFileDialog>

DbView::DbView(QWidget *parent, Session* session, QString dbname)
    : QDialog(parent)
    , ui(new Ui::DbView)
{
        ui->setupUi(this);
        this->session = session;
        QFileInfo fi(dbname);
        ui->dbnameLabel->setText(fi.fileName());

        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(dbname);
        //db.setDatabaseName("C:/Users/Registered user/Desktop/Hector.SQLite");
        bool ok = db.open();

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

    QSqlQuery query(requete, db);

    /* Execute the query */
    if (!query.exec()) {
        qDebug() << "Error executing query:" ;
        return;
    }

}


void DbView::on_dbTable_cellPressed(int row, int column)
{

    model = new QSqlTableModel(this, db);
    model->setTable(ui->dbTable->selectedItems().at(0)->text());
    model->select();

    ui->tableView->setModel(model);
}

