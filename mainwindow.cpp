#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newuser.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    unNouvelUtilisateur = new newUser();

    unNouvelUtilisateur->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    unNouvelUtilisateur->show();
}
