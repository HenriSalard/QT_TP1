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

QVector<Droits> Profil::getListDroits(){
    return listDroits;
}

void Profil::addDroit(Droits droit){
    listDroits.append(droit);
}

/**
 * @brief Profil::hasRight Dit si le profil possede le droit renseigné
 * @param droit
 * @return true si le profil a le droit, false sinon
 */
bool Profil::hasRight(Droits droit){
    return listDroits.contains(droit);
}
