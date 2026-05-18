//
// Created by thierry on 17/05/2026.
//

#include "../../headers/Qwidgets/tuto_qslider.h"


TutoQSlider::TutoQSlider(const Qt::Orientation& orientation, QWidget *parent) : QWidget(parent) {

    this->slider = new QSlider(orientation, this);

    // Plage de valeurs
    slider->setRange(0,100);
    slider->setValue(75);         // valeur initiale
    slider->setSingleStep(1);      // pas avec les touches directionnelles (on avance et on recule de 1)
    slider->setPageStep(10);      // pas avec Up/Down


    const int val = slider->value();
    qDebug() << "Valeur initialle" << val;

    connect(slider, &QSlider::valueChanged, this, &TutoQSlider::onValueChanged);
    connect(slider, &QSlider::sliderMoved, this, &TutoQSlider::onSliderMoved);
}


void TutoQSlider::onValueChanged(const int value) const {
    qDebug() << "Etat actuel :" << value;
}

void TutoQSlider::onSliderMoved(const int value) const {
    qDebug() << " L'utilisateur a déplacé le curseur" << value;
}

void TutoQSlider::onSliderReleased() const {
    const int position = slider->value();
    qDebug() << " L'utilisateur a relâché le slider : " << position;
}


