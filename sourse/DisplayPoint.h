#pragma once

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QVector>

class DisplayPoints : public QWidget {
Q_OBJECT

public:
    explicit DisplayPoints(QWidget *parent = nullptr);
public slots:
    void addPoint(const double x,const double y);
    void reset();

protected:
    void paintEvent(QPaintEvent *) override;
private:
    void createAxes();
    QVector<QPointF> m_vecPoints;
    QPixmap m_pixmap;
};
