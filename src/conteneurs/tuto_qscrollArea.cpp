//
// Created by thierry on 18/05/2026.
//


#include "../../headers/Conteneurs/tuto_qscrollArea.h"

#include <QVBoxLayout>
#include <QScrollBar>

TutoQScrollArea::TutoQScrollArea( QWidget* page, QWidget *parent) : QWidget(parent){
    this->m_layout = new QVBoxLayout(this);
    this->m_scrollArea = new QScrollArea(this);
    m_layout->addWidget(m_scrollArea);


    // Installer le contenu
    // un seul widget à la fois, si on appelle setWidget() une deuxième fois, l'ancien widget est retiré mais pas détruit
    m_scrollArea->setWidget(page);




    // adaptation de la largeur
    m_scrollArea->setWidgetResizable(true);



    // Politique des scrollbars
    m_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);   // visible quand le contenu dépasse
    //m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // jamais visible


    // Accès aux scrollbars
    QScrollBar* vBar = m_scrollArea->verticalScrollBar();
    const QScrollBar* hBar = m_scrollArea->horizontalScrollBar();

    //Lire la position actuelle
    int posActuelle = vBar->value();
    int minimum = vBar->minimum();    // toujours 0
    int maximum = vBar->maximum();    // dépend de la taille du contenu


    // Naviguer programmatiquement
      vBar->setValue(0);   // retour en haut
 //   vBar->setValue(vBar->maximum());   // Aller tout en bas
 //   vBar->setValue(vBar->value() + 100);   // Déscendre de 100px



    // Alignement (si le contenu est plus petit que la ScrollArea)
    m_scrollArea->setAlignment(Qt::AlignCenter);   // centré
  //  m_scrollArea->setAlignment(Qt::AlignTop);   // collé en haut


    QWidget* contenu = m_scrollArea->widget();   // retourne nullptr si rien d'installé
}



QScrollArea* TutoQScrollArea::scrollArea() const {
    return this->m_scrollArea;
}


