//
// Created by thierry on 19/05/2026.
//

#ifndef QT_TUTO_PANNEAU_H
#define QT_TUTO_PANNEAU_H
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>


class Panneau : public  QWidget {

    Q_OBJECT
    QLabel* m_titleBar {nullptr};
    QVBoxLayout* m_layout {nullptr};

    public:
        explicit Panneau(const QString& title, QWidget* content, QWidget* parent = nullptr);

};


#endif //QT_TUTO_PANNEAU_H
