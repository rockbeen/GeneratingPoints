#pragma once

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <random>

class DisplayPoints;

class Generator : public QThread {
Q_OBJECT

public:
    explicit Generator(DisplayPoints *displayPoints, QObject *parent = nullptr);
    void run() override;
    void startGenerating();
    void pauseGenerating();
    void stopGenerating();
private:
    QMutex mutex;
    std::uniform_real_distribution<double> m_Distribution{0.0, 1.0};
    DisplayPoints *m_displayPoints;
    QWaitCondition m_condition;
    std::mt19937 m_randomEngine;
    bool m_isGeneratorEnabled;

signals:
    void newPoint(const double x,const double y);
};
