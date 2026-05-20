//
// Created by thierry on 20/05/2026.
//

#pragma once
#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QLabel>
#include <QToolBar>
#include <QVBoxLayout>


class MenuExplorer : public QMainWindow {

    Q_OBJECT

    // Zone centrale
    QWidget* m_central {nullptr};
    QVBoxLayout* m_mainLayout {nullptr};
    QLabel* m_displayLabel {nullptr};

    // Actions - fichier
    QAction* m_actNouveau {nullptr};
    QAction* m_actOuvrir {nullptr};
    QAction* m_actEnregistrer {nullptr};
    QAction* m_actExportTxt {nullptr};
    QAction* m_actExportMd {nullptr};
    QAction* m_actExportHtml {nullptr};
    QAction* m_actQuitter {nullptr};


    // Actions - Edition
    QAction* m_actAnnuler {nullptr};
    QAction* m_actRetablir {nullptr};
    QAction* m_actCouper {nullptr};
    QAction* m_actCopier {nullptr};
    QAction* m_actColler {nullptr};
    QAction* m_actToutSelect {nullptr};

    // Actions Vue
    QAction* m_actToggleToolbar {nullptr};
    QAction* m_actToggleStatusBar {nullptr};
    QAction* m_actZoomPlus {nullptr};
    QAction* m_actZoomMoins {nullptr};
    QAction* m_actZoomReset {nullptr};


    // Actions - Outils
    QAction* m_actThemeClair {nullptr};
    QAction* m_actThemeSombre {nullptr};
    QActionGroup* m_groupTheme {nullptr};

    // Actions - aid
    QAction* m_actAPropos {nullptr};
    QAction* m_actAProposQt {nullptr};


    // Toolbar
    QToolBar* m_toolbar {nullptr};


    // Menu
    QMenu* m_menuFichier {nullptr};
    QMenu* m_sousMenuExport {nullptr};
    QMenu* m_menuEditor {nullptr};
    QMenu* m_menuVue {nullptr};
    QMenu* m_menuOutils {nullptr};
    QMenu* m_sousMenuTheme {nullptr};
    QMenu* m_menuAide {nullptr};

    // Etat
    int m_zoom {100};


    private:
        void creerActions();
        void creerMenus();
        void creerToolbar();
        void creerZoneCentrale();
        void connecterActions();

        void afficherAction(const QString& nom) const;
        void appliquerZoom() const;


    public:
        explicit  MenuExplorer(QWidget* parent = nullptr);
};
