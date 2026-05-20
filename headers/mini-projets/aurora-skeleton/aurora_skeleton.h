//
// Created by thierry on 19/05/2026.
//

#ifndef QT_TUTO_AURORA_SKELETON_H
#define QT_TUTO_AURORA_SKELETON_H

#include <QMainWindow>
#include <QPushButton>

#include <QSplitter>
#include <QStackedWidget>


#include "components/main_content.h"
#include "components/playerbar.h"
#include "components/sidebar.h"
#include "components/topbar.h"


class AuroraSkeletonApp : public QMainWindow {

    Q_OBJECT
    QWidget* m_central {nullptr};
    QVBoxLayout* m_mainLayout {nullptr};

    TopBar* m_topBar;

    QSplitter* m_splitter {nullptr};

    SideBar* m_sideBar {nullptr};
    MainContent* m_mainContent;


    PlayerBar* m_playerBar {nullptr};

    public:
        explicit AuroraSkeletonApp(QWidget* parent = nullptr);

    private slots:
        void onPageRequested(int index) const;

};




#endif //QT_TUTO_AURORA_SKELETON_H
