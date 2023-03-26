#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>
#include <QKeyEvent>
#include <QDebug>
#include <QDateTime>
#include <QTime>
#include <QTimeZone>
#include <QDate>

#include <chrono>

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	this->trayIcon = new QSystemTrayIcon(this);
	
	QIcon icon = QIcon(":/images/heart.png");
	//QIcon icon = QIcon("/Users/zhangpe/git/SchoolTimetable/heart.png");
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
	connect(quitAction, &QAction::triggered, this, &MainWindow::quit);
	connect(trayIcon, &QSystemTrayIcon::activated, this, &MainWindow::iconActivated);
	this->trayIcon->show();

	this->nextClassTimer = new QTimer(this);
	this->nextClassTimer->setSingleShot(true);
	connect(this->nextClassTimer, &QTimer::timeout, this, &MainWindow::timeout);
	this->hideScreenTimer = new QTimer(this);
	this->hideScreenTimer->setSingleShot(true);
	connect(this->hideScreenTimer, &QTimer::timeout, this, &MainWindow::hide);

	this->start();
/*
	this->expiredTime = QTime(20, 9);
	QDateTime expiredDateTime = QDateTime(
		QDate::currentDate(),
		this->expiredTime,
		QTimeZone::systemTimeZone()
	);
	QDateTime currentDateTime = QDateTime::currentDateTime();
	expiredDateTime = QDateTime::fromMSecsSinceEpoch(currentDateTime.toMSecsSinceEpoch() + 60000);

	qDebug() << expiredDateTime;
	qDebug() << currentDateTime;

	qint64 t = expiredDateTime.toMSecsSinceEpoch() - currentDateTime.toMSecsSinceEpoch();
	qDebug() << t << "seconds";
	QTimer::singleShot(t, this, SLOT(timeout()));
*/
}


MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::timeout() {
	this->showFullScreen();
	qDebug() << this->nextClassTimer->isActive();

	QTime currentTime = QTime::currentTime();
	QTime promptTime = this->nextClass.startTime;

	int msecsToPromptTime = currentTime.msecsTo(promptTime);

	this->hideScreenTimer->setInterval(msecsToPromptTime);

	this->hideScreenTimer->start();

	return;
}

void MainWindow::quit()
{
	if (!this->isVisible()) {
		this->showNormal();
	}
	this->close();
}

void MainWindow::start()
{
	this->nextClass = getNextSchoolClass();
	if (nextClass.className.isNull()) {
		this->ui->classNameLabel->setText("今天没有课程了");
		return;
	}

	this->ui->classNameLabel->setText(
		this->nextClass.className
	);

	QTime currentTime = QTime::currentTime();
	QTime promptTime = this->nextClass.startTime.addSecs(-30);

	int msecsToPromptTime = currentTime.msecsTo(promptTime);
	
	this->nextClassTimer->setInterval(msecsToPromptTime);

	this->nextClassTimer->start();

}

void MainWindow::stop()
{
	this->nextClassTimer->stop();
	this->hideScreenTimer->stop();
	return;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
	int key = event->key();
	if (key == Qt::Key_Escape) {
		// this->showNormal();
		this->hide();
	}
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
    case QSystemTrayIcon::DoubleClick:
        break;
		[[fallthrough]];
    case QSystemTrayIcon::MiddleClick:
        break;
    default:
        ;
    }
}