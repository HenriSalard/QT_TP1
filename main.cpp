#include "login.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    /*QDomDocument docu;

    QDomElement root = docu.createElement("User");

    docu.appendChild(root);

    for(int i = 0; i < 5; i++)
    {
        QDomElement user = docu.createElement("User");
        user.setAttribute("Password", "password" + QString::number(i));
        user.setAttribute("ID", "User" + QString::number(i));
        root.appendChild(user);
    }
    QFile file("C:/Users/Registered user/Documents/QT_TP1/myXML/myXML.xml");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Open the file for writing failed";
    }
    else
    {
        QTextStream stream(&file);
        stream << docu.toString();
        file.close();
        qDebug() << "Writing is done";
    }*/

    QApplication a(argc, argv);
    Login l;
    l.show();
    return a.exec();
}
