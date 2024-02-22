#include "login.h"
#include "gestxml.h"
#include "newuser.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    if (GestXML::CountUserXML() <= 1){
        newUser* nu = new newUser(nullptr, true);
        nu->show();
    }
    else{
        Login * l = new Login(nullptr);
        l->show();
    }
    return a.exec();
}
