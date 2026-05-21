//
// Created by thierry on 21/05/2026.
//

#include "../../../headers/mini-projets/form-dock/form_dock_app.h"

#include <QMenuBar>
#include <QStatusBar>


FormDockApp::FormDockApp(QWidget *parent)  : QMainWindow(parent){
    setWindowTitle("FormDock - QFormLayout + QDockWidget");
    resize(900, 600);

    creerZoneCentrale();
    creerDock();
    creerMenus();

    statusBar()->showMessage("Pret");
}



// Zone centrale
void FormDockApp::creerZoneCentrale() {
    m_central = new QWidget(this);
    m_mainLayout = new QVBoxLayout(m_central);
    m_mainLayout->setContentsMargins(32,32,32,32);
    setCentralWidget(m_central);

    m_resumeLabel = new QLabel(
        "Remplis le formulaire dans le panneau gauche\n"
        "puis clique sur Valider.",
        m_central
    );
    m_resumeLabel->setAlignment(Qt::AlignCenter);
    m_resumeLabel->setStyleSheet(
        "font-size: 15px; color: #666;"
       "border: 2px dashed #DDD;"
       "border-radius: 8px; padding: 40px;"
    );
    m_mainLayout->addWidget(m_resumeLabel);
}


void FormDockApp::creerDock() {
    m_dock = new QDockWidget("Propriétés", m_central);
    m_dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    m_dock->setFeatures(
        QDockWidget::DockWidgetMovable |
        QDockWidget::DockWidgetClosable |
        QDockWidget::DockWidgetFloatable
    );

    // contenu du dock dans une ScrollArea
    // Bon réflexe : toujours mettre un formulaire dans une
    // ScrollArea — si la fenêtre est petite, il reste accessible
    m_scrollArea = new QScrollArea();
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_scrollArea->setFrameShape(QFrame::NoFrame);

    m_dockConteneur = new QWidget();
    m_dockLayout = new QVBoxLayout(m_dockConteneur);
    m_dockLayout->setContentsMargins(12,12,12,12);
    m_dockLayout->setSpacing(8);


    // Section informations personnelles
    m_labelSection1 = new QLabel("👤  Informations");
    m_labelSection1->setStyleSheet(
        "font-weight: bold; font-size: 13px; color: #444;"
        "padding: 4px 0;"
    );

    m_inputPrenom = new QLineEdit();
    m_inputPrenom->setPlaceholderText("Votre Prénom");

    m_inputNom = new QLineEdit();
    m_inputNom->setPlaceholderText("Votre nom");

    m_inputEmail = new QLineEdit();
    m_inputEmail->setPlaceholderText("Votre@email.com");

    m_formInfos = new QFormLayout();
    m_formInfos->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    m_formInfos->setHorizontalSpacing(12);
    m_formInfos->setVerticalSpacing(8);
    m_formInfos->addRow("Prénom :", m_inputPrenom);
    m_formInfos->addRow("Nom :", m_inputNom);
    m_formInfos->addRow("Email :", m_inputEmail);


    // Section préférences
    m_labelSection2 = new QLabel("⚙️  Préférences");
    m_labelSection2->setStyleSheet(
      "font-weight: bold; font-size: 13px; color: #444;"
      "padding: 4px 0;"
    );
    m_comboTheme = new QComboBox();
    m_comboTheme->addItems({"Système", "Clair", "Sombre"});

    m_spinTaille = new QSpinBox();
    m_spinTaille->setRange(10,24);
    m_spinTaille->setValue(14);
    m_spinTaille->setSuffix(" px");

    m_checkNotifs = new QCheckBox("Activer les notifications");

    // QFormLayout pour la section préférences
    m_formPrefs = new QFormLayout();
    m_formPrefs->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    m_formPrefs->setHorizontalSpacing(12);
    m_formPrefs->setVerticalSpacing(8);
    m_formPrefs->addRow("Thème :", m_comboTheme);
    m_formPrefs->addRow("Police :", m_spinTaille);
    m_formPrefs->addRow(m_checkNotifs);


    // Boutons
    m_btnLayout = new QHBoxLayout();
    m_btnAnnuler = new QPushButton("Annuler");
    m_btnValider = new QPushButton("Valider");
    m_btnValider->setDefault(true);

    m_btnLayout->addWidget(m_btnAnnuler);
    m_btnLayout->addWidget(m_btnValider);


    // Assemblage du dock
    m_dockLayout->addWidget(m_labelSection1);
    m_dockLayout->addLayout(m_formInfos);
    m_dockLayout->addWidget(creerSeparator());
    m_dockLayout->addWidget(m_labelSection2);
    m_dockLayout->addLayout(m_formPrefs);
    m_dockLayout->addWidget(creerSeparator());
    m_dockLayout->addLayout(m_btnLayout);
    m_dockLayout->addStretch();

    m_scrollArea->setWidget(m_dockConteneur);
    m_dock->setWidget(m_scrollArea);
    m_dock->setMinimumWidth(260);

    addDockWidget(Qt::LeftDockWidgetArea, m_dock);

    // Connexions
    connect(m_btnValider, &QPushButton::clicked, this, &FormDockApp::mettreAJourTheme);
    connect(m_btnAnnuler, &QPushButton::clicked, this, [this] {
        m_inputPrenom->clear();
        m_inputNom->clear();
        m_inputEmail->clear();
        m_comboTheme->setCurrentIndex(0);
        m_spinTaille->setValue(14);
        m_checkNotifs->setEnabled(false);
        m_resumeLabel->setText(
            "Formulaire réinitialisé.\n"
            "Remplis les champs et clique sur Valider."
        );
        statusBar()->showMessage("Formulaire réinitialisé", 2000);
    });

    connect(m_dock, &QDockWidget::topLevelChanged, this, [this](const bool isFloating) {
        statusBar()->showMessage(isFloating ? "Panneau détaché " : "Panneau ancré", 2000);
    });
}


