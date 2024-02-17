#include "gestxml.h"

GestXML::GestXML()
{

}

bool GestXML::FindUserXML(User user){

    bool userFound = false;

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

    while(node.isNull() == false)
    {

        if(node.tagName() == "User"){
            while(!node.isNull()){
                QString id = node.attribute("ID");
                QString password = node.attribute("Password");

                if(id.toStdString() == user.getId() &&
                    password.toStdString() == user.getPassword()){

                    userFound = true;

                }
                node = node.nextSibling().toElement();
            }
        }
        node = node.nextSibling().toElement();
    }

    return userFound;

}

int GestXML::SaveUserXML(User user){


    QDomDocument dom("myXML");
    QFile doc_xml("C:/Users/Registered user/Documents/QT_TP1/myXML/myXML.xml");
    if(!doc_xml.open(QIODevice::ReadOnly))
    {
        doc_xml.close();
        return 1;
    }
    if(!dom.setContent(&doc_xml))
    {
        doc_xml.close();
        return 1;
    }
    doc_xml.close();

    QDomElement docElem = dom.documentElement();

    QDomElement write_elem = dom.createElement("User");

    write_elem.setAttribute("ID", QString::fromStdString(user.getId()));
    write_elem.setAttribute("Password", QString::fromStdString(user.getPassword()));

    docElem.appendChild(write_elem);

    QString write_doc = dom.toString();

    QFile fichier("C:/Users/Registered user/Documents/QT_TP1/myXML/myXML.xml");
    if(!fichier.open(QIODevice::WriteOnly))
    {
        fichier.close();
        return 2;
    }

    QTextStream stream(&fichier);

    stream << write_doc;

    fichier.close();

    return 0;

}
