#include "mainwindow.h"
#include <QIcon>
#include <QDebug>

MainWindow::MainWindow()
{
	qDebug() << QSystemTrayIcon::isSystemTrayAvailable();

	this->trayIcon = new QSystemTrayIcon(this);
	
	// QIcon icon = QIcon("C:\\Users\\zhang\\git\\SchoolTimetable\\heart.png");
	QIcon icon = QIcon("C:\\Users\\zhang\\git\\RegisterPrinter\\registerPrinter.png");
	this->trayIcon->setIcon(icon);
	this->trayIconMenu = new QMenu(this);
	this->trayIcon->setContextMenu(this->trayIconMenu);
	this->min = new QAction("Minimize", this);
	QAction *normal = new QAction("Normalize", this);
	QAction* fullScreen = new QAction("FullScreen", this);
	this->trayIconMenu->addAction(this->min);
	this->trayIconMenu->addAction(normal);
	this->trayIconMenu->addAction(fullScreen);
	connect(min, &QAction::triggered, this, &MainWindow::hide);
	connect(normal, &QAction::triggered, this, &MainWindow::showNormal);
	connect(fullScreen, &QAction::triggered, this, &MainWindow::showFullScreen);
	connect(trayIcon, &QSystemTrayIcon::activated, this, &MainWindow::iconActivated);
	this->trayIcon->show();



}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
    case QSystemTrayIcon::DoubleClick:
        break;
    case QSystemTrayIcon::MiddleClick:
        break;
    default:
        ;
    }
}