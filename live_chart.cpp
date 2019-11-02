//
// Created by lbd on 26/10/2019.
//

#include "live_chart.h"

LiveChart::LiveChart(QGraphicsItem *parent, Qt::WindowFlags wFlags) : QChart(QChart::ChartTypeCartesian, parent, wFlags) {
    series = new QLineSeries(this);
    series->setPen(QPen(Qt::red)); // set color of graph line
    addSeries(series);

    xAxis = new QValueAxis;
    yAxis = new QValueAxis;
    addAxis(xAxis, Qt::AlignBottom);
    addAxis(yAxis, Qt::AlignLeft);
    series->attachAxis(xAxis);
    series->attachAxis(yAxis);

    xAxis->setRange(0, 10);
    yAxis->setRange(0, 100);

    series->append(0, 0);
    addSeries(series);

    time.start();
}

LiveChart::~LiveChart() {}

void LiveChart::append(int yVal) {
    double t = time.elapsed();
//    qDebug() << t;
//    buffer.append(QPointF(t, yVal));
//    series->replace(buffer);
//    series->append(t, yVal);
    qreal newX = series->at(series->count()-1).x() + 1;
    series->append(newX, yVal);
//    scroll(10, 0);
    if(newX >= xAxis->max()) xAxis->setRange(xAxis->max() - 5, xAxis->max()+5);
}