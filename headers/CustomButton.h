//
// Created by thierry on 16/05/2026.
//

#ifndef QT_TUTO_CUSTOMBUTTON_H
#define QT_TUTO_CUSTOMBUTTON_H
#include <QPushButton>
#include <qwidget.h>


class CustomButton : public QPushButton{
    Q_OBJECT
    public:
        explicit CustomButton(QString title, QWidget* parent = Q_NULLPTR);
};




#endif //QT_TUTO_CUSTOMBUTTON_H
