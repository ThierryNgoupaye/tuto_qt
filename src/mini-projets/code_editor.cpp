//
// Created by thierry on 19/05/2026.
//

#include "../../headers/mini-projets/code_editor.h"

#include <QStatusBar>

#include "../../headers/mini-projets/panneau.h"


CodeEditorApp::CodeEditorApp(QWidget *parent) : QMainWindow(parent) {

    setWindowTitle("Editeur de code");
    resize(900, 600);

    this->m_central = new QWidget(this);
    this->m_layout = new QVBoxLayout(m_central);
    m_layout->setContentsMargins(8, 8, 8, 8);
    m_layout->setSpacing(8);
    m_central->setLayout(m_layout);
    setCentralWidget(m_central);


    // Bare de controle
    this->m_ctrlLayout = new QHBoxLayout();

    this->m_saveBtn = new QPushButton("Enregistrer", m_central);
    m_saveBtn->setFixedHeight(32);

    this->m_restoreBtn = new QPushButton("Restaurer", m_central);
    m_restoreBtn->setFixedHeight(32);
    m_restoreBtn->setEnabled(false);

    this->m_resetBtn = new QPushButton("Reset", m_central);
    m_resetBtn->setFixedHeight(32);


    m_ctrlLayout->addWidget(m_saveBtn);
    m_ctrlLayout->addWidget(m_restoreBtn);
    m_ctrlLayout->addWidget(m_resetBtn);
    m_ctrlLayout->addStretch();


    // contenu de la side bar
    this->m_fileList = new QListWidget();
    m_fileList->addItems({
        "📄  main.cpp",
        "📄  utils.cpp",
        "📄  mainwindow.cpp",
        "📋  mainwindow.h",
        "📋  utils.h",
        "⚙️  CMakeLists.txt"
        }
    );


    m_fileList->setStyleSheet(R"(
            QListWidget {
                background-color: #1E2130;
                color: #CCCCCC;
                border: none;
                font-size: 18px;
            }
            QListWidget::item { padding: 8px 14px; }
            QListWidget::item:selected {
                background-color: #4A90D9;
                color: white;
            }
            QListWidget::item:hover {
                background-color: #2C3050;
            }
        )");


    // Contenu de l'éditeur principal
    this->m_editor = new QTextEdit();
    m_editor->setPlainText(
    "#include <QApplication>\n"
        "#include <QMainWindow>\n\n"
        "int main(int argc, char* argv[]) {\n"
        "    QApplication app(argc, argv);\n\n"
        "    QMainWindow window;\n"
        "    window.setWindowTitle(\"Aurora Music\");\n"
        "    window.resize(1200, 800);\n"
        "    window.show();\n\n"
        "    return app.exec();\n"
        "}"
    );

    m_editor->setStyleSheet(R"(
            QTextEdit {
                background-color: #1E2130;
                color: #D4D4D4;
                border: none;
                font-family: monospace;
                font-size: 20px;
                padding: 10px;
            }
        )");



    // contenu de la console
    this->m_console = new QTextEdit();
    m_console->setReadOnly(true);
    m_console->setPlainText(
        "> cmake --build . --target all\n"
        "> [100%] Linking CXX executable AuroraMusic\n"
        "> Build finished successfully.\n"
    );
    m_console->setStyleSheet(R"(
            QTextEdit {
                background-color: #141620;
                color: #00FF88;
                border: none;
                font-family: monospace;
                font-size: 15px;
                padding: 10px;
            }
        )");


    // construction des splitters


    // splitter vertical : éditeur en haut, console en bas
    this->m_vSplitter = new TutoQSplitter();
    m_vSplitter->setOrientation(Qt::Vertical)
        .addWidget(new Panneau("EDITEUR", m_editor, m_vSplitter))
        .addWidget(new Panneau("CONSOLE", m_console, m_vSplitter))
        .setSizes({400, 150})
        .setStretchFactor(0,true)
        .setStretchFactor(1,false)
        .setCollapsible(0,true)
        .setCollapsible(1, false)
        .setHandleWidth(4)
        .setStyleSheet("QSplitter::handle { background-color: #3A3F50; }");


    this->m_hSplitter = new TutoQSplitter();
    m_hSplitter->setOrientation(Qt::Horizontal)
        .addWidget(new Panneau("EXPLORATEUR", m_fileList, m_hSplitter))
        .addWidget(m_vSplitter)
        .setSizes({200, 700})
        .setStretchFactor(0,false)
        .setStretchFactor(1,true)
        .setCollapsible(0,false)
        .setCollapsible(1, false)
        .setHandleWidth(4)
        .setStyleSheet("QSplitter::handle { background-color: #3A3F50; }");


    m_layout->addLayout(m_ctrlLayout);
    m_layout->addWidget(m_hSplitter, 1);

    // ── Barre de statut ───────────────────────────────
    m_statusLabel = new QLabel("Sidebar: 200px | Éditeur: 700px");
    statusBar()->addWidget(m_statusLabel);

    // ── Connexions ────────────────────────────────────
    configurerConnexions(m_saveBtn, m_restoreBtn, m_resetBtn);
}



void CodeEditorApp::configurerConnexions(const QPushButton* btnSauver, QPushButton* btnRestaurer, const QPushButton* btnReset)
    {
        // Signal splitterMoved sur le splitter horizontal
        connect(m_hSplitter, &TutoQSplitter::splitterMoved, this, [this](const int pos, const int index) {
            QList<int> tailles = m_hSplitter->splitter()->sizes();
            m_statusLabel->setText(
                QString("Sidebar: %1px | Éditeur: %2px  [poignée %3 à %4px]")
                .arg(tailles[0])
                .arg(tailles[1])
                .arg(index)
                .arg(pos)
            );
            qDebug() << "[hSplitter::splitterMoved] pos=" << pos
                     << "index=" << index
                     << "tailles=" << tailles;
        });


        // Signal splitterMoved sur le splitter vertical
        connect(m_vSplitter, &TutoQSplitter::splitterMoved, this, [this](const int pos, const int index) {
            const QList<int> tailles = m_vSplitter->splitter()->sizes();
            qDebug() << "[vSplitter::splitterMoved] pos=" << pos
                     << "index=" << index
                     << "tailles=" << tailles;
        });


        // Sauvegarder l'état des deux splitters
        connect(btnSauver, &QPushButton::clicked,this, [this, btnRestaurer] {
            // saveState() sérialise les positions en QByteArray
            m_savedState = m_hSplitter->splitter()->saveState();
            btnRestaurer->setEnabled(true);
            qDebug() << "[saveState] état sauvegardé —"
                     << m_savedState.size() << "bytes";
        });


        // Restaurer l'état sauvegardé
        connect(btnRestaurer, &QPushButton::clicked,
                this, [this] {
            m_hSplitter->splitter()->restoreState(m_savedState);
            qDebug() << "[restoreState] état restauré";
        });


        // Reset aux tailles par défaut
        connect(btnReset, &QPushButton::clicked, this, [this] {
            m_hSplitter->setSizes({200, 700});
            m_vSplitter->setSizes({400, 150});
            qDebug() << "[reset] tailles réinitialisées";
        });
    }
