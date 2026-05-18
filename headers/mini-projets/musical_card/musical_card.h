//
// Created by thierry on 18/05/2026.
//

#ifndef QT_TUTO_MUSICAL_CARD_H
#define QT_TUTO_MUSICAL_CARD_H
#include <QHBoxLayout>
#include <QLabel>
#include  <QHBoxLayout>


class MusicalCard : public QWidget {
    Q_OBJECT
    QLabel* m_title;
    QLabel* m_artist;
    QLabel* m_number;

    QPixmap* m_icon;
    QLabel* m_cardIcon;

    QHBoxLayout* m_layout;
    QVBoxLayout* m_content;

    public:
        MusicalCard(const QString& title, const QString& artist, int number, QWidget* parent);
        [[nodiscard]] QWidget* getCard() const;

};

#endif //QT_TUTO_MUSICAL_CARD_H
