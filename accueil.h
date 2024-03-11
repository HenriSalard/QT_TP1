#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QDialog>
#include "Session.h"

namespace Ui {
class Accueil;
}

/**
 * @brief Classe Controller de la vue Accueil
 */
class Accueil : public QDialog
{
    Q_OBJECT

    private:
        Ui::Accueil *ui;
        Session *session;

    public:
        explicit Accueil(QWidget *parent = nullptr);


          /**
         * @brief Constructeur de Accueil utilisé en pratique
         * @param parent    Fenetre parent
         * @param session   Pointeur vers session en cours
         */
        explicit Accueil(QWidget *parent = nullptr, Session *session = nullptr);
        ~Accueil();

    private slots:

        /**
         * @brief Selectionne le profil à utiliser
         */
        void on_validateButton_clicked();

        /**
         * @brief Quand le bouton deconnexion est clique, on supprime la session et on renvoie à la page de login
         */
        void on_disconnectButton_clicked();

        /**
         * @brief Lance la fenêtre de liste des utilisateurs, et ferme la fenêtre courrante
         */
        void on_profilsButton_clicked();

        void on_readButton_clicked();
};

#endif // ACCUEIL_H
