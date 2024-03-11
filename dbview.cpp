#include "dbview.h"
#include "session.h"
#include "ui_dbview.h"

DbView::DbView(QWidget *parent, Session* session)
    : QDialog(parent)
    , ui(new Ui::DbView)
{
        ui->setupUi(this);
        this->session = session;

}

DbView::~DbView()
{
    delete ui;
}
