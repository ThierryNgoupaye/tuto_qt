//
// Created by thierry on 20/05/2026.
//

#include "../../../headers/mini-projets/aurora-skeleton/components/main_content.h"


MainContent::MainContent(const QList<QWidget*>& pages, QWidget *parent) : QWidget(parent) {
    assert(!pages.isEmpty());
    m_layout = new QVBoxLayout(this);
    m_content = new QStackedWidget(this);


    for (const auto& page : pages) {
        m_content->addWidget(page);
    }

    m_layout->addWidget(m_content);
    setLayout(m_layout);

}


QStackedWidget* MainContent::getContent() const {
    return m_content;
}



