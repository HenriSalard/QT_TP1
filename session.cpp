#include "session.h"

void Session::setUsedProfil(const Profil &newUsedProfil)
{
    usedProfil = newUsedProfil;
}

User* Session::getUsedUser() const
{
    return usedUser;
}

Session::Session() {}

Session::Session(User *user){
    usedUser = user;
}


Profil Session::getUsedProfil() const{
    return usedProfil;
}
