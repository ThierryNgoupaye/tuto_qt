//
// Created by thierry on 19/05/2026.
//

#include "../../../headers/mini-projets/aurora-skeleton/aurora_skeleton.h"

#include "../../../headers/mini-projets/aurora-skeleton/pages/home_page.h"
#include "../../../headers/mini-projets/aurora-skeleton/pages/library_page.h"
#include "../../../headers/mini-projets/aurora-skeleton/pages/settings_page.h"
#include "../../../headers/mini-projets/aurora-skeleton/pages/star_page.h"



AuroraSkeletonApp::AuroraSkeletonApp(QWidget *parent) : QMainWindow(parent) {

    setWindowTitle("Auror Music Skeleton");
    resize(800, 600);


    m_central = new QWidget(this);
    m_mainLayout = new QVBoxLayout(m_central);
    m_mainLayout->setContentsMargins(10,10,10,10);
    m_mainLayout->setSpacing(20);
    m_central->setLayout(m_mainLayout);
    setCentralWidget(m_central);

    m_topBar = new TopBar(m_central);

    m_splitter = new QSplitter(Qt::Horizontal, m_central);

    // sideBar
    const QList<PageItem> pages = {
        {":/icons/accueil.png", " Accueil",0 } ,
        {":/icons/playlist.png", "Bibliothèque", 1},
        {":/icons/star.png", " Favoris", 2},
        {":/icons/settings.png", " Paramètres", 3}
    };
    m_sideBar = new SideBar(pages, m_central);

    // Contenu principal
    const QList<QWidget*> pageList = {
        new HomePage(),
        new LibraryPage(),
        new StarPage(),
        new SettingsPage()
    };
    m_mainContent = new MainContent(pageList, m_central);


    m_splitter->addWidget(m_sideBar);
    m_splitter->addWidget(m_mainContent);
    m_splitter->setSizes({200, 2000});
    m_splitter->setCollapsible(1,false);
    m_splitter->setCollapsible(0, false);
    m_splitter->setStretchFactor(0, 0);
    m_splitter->setStretchFactor(1, 1);

    // Barre inférieure
    m_playerBar = new PlayerBar(m_central);


    // Assemblage des différents composants
    m_mainLayout->addWidget(m_topBar);
    m_mainLayout->addWidget(m_splitter, 1);
    m_mainLayout->addWidget(m_playerBar);


    connect(m_sideBar, &SideBar::pageRequested, this, &AuroraSkeletonApp::onPageRequested);
}



void AuroraSkeletonApp::onPageRequested(const int index) const {
    m_mainContent->getContent()->setCurrentIndex(index);
}
