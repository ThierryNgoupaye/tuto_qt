//
// Created by thierry on 18/05/2026.
//

#include "../../../headers/Conteneurs/tuto_qsplitter.h"


TutoQSplitter::TutoQSplitter(QWidget *parent) : QWidget(parent) {

    this->m_layout = new QVBoxLayout(this);
    this->m_splitter = new QSplitter(this);
    m_layout->addWidget(m_splitter);

    if (m_pages.data() and !m_pages.isEmpty()) {
        for (const auto page : m_pages) {
            this->m_layout->addWidget(page);
        }
    }

    // Méthode pour inserer un widget à une position
    //m_splitter->insertWidget(0, new QWidget(this));


    // Informations
    qDebug() << m_splitter->count();   // Nombre de widgets
   // m_splitter->widget(0);  // widget à l'index 0
  //  m_splitter->indexOf(monWidget);   // index d'un widget donné


    // Sauvegarder / restaurer l'état
    //const QByteArray state = m_splitter->saveState();
    //m_splitter->restoreState(state);

    setLayout(m_layout);
    connect(m_splitter, &QSplitter::splitterMoved, this,  &TutoQSplitter::onSplitterMoved);
}



TutoQSplitter& TutoQSplitter::setPages(this TutoQSplitter& self, const QList<QWidget*>& pages) {
    self.m_pages = pages;
    for (QWidget* page : pages) {
        self.m_splitter->addWidget(page);
    }
    return self;
}


TutoQSplitter& TutoQSplitter::setOrientation(this TutoQSplitter &self, const Qt::Orientation &orientation) {
    self.m_splitter->setOrientation(orientation);
    return self;
}


QSplitter* TutoQSplitter::splitter() const {
    qDebug() << "la 4" ;
    return this->m_splitter;
}


TutoQSplitter& TutoQSplitter::setSizes(this TutoQSplitter& self, const QList<int>& sizes) {
    self.m_splitter->setSizes(sizes);
    qDebug() << "la 0" ;
    return self;
}


TutoQSplitter& TutoQSplitter::setCollapsible(this TutoQSplitter& self, const int zone, const bool choice) {
    self.m_splitter->setCollapsible(zone, choice);
    qDebug() << "la 1" ;
    return self;
}



TutoQSplitter& TutoQSplitter::setStretchFactor(this TutoQSplitter& self, const int zone, const bool choice) {
    self.m_splitter->setStretchFactor(zone, choice);
    return self;
}



TutoQSplitter& TutoQSplitter::setHandleWidth(this TutoQSplitter& self, const int width) {
    self.m_splitter->setHandleWidth(width);
    return self;
}


TutoQSplitter& TutoQSplitter::addWidget(this TutoQSplitter& self, QWidget* widget) {
    self.m_splitter->addWidget(widget);
    return self;
}


void TutoQSplitter::onSplitterMoved(const int pos, const int index) {
    emit splitterMoved(pos, index);
}
