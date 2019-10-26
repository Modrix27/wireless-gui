#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//    dataPoints = new QSplineSeries();
    dataPoints = new QLineSeries();
    for(int i=0; i<100; i++) {
        dataPoints->append(i, rand() % 100);
    }

    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(dataPoints);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(0,100);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    this->setCentralWidget(chartView);
}

MainWindow::~MainWindow()
{

}

