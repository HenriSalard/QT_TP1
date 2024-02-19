#ifndef PROFILS_MANAGER_H
#define PROFILS_MANAGER_H

#include <QDialog>
#include "session.h"

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

    void fillTable(const QVector<Profil> profils);

private slots:
    void on_accueilButton_clicked();
    void on_logOutButton_clicked();

    void on_backButton_clicked();

private:
    Ui::profils_manager *ui;
    Session *session;
};

#endif // PROFILS_MANAGER_H
