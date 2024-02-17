#include "user.h"
#include "gestxml.h"

User::User() {

    identifiant = nullptr;
    password = nullptr;
    listProfils = QVector<Profil>();
}

User::User(string s1, string s2) {
    identifiant = s1;
    password = s2;
    listProfils = QVector<Profil>();
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
