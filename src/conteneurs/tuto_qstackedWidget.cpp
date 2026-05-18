//
// Created by thierry on 18/05/2026.
//

#include "../../headers/Conteneurs/tuto_qstackedWidget.h"




TutoQStackedWidget::TutoQStackedWidget(const QList<QWidget*>& m_pages, QWidget *parent) : QWidget(parent){

    this->m_layout = new QVBoxLayout(this);
    this->stack = new QStackedWidget(this);
    this->pages = m_pages;

    m_layout->addWidget(stack);

    for (const auto page : pages) {
        this->stack->addWidget(page);
    }

    // Insérer une page
    //stack->insertWidget(2, pages[0]);  // insère la premiere page à l'index 2


    // Naviguer
    //stack->setCurrentIndex(1);     // par index
    //stack->setCurrentWidget(new QWidget(this));    // par pointeur

    int idx = stack->currentIndex();     // index actuel
    QWidget* w = stack->currentWidget();  // pointeur vers la page actuelle


    // Informations
    qDebug() << "Nombre de pages" << stack->count();   // Nombre de pages
    QWidget* w2 = stack->widget(2);     // Page à l'index 2
    int idx2 = stack->indexOf(pages[0]);  // retourne l'indexe d'un widget donné


    // Supprimer
    //stack->removeWidget(pages[0]);  // meme règle qu'avec un QTabWidget, retire sans détruire

    connect(stack, &QStackedWidget::currentChanged, this, &TutoQStackedWidget::onCurrentPageChanged);
    connect(stack, &QStackedWidget::widgetRemoved, this, &TutoQStackedWidget::onWidgetRemoved);

}


void TutoQStackedWidget::onCurrentPageChanged(const int index) {
    emit pageChanged(index);
    qDebug() << "Changement de page pour aller à l'index " << index;
}


void TutoQStackedWidget::onWidgetRemoved(const int index) const {
    qDebug() << "Widget " << index << " supprimé !";
}


void TutoQStackedWidget::retirerPage(const int index) const {
    if (stack->count() <= 1) {
        qDebug() << "Dernier widget, impossible de le supprimer !";
        return;
    }
    QWidget* w = stack->widget(index);
    stack->removeWidget(w);
    delete w;
}








