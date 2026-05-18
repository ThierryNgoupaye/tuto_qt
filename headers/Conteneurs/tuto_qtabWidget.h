//
// Created by thierry on 17/05/2026.
//

#ifndef QT_TUTO_TUTO_QTABWIDGET_H
#define QT_TUTO_TUTO_QTABWIDGET_H

#include <QTabWidget>
#include <QVBoxLayout>

// Il s'agit d'un widget qui affiche plusieurs pages, chacune accessible via un onglet en haut
// ou en bas/gauche/droit. Qt gère tout: le clic sur l'onglet, le changement de page, l'affichage.

using PageList = std::map<QString, std::tuple<QWidget*, std::optional<QIcon>>>;

class TutoQTabWidget : public QWidget {
    Q_OBJECT
    QVBoxLayout* layout;
    QTabWidget* tabWidget;
    PageList m_pages;


    public:
        explicit TutoQTabWidget(const PageList& pages, QWidget* parent = nullptr);
        [[nodiscard]] QTabWidget* getTabWidget() const {
            return this->tabWidget;
        }

    signals:
        void tabChanged(int index);


    private slots:
        void onCurrentTabChanged(int index);
        void onTabCloseRequested(int index) const;
        void onTabBarDoubleClicked(int index) const;


};


#endif //QT_TUTO_TUTO_QTABWIDGET_H
