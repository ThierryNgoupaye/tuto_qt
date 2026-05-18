//
// Created by thierry on 18/05/2026.
//

#ifndef QT_TUTO_QSTACKEDWIDGET_H
#define QT_TUTO_QSTACKEDWIDGET_H

#include <QWidget>
#include  <QStackedWidget>
#include <QVBoxLayout>


class QVBoxLayout;

class TutoQStackedWidget : public QWidget {

    Q_OBJECT
    QStackedWidget * stack;
    QVBoxLayout* layout;
    QList<QWidget*> pages;

    public:
        explicit  TutoQStackedWidget(const QList<QWidget*>& m_pages, QWidget *parent=nullptr);
        [[nodiscard]] QStackedWidget* getStack() const {
            return this->stack;
        }

    void retirerPage(int index) const;

    signals:
        void pageChanged(int index);

    private slots:
        void onCurrentPageChanged(int index);
        void onWidgetRemoved(int index) const;

};

#endif //QT_TUTO_QSTACKEDWIDGET_H
