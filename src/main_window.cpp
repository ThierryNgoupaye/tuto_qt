//
// Created by thierry on 16/05/2026.
//

#include "../headers/main_window.h"

#include <iostream>
#include <QDebug>


Main_window::Main_window(QWidget *parent) : QMainWindow(parent) {

    setWindowTitle("Ma super app");

    this->m_central = new QWidget(this);
    this->m_horizontal_layout = new QHBoxLayout(m_central);
    this->m_layout = new QVBoxLayout();

    const auto test = new QPushButton("Big Button", m_central);

    m_horizontal_layout->addLayout(m_layout);
    m_horizontal_layout->addWidget(test);


    this->m_central->setLayout(this->m_horizontal_layout);


    qInfo() << " Construction de la fenetre principale " << Qt::endl;


    for (int i = 0; i < 10; ++i) {
        const QString title = "Bouton " + QString::number(i);
        const auto btn = new CustomButton(title, this->m_central);
        this->m_listBtn.append(btn);
        this->m_layout->addWidget(btn);
    }


    setCentralWidget(m_central);

}


Main_window::~Main_window() {
    qDebug("Destruction de la fenetre principale");
}
