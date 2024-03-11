#include "dbview.h"
#include "ui_dbview.h"

DbView::DbView(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DbView)
{
    ui->setupUi(this);
}

DbView::~DbView()
{
    delete ui;
}
