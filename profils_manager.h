#ifndef PROFILS_MANAGER_H
#define PROFILS_MANAGER_H

#include <QDialog>
#include "session.h"


/**
 * Classe Controller de la vue ProfilsManager
 */
namespace Ui {
class profils_manager;
}

class profils_manager : public QDialog
{
    Q_OBJECT

public:
    explicit profils_manager(QWidget *parent,
                             Session * session,
                             User selectedUser);
    ~profils_manager();

    void fillTable(const QVector<Profil*> profils);

private slots:

    /**
     * @brief Renvoie vers l'accueil
     */
    void on_accueilButton_clicked();

    /**
    * @brief Quand le bouton deconnexion est clique, on supprime la session et on renvoie à la page de login
    */
    void on_logOutButton_clicked();

    void on_backButton_clicked();

    /**
     * @brief Quand ce boutton est cliqué on crée un nouveau profil (après verifications)
     */
    void on_newButton_clicked();


private:
    Ui::profils_manager *ui;
    Session *session;
    User *user;
};

#endif // PROFILS_MANAGER_H
