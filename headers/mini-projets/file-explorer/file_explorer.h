//
// Created by thierry on 21/05/2026.
//

#ifndef QT_TUTO_FILE_EXPLORER_H
#define QT_TUTO_FILE_EXPLORER_H

#include <QMainWindow>
#include <QTreeView>
#include <QFileSystemModel>
#include <QLabel>
#include <QPushButton>
#include <QDockWidget>
#include <QVBoxLayout>
#include <QAction>
#include <QFormLayout>
#include <QMenu>

class FileExplorer : public QMainWindow {

    Q_OBJECT

    //Modèle
    QFileSystemModel* m_model {nullptr};

    // Vue
    QTreeView* m_treeView {nullptr};

    // Dock explorateur
    QDockWidget* m_dockTree {nullptr};

    // Zone centrale - infos fichier
    QWidget* m_central {nullptr};
    QVBoxLayout* m_mainLayout {nullptr};
    QLabel* m_lblNom{nullptr};
    QLabel* m_lblChemin{nullptr};
    QLabel* m_lblType {nullptr};
    QLabel* m_lblTaille {nullptr};
    QLabel* m_lblDate {nullptr};
    QPushButton* m_btnOuvrir {nullptr};
    QPushButton* m_btnCopier {nullptr};

    QLabel* m_titreSection {nullptr};
    QFormLayout* m_form {nullptr};
    QFrame* m_sep {nullptr};

    QHBoxLayout* m_btnLayout {nullptr};


    // Menu
    QMenu* m_menuFichier {nullptr};
    QMenu* m_menuVue {nullptr};

    // Toolbar
    QToolBar* m_toolbar {nullptr};
    QAction* m_actOuvrir {nullptr};
    QAction* m_actMontrer {nullptr};


    // Chemin courant
    QString m_cheminCourant;

    void creerModele();
    void creerActions();
    void creerMenus();
    void creerToolbar();
    void creerDockExplorateur();
    void creerZoneCentrale();
    void connecter();

    void ouvrirDossier();
    void mettreAJourInfos(const QModelIndex& index);
    static QString formaterTaille(qint64 octets);

    public:
        explicit FileExplorer(QWidget* parent = nullptr);

};


#endif //QT_TUTO_FILE_EXPLORER_H
