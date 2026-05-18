//
// Created by thierry on 16/05/2026.
//

#include "../headers/CustomButton.h"

CustomButton::CustomButton(QString title, QWidget *parent) : QPushButton(std::move(title), parent) {
    setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
}