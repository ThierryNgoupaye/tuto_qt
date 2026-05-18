//
// Created by thierry on 18/05/2026.
//

#ifndef QT_TUTO_TUTO_QSCROLLAREA_H
#define QT_TUTO_TUTO_QSCROLLAREA_H

#include <QScrollArea>
#include <QVBoxLayout>

class TutoQScrollArea : public QWidget {
    Q_OBJECT
    QVBoxLayout* m_layout;
    QScrollArea* m_scrollArea;


    public:
        explicit TutoQScrollArea( QWidget* page = nullptr, QWidget* parent = nullptr);
        [[nodiscard]] QScrollArea* scrollArea() const;
};


#endif //QT_TUTO_TUTO_QSCROLLAREA_H
