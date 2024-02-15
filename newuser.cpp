#include "newuser.h"
#include "ui_newuser.h"
#include "user.h"
#include "login.h"
#include "Accueil.h"
#include "Session.h"

using namespace std;

newUser::newUser(QWidget *parent, bool isFirstConnection )
    : QDialog(parent)
    , ui(new Ui::newUser)
{
    ui->setupUi(this);
    ui->backButton->setVisible(!isFirstConnection);
}


newUser::~newUser()
{
    delete ui;
}

void newUser::savetoXML(User user){

    QDomDocument userXML;
    QFile xmlFile("C:/Users/Registered user/Documents/QT_TP1/myXML/myXML.xml");
    if (!xmlFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Failed to open the file for reading.";
    }
    userXML.setContent(&xmlFile);
    xmlFile.close();

    QDomElement root = userXML.documentElement();
    QDomElement node = root.firstChild().toElement();

    QVector<User> vUser;

    while(node.isNull() == false)
    {

        if(node.tagName() == "User"){
            while(!node.isNull()){
                qDebug() << node.tagName();
                QString id = node.attribute("ID");
                QString password = node.attribute("Password");

                User user = User(id.toStdString(),password.toStdString());

                vUser.append(user);

                node = node.nextSibling().toElement();
            }
        }
        node = node.nextSibling().toElement();
    }

    bool find = false;

    for(User us : vUser){
        if(user.getId()==us.getId()){
            QMessageBox::warning(this,"Create", "This user aready exists!");
            find = true;
        }
    }
    if(!find) saveUserXML(user);

}

void newUser::saveUserXML(User user){

    QFile file("C:/Users/Registered user/Documents/QT_TP1/myXML/myXML.xml");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Open the file for writing failed";
    }
    else
    {
        //Add user to xml
    }

}


void newUser::on_pushButton_clicked(){
    QString newPassword = ui->passwordTextField->text();
    QString newId = ui->idTextField->text();

    if(newPassword.isEmpty() || newId.isEmpty()){
        ui->labelError->setText("Erreur, veuillez remplir tous les champs");
    }
    else{
        User *newUser = new User(newId.toStdString(), newPassword.toStdString());
        Session *session = new Session(newUser);

        Accueil* accueil = new Accueil(this, session);
        accueil->show();
        this->setVisible(false);


    }

    // TODO Serialisation de l'utilisateur


}



void newUser::on_backButton_clicked()
{
    Login* nu = new Login();
    nu->show();
    this->setVisible(false);
}

