//
// Created by thierry on 17/05/2026.
//


#include "../../headers/mini-projets/tabWidget_app.h"



TabWidgetApp::TabWidgetApp(QWidget* parent) : QMainWindow(parent) {

    setWindowTitle("QTabWidget App");
    resize(800, 550);


    // Widget central
    this->centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    this->mainLayout = new QVBoxLayout(this->centralWidget);
    mainLayout->setContentsMargins(12,12,12,12);
    mainLayout->setSpacing(12);


    // Panneau de controle en haut
    // On utilisera un QGroupBox pour regrouper visuellement les controles
    // QGroupBox = un conteneur avec un titre et une bordure

    this->groupBox = new QGroupBox("Position des onglets", centralWidget);
    this->ctrlLayout = new QHBoxLayout(groupBox);


    // QButtonGroup garanti l'exclusivité des QRadioButton
    // Il permettra de connaitre quel bouton est coché via son id
    this->buttonGroup = new QButtonGroup(centralWidget);
    this->radioNorth  = new QRadioButton("Nord (haut)", groupBox);
    this->radioSouth  = new QRadioButton("Sud (bas)", groupBox);
    this->radioWest   = new QRadioButton("Ouest (gauche)", groupBox);
    this->radioEast   = new QRadioButton("East (bas)", groupBox);

    buttonGroup->addButton(radioNorth, QTabWidget::North);
    buttonGroup->addButton(radioSouth, QTabWidget::South);
    buttonGroup->addButton(radioWest, QTabWidget::West);
    buttonGroup->addButton(radioEast, QTabWidget::East);

    radioNorth->setChecked(true);  // Position haut par défaut

    ctrlLayout->addWidget(radioNorth);
    ctrlLayout->addWidget(radioSouth);
    ctrlLayout->addWidget(radioWest);
    ctrlLayout->addWidget(radioEast);
    ctrlLayout->addStretch();

    this->btnToggleClose = new QPushButton("Activer x", centralWidget);
    this->btnToggleMove  = new QPushButton("Activer drag", centralWidget);
    this->btnToggleClose->setCheckable(true);
    this->btnToggleMove->setCheckable(true);


    ctrlLayout->addWidget(btnToggleMove);
    ctrlLayout->addWidget(btnToggleClose);


    // QTabWidget

    PageList pList = {};
    pList.emplace("Accueil", creerPage("Accueil", "#F0F4FF", QIcon(":/icons/accueil.png"), this));
    pList.emplace("Musique", creerPage("Musique", "#F0F4FF", QIcon(":/icons/musique.png"), this));
    pList.emplace("Favoris", creerPage("Favoris", "#FFFBF0", QIcon(":/icons/star.png"), this));
    pList.emplace("Réglages", creerPage("Réglages", "#FFF0F0", QIcon(":/icons/settings.png"), this));

    this->tabWidget = new TutoQTabWidget(pList, this);


    // Assemblage
    mainLayout->addWidget(groupBox);
    mainLayout->addWidget(tabWidget, 1);


    // Bare de statut
    this->label = new QLabel("Page active : Acceuil (index 0)");
    statusBar()->addWidget(label);

    // Connexions
    connect(tabWidget, &TutoQTabWidget::tabChanged, this, &TabWidgetApp::onCurrentTabChanged);
    connect(buttonGroup, &QButtonGroup::idClicked, this, &TabWidgetApp::onButtonGroupIdClicked);
    connect(btnToggleClose, &QPushButton::toggled, this, &TabWidgetApp::onEnableDisableTab);
    connect(btnToggleMove, &QPushButton::toggled, this, &TabWidgetApp::onToggleMove);
}



void TabWidgetApp::onCurrentTabChanged(const int index) const {
    const QString nom = this->tabWidget->getTabWidget()->tabText(index);
    this->label->setText(QString("Page active : %1 (index %2)").arg(nom).arg(index));
}


void TabWidgetApp::onButtonGroupIdClicked(const int id) const {
    const auto position = static_cast<QTabWidget::TabPosition>(id);
    this->tabWidget->getTabWidget()->setTabPosition(position);
    QString posNom;
    switch (position) {
        case QTabWidget::North: posNom = "Nord";  break;
        case QTabWidget::South: posNom = "Sud";   break;
        case QTabWidget::West:  posNom = "Ouest"; break;
        case QTabWidget::East:  posNom = "Est";   break;
    }
    qDebug() <<  "Position changée " << posNom;
}



void TabWidgetApp::onEnableDisableTab(const bool checked) const {
    this->tabWidget->getTabWidget()->setTabsClosable(checked);
    this->btnToggleClose->setText(checked ? "Désactiver x" : "Activer x");
    qDebug() <<"tabs closable " << checked;
}


void TabWidgetApp::onToggleMove(const bool checked) const {
    this->tabWidget->getTabWidget()->setMovable(checked);
    this->btnToggleMove->setText(checked ? "Désactiver drag" : "Activer drag");
    qDebug() << "Movable " << checked;
}




WidgetPage TabWidgetApp::creerPage(const QString& texte, const QString& couleur, const std::optional<QIcon>& icon, QWidget* parent) {

    auto page   = new QWidget(parent);
    const auto layout = new QVBoxLayout(page);
    const auto label  = new QLabel(texte, page);

    // Style inline pour donner une couleur de fond distinctive à chaque page
    page->setStyleSheet(QString("background-color: %1;").arg(couleur));

    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 24px; font-weight: bold; color: #333;");

    layout->addWidget(label);
    return {page, icon};
}

