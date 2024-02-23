#ifndef GESTXML_H
#define GESTXML_H

#include <QDialog>
#include "user.h"
#include <QMessageBox>
#include <QtXml>

/**
 * @brief Contient les fonctions de lecture-ecriture des fichiers XML
 */
class GestXML
{
public:
    GestXML();


    /**
     * @brief Checks if a user with the right password exists in the xml file
     * @param user   The user to search
     * @return userFound  true if the user exists and the password is correct, false otherwise
     */
    static bool FindUserXML(User user);


     /**
     * @brief Checks if a user exists in the xml file
     * @param user   The user to search
     * @return userFound  true if the user exists, false otherwise
     */
    static bool UserExistsXML(User user);

    /**
     * @brief Add an user to the xml file
     * @param user   The user to add
     * @return error code
     */
    static int SaveUserXML(User user);

    /**
     * @brief Count the number of User in the XML file
     * @return count  number of User
     */
    static unsigned int CountUserXML();
    /**
    * @brief Get all the profiles from a single user in the XML file
    * @param id of the user
    * @return vProfil the vector containing all the user's profiles
    */
    static QVector<Profil> GetUserProfil(string id);

     /**
     * @brief Recupere la liste des utilisateurs depuis le fichier XML
     * @return vUsers QVector contenant les utilisateurs
     */
    static QVector<User> GetAllUsers();

    /**
     * @brief Update all the profiles of a single user in the XML
     * @param user the user to update
     */
    static void ChangeUserProfil(User user);

    /**
    * @brief Add a profile to a single user in the XML
    * @param user that will have the profil
    * @param profil that the user will have
    */
    static void AddUserProfil(User user,Profil profil);

    /**
     * @brief Recupere tous les profils du fichier XML
     * @return tous les profils dans un vecteur
     */
    static QVector<Profil> GetAllProfils();


};

#endif // GESTXML_H
