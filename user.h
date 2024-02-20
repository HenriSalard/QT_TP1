#ifndef USER_H
#define USER_H

#include "Profil.h"
#include <iostream>
using namespace std;

/**
 * @brief Instancie les utilisateurs
 */
class User
{
private:
    string identifiant;
    string password;
    QVector<Profil> listProfils;

public:
    User();

    User(string Id, string password);

    string getId();

    string getPassword();

    QVector<Profil> getListProfils();

    void setListProfils();

    void addProfil(Profil profilToAdd);

    Profil getProfil(string name);

};

#endif // USER_H
