//
// Created by thierry on 17/05/2026.
//

#ifndef QT_TUTO_TUTO_QSLIDER_H
#define QT_TUTO_TUTO_QSLIDER_H
#include <QSlider>
#include <QWidget>

class TutoQSlider : public QWidget {
    Q_OBJECT
    QSlider* slider;
    public:
        explicit TutoQSlider(const Qt::Orientation& orientation, QWidget* parent = nullptr);

    private slots:
        void onValueChanged(int value) const;   // Quand la valeur change (pendant le glissement et programmatiquement)
        void onSliderMoved(int value) const;    // Seulement quand l'utilisateur déplace le curseur
        void onSliderReleased() const; // Relâchement du curseur,
};


#endif //QT_TUTO_TUTO_QSLIDER_H
