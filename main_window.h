#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QChartView>
#include <QtCharts/QChart>
#include <QLineSeries>
#include <QSplineSeries>
#include <QTimer>
#include <QtCharts/QValueAxis>

#include "live_chart.h"


using namespace QtCharts;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void handleTimeout();
private:
    QChartView* chartView;
    LiveChart* chart;
    QTimer m_timer;
    qreal newY;

};
#endif // MAINWINDOW_H
