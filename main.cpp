#include <QApplication>


#include "headers/mini-projets/audio-system/audio_engine_app.h"





int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

     const AudioEngineApp audioEngineApp;
     audioEngineApp.show();

    return QApplication::exec();
}

