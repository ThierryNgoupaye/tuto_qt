//
// Created by thierry on 17/05/2026.
//

#ifndef QT_TUTO_TUTO_QLINEDIT_H
#define QT_TUTO_TUTO_QLINEDIT_H
#include <QLineEdit>
#include <QWidget>


class TutoQlineEdit : public QWidget{
    Q_OBJECT
    QLineEdit* input;
    public:
        explicit TutoQlineEdit(QWidget *parent = nullptr);

    private slots:
        void onTextChanged(const QString& text) const;
        void onTextEdited(const QString& text) const;
        void onReturnPressed() const ;
        void onEditingFinished() const;
};


#endif //QT_TUTO_TUTO_QLINEDIT_H
