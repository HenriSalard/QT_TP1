#include "Profil.h"

/**
 * @brief Create a profil with zero right and zero database
 */
Profil::Profil(){
    listDroits = QVector<Droits>();
    listDB = QVector<QString>();
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

QVector<QString> Profil::getListDB(){
    return listDB;
}

void Profil::setListDB(QVector<QString> pathList){
    this->listDB = pathList;
}


void Profil::addListDB(QString newDB){
    listDB.append(newDB);
}


/**
     * @brief Remove a database from listDB
     * @param dbToRemove : int The index of the database to remove in the list
     */
void Profil::removeDB(int dbToRemove){
    listDB.remove(dbToRemove);
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
