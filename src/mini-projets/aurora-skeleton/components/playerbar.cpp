//
// Created by thierry on 19/05/2026.
//

#include <QIcon>
#include "../../../headers/mini-projets/aurora-skeleton/components/playerbar.h"



PlayerBar::PlayerBar(QWidget *parent) : QWidget(parent) {

    m_layout = new QHBoxLayout(this);

    // Bouton back
    m_backBtn = new QPushButton(QIcon(":/icons/back.png"), "", this);
    m_backBtn->setIconSize(QSize(24, 24));
    m_backBtn->setCursor(Qt::PointingHandCursor);
    m_backBtn->setToolTip("Précédent");
    m_backBtn->setFlat(true);

    // Bouton Play
    m_playBtn = new QPushButton(QIcon(":/icons/play-button.png"),"", this);
    m_playBtn->setIconSize(QSize(50, 50));
    m_playBtn->setCursor(Qt::PointingHandCursor);
    m_playBtn->setToolTip("Play");
    m_playBtn->setFlat(true);

    // Bouton next
    m_nextBtn = new QPushButton(QIcon(":/icons/next.png"), "", this);
    m_nextBtn->setIconSize(QSize(24, 24));
    m_nextBtn->setCursor(Qt::PointingHandCursor);
    m_nextBtn->setToolTip("Suivant");
    m_nextBtn->setFlat(true);


    // Progression de la musique
    m_progressBar = new QSlider(Qt::Horizontal, this);
    m_progressBar->setRange(0, 300);
    m_progressBar->setFixedHeight(40);
    m_progressBar->setValue(20);


    // Bouton de mute
    m_microBtn = new QPushButton(QIcon(":/icons/volume-up.png"),"",this);
    m_microBtn->setIconSize(QSize(30, 30));
    m_microBtn->setCursor(Qt::PointingHandCursor);
    m_microBtn->setToolTip("Mute");
    m_microBtn->setFlat(true);


    // Bouton de gestion du volume
    m_volumeBar = new QSlider(Qt::Horizontal, this);
    m_volumeBar->setRange(0, 100);
    m_volumeBar->setFixedHeight(20);
    m_volumeBar->setValue(20);

    // Assemblage
    m_layout->addWidget(m_backBtn);
    m_layout->addWidget(m_playBtn);
    m_layout->addWidget(m_nextBtn);
    m_layout->addStretch();
    m_layout->addWidget(m_progressBar, 1);
    m_layout->addStretch();
    m_layout->addWidget(m_microBtn);
    m_layout->addWidget(m_volumeBar);

}
