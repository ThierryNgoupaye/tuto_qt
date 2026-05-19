//
// Created by thierry on 18/05/2026.
//

#ifndef QT_TUTO_TUTO_QSPLITTER_H
#define QT_TUTO_TUTO_QSPLITTER_H


#include <QSplitter>
#include <QVBoxLayout>


class TutoQSplitter : public QWidget {

    Q_OBJECT
    QSplitter* m_splitter;
    QVBoxLayout* m_layout;
    QList<QWidget*> m_pages;

    public :
        explicit TutoQSplitter(QWidget *parent = nullptr);

        TutoQSplitter& addWidget(this TutoQSplitter& self, QWidget* widget);

        TutoQSplitter& setPages(this TutoQSplitter& self, const QList<QWidget*> &pages);
        TutoQSplitter& setOrientation(this TutoQSplitter& self, const Qt::Orientation& orientation);
        [[nodiscard]] QSplitter* splitter() const ;

        // Fixe la taille en pixels pour chaque widget
        TutoQSplitter& setSizes(this TutoQSplitter& self, const QList<int> &sizes);

        // Permet à ce que le double clic sur la poignée collapse la zone soit réduite à 0px
        TutoQSplitter& setCollapsible(this TutoQSplitter& self, int zone, bool choice);

        // La zone (zone) prend tout l'espace restant (choice == 1) ou ne s'étire pas (choice == 0).
        TutoQSplitter& setStretchFactor(this TutoQSplitter& self, int zone, bool choice);

        // Règle la largeur de la poignée
        TutoQSplitter& setHandleWidth(this TutoQSplitter& self, int width);


    signals:
        void splitterMoved(int pos, int index);


    private slots:
        void onSplitterMoved(int pos, int index);


};


#endif //QT_TUTO_TUTO_QSPLITTER_H
