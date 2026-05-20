//
// Created by thierry on 20/05/2026.
//

#include "../../../headers/mini-projets/menu-explorer/menu_explorer.h"
#include <QApplication>
#include <QMenuBar>
#include <QStatusBar>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QActionGroup>

MenuExplorer::MenuExplorer(QWidget *parent) : QMainWindow(parent) {
    setWindowFilePath("Explorateur de menu");
    resize(800, 500);


    creerActions();
    creerMenus();
    creerToolbar();
    creerZoneCentrale();
    connecterActions();
    statusBar()->showMessage("Pret");
}



// Création de toutes les actions indépendamment des menus
void MenuExplorer::creerActions() {

    // Fichier
    m_actNouveau = new QAction(QIcon(":/icons/new-file.png"), "Nouveau", this);
    m_actNouveau->setShortcut(QKeySequence::New);
    m_actNouveau->setStatusTip("Créer un nouveau fichier");

    m_actOuvrir = new QAction(QIcon(":/icons/open-file.png"), "Ouvrir...", this);
    m_actOuvrir->setShortcut(QKeySequence::Open);
    m_actOuvrir->setStatusTip("Ouvrir un fichier existant");

    m_actEnregistrer = new QAction(QIcon(":icons/save.png"), "Enregistrer", this);
    m_actEnregistrer->setShortcut(QKeySequence::Save);
    m_actEnregistrer->setStatusTip("Enregistrer le fichier courant");
    m_actEnregistrer->setEnabled(false);


    //Action du sous menu Exporter
    m_actExportTxt = new QAction("Texte brut (.txt)", this);
    m_actExportMd = new QAction("Markdown (.md)", this);
    m_actExportHtml = new QAction("Html (.html)", this);

    m_actQuitter = new QAction("Quitter", this);
    m_actQuitter->setShortcut(QKeySequence::Quit);
    m_actQuitter->setStatusTip("Quitter l'application");
    m_actQuitter->setMenuRole(QAction::QuitRole);


    // Edition
    m_actAnnuler = new QAction(QIcon(":icons/undo.png"),"Annuler", this);
    m_actAnnuler->setShortcut(QKeySequence::Undo);
    m_actAnnuler->setEnabled(false);

    m_actRetablir = new QAction(QIcon(":icons/redo.png"), "Rétablir", this);
    m_actRetablir->setShortcut(QKeySequence::Redo);
    m_actRetablir->setEnabled(false);

    m_actCouper = new QAction(QIcon(":icons/cut.png"), "Couper", this);
    m_actCouper->setShortcut(QKeySequence::Cut);

    m_actCopier = new QAction(QIcon(":icons/copy.png"), "Copier", this);
    m_actCopier->setShortcut(QKeySequence::Copy);

    m_actColler = new QAction(QIcon(":icons/paste.png"), "Coller", this);
    m_actColler->setShortcut(QKeySequence::Paste);

    m_actToutSelect = new QAction("Tout sélectionner", this);
    m_actToutSelect->setShortcut(QKeySequence::SelectAll);


    // Vue
    m_actToggleToolbar = new QAction( "Barre d'outils", this);
    m_actToggleToolbar->setCheckable(true);
    m_actToggleToolbar->setChecked(true);
    m_actToggleToolbar->setShortcut(QKeySequence("Ctrl+Shift+T"));

    m_actToggleStatusBar = new QAction("Barre de statut", this);
    m_actToggleStatusBar->setCheckable(true);
    m_actToggleStatusBar->setChecked(true);

    m_actZoomPlus = new QAction("Zoom +", this);
    m_actZoomPlus->setShortcut(QKeySequence::ZoomIn);

    m_actZoomMoins = new QAction("Zoom -", this);
    m_actZoomMoins->setShortcut(QKeySequence::ZoomOut);

    m_actZoomReset = new QAction("Zoom normal (100%)", this);
    m_actZoomReset->setShortcut(QKeySequence("Ctrl+0"));

    // Outils -Theme (actions exclusives entre elles)
    m_actThemeClair   = new QAction("Clair",  this);
    m_actThemeSombre  = new QAction("Sombre", this);
    m_actThemeClair->setCheckable(true);
    m_actThemeSombre->setCheckable(true);
    m_actThemeClair->setChecked(true);

    // QActionGroup = une seule action cochée à la fois dans le groupe
    m_groupTheme = new QActionGroup(this);
    m_groupTheme->addAction(m_actThemeClair);
    m_groupTheme->addAction(m_actThemeSombre);
    m_groupTheme->setExclusive(true);


    // Aide
    m_actAPropos = new QAction("À Propos de MenuExplorer...", this);
    m_actAPropos->setMenuRole(QAction::AboutRole);

    m_actAProposQt = new QAction("À propos de Qt...", this);
    m_actAProposQt->setMenuRole(QAction::AboutQtRole);
}


