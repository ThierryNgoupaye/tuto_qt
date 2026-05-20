//
// Created by thierry on 19/05/2026.
//

#include "../../../headers/mini-projets/aurora-skeleton/pages/home_page.h"


HomePage::HomePage(QWidget *parent) : QScrollArea(parent) {

    m_container = new QWidget(this);

    m_layout = new QVBoxLayout(m_container);

    m_title = new QLabel("Page d'accueil", this);
    m_title->setAlignment(Qt::AlignCenter);
    m_title->setStyleSheet(R"(
        background : #FFF0F0;
        font-size : 16px;
        font-weight: bold;
    )");

    m_layout->addWidget(m_title);
    m_container->setLayout(m_layout);
    setWidget(m_container);
    setWidgetResizable(true);
}
