//
// Created by thierry on 20/05/2026.
//

#include <qdebug.h>
#include <QThread>

#include "../../../headers/mini-projets/audio-system/audio_engine.h"

AudioEngine::AudioEngine(QObject *parent) : QObject(parent) {}


void AudioEngine::play() {
    if (m_playing) return;
    m_playing = true;
    if (m_positionTimer) m_positionTimer->start(100);   //Tick toutes les 100ms
    emit playbackStarted();
    qDebug() << "[AudioEngine] play()  - émission de playbackStarted";
}


void AudioEngine::pause() {
    if (!m_playing) return;
    m_playing = false;
    if (m_positionTimer) m_positionTimer->stop();
    emit playbackPaused();
    qDebug() << "[AudioEngine] pause()";
}


void AudioEngine::stop() {
    m_playing = false;
    m_position = 0;
    if (m_positionTimer) m_positionTimer->stop();
    emit playbackStopped();
    emit positionChanged(0);
    qDebug() << "[AudioEngine] stop()";
}

void AudioEngine::setVolume(const int volume) {
    m_volume = qBound(0, volume, 100);
    emit volumeChanged(m_volume);
    qDebug() << "[AudioEngine]  volume= " << m_volume;
}

void AudioEngine::seek(const int positionMs) {
    m_position = qMax(0, positionMs);
    emit positionChanged(m_position);
    qDebug() << "[AudioEngine] seek à " << m_position << "ms";
}


void AudioEngine::loadTrack(const QString &title, const int durationMs) {
    stop();
    emit trackLoaded(title, durationMs);
    qDebug() << "[AudioEngine] piste chargée";
}


void AudioEngine::initialize() {
    // Timer qui simule la progression de la piste
    // chaque 100ms, on avance de 100ms dans la piste
    qDebug() << "[AudioEngine::initialize] thread : " << QThread::currentThreadId();
    m_positionTimer = new QTimer(this);
    connect(m_positionTimer, &QTimer::timeout, this, [this] {
        m_position += 100;
        emit positionChanged(m_position);
        }
    );
}




