//
// Created by thierry on 20/05/2026.
//

#ifndef QT_TUTO_SETTINGS_PAGE_H
#define QT_TUTO_SETTINGS_PAGE_H

#include <QScrollArea>
#include <QLabel>
#include <QVBoxLayout>

class SettingsPage : public QScrollArea {

    Q_OBJECT
    QWidget* m_container {nullptr};
    QVBoxLayout* m_layout {nullptr};
    QLabel* m_title {nullptr};


    public:
        explicit SettingsPage(QWidget* parent = nullptr);

};

#endif //QT_TUTO_SETTINGS_PAGE_H
