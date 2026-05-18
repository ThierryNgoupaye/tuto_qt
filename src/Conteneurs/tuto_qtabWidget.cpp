//
// Created by thierry on 17/05/2026.
//


#include "../../headers/Conteneurs/tuto_qtabWidget.h"
#include <QVBoxLayout>


TutoQTabWidget::TutoQTabWidget(const PageList& pages, QWidget *parent) : QWidget(parent) {

    this->tabWidget = new QTabWidget(this);
    this->layout = new QVBoxLayout(this);

    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(tabWidget);


    for (const auto& [title, widget] : pages) {
        if (const auto& [page, icon] = widget; icon.has_value()) {
            page->setParent(this);
            tabWidget->addTab(page, icon.value(), title);
        }
        else {
            this->tabWidget->addTab(page, title);   // retourne l'index de la pag ajoutée
        }
    }


    //Insérer à une position précise plutot qu'à la fin
    //tabWidget->insertTab(0, new QWidget(this), "Podcast");       // insère à la position 0


    // naviguer entre les pages
    //tabWidget->setCurrentIndex(0);   // Active la page à l'indexe 0
    //tabWidget->setCornerWidget(/*page*/);  // active directement par pointeur


    const int actif = tabWidget->currentIndex(); // index de la page active
    QWidget* widget = tabWidget->currentWidget();  // retourne la page active


    // Modifier les onglets
    //tabWidget->setTabText(0, "Musique");   // Change le texte d'un onglet
    //tabWidget->setTabToolTip(0, "Votre bibliothèque musicale");
    //tabWidget->setTabEnabled(1, false);   // désactive un onglet (grisé)

    // supprimer des pages
    //tabWidget->removeTab(0);    // la page est retireé du QTabWidget mais pas détruit n mémoire


    // Position des onglets
    //tabWidget->setTabPosition(QTabWidget::North); //En haut (par défaut)
    //tabWidget->setTabPosition(QTabWidget::South);  // En bas
    //tabWidget->setTabPosition(QTabWidget::West);  // À gauche
    //tabWidget->setTabPosition(QTabWidget::East);  // à droite


    // Onglets fermables
    //tabWidget->setTabsClosable(true);       // Affiche un bouton x sur chaque onglet
    //tabWidget->setMovable(true);                // L'utilisateur peut réordonner les onglets par drag and drop


    // Nombre de pages
    const int nombre = tabWidget->count();


    connect(tabWidget, &QTabWidget::currentChanged, this, &TutoQTabWidget::onCurrentTabChanged);
    connect(tabWidget, &QTabWidget::tabCloseRequested, this, &TutoQTabWidget::onTabCloseRequested);
    connect(tabWidget, &QTabWidget::tabBarDoubleClicked, this, &TutoQTabWidget::onTabBarDoubleClicked);
}



void TutoQTabWidget::onCurrentTabChanged(const int index)  {
    emit tabChanged(index);
    const QString titre = this->tabWidget->tabText(index);
    qDebug() << "Onglet actif :" << index << " de nom " << titre;
}


void TutoQTabWidget::onTabCloseRequested(const int index) const {
    if (this->tabWidget->count() <= 1) {
        qDebug() << "Impossible de fermer le dernier onglet ";
        return;
    }

    const QWidget* widget = tabWidget->widget(index);
    tabWidget->removeTab(index);
    delete widget;
    qDebug() << "Onglet " << tabWidget->tabText(index) << " fermé !";
}


void TutoQTabWidget::onTabBarDoubleClicked(const int index) const {
    qDebug() << "Double click à l'index " << index;
    this->tabWidget->setTabText(index, "✏️ " + tabWidget->tabText(index));
}