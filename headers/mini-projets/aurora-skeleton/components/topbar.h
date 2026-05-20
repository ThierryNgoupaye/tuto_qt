//
// Created by thierry on 19/05/2026.
//

#ifndef QT_TUTO_TOP_BAR_H
#define QT_TUTO_TOP_BAR_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <QLabel>

class TopBar : public QWidget {
    Q_OBJECT
    QHBoxLayout* m_topBarLayout {nullptr};
    QLineEdit* m_searchInput {nullptr};
    QCheckBox* m_shuffleBtn {nullptr};
    QLabel* m_shuffleBtnLabel {nullptr};

    public:
        explicit TopBar(QWidget* parent);
        [[nodiscard]] QLineEdit& searchInput() const;
        [[nodiscard]] QCheckBox& shuffleBtn() const;
};



#endif //QT_TUTO_TOP_BAR_H
