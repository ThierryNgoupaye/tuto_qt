//
// Created by thierry on 20/05/2026.
//

#ifndef QT_TUTO_MAIN_CONTENT_H
#define QT_TUTO_MAIN_CONTENT_H
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QWidget>


class MainContent : public QWidget {
    Q_OBJECT
    QStackedWidget* m_content {nullptr};
    QVBoxLayout* m_layout {nullptr};

    public:
        explicit MainContent(const QList<QWidget*>& pages, QWidget* parent);
        [[nodiscard]] QStackedWidget* getContent() const;



};

#endif //QT_TUTO_MAIN_CONTENT_H
