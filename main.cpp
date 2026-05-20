#include <QApplication>


#include "headers/mini-projets/audio-system/audio_engine_app.h"
#include "headers/mini-projets/menu-explorer/menu_explorer.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MenuExplorer m;
    m.show();

    return QApplication::exec();
}

