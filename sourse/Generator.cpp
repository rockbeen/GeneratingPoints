#include "Generator.h"
#include "DisplayPoint.h"

Generator::Generator(DisplayPoints *displayPoints, QObject *parent)
        : QThread(parent), m_displayPoints(displayPoints), m_isGeneratorEnabled(false), m_randomEngine(std::random_device()()) {}

void Generator::run() {
    while (m_isGeneratorEnabled)
    {
        emit newPoint(m_Distribution(m_randomEngine), m_Distribution(m_randomEngine));
        QThread::msleep(200);
    }
}

void Generator::startGenerating() {
    QMutexLocker locker(&mutex);
    m_condition.wakeAll();
    m_isGeneratorEnabled = true;
    start();
}

void Generator::pauseGenerating() {
    QMutexLocker locker(&mutex);
    m_isGeneratorEnabled = false;
}

void Generator::stopGenerating() {
    QMutexLocker locker(&mutex);
    m_displayPoints->reset();
    m_isGeneratorEnabled = false;
    m_condition.wakeAll();
}