// Mise à jour du résumé
void FormDockApp::mettreAJourTheme() const {
    if (m_inputPrenom->text().trimmed().isEmpty() || m_inputNom->text().trimmed().isEmpty()) {
        statusBar()->showMessage("⚠️  Prénom et nom sont obligatoires", 3000);
        m_inputPrenom->setFocus();
        return;
    }
    const QString resume = QString(
        "✅  Profil enregistré\n\n"
        "Nom complet : %1 %2\n"
        "Email : %3\n\n"
        "Thème : %4\n"
        "Taille de police : %5 px\n"
        "Notifications : %6"
    ).arg(m_inputPrenom->text().trimmed(), m_inputNom->text().trimmed(), m_inputEmail->text().trimmed(), m_comboTheme->currentText())
    .arg(m_spinTaille->value())
    .arg(m_checkNotifs->isChecked() ? "Activées" : "Désactivées");


    m_resumeLabel->setText(resume);
    m_resumeLabel->setStyleSheet(
        "font-size: 15px; color: #333;"
        "border: 2px solid #4A90D9;"
        "border-radius: 8px; padding: 40px;"
    );
    statusBar()->showMessage("Profil enregistré !", 3000);

}



QFrame* FormDockApp::creerSeparator() {
    // ReSharper disable once CppDFAMemoryLeak
    auto* sep = new QFrame();
    sep->setFrameShape(QFrame::HLine);
    sep->setFrameShadow(QFrame::Sunken);
    return sep;
}


void FormDockApp::creerMenus() {
    m_menuVue = menuBar()->addMenu("&Vue");

    m_actToggleDock = m_dock->toggleViewAction();
    m_actToggleDock->setText("Panneau Propriétés");
    m_actToggleDock->setShortcut(QKeySequence("Ctrl+Shift+P"));
    m_menuVue->addAction(m_actToggleDock);
}
