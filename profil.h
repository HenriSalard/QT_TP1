#ifndef PROFIL_H
#define PROFIL_H

#include <QVector>
#include "Droits.h"

using namespace std;

/**
 * @brief Classe qui instancie les differents profils
 */
class Profil {
private:
    string name;
    QVector<Droits> listDroits ;
    QVector<QString> listDB;

public:

    /**
    * @brief Create a profil with zero right
     */
    Profil();

    /**
    * @brief Return the name of the profil
    * @return name
    */
    string getName();

    /**
    * @brief Change the profil name
    * @param nameParam the new name
    */
    void setName(string name);

    /**
    * @brief Return all the rights from the profil
    * @return listDroits
    */
    QVector<Droits> getListDroits();

    QVector<QString> getListDB();



    void setListDB(QVector<QString> pathList);


    /**
     * @brief add rightd to the profil
    * @param droit the right to be added
    */

    void addDroit(Droits droit);

    /**
    * @brief Profil::hasRight Dit si le profil possede le droit renseigné
    * @param droit
    * @return true si le profil a le droit, false sinon
    */
    bool hasRight(Droits droit);
};

#endif // PROFIL_H
