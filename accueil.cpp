#include "accueil.h"
#include "ui_accueil.h"

Accueil::Accueil(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Accueil)
{
    ui->setupUi(this);
}

Accueil::Accueil(QWidget *parent, Session *session)
    : QDialog(parent)
    , ui(new Ui::Accueil)
{
    ui->setupUi(this);
    this->session = session;
    ui->label_2->setText(QString::fromStdString(session->getUsedUser()->getId()));
    ui->label_2->repaint();
}



Accueil::~Accueil()
{
    delete ui;
}
