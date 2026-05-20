//
// Created by thierry on 20/05/2026.
//

#ifndef QT_TUTO_AUDIO_ENGINE_H
#define QT_TUTO_AUDIO_ENGINE_H

#include <QObject>
#include <QTimer>


class AudioEngine : public QObject {
    Q_OBJECT

    int m_volume {50};
    int m_position {0};
    bool m_playing {false};
    QTimer m_positionTimer;

    public:
        explicit AudioEngine(QObject *parent = nullptr);

    signals:
        void playbackStarted();
        void playbackPaused();
        void playbackStopped();
        void volumeChanged(int newVolume);
        void positionChanged(int positionMs);
        void trackLoaded(const QString& title, int durationMs);
        void errorOccurred(const QString& message);

    public slots:
        void play();
        void pause();
        void stop();
        void setVolume(int volume);
        void seek(int positionMs);
        void loadTrack(const QString& title, int durationMs);
};



#endif //QT_TUTO_AUDIO_ENGINE_H
