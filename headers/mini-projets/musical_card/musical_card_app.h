//
// Created by thierry on 18/05/2026.
//

#ifndef QT_TUTO_MUSICAL_CARD_APP_H
#define QT_TUTO_MUSICAL_CARD_APP_H
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>

#include "../../Conteneurs/tuto_qscrollArea.h"

class MusicalCardApp : public QMainWindow {

    Q_OBJECT

    TutoQScrollArea* m_scrollArea {nullptr};
    QWidget* m_content {nullptr};
    QWidget* m_central {nullptr};
    QVBoxLayout* m_mainLayout {nullptr};

    QHBoxLayout* m_ctrlLayout {nullptr};
    QPushButton* m_addBtn {nullptr};
    QPushButton* m_btnHaut {nullptr};
    QPushButton* m_btnBas {nullptr};




    QVBoxLayout* m_listLayout {nullptr};
    QLabel* m_statusLabel {nullptr};
    int m_counter{0};

    void ajouterPiste();

    public :
        explicit MusicalCardApp(QWidget* parent = nullptr);


};




#endif //QT_TUTO_MUSICAL_CARD_APP_H
