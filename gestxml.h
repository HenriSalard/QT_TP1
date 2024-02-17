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
    static int SaveUserXML(User user);
};

#endif // GESTXML_H
