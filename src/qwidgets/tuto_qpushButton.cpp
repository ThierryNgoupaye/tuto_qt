//
// Created by thierry on 17/05/2026.
//

#include "../../headers/Qwidgets/tuto_qpushButton.h"


TutoQPushButton::TutoQPushButton(QWidget *parent)  :QWidget(parent) {


    this->button = new QPushButton("   Lecture",this);

    button->setIcon(QIcon(":/icons/play-button.png"));
    button->setIconSize(QSize(24,24));


    // Bouton par défaut (activé par Entrée dans un dialog)
    button->setDefault(true);


    // Bouton toggle (reste enfoncé)
    button->setCheckable(true);
    button->setChecked(false);


    // Taille fixe ou contraire
    button->setFixedSize(120, 40);


    this->button->connect(button, &QPushButton::clicked, this,&TutoQPushButton::onClicked);
    this->button->connect(button, &QPushButton::pressed, this,&TutoQPushButton::onPressed);
    this->button->connect(button, &QPushButton::released, this,&TutoQPushButton::onReleased);
    this->button->connect(button, &QPushButton::toggled, this,&TutoQPushButton::onChecked);
}


void TutoQPushButton::onClicked() const {
    qDebug() << "Ce bouton a été cliqué !";
}


void TutoQPushButton::onPressed() const {
    qDebug() << "Le bouton a été préssé !" << Qt::endl;
}

void TutoQPushButton::onReleased() const {

    qDebug() << "Le bouton a été relaché !" << Qt::endl;

}

void TutoQPushButton::onChecked(const bool checked) const {
    const QString msg = (checked) ? "Vous etes en pause" : "Vous en sur play";
    qDebug() << msg << Qt::endl;
}
