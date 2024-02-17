#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newuser.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    unNouvelUtilisateur->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    unNouvelUtilisateur = new newUser(this,true);
    unNouvelUtilisateur->show();
}
