#pragma once

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "DisplayPoint.h"
#include "Generator.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
private:
    Generator *pntGenerator;
    DisplayPoints *displayPoints;

private slots:
    void stopGenerating() { pntGenerator->stopGenerating();}
};
