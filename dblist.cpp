#include "dblist.h"
#include "ui_dblist.h"

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
