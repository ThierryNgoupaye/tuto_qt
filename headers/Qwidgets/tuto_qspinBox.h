//
// Created by thierry on 17/05/2026.
//

#ifndef QT_TUTO_TUTO_QSPINBOX_H
#define QT_TUTO_TUTO_QSPINBOX_H
#include <QSpinBox>
#include <QWidget>


class TutoQSpinBox : public QWidget {
    Q_OBJECT
    QSpinBox* spinBox;
    public:
        explicit TutoQSpinBox(QWidget* parent = nullptr);

    private slots:
        void onValueChanged(int value) const;
};



class TutoQDoubleSpinBox : public QWidget {
    Q_OBJECT
    QDoubleSpinBox* spinBox;
    public:
        explicit TutoQDoubleSpinBox(QWidget* parent = nullptr);
    private slots:
        void onValueChanged(double value) const;
};


#endif //QT_TUTO_TUTO_QSPINBOX_H
