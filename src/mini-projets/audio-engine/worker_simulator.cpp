//
// Created by thierry on 20/05/2026.
//

#include <qdebug.h>
#include <QThread>
#include "../../../headers/mini-projets/audio-system/worker_simulator.h"


WorkerSimulator::WorkerSimulator(QObject *parent) : QObject(parent){}

void WorkerSimulator::startHeavyTask(const QString& task) {
    qDebug() << "[Worker] tache démarrée dans le thread : " << QThread::currentThreadId();
    emit taskStarted(task);

    // simulation d'un long traitement par étapes
    for (int i = 0; i<=100; i+=10) {
        QThread::msleep(150);  // bloque le thread secondaire

        emit progressUpdated(i);
        qDebug() <<"[Worker] " << task << ": " << i  << "%";
    }

    emit taskFinished(task);
    qDebug() << "[Worker] " << "tache terminée " << task;
}


