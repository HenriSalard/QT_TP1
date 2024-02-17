#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QDialog>
#include "Session.h"

namespace Ui {
class Accueil;
}

class Accueil : public QDialog
{
    Q_OBJECT

    private:
        Ui::Accueil *ui;
        Session *session;

    public:
        explicit Accueil(QWidget *parent = nullptr);
        explicit Accueil(QWidget *parent = nullptr, Session *session = nullptr);
        ~Accueil();


};

#endif // ACCUEIL_H
