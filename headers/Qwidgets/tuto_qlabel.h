//
// Created by thierry on 17/05/2026.
//

#ifndef QT_TUTO_TUTO_QLABEL_H
#define QT_TUTO_TUTO_QLABEL_H


#include <QLabel>
#include <QWidget>

class TutoQLabel : public QWidget {

    Q_OBJECT
    QLabel* label;
    public:
        explicit TutoQLabel(QWidget *parent = nullptr);
        void applyLabelWithImage() const;


};


#endif //QT_TUTO_TUTO_QLABEL_H
