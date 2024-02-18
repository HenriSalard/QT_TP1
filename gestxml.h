#ifndef GESTXML_H
#define GESTXML_H

#include <QDialog>
#include "user.h"
#include <QMessageBox>
#include <QtXml>

class GestXML
{
public:
    GestXML();


    static bool FindUserXML(User user);


     /**
     * @brief Checks if a user exists in the xml file
     * @param user   The user to search
     * @return userFound  true if the user exists, false otherwise
     */

    static bool UserExistsXML(User user);
    static int SaveUserXML(User user);
    static unsigned int CountUserXML();
    static QVector<Profil> GetUserProfil(string id);



     /**
     * @brief Recupere la liste des utilisateurs depuis le fichier XML
     * @return vUsers QVector contenant les utilisateurs
     */
    static QVector<User> GetAllUsers();


};

#endif // GESTXML_H
