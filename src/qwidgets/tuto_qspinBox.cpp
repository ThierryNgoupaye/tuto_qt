//
// Created by thierry on 17/05/2026.
//

#include "../../headers/Qwidgets/tuto_qspinBox.h"


TutoQSpinBox::TutoQSpinBox(QWidget *parent) : QWidget(parent) {

    this->spinBox = new QSpinBox(this);
    spinBox->setRange(0,300);
    spinBox->setValue(120);
    spinBox->setSuffix(" BPM");    // un suffixe à afficher après la valeur
    spinBox->setPrefix("♩ ");     // un préfixe

    connect(spinBox, &QSpinBox::valueChanged, this, &TutoQSpinBox::onValueChanged);
}


void TutoQSpinBox::onValueChanged(const int value) const {
    qDebug() << "Valeur :" << value;
}



TutoQDoubleSpinBox::TutoQDoubleSpinBox(QWidget *parent) : QWidget(parent) {

    this->spinBox = new QDoubleSpinBox(this);
    spinBox->setRange(0.0,2.0);
    spinBox->setSingleStep(0.5);
    spinBox->setValue(1.0);
    spinBox->setSuffix(" BPM");    // un suffixe à afficher après la valeur
    spinBox->setPrefix("♩ ");     // un préfixe

    connect(spinBox, &QDoubleSpinBox::valueChanged, this, &TutoQDoubleSpinBox::onValueChanged);
}


void TutoQDoubleSpinBox::onValueChanged(const double value) const {
    qDebug() << "Valeur :" << value;
}