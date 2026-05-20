//
// Created by thierry on 20/05/2026.
//

#ifndef QT_TUTO_PLAYER_UI_H
#define QT_TUTO_PLAYER_UI_H

#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStatusBar>
#include <QComboBox>
#include <QMainWindow>
#include <QProgressBar>


class PlayerUI : public QMainWindow {

    Q_OBJECT
    QWidget* m_central{nullptr};
    QVBoxLayout* m_layout {};

    QLabel* m_trackLabel {};
    QLabel* m_positionLabel {};
    QLabel* m_durationLabel {};


    QHBoxLayout* m_progressRow {};
    QPushButton* m_loadBtn {};
    QPushButton* m_playBtn {};
    QPushButton* m_stopBtn{};
    QSlider* m_progressSlider{};


    QHBoxLayout* m_ctrlRow {};

    QHBoxLayout* m_volumeRow {};
    QSlider* m_volumeSlider{};
    QLabel* m_volumeLabel {};
    QComboBox* m_trackSelector {};
    QLabel* m_statusLabel{};

    bool m_isPlaying {false};
    int m_duration {0};

    QProgressBar* m_taskProgress {nullptr};
    QPushButton* m_scanBtn {nullptr};


    public:
        explicit PlayerUI(QWidget* parent = nullptr);

    signals:
        void playRequested();
        void pauseRequested();
        void stopRequested();
        void volumeRequested(int volume);
        void seekRequested(int positionMs);
        void trackLoadRequested(const QString& title, int duration);
        void heavyTaskRequested(const QString& task);


    public slots:
        void onPlaybackStarted();
        void onPlaybackPaused();
        void onPlaybackStopped();
        void onVolumeChanged(int volume) const;
        void onPositionChanged(int positionMs) const;
        void onTrackLoaded(const QString& title, int durationMs);
        void onErrorOccurred(const QString& message) const;
        void onTaskStarted(const QString& task) const;
        void onProgressUpdated(int percent) const;
        void onTaskFinished(const QString& task) const;


    private:
        static QString formatDuration(int duration);
};

#endif //QT_TUTO_PLAYER_UI_H
