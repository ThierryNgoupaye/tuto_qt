//
// Created by thierry on 17/05/2026.
//

#ifndef QT_TUTO_TUTO_QPROGRESSBAR_H
#define QT_TUTO_TUTO_QPROGRESSBAR_H

#include <QProgressBar>


class TutoQProgressBar : public QWidget {
    Q_OBJECT
    QProgressBar* progressBar;

    public:
        explicit TutoQProgressBar(QWidget* parent = nullptr);

};

#endif //QT_TUTO_TUTO_QPROGRESSBAR_H
