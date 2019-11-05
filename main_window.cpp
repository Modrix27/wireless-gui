#include "main_window.h"
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
QObject::connect(&m_timer, &QTimer::timeout, this, &MainWindow::handleTimeout);
m_timer.setInterval(20); // setup 1-second delay between updates to graph

chart = new LiveChart();
chart->legend()->hide();
//chart->setAnimationOptions(QChart::AllAnimations);

chartView = new QChartView(chart);
chartView->setMinimumSize(1000, 600);
chartView->setRenderHint(QPainter::Antialiasing);

this->setCentralWidget(chartView);

m_timer.start();
}

void MainWindow::handleTimeout()
{
    newY = QRandomGenerator::global()->bounded(100);

    chart->append(newY);
}

MainWindow::~MainWindow()
{

}

