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
};

#endif // PROFIL_H
