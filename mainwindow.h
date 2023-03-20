#pragma once
#include <QDialog>
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include <QTime>
#include <QTimer>

class MainWindow :
    public QDialog
{
    Q_OBJECT
public:
    MainWindow();
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
};

