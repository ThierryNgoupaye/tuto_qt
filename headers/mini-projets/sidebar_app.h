//
// Created by thierry on 18/05/2026.
//

#ifndef QT_TUTO_SIDEBAR_APP_H
#define QT_TUTO_SIDEBAR_APP_H
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>

#include "../Conteneurs/tuto_qstackedWidget.h"

class SidebarApp : public QMainWindow {

    Q_OBJECT
    TutoQStackedWidget* m_stack{nullptr};
    QList<QPushButton*> m_navBtn;
    QLabel* m_statusLabel {nullptr};

    QWidget* m_central;
    QHBoxLayout* m_mainLayout;
    QWidget* m_sidebar;
    QVBoxLayout* m_sidebarLayout;
    QLabel* m_title;

    void naviguerVers(int index);

    public:
        explicit SidebarApp(const QString& title, QWidget* parent = nullptr);

    static QWidget* creerPage(const QString& texte, const QString& couleur, QWidget* parent);

    private slots:
        void onPageChanged(int index) const;

};



#endif //QT_TUTO_SIDEBAR_APP_H
