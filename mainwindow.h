#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include <QTime>
#include <QTimer>
#include <QMainWindow>
#include "SchoolTimetable.h"

namespace Ui {
    class MainWindow;
}

class MainWindow :
    public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent *event) override;
private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void timeout();
private:
    QSystemTrayIcon* trayIcon;
    QAction* min;
    QMenu* trayIconMenu;
    QTime expiredTime;
    QTimer* timer;
private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H