#include "gestxml.h"

GestXML::GestXML()
{

}

bool GestXML::FindUserXML(User user){

    bool userFound = false;

    QDomDocument userXML;
    QFile xmlFile("../QT_TP1/myXML/myXML.xml");
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
/**
 * @brief Checks if a user exists in the xml file
 * @param user   The user to search
 * @return userFound  true if the user exists, false otherwise
 */

bool GestXML::UserExistsXML(User user){

    bool userFound = false;

    QDomDocument userXML;
    QFile xmlFile("../QT_TP1/myXML/myXML.xml");
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
                QString readId = node.attribute("ID");

                if(user.getId() == readId.toStdString()){

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
    QFile doc_xml("../QT_TP1/myXML/myXML.xml");
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

    QFile fichier("../QT_TP1/myXML/myXML.xml");
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

unsigned int GestXML::CountUserXML(){

    unsigned int count = 0;

    QDomDocument userXML;
    QFile xmlFile("../QT_TP1/myXML/myXML.xml");
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
            count++;
        }
        node = node.nextSibling().toElement();
    }


    //std::cout<<"Count "<<count;
    return count;

}

QVector<Profil> GestXML::GetUserProfil(string id){

    QVector<Profil> vProfil;

    QDomDocument userXML;
    QFile xmlFile("../QT_TP1/myXML/UserProfil.xml");
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
        if(node.tagName() == "UserProfil"){

            QString idXML = node.attribute("UserId");
            QString name = node.attribute("ProfilName");

            if(idXML.toStdString() == id){

                Profil profil;
                profil.setName(name.toStdString());
                vProfil.append(profil);
            }
        }
        node = node.nextSibling().toElement();
    }
    return vProfil;

}

/**
 * @brief Recupere la liste des utilisateurs depuis le fichier XML
 * @return vUsers QVector contenant les utilisateurs
 */
QVector<User> GestXML::GetAllUsers(){
    QVector<User> vUsers;


    QDomDocument userXML;
    QFile xmlFile("../QT_TP1/myXML/myXML.xml");
    if (!xmlFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Failed to open the file for reading.";
    }
    userXML.setContent(&xmlFile);
    xmlFile.close();

    QDomElement root = userXML.documentElement();
    QDomElement node = root.firstChild().toElement();

    // Parcours des utilisateurs
    while(!node.isNull())
    {

        if(node.tagName() == "User"){
            while(!node.isNull()){
                QString readId = node.attribute("ID");
                QString password = node.attribute("Password");

                // Creation de l'utilisateur et ajout au QVector
                vUsers.append(User(readId.toStdString(),
                                   password.toStdString()));

                node = node.nextSibling().toElement();

            }
        }
        node = node.nextSibling().toElement();
    }
        node = node.nextSibling().toElement();

    return vUsers;
}
