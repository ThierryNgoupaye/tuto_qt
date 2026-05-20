#include <QApplication>
#include "headers/Qwidgets/tuto_qlabel.h"
#include "headers/mini-projets/aurora-skeleton/aurora_skeleton.h"



int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    AuroraSkeletonApp mainWindow;

    mainWindow.show();

    return QApplication::exec();
}

