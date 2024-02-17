#include "Profil.h"


Profil::Profil(){
    listDroits = QVector<Droits>();
}

string Profil::getName(){
    return name;
}

void Profil::setName(string nameParam){

    name = nameParam;

}
