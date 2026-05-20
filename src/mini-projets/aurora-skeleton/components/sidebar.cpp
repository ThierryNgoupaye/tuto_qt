//
// Created by thierry on 19/05/2026.
//


#include "../../../headers/mini-projets/aurora-skeleton/components/sidebar.h"

#include <QPushButton>
#include "../../../../headers/mini-projets/aurora-skeleton/components/main_content.h"


SideBar::SideBar(const QList<PageItem>& buttonList, QWidget *parent) : QWidget(parent) {

    assert(!buttonList.empty());

    // Layout
    m_layout = new QVBoxLayout(this);
    m_layout->setContentsMargins(0,0,0,0);
    m_layout->setSpacing(10);

    // Groupe de boutons de la sidebar
    m_btnGroup = new QButtonGroup(this);
    m_btnGroup->setExclusive(true);

    // Ajout des différents boutons de la sidebar
    for (const auto& [pageIcon, pageTitle, index]: buttonList) {
        assert(!QIcon(pageIcon).isNull());

        // ReSharper disable once CppDFAMemoryLeak
        const auto button = new QPushButton(QIcon(pageIcon), pageTitle, this);

        button->setCheckable(true);
        button->setIconSize(QSize(15,15));
        button->setFixedHeight(40);
        button->setCursor(Qt::PointingHandCursor);
        button->setFlat(true);

        m_btnGroup->addButton(button, index);
        m_layout->addWidget(button);

        // 1er bouton activé par défaut
        if (index == 0) button->setChecked(true);
    }

    m_layout->addStretch();

    // style
    setStyleSheet(R"(
        QPushButton {
            background: #353535;
            color: white;
            border-radius: 8px;
        }
        QPushButton:hover {
            background: #454545;
        }
        QPushButton:checked {
            background: #555555;
        }
        )"
    );

    connect(m_btnGroup, &QButtonGroup::idClicked, this, &SideBar::pageRequested);
}
