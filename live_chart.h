//
// Created by lbd on 26/10/2019.
//

#ifndef WIRELESS_GUI_LIVE_CHART_H
#define WIRELESS_GUI_LIVE_CHART_H

#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>
using namespace QtCharts;
#include <QTime>
#include <QVector>
#include <QPointF>
#include <QDebug>

class LiveChart : public QChart {
    Q_OBJECT
public:
    LiveChart(QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = Qt::WindowFlags());
    ~LiveChart();


public slots:
    void append(int yVal);

private:
    QLineSeries *series;
    QValueAxis *xAxis, *yAxis;

    QVector<QPointF> buffer;

    QTime time;
};


#endif //WIRELESS_GUI_LIVE_CHART_H
