#include <QApplication>
#include "mainwindow.h"
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWin;
    mainWin.show();
    // mainWin.showFullScreen();
    return app.exec();
}