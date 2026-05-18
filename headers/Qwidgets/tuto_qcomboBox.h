//
// Created by thierry on 17/05/2026.
//

#ifndef QT_TUTO_TUTO_QCOMBOBOX_H
#define QT_TUTO_TUTO_QCOMBOBOX_H
#include <QComboBox>
#include <map>

class TutoQComboBox : public QWidget {
    Q_OBJECT
    QComboBox* comboBox;
    QList<QString> m_items;
    std::map<QString, QVariant> m_itemsMap;

    public:
        explicit TutoQComboBox(const QList<QString>& items, const std::map<QString, QVariant>& itemsMap, QWidget* parent = nullptr);

    private slots:
        void onCurrentIndexChanged(int index) const;
};



#endif //QT_TUTO_TUTO_QCOMBOBOX_H
