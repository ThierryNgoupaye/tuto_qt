//
// Created by thierry on 20/05/2026.
//


#include "../../../headers/mini-projets/audio-system/player_ui.h"
#include <QStatusBar>

PlayerUI::PlayerUI(QWidget *parent) : QMainWindow(parent) {

    // configurations initiales
    m_central = new QWidget(this);
    setCentralWidget(m_central);
    m_layout = new QVBoxLayout(m_central);
    m_central->setLayout(m_layout);
    m_layout->setContentsMargins( 16, 16, 16, 16);
    m_layout->setSpacing(12);


    // Sélecteur de piste
    m_trackSelector = new QComboBox(m_central);
    m_trackSelector->addItem("Bohemian Rhapsody — Queen",       180000);
    m_trackSelector->addItem("Stairway to Heaven — Led Zep",    482000);
    m_trackSelector->addItem("Hotel California — Eagles",       391000);

    // Infos piste
    m_trackLabel = new QLabel("Aucune piste chargée", m_central);
    m_trackLabel->setAlignment(Qt::AlignCenter);
    m_trackLabel->setStyleSheet("font-size: 16px; font-weight: bold");

    // Progression
    m_progressRow = new QHBoxLayout();
    m_positionLabel = new QLabel("00:00", m_central);
    m_progressSlider = new QSlider(Qt::Horizontal, m_central);
    m_progressSlider->setRange(0,0);
    m_durationLabel = new QLabel("00:00", m_central);

    m_progressRow->addWidget(m_positionLabel);
    m_progressRow->addWidget(m_progressSlider, 1);
    m_progressRow->addWidget(m_durationLabel);


    //controles
    m_ctrlRow = new QHBoxLayout();
    m_loadBtn = new QPushButton(" Charger", m_central);
    m_playBtn = new QPushButton(" Play", m_central);
    m_stopBtn = new QPushButton(" Stop", m_central);

    m_playBtn->setEnabled(false);
    m_stopBtn->setEnabled(false);

    m_ctrlRow->addWidget(m_loadBtn);
    m_ctrlRow->addStretch();
    m_ctrlRow->addWidget(m_playBtn);
    m_ctrlRow->addWidget(m_stopBtn);


    // Volume
    m_volumeRow = new QHBoxLayout();
    m_volumeLabel = new QLabel("🔊", m_central);
    m_volumeSlider = new QSlider(Qt::Horizontal, m_central);
    m_volumeSlider->setRange(0,100);
    m_volumeSlider->setValue(50);
    m_volumeSlider->setFixedWidth(120);

    m_volumeRow->addStretch();
    m_volumeRow->addWidget(m_volumeLabel);
    m_volumeRow->addWidget(m_volumeSlider);

    m_layout->addWidget(m_trackSelector);
    m_layout->addWidget(m_trackLabel);

    m_layout->addLayout(m_progressRow);
    m_layout->addLayout(m_volumeRow);
    m_layout->addLayout(m_ctrlRow);


    m_statusLabel = new QLabel("Pret");
    statusBar()->addWidget(m_statusLabel);


    connect(m_loadBtn, &QPushButton::clicked, this, [this] {
            const QString title = m_trackSelector->currentText();
            const int duration = m_trackSelector->currentData().toInt();
        emit trackLoadRequested(title, duration);
        }
    );

    connect(m_playBtn, &QPushButton::clicked, this, [this] {
            if (m_isPlaying) emit pauseRequested();
            else emit playRequested();
        }
    );

    connect(m_stopBtn, &QPushButton::clicked, this, &PlayerUI::stopRequested);


    connect(m_progressSlider, &QSlider::sliderReleased, this, [this] {
            emit seekRequested(m_progressSlider->value());
        }
    );

    connect(m_volumeSlider, &QSlider::valueChanged, this,  &PlayerUI::volumeRequested);

}


void PlayerUI::onPlaybackStarted() {
    m_isPlaying = true;
    m_playBtn->setText("Pause");
    m_stopBtn->setEnabled(true);
    m_statusLabel->setText("Lecture en cours ...");
    qDebug() << "[PlayerUI] onPlaybackStarted";
}

void PlayerUI::onPlaybackPaused() {
    m_isPlaying = false;
    m_playBtn->setText("Play");
    m_statusLabel->setText("En pause");
}


void PlayerUI::onPlaybackStopped() {
    m_isPlaying = false;
    m_playBtn->setText("Play");
    m_stopBtn->setEnabled(false);
    m_progressSlider->setValue(0);
    m_positionLabel->setText("00:00");
    m_statusLabel->setText("Arrêté");
}

void PlayerUI::onVolumeChanged(const int volume) const {

    m_volumeSlider->blockSignals(true);
    m_volumeSlider->setValue(volume);
    m_volumeSlider->blockSignals(false);
    m_statusLabel->setText(QString("Volume: %1%").arg(volume));
}

void PlayerUI::onPositionChanged(const int positionMs) const {
    if (m_progressSlider->isSliderDown()) {
        m_progressSlider->setValue(positionMs);
    }
    m_positionLabel->setText(formatDuration(positionMs));
}


void PlayerUI::onTrackLoaded(const QString& title, const int durationMs) {
    m_duration = durationMs;
    m_trackLabel->setText(title);
    m_progressSlider->setRange(0, durationMs);
    m_durationLabel->setText(formatDuration(durationMs));
    m_playBtn->setEnabled(true);
    m_statusLabel->setText("Piste chargée - " + title);
}


void PlayerUI::onErrorOccurred(const QString& message) const {
    m_statusLabel->setText("❌ Erreur : " + message);
}

QString PlayerUI::formatDuration(const int duration)  {
    const int totalSec = duration / 1000;
    const int min = totalSec / 60;
    const int sec = totalSec % 60;
    return QString("%1:%2")
    .arg(min, 2, 10, QChar('0'))
    .arg(sec, 2, 10, QChar('0'));
}

