//
// Created by thierry on 16/05/2026.
//

#ifndef QT_TUTO_MAIN_WINDOW_H
#define QT_TUTO_MAIN_WINDOW_H

#include <qwidget.h>
#include <QMainWindow>
#include "CustomButton.h"
#include <QVBoxLayout>


class Main_window : public QMainWindow {
    Q_OBJECT
    QVBoxLayout* m_layout;
    QWidget* m_central;
    QList<CustomButton*> m_listBtn{};
    QHBoxLayout* m_horizontal_layout;

    public:
        explicit Main_window(QWidget* parent = Q_NULLPTR);
        ~Main_window() override;
    

};


#endif //QT_TUTO_MAIN_WINDOW_H