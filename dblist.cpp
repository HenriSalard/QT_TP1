#include "dblist.h"
#include "ui_dblist.h"
#include <QFileDialog>

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

    };

void DBList::fillTable(){
    ui->tableWidget->setColumnCount(1); // Une colonne pour le nom et une colonne pour supprimer

}

void DBList::on_pushButton_clicked(){
    QString fileName = QFileDialog::getOpenFileName(this,
                  tr("Open database"), "..", tr("*.sqlite *.sqlite3 *.db *.db3 *.s3db *.sl3"));

    ui->label->setText(fileName);
}


