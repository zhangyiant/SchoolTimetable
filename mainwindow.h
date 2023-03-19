#pragma once
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>

class MainWindow :
    public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
private:
    QSystemTrayIcon* trayIcon;
    QAction* min;
    QMenu* trayIconMenu;
};

