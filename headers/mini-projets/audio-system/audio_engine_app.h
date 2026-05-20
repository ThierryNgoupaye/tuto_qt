//
// Created by thierry on 20/05/2026.
//

#ifndef QT_TUTO_AUDIO_ENGINE_APP_H
#define QT_TUTO_AUDIO_ENGINE_APP_H
#include <QObject>
#include <QWidget>
#include <QThread>

#include "audio_engine.h"
#include "player_ui.h"
#include "worker_simulator.h"

PlayerUI* startAudioEngineApp();

class AudioEngineApp: public QObject {
    Q_OBJECT

    QThread* m_engineThread {nullptr};
    QThread* m_workerThread {nullptr};
    AudioEngine* m_engine {nullptr};
    WorkerSimulator* m_worker {nullptr};
    PlayerUI* m_ui {nullptr};

    public:
        explicit AudioEngineApp(QObject* parent = nullptr);
        ~AudioEngineApp() override;

        void show() const;
};

#endif //QT_TUTO_AUDIO_ENGINE_APP_H
