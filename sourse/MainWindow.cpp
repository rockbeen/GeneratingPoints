#include "MainWindow.h"
#include <QStyle>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    auto startButton = new QPushButton(this);
    auto pauseButton = new QPushButton(this);
    auto stopButton = new QPushButton(this);
    auto centrWidget = new QWidget(this);
    auto boxLayout = new QHBoxLayout();
    auto centrLayout = new QVBoxLayout(centrWidget);
    displayPoints = new DisplayPoints(this);
    pntGenerator = new Generator(displayPoints, this);

    startButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    pauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    boxLayout->addWidget(startButton);
    boxLayout->addWidget(pauseButton);
    boxLayout->addWidget(stopButton);
    centrLayout->addWidget(displayPoints);
    centrLayout->addLayout(boxLayout);

    setCentralWidget(centrWidget);
    connect(startButton, &QPushButton::released, pntGenerator, &Generator::startGenerating);
    connect(pauseButton, &QPushButton::released, pntGenerator, &Generator::pauseGenerating);
    connect(pntGenerator, &Generator::newPoint, displayPoints, &DisplayPoints::addPoint);
    connect(stopButton, &QPushButton::released, this, &MainWindow::stopGenerating);
    pntGenerator->start();
}
