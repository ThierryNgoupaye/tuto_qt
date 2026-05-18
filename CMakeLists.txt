cmake_minimum_required(VERSION 4.2)
project(qt_tuto)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/thierry/Qt/6.8.3/gcc_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(qt_tuto main.cpp
        resources/resources.qrc
        src/main_window.cpp
        headers/main_window.h
        src/CustomButton.cpp
        headers/CustomButton.h
        headers/Qwidgets/tuto_qlabel.h
        src/qwidgets/tuto_qlabel.cpp
        headers/Qwidgets/tuto_qpushButton.h
        src/qwidgets/tuto_qpushButton.cpp
        src/qwidgets/tuto_qlineEdit.cpp
        headers/Qwidgets/tuto_qlineEdit.h
        headers/Qwidgets/tuto_qslider.h
        src/qwidgets/tuto_qslider.cpp
        headers/Qwidgets/tuto_qspinBox.h
        src/qwidgets/tuto_qspinBox.cpp
        headers/Qwidgets/tuto_qcheckBox.h
        src/qwidgets/tuto_qcheckBox.cpp
        headers/Qwidgets/tuto_qcomboBox.h
        src/qwidgets/tuto_qcomboBox.cpp
        headers/Qwidgets/tuto_qprogressBar.h
        src/qwidgets/tuto_qprogressBar.cpp
        headers/Conteneurs/tuto_qtabWidget.h
        src/conteneurs/tuto_qtabWidget.cpp
        src/mini-projets/tabWidget_app.cpp
        headers/mini-projets/tabWidget_app.h
        headers/Conteneurs/tuto_qstackedWidget.h
        src/conteneurs/tuto_qstackedWidget.cpp
        headers/mini-projets/sidebar_app.h
        src/mini-projets/sidebar_app.cpp
        headers/Conteneurs/tuto_qscrollArea.h
        src/conteneurs/tuto_qscrollArea.cpp
        headers/mini-projets/musical_card/musical_card_app.h
        src/mini-projets/musical_card/musical_card_app.cpp
        headers/mini-projets/musical_card/musical_card.h
        src/mini-projets/musical_card/musical_card.cpp
)
target_link_libraries(qt_tuto
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

