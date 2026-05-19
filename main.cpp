#include <QApplication>
#include <qboxlayout.h>

#include <QLineEdit>
#include  <QPointer>
#include  <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include  <QSpinBox>
#include  <QStatusBar>
#include <QGroupBox>
#include <QButtonGroup>
#include <QRadioButton>

#include "headers/CustomButton.h"
#include "headers/Qwidgets/tuto_qlabel.h"
#include "headers/Qwidgets/tuto_qpushButton.h"
#include "headers/Qwidgets/tuto_qlineEdit.h"
#include "headers/Qwidgets/tuto_qslider.h"
#include "headers/Qwidgets/tuto_qcomboBox.h"
#include "headers/Qwidgets/tuto_qprogressBar.h"
#include  "headers/Conteneurs/tuto_qtabWidget.h"
#include "headers/mini-projets/code_editor.h"
#include "headers/mini-projets/tabWidget_app.h"
#include "headers/mini-projets/sidebar_app.h"
#include "headers/mini-projets/musical_card/musical_card_app.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    CodeEditorApp mainWindow;

    mainWindow.show();


    return QApplication::exec();
}

