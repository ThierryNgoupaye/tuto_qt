//
// Created by thierry on 18/05/2026.
//

#include "../../headers/mini-projets/sidebar_app.h"

#include <QPushButton>
#include <QKeySequence>
#include <QShortcut>
#include <QStatusBar>
#include <QIcon>
#include <QSize>

struct PageInfo {
    QString label;
    QString titre;
    QString couleur;
    QString iconPath;  
};


static const std::vector<PageInfo> pages = {
    {"Accueil",   "Page Accueil",   "#F0F4FF", ":/icons/accueil.png"},
    {" Musique",  "Page Musique",   "#F0FFF4", ":/icons/musique.png"},
    {" Favoris",  "Page Favoris",   "#FFFBF0", ":/icons/star.png"},
    {"Réglages",  "Page Réglages",  "#FFF0F0", ":/icons/settings.png"},
};



SidebarApp::SidebarApp(const QString& title, QWidget *parent) : QMainWindow(parent) {

    setWindowTitle("Sidebar Application");
    resize(800, 600);

    this->m_central = new QWidget(this);
    setCentralWidget(m_central);
    this->m_mainLayout = new QHBoxLayout(m_central);
    m_mainLayout->setContentsMargins(0,0,0,0);
    m_mainLayout->setSpacing(0);


    // Sidebar
    this->m_sidebar = new QWidget(m_central);
    this->m_sidebarLayout = new QVBoxLayout(this->m_sidebar);
    m_sidebar->setFixedWidth(250);
    m_sidebar->setStyleSheet("background-color: #2C2F3A");
    m_sidebarLayout->setContentsMargins(0,20,0,20);
    m_sidebarLayout->setSpacing(5);

    // Titre de la sidebar
    this->m_title = new QLabel(title, m_sidebar);
    m_title->setAlignment(Qt::AlignCenter);
    m_title->setStyleSheet(
        "color: white; font-size: 18px;"
        "font-weight:bold; padding: 10px 0 20px 0;"
    );
    m_sidebarLayout->addWidget(this->m_title);


    QList<QWidget*> pageList = {};
    for (size_t i = 0; i < pages.size(); ++i) {
        const auto& [label, titre, couleur, iconPath] = pages.at(i);
        pageList.append(creerPage(titre, couleur, this));


        // ReSharper disable once CppDFAMemoryLeak
        const auto navBtn = new QPushButton(QIcon(iconPath), label, m_sidebar);
        navBtn->setIconSize(QSize(24,24));
        navBtn->setFlat(true);
        navBtn->setCheckable(true);
        navBtn->setCursor(Qt::PointingHandCursor);
        navBtn->setFixedHeight(44);

        navBtn->setStyleSheet(R"(
            QPushButton {
                    color: #AAAAAA;
                    text-align: left;
                    padding-left: 24px;
                    border: none;
                    border-radius: 0px;
                    font-size: 14px;
                }
                QPushButton:hover {
                    background-color: #3A3F50;
                    color: white;
                }
                QPushButton:checked {
                    background-color: #4A90D9;
                    color: white;
                    border-radius: 10px;
                    font-weight: bold;
                }
        )");

        m_sidebarLayout->addWidget(navBtn);
        m_navBtn.emplace_back(navBtn);

        connect(navBtn, &QPushButton::clicked, this, [this, i] {
            this->naviguerVers(static_cast<int>(i));
        });
    }

    this->m_stack = new TutoQStackedWidget(pageList, this);
    m_sidebarLayout->addStretch();

    for (std::size_t i = 0; i < pageList.size(); ++i) {

        // ReSharper disable once CppDFAMemoryLeak
        const auto* shortcut = new QShortcut(
                QKeySequence(Qt::CTRL | static_cast<Qt::Key>(Qt::Key_1 + i)),
                this
            );

        connect(shortcut, &QShortcut::activated, this, [this, i] {
            naviguerVers(static_cast<int>(i));
        });
    }


    // Assemblage
    m_mainLayout->addWidget(m_sidebar);
    m_mainLayout->addWidget(m_stack, 1);


    // Signal currentChanged
    naviguerVers(0);


    // Bare de Statut
    m_statusLabel = new QLabel(pages[0].label, m_central);
    statusBar()->addWidget(m_statusLabel);

    connect(m_stack, &TutoQStackedWidget::pageChanged, this, &SidebarApp::onPageChanged);
}




void SidebarApp::onPageChanged(const int index) const {
    m_statusLabel->setText(
                QString("Page : %1  |  Index : %2  |  "
                        "Raccourci : Ctrl+%3")
                .arg(pages[index].label)
                .arg(index)
                .arg(index + 1)
            );
    qDebug() << "[currentChanged] index =" << index;
}



QWidget* SidebarApp::creerPage(const QString& texte, const QString& couleur, QWidget* parent) {

    // ReSharper disable once CppDFAMemoryLeak
    const auto page = new QWidget(parent);

    // ReSharper disable once CppDFAMemoryLeak
    const auto layout = new QVBoxLayout(page);

    // ReSharper disable once CppDFAMemoryLeak
    const auto label = new QLabel(texte, page);

    page->setStyleSheet(QString("background-color: %1;").arg(couleur));
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 26px; font-weight: bold; color: #333;");

    layout->addWidget(label);
    return page;
}


void  SidebarApp::naviguerVers(const int index) {
    if (index < 0 || index >= m_stack->getStack()->count()) return;
    m_stack->getStack()->setCurrentIndex(index);

    // Mettre à jour l'état visuel des boutons
    // Un seul bouton doit être "checked" à la fois
    for (std::size_t i = 0; i < m_navBtn.size(); ++i) {
        m_navBtn[static_cast<int>(i)]->setChecked(i == index);
    }

    qDebug() << "[naviguerVers] index =" << index;
}



