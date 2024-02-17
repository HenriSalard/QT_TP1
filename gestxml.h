#ifndef GESTXML_H
#define GESTXML_H

#include <QDialog>
#include "user.h"
#include <QMessageBox>
#include <QtXml>

class GestXML
{
public:
    GestXML();

    static bool FindUserXML(User user);
    static bool UserExistsXML(User user);
    static int SaveUserXML(User user);
    static unsigned int CountUserXML();
    static QVector<Profil> GetUserProfil(string id);
};

#endif // GESTXML_H
