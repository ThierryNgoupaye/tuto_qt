//
// Created by thierry on 17/05/2026.
//

#ifndef QT_TUTO_TUTO_QPUSHBUTTON_H
#define QT_TUTO_TUTO_QPUSHBUTTON_H
#include <QWidget>
#include <QPushButton>



class TutoQPushButton : public QWidget {

    Q_OBJECT
    QPushButton* button;
    public:
        explicit TutoQPushButton(QWidget *parent = nullptr);

    private slots:
        void onClicked() const;
        void onChecked(bool checked) const ;
        void onPressed() const ;
        void onReleased() const ;
};


#endif //QT_TUTO_TUTO_QPUSHBUTTON_H
