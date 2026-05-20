//
// Created by thierry on 19/05/2026.
//

#ifndef QT_TUTO_LIBRARY_PAGE_H
#define QT_TUTO_LIBRARY_PAGE_H

#include <QScrollArea>
#include <QVBoxLayout>
#include <QLabel>

class LibraryPage : public QScrollArea {

    Q_OBJECT
    QWidget* m_container {nullptr};
    QVBoxLayout* m_layout {nullptr};
    QLabel* m_title {nullptr};

    public:
        explicit LibraryPage(QWidget* parent = nullptr);
};

#endif //QT_TUTO_LIBRARY_PAGE_H
