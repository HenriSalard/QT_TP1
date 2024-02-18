#include "user.h"
#include "gestxml.h"

User::User() {

    identifiant = nullptr;
    password = nullptr;
    listProfils = QVector<Profil>();
    listProfils.append(Profil());
    listProfils[0].setName("base");
    listProfils[0].addDroit(Droits::Read);
}

User::User(string s1, string s2) {
    identifiant = s1;
    password = s2;
    listProfils = QVector<Profil>();
    listProfils.append(Profil());
    listProfils[0].setName("base");
    listProfils[0].addDroit(Droits::Manage_profils); // juste le temps des tests après on remplacera par read
}

string User::getId(){
    return identifiant;
}

string User::getPassword(){
    return password;
}

QVector<Profil> User::getListProfils(){
    return listProfils;
}

void User::setListProfils(){
    listProfils = GestXML::GetUserProfil(identifiant);
}

void User::addProfil(Profil profilToAdd){
    listProfils.append(profilToAdd);
}
