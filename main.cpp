#include "main_window.h"

#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    w.setWindowTitle("Experimenting with QXYSeries live graphing");
    w.setToolTip("QXYSeries graph");
    w.resize(500, 500);

    return a.exec();
}
