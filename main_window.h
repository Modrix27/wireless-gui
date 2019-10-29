#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QChartView>
#include <QtCharts/QChart>
#include <QLineSeries>
#include <QSplineSeries>
#include <QTimer>
#include <QtCharts/QValueAxis>

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
    QChart* chart;
    QTimer m_timer;
    QSplineSeries *m_series;
    QStringList m_titles;
    QValueAxis *m_axisX;
    QValueAxis *m_axisY;
    qreal m_step;
    qreal m_x;
    qreal m_y;

};
#endif // MAINWINDOW_H
