#include "session.h"

/**
 * @brief Change the profil of the user
 * @param newUsedProfil
 */
void Session::setUsedProfil(const Profil &newUsedProfil)
{
    usedProfil = newUsedProfil;
}

/**
 * @brief Session::getUsedUser
 * @return user of the Session
 */
User* Session::getUsedUser() const
{
    return usedUser;
}

Session::Session() {}

Session::Session(User *user){
    usedUser = user;
}

/**
 * @brief Session::getUsedProfil
 * @return the current profil of the User
 */
Profil Session::getUsedProfil() const{
    return usedProfil;
}
