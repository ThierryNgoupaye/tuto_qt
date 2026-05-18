//
// Created by thierry on 17/05/2026.
//

#ifndef QT_TUTO_TUTO_QCHECKBOX_H
#define QT_TUTO_TUTO_QCHECKBOX_H
#include <QCheckBox>
#include <QRadioButton>



class TutoQCheckBox : public QWidget {

    Q_OBJECT
    QCheckBox* checkBox;

    public:
        explicit TutoQCheckBox(QString title,  QWidget* parent = nullptr);

    private slots:
        void onCheckBoxToggled(bool checked) const ;
};



class TutoRadioButton : public QWidget {
    Q_OBJECT
    QRadioButton* checkBox;

    public:
        explicit TutoRadioButton(QString title,  QWidget* parent = nullptr);

    private slots:
        void onRadioButtonToggled(bool checked) const ;
};



#endif //QT_TUTO_TUTO_QCHECKBOX_H
