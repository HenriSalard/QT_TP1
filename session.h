#ifndef SESSION_H
#define SESSION_H

#include "user.h"
//#include "profil.h"

/**
 * @brief Instancie la session qui contient l'utilisateur connecté ainsi que le profil utilisé
 */
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
    Profil getUsedProfil() const;
};

#endif // SESSION_H
