//
// Created by thierry on 17/05/2026.
//

#ifndef QT_TUTO_TABWIDGET_APP_H
#define QT_TUTO_TABWIDGET_APP_H

#include <QMainWindow>
#include <QLabel>
#include <QStatusBar>
#include <QPushButton>
#include <QButtonGroup>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QRadioButton>

#include "../Conteneurs/tuto_qtabWidget.h"


using WidgetPage = std::tuple<QWidget*, std::optional<QIcon>>;

class TabWidgetApp : public QMainWindow {

    Q_OBJECT
    QWidget* centralWidget;
    QHBoxLayout* ctrlLayout;
    QVBoxLayout* mainLayout;
    TutoQTabWidget* tabWidget;
    QGroupBox* groupBox;

    QButtonGroup* buttonGroup;
    QPushButton* btnToggleClose;
    QPushButton* btnToggleMove;
    QRadioButton* radioNorth;
    QRadioButton* radioSouth;
    QRadioButton* radioWest;
    QRadioButton* radioEast;

    QLabel* label;

    public:
        explicit TabWidgetApp(QWidget* parent = nullptr);


    private slots:
        void onCurrentTabChanged(int index) const;
        void onButtonGroupIdClicked(int id) const;
        void onEnableDisableTab(bool checked) const;
        void onToggleMove(bool checked) const;


    static WidgetPage creerPage(const QString& texte, const QString& couleur, const std::optional<QIcon>& icon, QWidget* parent);
};

#endif //QT_TUTO_TABWIDGET_APP_H
