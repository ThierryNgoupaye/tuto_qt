//
// Created by thierry on 20/05/2026.
//


#include "../../../headers/mini-projets/audio-system/audio_engine_app.h"

#include "../../../headers/mini-projets/audio-system/audio_engine.h"
#include "../../../headers/mini-projets/audio-system/player_ui.h"

PlayerUI* startAudioEngineApp() {

    const auto engine = new AudioEngine();
    const auto ui  = new PlayerUI;

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
