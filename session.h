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
    Profil *usedProfil;
    bool canRead; // True si l'utilisateur a cliqué sur lire ou ecrire
    bool canWrite; // True si l'utilisateur a cliqué sur ecrire


public:
    Session();
    Session(User *user);



    /**
     * @brief Change the profil of the user
    * @param newUsedProfil
    */
    void setUsedProfil(Profil *newUsedProfil);

    /**
    * @brief Session::getUsedUser
    * @return user of the Session
    */
    User* getUsedUser() const;

    /**
    * @brief Session::getUsedProfil
    * @return the current profil of the User
    */
    Profil* getUsedProfil() const;

    /**
     * @brief Setter de canRead
     * @param can
     */
    void setCanRead(bool can);

    /**
     * @brief Setter de canWrite
     * @param can
     */
    void setCanWrite(bool can);

    /**
     * @brief Getter de canRead
     * @param can
     */
    bool getCanRead();

    /**
     * @brief Getter de canWrite
     * @param can
     */
    bool getCanWrite();

};

#endif // SESSION_H
