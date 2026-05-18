//
// Created by thierry on 17/05/2026.
//

#include "../../headers/Qwidgets/tuto_qlineEdit.h"


TutoQlineEdit::TutoQlineEdit(QWidget *parent) : QWidget(parent) {
    this->input = new QLineEdit(this);

    // Placeholder
    input->setPlaceholderText("Rechercher un titre, un artiste ...");

    // Valeur initiale
    input->setText("The Dark Side");

    // Lecture Seule
    input->setReadOnly(false);

    //Mode mot de passe
    input->setEchoMode(QLineEdit::Password);

    // Limite de caractères
    input->setMaxLength(100);

    //Lire une valeur
    QString valeur = input->text();

    // Effacer l'input
   // input->clear();


    connect(input, &QLineEdit::textChanged, this, &TutoQlineEdit::onTextChanged);
    connect(input, &QLineEdit::textEdited, this, &TutoQlineEdit::onTextEdited);
    connect(input, &QLineEdit::returnPressed, this, &TutoQlineEdit::onReturnPressed);
    connect(input, &QLineEdit::editingFinished, this, &TutoQlineEdit::onEditingFinished);
}



void TutoQlineEdit::onTextChanged(const QString& text) const {
    qDebug() <<" Le texte a changé : " <<text << Qt::endl;
}

void TutoQlineEdit::onTextEdited(const QString& text) const {
    qDebug() << "Texte édité : " << text << Qt::endl;
    // Contrairement à textChanged, ne se déclenche pas si setText() est appelé programmatiquement
}

void TutoQlineEdit::onReturnPressed() const {
    const QString text = input->text();
    qDebug() << "Recherche lancée" << text << Qt::endl;
    input->clear();
}

void TutoQlineEdit::onEditingFinished() const{
    const QString text = input->text();
    qDebug() << "Saisie terminée";
}
