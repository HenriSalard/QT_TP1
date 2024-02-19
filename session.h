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



    /**
     * @brief Change the profil of the user
    * @param newUsedProfil
    */
    void setUsedProfil(const Profil &newUsedProfil);

    /**
    * @brief Session::getUsedUser
    * @return user of the Session
    */
    User* getUsedUser() const;

    /**
    * @brief Session::getUsedProfil
    * @return the current profil of the User
    */
    Profil getUsedProfil() const;
};

#endif // SESSION_H
