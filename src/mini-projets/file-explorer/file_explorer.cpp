//
// Created by thierry on 21/05/2026.
//

#include "../../../headers/mini-projets/file-explorer/file_explorer.h"
#include <QApplication>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QFrame>
#include <QFileDialog>
#include <QClipboard>
#include <QDesktopServices>
#include <QUrl>
#include <QHeaderView>


FileExplorer::FileExplorer(QWidget *parent) : QMainWindow(parent) {

    setWindowTitle("File Explorer");
    resize(1000, 700);

    creerModele();
    creerActions();
    creerMenus();
    creerToolbar();
    creerZoneCentrale();
    creerDockExplorateur();
    connecter();

    statusBar()->showMessage("Pret - ouvre un dossier pour commencer");
}



// Modèle
void FileExplorer::creerModele() {
    m_model = new QFileSystemModel(this);
    m_model->setRootPath(QDir::homePath());
    m_model->setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
}


// Actions
void FileExplorer::creerActions() {
    m_actOuvrir = new QAction(QIcon(":/icons/open-file.png"), "Ouvrir un dossier...", this);
    m_actOuvrir->setShortcut(QKeySequence::Open);
    m_actOuvrir->setStatusTip("Choisir un dossier à explorer");


    m_actMontrer = new QAction("Explorateur", this);
    m_actMontrer->setCheckable(true);
    m_actMontrer->setChecked(true);
    m_actMontrer->setShortcut(QKeySequence("Ctrl+Shift+E"));
}


// Menu
void FileExplorer::creerMenus() {
    m_menuFichier = menuBar()->addMenu("&fichier");
    m_menuFichier->addAction(m_actOuvrir);

    m_menuVue = menuBar()->addMenu("&Vue");
    m_menuVue->addAction(m_actMontrer);
}


// Toolbar
void FileExplorer::creerToolbar() {
    m_toolbar = addToolBar("Principal");
    m_toolbar->setMovable(false);
    m_toolbar->setIconSize(QSize(18,18));
    m_toolbar->addAction(m_actOuvrir);
}



// Zone centrale
void FileExplorer::creerZoneCentrale() {
    m_central = new QWidget(this);
    m_mainLayout = new QVBoxLayout(m_central);
    m_mainLayout->setContentsMargins(32,32,32,32);
    m_mainLayout->setSpacing(16);
    setCentralWidget(m_central);


    // Titre de la section
    m_titreSection = new QLabel("Fichier sélectionné", m_central);
    m_titreSection->setStyleSheet("font-size: 18px; font-weight: bold; color: #333;");


    // Informations via un formulaire
    m_form = new QFormLayout();
    m_form->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    m_form->setHorizontalSpacing(16);
    m_form->setVerticalSpacing(10);

    m_lblNom = new QLabel("—", m_central);
    m_lblChemin = new QLabel("—", m_central);
    m_lblChemin->setWordWrap(true);
    m_lblType   = new QLabel("—", m_central);
    m_lblTaille = new QLabel("—", m_central);
    m_lblDate   = new QLabel("—", m_central);

    m_form->addRow("Nom: ", m_lblNom);
    m_form->addRow("Chemin complet :", m_lblChemin);
    m_form->addRow("Type :",           m_lblType);
    m_form->addRow("Taille :",         m_lblTaille);
    m_form->addRow("Modifié le :",     m_lblDate);


    // Séparateur
    m_sep = new QFrame();
    m_sep->setFrameShape(QFrame::HLine);
    m_sep->setFrameShadow(QFrame::Sunken);

    // Boutons d'action
    m_btnLayout = new QHBoxLayout();
    m_btnOuvrir = new QPushButton(QIcon(":/icons/open-file.png"),"  Ouvrir", m_central);
    m_btnCopier = new QPushButton(QIcon(":/icons/copy.png"), "  Copier le chemin", m_central);
    m_btnOuvrir->setEnabled(false);
    m_btnCopier->setEnabled(false);

    m_btnLayout->addWidget(m_btnOuvrir);
    m_btnLayout->addWidget(m_btnCopier);
    m_btnLayout->addStretch();


    // Assemblage
    m_mainLayout->addWidget(m_titreSection);
    m_mainLayout->addLayout(m_form);
    m_mainLayout->addWidget(m_sep);
    m_mainLayout->addLayout(m_btnLayout);
    m_mainLayout->addStretch();

}


