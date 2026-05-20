//
// Created by thierry on 19/05/2026.
//

#include "../../../headers/mini-projets/aurora-skeleton/components/topbar.h"

#include <QPushButton>


TopBar::TopBar(QWidget *parent) : QWidget(parent) {

    setFixedHeight(60);
    m_topBarLayout = new QHBoxLayout(this);

    m_searchInput = new QLineEdit(this);
    m_searchInput->setFixedSize(250, 40);
    m_searchInput->setPlaceholderText(tr("Rechercher une musique"));

    m_shuffleBtnLabel = new QLabel("Lecture aléatoire", this);
    m_shuffleBtn = new QCheckBox(this);
    m_shuffleBtn->setMinimumSize(QSize(60,60));
    m_shuffleBtn->setCheckable(true);

    m_topBarLayout->addWidget(m_searchInput);
    m_topBarLayout->addStretch();
    m_topBarLayout->addWidget(m_shuffleBtnLabel);
    m_topBarLayout->addWidget(m_shuffleBtn);

    setStyleSheet(R"(
            QLineEdit {
                border: 1px solid rgba(255, 255, 255, 40);
                border-radius: 10px;
                padding: 4px 10px;
                background-color: rgba(255,255,255,20);
                color: white;
            }
            QLineEdit:focus {
                border: 1px solid rgba(255, 255, 255, 80);
            }
        )"
    );
}



QLineEdit& TopBar::searchInput() const {
    return *m_searchInput;
}


QCheckBox& TopBar::shuffleBtn() const {
    return *m_shuffleBtn;
}