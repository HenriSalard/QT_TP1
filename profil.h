#ifndef PROFIL_H
#define PROFIL_H

#include <QVector>
#include "Droits.h"

using namespace std;

class Profil {
private:
    string name;
    QVector<Droits> listDroits ;

public:
    Profil();
    string getName();
    void setName(string name);
    QVector<Droits> getListDroits();
    void addDroit(Droits droit);
    bool hasRight(Droits droit);
};

#endif // PROFIL_H
