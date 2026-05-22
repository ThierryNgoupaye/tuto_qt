#include <QApplication>


#include "headers/mini-projets/audio-system/audio_engine_app.h"
#include "headers/mini-projets/file-explorer/file_explorer.h"
#include "headers/mini-projets/form-dock/form_dock_app.h"
#include "headers/mini-projets/menu-explorer/menu_explorer.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    FileExplorer m;
    m.show();

    return QApplication::exec();
}