// Dock avec QTreeView
void FileExplorer::creerDockExplorateur() {
    m_dockTree = new QDockWidget("Explorateur", this);
    m_dockTree->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    m_dockTree->setFeatures(QDockWidget::NoDockWidgetFeatures);


    // QTreeView
    m_treeView = new QTreeView(m_dockTree);
    m_treeView->setModel(m_model);

    // Racine visible = home de l'utilisateur
    m_treeView->setRootIndex(m_model->index(QDir::homePath()));


    // Cacher les colonnes inutiles et garder seulement le nom
    m_treeView->hideColumn(1);  // Taille
    m_treeView->hideColumn(2);  // Type
    m_treeView->hideColumn(3);  // Date

    m_treeView->setAnimated(true);
    m_treeView->setIndentation(20);
    m_treeView->setSortingEnabled(true);
    m_treeView->sortByColumn(0, Qt::AscendingOrder);
    m_treeView->setSelectionMode(QAbstractItemView::SingleSelection);

    // Cacher l'en-tete
    m_treeView->header()->hide();

    m_dockTree->setWidget(m_treeView);
    m_dockTree->setMinimumWidth(250);

    addDockWidget(Qt::LeftDockWidgetArea, m_dockTree);


    // connecter le toggle du dock à l'action montrer
    connect(m_actMontrer, &QAction::toggled, m_dockTree, &QDockWidget::setVisible);
    connect(m_dockTree, &QDockWidget::visibilityChanged, m_actMontrer, &QAction::setChecked);
}



// Connexions
void FileExplorer::connecter() {

    // Ouvrir un dossier via QFileDialog
    connect(m_actOuvrir, &QAction::triggered, this, &FileExplorer::ouvrirDossier);

    // clic simple = afficher les infos
    connect(m_treeView, &QTreeView::clicked, this, [this](const QModelIndex& index) {
        mettreAJourInfos(index);
    });

    connect(m_treeView, &QTreeView::doubleClicked, this, [this](const QModelIndex& index) {
       if (!m_model->isDir(index)) {
           const QString chemin = m_model->filePath(index);
           QDesktopServices::openUrl(QUrl::fromLocalFile(chemin));
           statusBar()->showMessage("Ouverture: " + chemin, 3000);
       }
    });


    connect(m_btnOuvrir, &QPushButton::clicked, this, [this] {
       QDesktopServices::openUrl(QUrl::fromLocalFile(m_cheminCourant));
    });


    connect(m_btnCopier, &QPushButton::clicked, this, [this] {
       QApplication::clipboard()->setText(m_cheminCourant);
        statusBar()->showMessage("Chemin copié: " + m_cheminCourant, 2000);
    });
}


void FileExplorer::ouvrirDossier() {
    const QString dossier = QFileDialog::getExistingDirectory(
        this,
        "Choisir un dossier",
        QDir::homePath(),
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
    );

    if (dossier.isEmpty()) return;

    m_model->setRootPath(dossier);
    m_treeView->setRootIndex(m_model->index(dossier));

    setWindowTitle("FileExplorer - "+ dossier);
    statusBar()->showMessage("Dossier ouvert : " +dossier, 3000);
}



void FileExplorer::mettreAJourInfos(const QModelIndex& index) {
    const QFileInfo info = m_model->fileInfo(index);
    m_cheminCourant = info.absoluteFilePath();

    m_lblNom->setText(info.fileName());
    m_lblChemin->setText(info.absoluteFilePath());

    if (info.isDir()) {
        m_lblType->setText("Dossier");
        m_lblTaille->setText("-");
    }
    else {
        const QString ext = info.suffix().toLower();
        QString type = "Fichier";
        if (ext == "cpp" || ext == "h" || ext == "cxx")
            type = "Fichier C++";
        else if (ext == "py")
            type = "Script Python";
        else if (ext == "js" || ext == "ts")
            type = "JavaScript/TypeScript";
        else if (ext == "md")
            type = "Markdown";
        else if (ext == "json")
            type = "JSON";
        else if (ext == "cmake" || info.fileName() == "CMakeLists.txt")
            type = "CMake";
        else if (ext == "mp3" || ext == "flac" || ext == "wav")
            type = "Audio";

        m_lblType->setText(type);
        m_lblTaille->setText(formaterTaille(info.size()));

        m_lblDate->setText(info.lastModified().toString("dd/MM/yyyy HH:mm:ss"));

        m_btnOuvrir->setEnabled(!info.isDir());
        m_btnCopier->setEnabled(true);

        statusBar()->showMessage(m_cheminCourant);
    }
}



// Formater une taille en octets
QString FileExplorer::formaterTaille(const qint64 octets) {
    if (octets < 1024)
        return QString("%1 o").arg(octets);
    if (octets < 1024 * 1024)
        return QString("%1 Ko").arg(octets / 1024.0, 0, 'f', 1);
    if (octets < 1024 * 1024 * 1024)
        return QString("%1 Mo").arg(octets / (1024.0 * 1024), 0, 'f', 1);
    return QString("%1 Go").arg(
        octets / (1024.0 * 1024 * 1024), 0, 'f', 2
    );
}