#include "DisplayPoint.h"
#include <qnamespace.h>

DisplayPoints::DisplayPoints(QWidget *parent) : QWidget(parent) {
    setAttribute(Qt::WA_OpaquePaintEvent);
}

void DisplayPoints::reset() {
    m_vecPoints.clear();
    createAxes();
    update();
}

void DisplayPoints::createAxes() {
    m_pixmap = QPixmap(width(), height());
    m_pixmap.fill(Qt::white);
    QPainter painter(&m_pixmap);
    int widthWidget = width();
    int heightWidget = height();
    painter.drawText(widthWidget - 15, heightWidget - 35, "X");
    painter.drawText(5, 25, "Y");
    painter.drawText(15, heightWidget - 5, "0");
    //X
    painter.drawLine(20, heightWidget - 20, widthWidget - 20, heightWidget - 20);
    painter.drawLine(widthWidget - 20, heightWidget - 20, widthWidget - 35, heightWidget - 15);
    painter.drawLine(widthWidget - 20, heightWidget - 20, widthWidget - 35, heightWidget - 25);
    //Y
    painter.drawLine(20, heightWidget - 20, 20, 20);
    painter.drawLine(20, 20, 15, 40);
    painter.drawLine(20, 20, 25, 40);
}

void DisplayPoints::addPoint(const double x,const double y) {
    m_vecPoints.append(QPointF(x, y));
    QPainter painter(&m_pixmap);
    painter.setPen(Qt::blue);
    auto pointX = 20 + x * (width() - 40);
    auto pointY = height() - (20 + y * (height() - 40));
    painter.drawPoint(pointX, pointY);
    update(pointX - 5, pointY - 5, 10, 10);
}

void DisplayPoints::paintEvent(QPaintEvent *event) {
    if (m_pixmap.isNull())
        createAxes();

    QPainter painter(this);
    painter.drawPixmap(0, 0, m_pixmap);
    painter.setPen(Qt::blue);
    painter.setBrush(QBrush(Qt::blue));

    if (!m_vecPoints.empty())
        painter.drawEllipse(QPointF(20 + m_vecPoints.back().x() * (width() - 40), height() - (20 + m_vecPoints.back().y() * (height() - 40))), 5, 5);
}
