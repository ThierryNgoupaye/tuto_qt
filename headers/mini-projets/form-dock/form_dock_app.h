//
// Created by thierry on 21/05/2026.
//

#ifndef QT_TUTO_FORM_DOCK_APP_H
#define QT_TUTO_FORM_DOCK_APP_H

#include <QMainWindow>
#include <QDockWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QCheckBox>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QFrame>
#include <QMenu>


class FormDockApp : public QMainWindow {

    Q_OBJECT

    // Configurations
    QWidget* m_central {nullptr};
    QVBoxLayout* m_mainLayout {nullptr};


    // Éléments du formulaire
    QFormLayout* m_formInfos {nullptr};
    QFormLayout* m_formPrefs {nullptr};
    QHBoxLayout* m_btnLayout {nullptr};
    QLabel* m_labelSection1 {nullptr};
    QLabel* m_labelSection2 {nullptr};
    QLineEdit* m_inputPrenom {nullptr};
    QLineEdit* m_inputNom {nullptr};
    QLineEdit* m_inputEmail {nullptr};
    QComboBox* m_comboTheme {nullptr};
    QSpinBox* m_spinTaille {nullptr};
    QCheckBox* m_checkNotifs {nullptr};
    QPushButton* m_btnValider {nullptr};
    QPushButton* m_btnAnnuler {nullptr};

    // Zone centrale
    QLabel* m_resumeLabel {nullptr};

    // Dock
    QDockWidget* m_dock {nullptr};
    QScrollArea* m_scrollArea {nullptr};
    QWidget* m_dockConteneur {nullptr};
    QVBoxLayout* m_dockLayout {nullptr};


    // Menus
    QMenu* m_menuVue {nullptr};
    QAction* m_actToggleDock {nullptr};


    void creerMenus();
    void creerDock();
    void creerZoneCentrale();
    void mettreAJourTheme() const;
    static QFrame* creerSeparator();

    public:
        explicit FormDockApp(QWidget* parent = nullptr);

};

#endif //QT_TUTO_FORM_DOCK_APP_H
