#ifndef DBLIST_H
#define DBLIST_H

#include <QDialog>
#include "qtablewidget.h"
#include "session.h"

namespace Ui {
class DBList;
}

/**
 * @brief Fenetre presentant la liste des bases de données enregistrées par un profil
 * Permet d'ajouter et de supprimer des bases
 */
class DBList : public QDialog
{
    Q_OBJECT

public:
    explicit DBList(QWidget *parent = nullptr);
    explicit DBList(QWidget *parent = nullptr,  Session *session = nullptr);

    /**
     * @brief Remplit la table avec la liste de bases de données
     * @param pathes : QVector<QString> : La liste des chemins vers les bases de données
     */
    void fillTable(const QVector<QString> pathes);
    ~DBList();

    /**
     * @brief Gere le clic sur un element du tableau
     * @param item  L'element sur lequel on a cliqué
     */
    void onTableItemClicked(QTableWidgetItem *item);


private slots:

    /**
     * @brief Gere le clic sur le bouton d'ajout de base
     * Ouvre un QFileDialog qui permet d'ajouter un fichier SQLite
     */
    void on_pushButton_clicked();

    /**
     * @brief Clic sur le bouton retour
     */
    void on_pushButton_2_clicked();


    /**
     * @brief Gere le clic sur un element du tableau (ouverture d'une base ou "supprimer")
     * @param item : QTableWidgetItem : L'item sur lequel on clique
     */
    void on_tableWidget_itemClicked(QTableWidgetItem *item);

private:
    Ui::DBList *ui;
    Session *session;
    QVector<QString> vPathes; // Les chemins des fichiers bdd
};

#endif // DBLIST_H
