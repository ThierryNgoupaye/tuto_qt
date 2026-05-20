//
// Created by thierry on 19/05/2026.
//

#ifndef QT_TUTO_PLAYER_BAR_H
#define QT_TUTO_PLAYER_BAR_H

#include <QHBoxLayout>
#include <QProgressBar>
#include <QSlider>
#include <QWidget>
#include <QPushButton>

class PlayerBar : public QWidget {

    Q_OBJECT

    QHBoxLayout* m_layout {nullptr};

    QPushButton* m_backBtn {nullptr};
    QPushButton* m_playBtn {nullptr};
    QPushButton* m_nextBtn {nullptr};

    QSlider* m_progressBar {nullptr};

    QPushButton* m_microBtn {nullptr};
    QSlider* m_volumeBar {nullptr};

    public:
        explicit PlayerBar(QWidget* parent);


};


#endif //QT_TUTO_PLAYER_BAR_H
