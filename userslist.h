#ifndef USERSLIST_H
#define USERSLIST_H

#include <QDialog>
#include "session.h"
#include "QTableWidgetItem"

namespace Ui {

/**
 * Classe controller de la vue UserList
 */

class UsersList;
}

class UsersList : public QDialog
{
    Q_OBJECT

public:
    explicit UsersList(QWidget *parent = nullptr,Session *session = nullptr);
    ~UsersList();

    /**
     * @brief Rempli le tableau avec la liste des utilisateurs
     * @param users QVector<User> : Vecteur contenant les utilisateurs
     */
    void fillTable(const QVector<User> users);

    /**
     * @brief Gere le clic sur un element du tableau
     * @param item  L'element sur lequel on a cliqué
     * @param users Liste des utilisateurs
     */
    void onTableItemClicked(QTableWidgetItem *item, QVector<User> users);

private slots:


    /**
     * @brief Renvoie vers l'accueil
     */
    void on_accueilButton_clicked();

    /**
    * @brief Quand le bouton deconnexion est clique, on supprime la session et on renvoie à la page de login
    */
    void on_logOutButton_clicked();

private:
    Ui::UsersList *ui;
    Session *session;
};

#endif // USERSLIST_H
