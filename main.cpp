#include <QApplication>


#include "headers/mini-projets/audio-system/audio_engine_app.h"





int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    PlayerUI* ui = startAudioEngineApp();
    ui->show();

    return QApplication::exec();
}

