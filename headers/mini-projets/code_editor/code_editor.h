//
// Created by thierry on 19/05/2026.
//

#ifndef QT_TUTO_CODE_EDITOR_H
#define QT_TUTO_CODE_EDITOR_H
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>
#include <QTextEdit>

#include "../../Conteneurs/tuto_qsplitter.h"


class CodeEditorApp : public QMainWindow {
    Q_OBJECT

    // Squelette
    TutoQSplitter* m_hSplitter;
    TutoQSplitter* m_vSplitter;
    QLabel* m_statusLabel;
    QByteArray m_savedState;


    QWidget* m_central;
    QVBoxLayout* m_layout;

    QHBoxLayout* m_ctrlLayout;


    // Boutons
    QPushButton* m_saveBtn;
    QPushButton* m_restoreBtn;
    QPushButton* m_resetBtn;


    QListWidget* m_fileList;
    QTextEdit* m_editor;
    QTextEdit* m_console;

    void configurerConnexions(const QPushButton* btnSauver, QPushButton* btnRestaurer, const QPushButton* btnReset);

    public:
        explicit CodeEditorApp(QWidget* parent = nullptr);

};



#endif //QT_TUTO_CODE_EDITOR_H