// Construction des menus avec les actions existantes
void MenuExplorer::creerMenus() {

    // Menu Fichier
    m_menuFichier = menuBar()->addMenu("&Fichier");
    m_menuFichier->addAction(m_actNouveau);
    m_menuFichier->addAction(m_actOuvrir);
    m_menuFichier->addSeparator();
    m_menuFichier->addAction(m_actEnregistrer);

    // sous menu "enregistrer sous"
    m_sousMenuExport = m_menuFichier->addMenu("Enregistrer sous...");
    m_sousMenuExport->addAction(m_actExportTxt);
    m_sousMenuExport->addAction(m_actExportMd);
    m_sousMenuExport->addAction(m_actExportHtml);

    m_menuFichier->addSeparator();
    m_menuFichier->addAction(m_actQuitter);



    // Menu Édition
    m_menuEditor = menuBar()->addMenu("&Edition");

    m_menuEditor->addAction(m_actAnnuler);
    m_menuEditor->addAction(m_actRetablir);
    m_menuEditor->addSeparator();
    m_menuEditor->addAction(m_actCouper);
    m_menuEditor->addAction(m_actCopier);
    m_menuEditor->addAction(m_actColler);
    m_menuEditor->addSeparator();
    m_menuEditor->addAction(m_actToutSelect);


    // Menu Vue
    m_menuVue = menuBar()->addMenu("&Vue");

    m_menuVue->addAction(m_actToggleToolbar);
    m_menuVue->addAction(m_actToggleStatusBar);
    m_menuVue->addSeparator();
    m_menuVue->addAction(m_actZoomPlus);
    m_menuVue->addAction(m_actZoomMoins);
    m_menuVue->addAction(m_actZoomReset);


    // Menu Outils
    m_menuOutils = menuBar()->addMenu("&Outils");

    // sous-meu Thème
    m_sousMenuTheme = m_menuOutils->addMenu("Theme");
    m_sousMenuTheme->addAction(m_actThemeClair);
    m_sousMenuTheme->addAction(m_actThemeSombre);

    // Menu aide
    m_menuAide = m_menuVue->addMenu("&Aide");
    m_menuAide->addAction(m_actAPropos);
    m_menuAide->addAction(m_actAProposQt);
}



// Toolbar avec les memes actions
void MenuExplorer::creerToolbar() {
    m_toolbar = addToolBar("Principal");
    m_toolbar->setMovable(false);
    m_toolbar->setIconSize(QSize(20,20));

    // Les memes actions
    m_toolbar->addAction(m_actNouveau);
    m_toolbar->addAction(m_actOuvrir);
    m_toolbar->addAction(m_actEnregistrer);
    m_toolbar->addSeparator();
    m_toolbar->addAction(m_actAnnuler);
    m_toolbar->addAction(m_actRetablir);
    m_toolbar->addSeparator();
    m_toolbar->addAction(m_actZoomPlus);
    m_toolbar->addAction(m_actZoomMoins);
}


// zone centrale avec menu contextuel
void MenuExplorer::creerZoneCentrale() {
    m_central = new QWidget(this);
    m_mainLayout = new QVBoxLayout(m_central);
    m_central->setLayout(m_mainLayout);
    setCentralWidget(m_central);

    m_displayLabel = new QLabel("Clique sur un menu ou fais clic droit ici", m_central);
    m_displayLabel->setAlignment(Qt::AlignCenter);
    m_displayLabel->setStyleSheet(
        "font-size: 25px; color: #555;"
        "border: 2px dashed #CCC; border-radius: 10px;"
        "padding: 45px;"
    );
    m_mainLayout->addWidget(m_displayLabel);


    // Menu contextuel sur clic droit
    m_displayLabel->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(m_displayLabel, &QLabel::customContextMenuRequested, this, [this](const QPoint& pos)
        {
            QMenu contextMenu(this);
            contextMenu.setTitle("Actions rapides");

            //On réutilise les actions existences dans le menu contextuel
            contextMenu.addAction(m_actNouveau);
            contextMenu.addAction(m_actOuvrir);
            contextMenu.addSeparator();

            const auto* actInfo = contextMenu.addAction("ℹ️  Infos contextuelles");
            contextMenu.addSeparator();
            contextMenu.addAction(m_actZoomPlus);
            contextMenu.addAction(m_actZoomMoins);

            if (const QAction* choix = contextMenu.exec(m_displayLabel->mapToGlobal(pos)); choix == actInfo) {
                afficherAction("Infos contextuelles - position : " + QString("(%1, %2)").arg(pos.x()).arg(pos.y()));
            }
        }
    );
}


