//
// Created by thierry on 18/05/2026.
//


#include "../../../headers/mini-projets/musical_card/musical_card.h"


MusicalCard::MusicalCard(const QString& title, const QString& artist, const int number, QWidget* parent) : QWidget(parent) {

    this->m_layout = new QHBoxLayout(this);
    m_layout->setContentsMargins(16, 12, 16, 12);

    // Numéro de piste
    this->m_number = new QLabel(QString::number(number), this);
    m_number->setFixedWidth(32);
    m_number->setAlignment(Qt::AlignCenter);
    m_number->setStyleSheet("color: #888; font-size: 13px;");

    // Icône fixe
    this->m_icon = new QPixmap(":/icons/musique.png");
    this->m_cardIcon = new QLabel(this);

    m_cardIcon->setPixmap(m_icon->scaled(40, 40));
    m_cardIcon->setFixedSize(40, 40);
    m_cardIcon->setAlignment(Qt::AlignCenter);
    m_cardIcon->setStyleSheet(
        "background-color: #4A90D9; border-radius: 6px;"
    );

    // Infos texte
    this->m_content = new QVBoxLayout();
    this->m_title  = new QLabel(title,  this);
    this->m_artist = new QLabel(artist, this);

    m_title->setStyleSheet("font-weight: bold; font-size: 14px; color: #222;");
    m_artist->setStyleSheet("font-size: 12px; color: #888;");

    m_content->addWidget(m_title);
    m_content->addWidget(m_artist);
    m_content->setSpacing(2);

    m_layout->addWidget(m_number);
    m_layout->addSpacing(10);
    m_layout->addWidget(m_cardIcon);
    m_layout->addSpacing(10);
    m_layout->addLayout(m_content, 1);

    // Style de la carte
    setStyleSheet(R"(
        MusicalCard {
            background-color: white;
            border: 1px solid #E8E8E8;
            border-radius: 8px;
        }
    )");
    setFixedHeight(72);
}


QWidget* MusicalCard::getCard() const {
    return const_cast<MusicalCard*>(this);
}
