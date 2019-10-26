#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QChartView>
#include <QChart>
#include <QLineSeries>
#include <QSplineSeries>
using namespace QtCharts;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QChartView *chartView;
    QChart *chart;
    QLineSeries *dataPoints;

};
#endif // MAINWINDOW_H
