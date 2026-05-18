//
// Created by thierry on 17/05/2026.
//

#include "../../headers/Qwidgets/tuto_qprogressBar.h"

TutoQProgressBar::TutoQProgressBar(QWidget *parent) : QWidget(parent){

    this->progressBar = new QProgressBar(this);

    progressBar->setRange(0, 100);

    progressBar->setValue(0);

    // Mode indéterminé (chargement sans % connu)
    //progressBar->setRange(0, 0);

    //cacher le texte de pourcentage
    progressBar->setTextVisible(false);

    // Mise à jour
    //progressBar->setValue(42);
}
