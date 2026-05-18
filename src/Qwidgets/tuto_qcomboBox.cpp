//
// Created by thierry on 17/05/2026.
//

#include "../../headers/Qwidgets/tuto_qcomboBox.h"


TutoQComboBox::TutoQComboBox(const QList<QString>& items, const std::map<QString, QVariant> &itemsMap, QWidget *parent) : QWidget(parent){

    this->comboBox = new QComboBox(this);

    if (!items.isEmpty()) {
        for (const auto& item : items) {
            comboBox->addItem(item);
        }
    }
    else if (!itemsMap.empty()) {
        for (const auto& [key, value] : itemsMap) {
            comboBox->addItem(key, value);
        }
    }

    int index = comboBox->currentIndex();
    QString texte = comboBox->currentText();

    if (!itemsMap.empty()) QVariant data = comboBox->currentData();

    connect(comboBox, &QComboBox::currentIndexChanged, this, &TutoQComboBox::onCurrentIndexChanged );
}


void TutoQComboBox::onCurrentIndexChanged(const int index) const {
    const QString currentText = comboBox->itemText(index);
    qDebug() << "Le texte actuellement sélectionné à l'indexe : " << index << " est : " << currentText;
    qDebug() << "La méthode currentText donne : " << comboBox->currentText();
}
