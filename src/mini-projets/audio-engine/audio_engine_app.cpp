//
// Created by thierry on 20/05/2026.
//


#include "../../../headers/mini-projets/audio-system/audio_engine_app.h"

#include "../../../headers/mini-projets/audio-system/audio_engine.h"
#include "../../../headers/mini-projets/audio-system/player_ui.h"


// Communication par signaux et slots en utilisant DirectConnexion
PlayerUI* startAudioEngineApp() {

    const auto engine = new AudioEngine();
    const auto ui  = new PlayerUI;

    // Démarrage du timer
    engine->initialize();

    // ── Câblage UI → Engine ───────────────────────────────
    // La UI demande → l'Engine exécute
    QObject::connect(ui, &PlayerUI::playRequested, engine, &AudioEngine::play);
    QObject::connect(ui, &PlayerUI::pauseRequested, engine, &AudioEngine::pause);
    QObject::connect(ui, &PlayerUI::stopRequested, engine, &AudioEngine::stop);
    QObject::connect(ui, &PlayerUI::volumeRequested, engine, &AudioEngine::setVolume);
    QObject::connect(ui, &PlayerUI::seekRequested, engine, &AudioEngine::seek);
    QObject::connect(ui, &PlayerUI::trackLoadRequested, engine, &AudioEngine::loadTrack);

    // ── Câblage Engine → UI ───────────────────────────────
    // L'Engine notifie → la UI se met à jour
    QObject::connect(engine, &AudioEngine::playbackStarted, ui, &PlayerUI::onPlaybackStarted);
    QObject::connect(engine, &AudioEngine::playbackPaused, ui, &PlayerUI::onPlaybackPaused);
    QObject::connect(engine, &AudioEngine::playbackStopped, ui, &PlayerUI::onPlaybackStopped);
    QObject::connect(engine, &AudioEngine::volumeChanged, ui, &PlayerUI::onVolumeChanged);
    QObject::connect(engine, &AudioEngine::positionChanged, ui, &PlayerUI::onPositionChanged);
    QObject::connect(engine, &AudioEngine::trackLoaded, ui, &PlayerUI::onTrackLoaded);
    QObject::connect(engine, &AudioEngine::errorOccurred, ui, &PlayerUI::onErrorOccurred);
    return ui;
}



AudioEngineApp::AudioEngineApp(QObject *parent) : QObject(parent) {

    m_ui = new PlayerUI();
    m_engine = new AudioEngine();
    m_worker = new WorkerSimulator();

    m_engineThread = new QThread(this);
    m_workerThread = new QThread(this);

    m_engine->moveToThread(m_engineThread);
    m_worker->moveToThread(m_workerThread);


    // Gestion du thread à son lancement et la fin d'exécution de sa tâche
    connect(m_engineThread, &QThread::started, m_engine, &AudioEngine::initialize);
    connect(m_engineThread, &QThread::finished, m_engine, &QObject::deleteLater);
    connect(m_workerThread, &QThread::finished, m_worker, &QObject::deleteLater);


    // Cablage UI → Engine (thread principal → thread secondaire)
    // AutoConnection détecte threads différents → QueuedConnection
    connect(m_ui, &PlayerUI::playRequested, m_engine, &AudioEngine::play);
    connect(m_ui, &PlayerUI::pauseRequested, m_engine, &AudioEngine::pause);
    connect(m_ui, &PlayerUI::stopRequested, m_engine, &AudioEngine::stop);
    connect(m_ui, &PlayerUI::volumeRequested, m_engine, &AudioEngine::setVolume);
    connect(m_ui, &PlayerUI::seekRequested, m_engine, &AudioEngine::seek);
    connect(m_ui, &PlayerUI::trackLoadRequested, m_engine, &AudioEngine::loadTrack);


    // Cablage UI → Worker (thread principal → secondaire)
    connect(m_ui, &PlayerUI::heavyTaskRequested, m_worker, &WorkerSimulator::startHeavyTask);


    // Cablage Engine → UI (Thread secondaire → principal)
    connect(m_engine, &AudioEngine::playbackStarted, m_ui, &PlayerUI::onPlaybackStarted);
    connect(m_engine, &AudioEngine::playbackPaused, m_ui, &PlayerUI::onPlaybackPaused);
    connect(m_engine, &AudioEngine::playbackStopped, m_ui, &PlayerUI::onPlaybackStopped);
    connect(m_engine, &AudioEngine::volumeChanged, m_ui, &PlayerUI::onVolumeChanged);
    connect(m_engine, &AudioEngine::positionChanged, m_ui, &PlayerUI::onPositionChanged);
    connect(m_engine, &AudioEngine::trackLoaded, m_ui, &PlayerUI::onTrackLoaded);
    connect(m_engine, &AudioEngine::errorOccurred, m_ui, &PlayerUI::onErrorOccurred);


    // Cablage Worker → UI (thread secondaire → principal)
    connect(m_worker, &WorkerSimulator::taskStarted, m_ui, &PlayerUI::onTaskStarted);
    connect(m_worker, &WorkerSimulator::progressUpdated, m_ui, &PlayerUI::onProgressUpdated);
    connect(m_worker, &WorkerSimulator::taskFinished, m_ui, &PlayerUI::onTaskFinished);

    // Demarrage du thread
    m_engineThread->start();
    m_workerThread->start();

    qDebug() << "[App] Thread principal: " << QThread::currentThreadId();
}


AudioEngineApp::~AudioEngineApp() {
    m_engineThread->quit();
    m_workerThread->quit();
    m_engineThread->wait();
    m_workerThread->wait();
}


void AudioEngineApp::show() const {
    m_ui->show();
}


