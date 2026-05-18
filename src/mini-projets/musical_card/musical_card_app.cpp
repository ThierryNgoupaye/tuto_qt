//
// Created by thierry on 18/05/2026.
//

#include "../../../headers/mini-projets/musical_card/musical_card_app.h"

#include <QScrollBar>
#include <QStatusBar>

#include "../../../headers/mini-projets/musical_card/musical_card.h"


MusicalCardApp::MusicalCardApp(QWidget *parent) : QMainWindow(parent)  {

    setWindowTitle("Liste de pistes");
    resize(640, 520);

    this->m_central = new QWidget(this);
    this->m_mainLayout = new QVBoxLayout(m_central);
    setCentralWidget(m_central);
    m_central->setStyleSheet("background-color: #F3F4F6;");

    m_mainLayout->setContentsMargins(16,16,16,16);
    m_mainLayout->setSpacing(12);


    // Barre de controle
    this->m_ctrlLayout = new QHBoxLayout;
    this->m_addBtn = new QPushButton(QIcon(":/icons/plus.png"), " Ajouter une piste", m_central);
    this->m_btnHaut = new QPushButton(QIcon(":/icons/up-arrow.png"), " Haut", m_central);
    this->m_btnBas = new QPushButton(QIcon(":/icons/down-arrow.png"), " Bas", m_central);
    const QString btnStyle = "QPushButton { color: #111827; background: transparent; border: none; }";

    m_addBtn->setFixedHeight(36);
    m_addBtn->setFlat(true);
    m_addBtn->setCursor(Qt::PointingHandCursor);
    m_addBtn->setIconSize(QSize(18,18));
    m_addBtn->setStyleSheet(btnStyle);

    m_btnHaut->setFixedHeight(36);
    m_btnHaut->setFlat(true);
    m_btnHaut->setCursor(Qt::PointingHandCursor);
    m_btnHaut->setIconSize(QSize(18,18));
    m_btnHaut->setStyleSheet(btnStyle);

    m_btnBas->setFixedHeight(36);
    m_btnBas->setFlat(true);
    m_btnBas->setCursor(Qt::PointingHandCursor);
    m_btnBas->setIconSize(QSize(18,18));
    m_btnBas->setStyleSheet(btnStyle);


    m_ctrlLayout->addWidget(m_addBtn);
    m_ctrlLayout->addStretch();
    m_ctrlLayout->addWidget(m_btnHaut);
    m_ctrlLayout->addWidget(m_btnBas);



    // Construction de la ScrollArea
    this->m_scrollArea = new TutoQScrollArea(nullptr, m_central);

    this->m_content = new QWidget(m_scrollArea);
    m_listLayout = new QVBoxLayout(m_content);
    m_listLayout->setContentsMargins(0,0,0,0);
    m_listLayout->setSpacing(0);
    m_listLayout->addStretch();

    m_scrollArea->scrollArea()->setWidget(m_content);
    m_scrollArea->scrollArea()->setStyleSheet(
        "QScrollArea { border: none; background: #F3F4F6; }"
        "QScrollArea > QWidget > QWidget { background: #F3F4F6; }"
    );


    // Assemblage
    m_mainLayout->addLayout(m_ctrlLayout);
    m_mainLayout->addWidget(m_scrollArea, 1);


    // Barre de statu
    m_statusLabel = new QLabel("0 piste | Position 0");
    statusBar()->addWidget(m_statusLabel);


    // ── Connexions ────────────────────────────────────
    connect(m_addBtn, &QPushButton::clicked, this, &MusicalCardApp::ajouterPiste);

    connect(m_btnHaut, &QPushButton::clicked,
            this, [this] {
        m_scrollArea->scrollArea()->verticalScrollBar()->setValue(0);
    });


    connect(m_btnBas, &QPushButton::clicked,
            this, [this]() {
        m_scrollArea->scrollArea()->verticalScrollBar()->setValue(
            m_scrollArea->scrollArea()->verticalScrollBar()->maximum()
        );
    });


    // Signal valueChanged sur la scrollbar
    connect(m_scrollArea->scrollArea()->verticalScrollBar(), &QScrollBar::valueChanged,
            this, [this](const int value) {
        const int maximum = m_scrollArea->scrollArea()->verticalScrollBar()->maximum();
        m_statusLabel->setText(
            QString("%1 pistes | Position : %2 / %3")
            .arg(m_counter)
            .arg(value)
            .arg(maximum)
        );
    });


    // Signal rangeChanged : déclenché quand le contenu change de taille
    connect(m_scrollArea->scrollArea()->verticalScrollBar(), &QScrollBar::rangeChanged,
            this, [this](const int min, const int max) {
        qDebug() << "[rangeChanged] plage :" << min << "→" << max;

        // Scroller automatiquement vers le bas quand on ajoute une piste
        m_scrollArea->scrollArea()->verticalScrollBar()->setValue(max);
    });

    for (int i = 0; i < 5; ++i) ajouterPiste();


}



void MusicalCardApp::ajouterPiste() {
    ++m_counter;

    const QStringList titres = {
        "Bohemian Rhapsody", "Stairway to Heaven",
        "Hotel California",  "Smells Like Teen Spirit",
        "Imagine",           "Purple Haze",
        "What's Going On",   "Johnny B. Goode"
    };
    const QStringList artistes = {
        "Queen", "Led Zeppelin", "Eagles",
        "Nirvana", "John Lennon", "Jimi Hendrix",
        "Marvin Gaye", "Chuck Berry"
    };

    const int idx = (m_counter - 1) % titres.size();

    // ⚠️ Insertion AVANT le stretch final
    // count() - 1 = index du stretch → on insère juste avant
    const auto musicCard = new MusicalCard(titres[idx], artistes[idx], m_counter, m_content);
    m_listLayout->insertWidget(
        m_listLayout->count() - 1,
        musicCard->getCard()
    );

    qDebug() << "[ajouterPiste] piste" << m_counter << "ajoutée";
}

