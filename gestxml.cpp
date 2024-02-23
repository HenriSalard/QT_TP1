#include "gestxml.h"

GestXML::GestXML()
{

}

/**
* @brief Checks if a user with the right password exists in the xml file
* @param user   The user to search
* @return userFound  true if the user exists and the password is correct, false otherwise
*/
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

/**
* @brief Add an user to the xml file
* @param user   The user to add
* @return error code
*/
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

/**
* @brief Count the number of User in the XML file
* @return count  number of User
*/
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

/**
 * @brief Get all the profiles from a single user in the XML file
 * @param id of the user
 * @return vProfil the vector containing all the user's profiles
 */
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

            QDomElement nodeChild = node.firstChildElement("Profil");

            QString Read = nodeChild.attribute("Read");
            QString Write = nodeChild.attribute("Write");
            QString Create_user = nodeChild.attribute("Create_user");
            QString Manage_users = nodeChild.attribute("Manage_users");

            if(idXML.toStdString() == id){

                Profil profil;
                profil.setName(name.toStdString());

                if(Read.toStdString() == "true"){
                    profil.addDroit(Droits::Read);
                }
                if(Write.toStdString() == "true"){
                    profil.addDroit(Droits::Write);
                }
                /*if(Create_user.toStdString() == "true"){
                    profil.addDroit(Droits::Create_profils);
                }*/
                if(Manage_users.toStdString() == "true"){
                    profil.addDroit(Droits::Manage_profils);
                }

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
                User user = User(readId.toStdString(),
                                 password.toStdString());
                user.setListProfils();
                vUsers.append(user);

                node = node.nextSibling().toElement();

            }
        }
        node = node.nextSibling().toElement();
    }
    node = node.nextSibling().toElement();

    return vUsers;
}

/**
* @brief Update all the profiles of a single user in the XML
* @param user the user to update
*/
void GestXML::ChangeUserProfil(User user){

    QDomDocument userProfilXML;
    QFile xmlFile("../QT_TP1/myXML/UserProfil.xml");
    if (!xmlFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Failed to open the file for reading.";
    }
    userProfilXML.setContent(&xmlFile);
    xmlFile.close();

    QDomElement root = userProfilXML.documentElement();
    QDomNodeList nodes = userProfilXML.elementsByTagName("UserProfil");

    // Parcours des userProfil
    for(int i = 0; i< nodes.count(); i++)
    {
        QDomNode node = nodes.item(i);

        if(node.nodeType() == QDomNode::ElementNode)
        {
            QDomElement element = node.toElement();

            QString idUser = element.attribute("UserId");
            QString nameProfil = element.attribute("ProfilName");


            //Si c'est le bon utilisateur
            if(idUser.toStdString() == user.getId()){

                //On récupère le bon profil
                Profil profil = user.getProfil(nameProfil.toStdString());

                //On crée un nouveau noeud
                QDomElement newNodeTag = userProfilXML.createElement(QString("UserProfil"));
                newNodeTag.setAttribute("UserId", QString::fromStdString(user.getId()));
                newNodeTag.setAttribute("ProfilName", QString::fromStdString(profil.getName()));

                //On crée le fils du nouveau noeud
                QDomElement newProfilNode = userProfilXML.createElement(QString("Profil"));

                if(profil.hasRight(Droits::Read)){
                    newProfilNode.setAttribute("Read", QString("true"));
                }
                else{
                    newProfilNode.setAttribute("Read", QString("false"));
                }

                if(profil.hasRight(Droits::Write)){
                    newProfilNode.setAttribute("Write", QString("true"));
                }
                else{
                    newProfilNode.setAttribute("Write", QString("false"));
                }

                /*if(profil.hasRight(Droits::Create_profils)){
                    newProfilNode.setAttribute("Create_user", QString("true"));
                }
                else{
                    newProfilNode.setAttribute("Create_user", QString("false"));
                }*/

                if(profil.hasRight(Droits::Manage_profils)){
                    newProfilNode.setAttribute("Manage_users", QString("true"));
                }
                else{
                    newProfilNode.setAttribute("Manage_users", QString("false"));
                }

                //On attribue le profil au noeud userProfil
                newNodeTag.appendChild(newProfilNode);

                //On remplace l'ancien noeud
                root.replaceChild(newNodeTag,node);
            }

        }

    }

    //On réécrit le XML
    QString write_doc = userProfilXML.toString();

    QFile fichier("../QT_TP1/myXML/USerProfil.xml");
    if(!fichier.open(QIODevice::WriteOnly))
    {
        fichier.close();
        qDebug()<<"Erreur d'ouverture de fichier";
    }

    QTextStream stream(&fichier);

    stream << write_doc;

    fichier.close();

    qDebug()<<"Profils modifiés";

}

/**
 * @brief Add a profile to a single user in the XML
 * @param user that will have the profil
 * @param profil that the user will have
 */
void GestXML::AddUserProfil(User user,Profil profil){

    QDomDocument dom("myXML");
    QFile doc_xml("../QT_TP1/myXML/UserProfil.xml");
    if(!doc_xml.open(QIODevice::ReadOnly))
    {
        doc_xml.close();
        return;
    }
    if(!dom.setContent(&doc_xml))
    {
        doc_xml.close();
        return;
    }
    doc_xml.close();

    QDomElement docElem = dom.documentElement();

    QDomElement newNodeTag = dom.createElement(QString("UserProfil"));
    newNodeTag.setAttribute("UserId", QString::fromStdString(user.getId()));
    newNodeTag.setAttribute("ProfilName", QString::fromStdString(profil.getName()));

    QDomElement newProfilNode = dom.createElement(QString("Profil"));

    if(profil.hasRight(Droits::Read)){
        newProfilNode.setAttribute("Read", QString("true"));
    }
    else{
        newProfilNode.setAttribute("Read", QString("false"));
    }

    if(profil.hasRight(Droits::Write)){
        newProfilNode.setAttribute("Write", QString("true"));
    }
    else{
        newProfilNode.setAttribute("Write", QString("false"));
    }

    /*if(profil.hasRight(Droits::Create_profils)){
        newProfilNode.setAttribute("Create_user", QString("true"));
    }
    else{
        newProfilNode.setAttribute("Create_user", QString("false"));
    }*/

    if(profil.hasRight(Droits::Manage_profils)){
        newProfilNode.setAttribute("Manage_users", QString("true"));
    }
    else{
        newProfilNode.setAttribute("Manage_users", QString("false"));
    }

    //On attribue le profil au noeud userProfil
    newNodeTag.appendChild(newProfilNode);

    docElem.appendChild(newNodeTag);

    QString write_doc = dom.toString();

    QFile fichier("../QT_TP1/myXML/UserProfil.xml");
    if(!fichier.open(QIODevice::WriteOnly))
    {
        fichier.close();
        return;
    }

    QTextStream stream(&fichier);

    stream << write_doc;

    fichier.close();

    return;

}

/**
* @brief Recupere tous les profils du fichier XML
* @return tous les profils dans un vecteur
*/
QVector<Profil> GestXML::GetAllProfils(){

    qDebug()<<"Test";

    return QVector<Profil>();

}
