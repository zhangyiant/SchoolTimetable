#include "mainwindow.h"
#include <QIcon>
#include <QKeyEvent>
#include <QDebug>
#include <QDateTime>
#include <QTimeZone>
#include <QDate>

#include <chrono>

MainWindow::MainWindow()
{
	qDebug() << QSystemTrayIcon::isSystemTrayAvailable();

	this->trayIcon = new QSystemTrayIcon(this);
	
	// QIcon icon = QIcon("C:\\Users\\zhang\\git\\SchoolTimetable\\heart.png");
	QIcon icon = QIcon("/Users/zhangpe/git/SchoolTimetable/heart.png");
	this->trayIcon->setIcon(icon);
	this->trayIconMenu = new QMenu(this);
	this->trayIcon->setContextMenu(this->trayIconMenu);
	QAction* hideAction = new QAction("Hide", this);
	QAction* normalAction = new QAction("Normalize", this);
	QAction* fullScreenAction = new QAction("FullScreen", this);
	QAction* quitAction = new QAction("Quit", this);
	this->trayIconMenu->addAction(hideAction);
	this->trayIconMenu->addAction(normalAction);
	this->trayIconMenu->addAction(fullScreenAction);
	this->trayIconMenu->addSeparator();
	this->trayIconMenu->addAction(quitAction);
	connect(hideAction, &QAction::triggered, this, &MainWindow::hide);
	connect(normalAction, &QAction::triggered, this, &MainWindow::showNormal);
	connect(fullScreenAction, &QAction::triggered, this, &MainWindow::showFullScreen);
	connect(quitAction, &QAction::triggered, this, &MainWindow::close);
	connect(trayIcon, &QSystemTrayIcon::activated, this, &MainWindow::iconActivated);
	this->trayIcon->show();


	this->expiredTime = QTime(16, 55);
	QDateTime expiredDateTime = QDateTime(
		QDate::currentDate(),
		this->expiredTime,
		QTimeZone::systemTimeZone()
	);
	QDateTime currentDateTime = QDateTime::currentDateTime();

	qDebug() << expiredDateTime;
	qDebug() << currentDateTime;

	std::chrono::milliseconds t = expiredDateTime - currentDateTime;
	qDebug() << t.count() << "seconds";
	QTimer::singleShot(t, this, SLOT(timeout()));
}

void MainWindow::timeout() {
	this->showFullScreen();
	return;
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
	int key = event->key();
	if (key == Qt::Key_Escape) {
		this->showNormal();
		this->hide();
	}
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