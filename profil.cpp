#include "Profil.h"

/**
 * @brief Create a profil with zero right
 */
Profil::Profil(){
    listDroits = QVector<Droits>();
}

/**
 * @brief Return the name of the profil
 * @return name
 */
string Profil::getName(){
    return name;
}

/**
 * @brief Change the profil name
 * @param nameParam the new name
 */
void Profil::setName(string nameParam){

    name = nameParam;

}

/**
 * @brief Return all the rights from the profil
 * @return listDroits
 */
QVector<Droits> Profil::getListDroits(){
    return listDroits;
}

/**
 * @brief add rightd to the profil
 * @param droit the right to be added
 */
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
