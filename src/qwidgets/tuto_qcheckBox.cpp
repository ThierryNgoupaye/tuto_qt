//
// Created by thierry on 17/05/2026.
//

#include "../../headers/Qwidgets/tuto_qcheckBox.h"


TutoQCheckBox::TutoQCheckBox(QString title, QWidget *parent) : QWidget(parent) {

    this->checkBox = new QCheckBox(std::move(title), this);
    checkBox->setChecked(true);
    connect(checkBox, &QCheckBox::toggled, this, &TutoQCheckBox::onCheckBoxToggled);
}



void TutoQCheckBox::onCheckBoxToggled(const bool checked) const {
    qDebug() << (checked ? "Shuffle ON" : "Shuffle OFF");
}




TutoRadioButton::TutoRadioButton(QString title, QWidget *parent) : QWidget(parent) {
    this->checkBox = new QRadioButton(std::move(title), this);
    checkBox->setChecked(true);
    connect(checkBox, &QRadioButton::toggled, this, &TutoRadioButton::onRadioButtonToggled);

}


void TutoRadioButton::onRadioButtonToggled(const bool checked) const {
    qDebug() << (checked ? "Qualité basse sélectionnée" : "Rien à dire !");
}
