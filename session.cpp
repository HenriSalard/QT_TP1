#include "session.h"

/**
 * @brief Change the profil of the user
 * @param newUsedProfil
 */
void Session::setUsedProfil(Profil *newUsedProfil)
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

Session::Session() {
    canRead = false;
    canRead = true;
}

Session::Session(User *user){
    usedUser = user;
    canRead = false;
    canWrite = false;

}

/**
 * @brief Session::getUsedProfil
 * @return the current profil of the User
 */
Profil* Session::getUsedProfil() const{
    return usedProfil;
}

void Session::setCanRead(bool can){
    canRead = can;
}

void Session::setCanWrite(bool can){
    canWrite = can;
}

bool Session::getCanRead(){
    return canRead;
}

bool Session::getCanWrite(){
    return canWrite;
}
