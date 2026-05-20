//
// Created by thierry on 19/05/2026.
//

#include "../../../headers/mini-projets/code_editor/panneau.h"


Panneau::Panneau(const QString &title, QWidget *content, QWidget *parent) : QWidget (parent) {

    this->m_layout = new QVBoxLayout(this);
    m_layout->setContentsMargins(5,5,5,5);
    m_layout->setSpacing(5);

    // Barre de titre du panneau
    this->m_titleBar = new QLabel(title, this);
    m_titleBar->setFixedHeight(35);
    m_titleBar->setAlignment(Qt::AlignCenter);
    m_titleBar->setStyleSheet(
        R"(
            QLabel {
                background-color: #2C2F3A;
                color: #AAAAAA;
                font-size: 18px;
                font-weight: bold;
                padding-left: 12px;
                border-bottom: 1px solid #1A1C24;
            }
        )"
    );
    m_layout->addWidget(m_titleBar);
    m_layout->addWidget(content, 1);
    this->setLayout(m_layout);

}
