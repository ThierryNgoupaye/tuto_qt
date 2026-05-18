//
// Created by thierry on 17/05/2026.
//

#include "../../headers/Qwidgets/tuto_qlabel.h"


TutoQLabel::TutoQLabel(QWidget *parent): QWidget(parent) {

    this->label = new QLabel(this);

    // Alignement du texte
    label->setAlignment(Qt::AlignCenter);
    label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);


    // Qt supporte le HTML basique dans les labels
    label->setText("<b>Titre</b> - <i>Artiste</i>");
    label->setTextFormat(Qt::RichText);    // Force l'interprétation HTML
  //  label->setTextFormat(Qt::PlainText);   // Force le texte brut


    // Retour à la ligne automatique
    label->setWordWrap(true);

    // Taille adaptée au contenu
    label->adjustSize();
}


void TutoQLabel::applyLabelWithImage() const {
    if (const QPixmap pochette(":/images/cover.jpg"); pochette.isNull()) {
        label->setText("Image manquante !");
    }
    else {
        this->label->setPixmap(
            pochette.scaled(
                this->label->size(),
                Qt::KeepAspectRatio,
                Qt::SmoothTransformation
            )
        );
    }
    this->label->setAlignment(Qt::AlignCenter);
}
