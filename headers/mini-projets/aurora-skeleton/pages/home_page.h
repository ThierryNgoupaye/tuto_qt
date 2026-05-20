//
// Created by thierry on 19/05/2026.
//

#ifndef QT_TUTO_HOME_PAGE_H
#define QT_TUTO_HOME_PAGE_H
#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>


class HomePage : public QScrollArea {

    Q_OBJECT

    QWidget* m_container {nullptr};
    QVBoxLayout* m_layout {nullptr};
    QLabel* m_title {nullptr};

    public:
        explicit HomePage(QWidget* parent = nullptr);
};



#endif //QT_TUTO_HOME_PAGE_H
