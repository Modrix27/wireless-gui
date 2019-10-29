#include "main_window.h"
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    m_series(0),
    m_axisX(new QValueAxis()),
    m_axisY(new QValueAxis()),
    m_step(0),
    m_x(5),
    m_y(1)
{
QObject::connect(&m_timer, &QTimer::timeout, this, &MainWindow::handleTimeout);
m_timer.setInterval(1000);

chart = new QChart();
chart->setTitle("Data Simulation");
chart->legend()->hide();
chart->setAnimationOptions(QChart::AllAnimations);

m_series = new QSplineSeries(this);
QPen green(Qt::red);
green.setWidth(3);
m_series->setPen(green);
m_series->append(m_x, m_y);

chart->addSeries(m_series);

chart->addAxis(m_axisX,Qt::AlignBottom);
chart->addAxis(m_axisY,Qt::AlignLeft);
m_series->attachAxis(m_axisX);
m_series->attachAxis(m_axisY);
m_axisX->setTickCount(5);
m_axisX->setRange(0, 10);
m_axisY->setRange(-5, 10);


chartView = new QChartView(chart);
chartView->setRenderHint(QPainter::Antialiasing);

this->setCentralWidget(chartView);

m_timer.start();
}

void MainWindow::handleTimeout()
{
    qreal x = chart->plotArea().width() / m_axisX->tickCount();
    qreal y = (m_axisX->max() - m_axisX->min()) / m_axisX->tickCount();
    m_x += y;
    m_y = QRandomGenerator::global()->bounded(5) - 2.5;
    m_series->append(m_x, m_y);
    chart->scroll(x, 0);
    if (m_x >= 100)
        m_timer.stop();
}

MainWindow::~MainWindow()
{

}

