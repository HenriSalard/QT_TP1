#ifndef USER_H
#define USER_H

#include "Profil.h"
#include <iostream>
using namespace std;


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

};

#endif // USER_H