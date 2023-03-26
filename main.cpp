#include <QApplication>
#include "mainwindow.h"

#include "SchoolTimetable.h"
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    initDefaultSchoolTimetable();

    MainWindow mainWin;
    mainWin.show();
    // mainWin.showFullScreen();
    return app.exec();
}