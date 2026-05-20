//
// Created by thierry on 20/05/2026.
//

#ifndef QT_TUTO_WORKER_SIMULATOR_H
#define QT_TUTO_WORKER_SIMULATOR_H
#include <QObject>


class WorkerSimulator : public QObject {
    Q_OBJECT

    public :
        explicit WorkerSimulator(QObject *parent = nullptr);

    public slots:
        void startHeavyTask(const QString& task);

    signals:
        void taskStarted(const QString& task);
        void progressUpdated(int percent);
        void taskFinished(const QString& task);

};



#endif //QT_TUTO_WORKER_SIMULATOR_H
