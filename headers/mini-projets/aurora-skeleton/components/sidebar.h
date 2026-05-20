//
// Created by thierry on 19/05/2026.
//

#ifndef QT_TUTO_SIDEBAR_H
#define QT_TUTO_SIDEBAR_H
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QPushButton>


struct PageItem {
    QString icon;
    QString title;
    int index;
};


class SideBar : public QWidget {

    Q_OBJECT
    QVBoxLayout* m_layout {nullptr};
    QButtonGroup* m_btnGroup {nullptr};

    public:
        explicit SideBar(const QList<PageItem>& buttonList, QWidget* parent);


    signals:
        void pageRequested(int index);
};

#endif //QT_TUTO_SIDEBAR_H
