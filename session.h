#ifndef SESSION_H
#define SESSION_H

#include "user.h"
//#include "profil.h"

class Session
{
private:
    User *usedUser;
    Profil usedProfil;


public:
    Session();
    Session(User *user);



    void setUsedProfil(const Profil &newUsedProfil);
    User* getUsedUser() const;
};

#endif // SESSION_H