void MenuExplorer::connecterActions() {

    // Fichier
    connect(m_actNouveau, &QAction::triggered, this, [this] {
        afficherAction("Nouveau fichier crée");
        m_actEnregistrer->setEnabled(true);
        m_actAnnuler->setEnabled(true);
    });
    connect(m_actOuvrir, &QAction::triggered, this, [this] {
       afficherAction("Ouvrir... (dialog à implémenter)");
        m_actEnregistrer->setEnabled(true);
    });
    connect(m_actEnregistrer, &QAction::triggered, this, [this] {
       afficherAction("Fichier enregistré !");
    });
    connect(m_actExportTxt, &QAction::triggered, this, [this]() {
        afficherAction("Export → .txt");
    });
    connect(m_actExportMd, &QAction::triggered, this, [this]() {
        afficherAction("Export → .md");
    });
    connect(m_actExportHtml, &QAction::triggered, this, [this]() {
        afficherAction("Export → .html");
    });
    connect(m_actQuitter, &QAction::triggered, qApp, &QApplication::quit);


    // Edition
    connect(m_actAnnuler, &QAction::triggered, this, [this] {
        afficherAction("Annuler la dernière action");
        m_actRetablir->setEnabled(true);
    });
    connect(m_actRetablir, &QAction::triggered, this, [this]() {
       afficherAction("Rétablir ↪");
   });

    connect(m_actCouper,    &QAction::triggered, this, [this] {
        afficherAction("Couper ✂️");
    });
    connect(m_actCopier,    &QAction::triggered, this, [this] {
        afficherAction("Copier 📋");
    });
    connect(m_actColler,    &QAction::triggered, this, [this] {
        afficherAction("Coller 📌");
    });
    connect(m_actToutSelect, &QAction::triggered, this,[this] {
        afficherAction("Tout sélectionné");
    });


    // - Vue
    connect(m_actToggleToolbar, &QAction::toggled, this, [this](const bool visible) {
        m_toolbar->setVisible(visible);
        afficherAction(visible ? "Toolbar affichée" : "Toolbar masquée");
    });
    connect(m_actToggleStatusBar, &QAction::toggled, this, [this](const bool visible) {
        statusBar()->setVisible(visible);
        afficherAction(visible ? "StatusBar affichée" : "StatusBar masquée");
    });
    connect(m_actZoomPlus, &QAction::triggered, this, [this] {
        m_zoom = qMin(m_zoom + 10, 200);
        appliquerZoom();
    });
    connect(m_actZoomMoins, &QAction::triggered, this, [this] {
        m_zoom = qMax(m_zoom - 10, 50);
        appliquerZoom();
    });
    connect(m_actZoomReset, &QAction::triggered, this, [this] {
        m_zoom = 100;
        appliquerZoom();
    });


    // Outils
    connect(m_actThemeClair, &QAction::triggered, this, [this] {
        qApp->setStyleSheet("");
        afficherAction("Thème clair activé");
    });
    connect(m_actThemeSombre, &QAction::triggered, this, [this] {
        qApp->setStyleSheet(R"(
            QMainWindow, QWidget {
                background-color: #2B2B2B;
                color: #D4D4D4;
            }
            QMenuBar {
                background-color: #3C3F41;
                color: #D4D4D4;
            }
            QMenuBar::item:selected {
                background-color: #4A90D9;
            }
            QMenu {
                background-color: #3C3F41;
                color: #D4D4D4;
                border: 1px solid #555;
            }
            QMenu::item:selected {
                background-color: #4A90D9;
            }
            QToolBar {
                background-color: #3C3F41;
                border-bottom: 1px solid #555;
            }
            QStatusBar {
                background-color: #3C3F41;
                color: #888;
            }
        )");
        afficherAction("Thème sombre activé");
    });


    // Aide
    connect(m_actAPropos, &QAction::triggered, this, [this] {
        QMessageBox::about(this,
            "À propos de MenuExplorer",
            "<b>MenuExplorer v1.0</b><br><br>"
            "Démonstration complète de QMenuBar,<br>"
            "QMenu, QAction, QToolBar et menus contextuels.<br><br>"
            "Formation Qt6 — Polytech Dijon"
        );
    });
    connect(m_actAProposQt, &QAction::triggered, qApp, &QApplication::aboutQt);
}


void MenuExplorer::afficherAction(const QString &nom) const {
    m_displayLabel->setText("Action déclenchée: \n" + nom);
    statusBar()->showMessage(nom, 3000);
}


void MenuExplorer::appliquerZoom() const {
    const QString msg = QString("Zoom : %1%").arg(m_zoom);
    m_displayLabel->setStyleSheet(
        QString("font-size: %1px; color: #555;"
            "border: 2px dashed #CCC; border-radius: 8px;"
            "padding: 40px;").arg(16 * m_zoom / 100)
    );
    afficherAction(msg);
}

