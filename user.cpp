#include "user.h"
#include "gestxml.h"

User::User() {

    identifiant = nullptr;
    password = nullptr;
    listProfils = QVector<Profil*>();
    Profil* profil = new Profil();
    listProfils.append(profil);
    listProfils[0]->setName("BasicProfil");
    listProfils[0]->addDroit(Droits::Read);
}

User::User(string s1, string s2) {
    identifiant = s1;
    password = s2;
    listProfils = QVector<Profil*>();
    Profil* profil = new Profil();
    listProfils.append(profil);
    listProfils[0]->setName("BasicProfil");
    listProfils[0]->addDroit(Droits::Read);
}

string User::getId(){
    return identifiant;
}

string User::getPassword(){
    return password;
}

QVector<Profil*> User::getListProfils(){
    return listProfils;
}

void User::setListProfils(){
    listProfils = GestXML::GetUserProfil(identifiant);
}

void User::addProfil(Profil* profilToAdd){
    listProfils.append(profilToAdd);
}

Profil* User::getProfil(string name){
    for(Profil* profil : listProfils){
        if(profil->getName() == name){
            return profil;
        }
    }
    return NULL;
}
