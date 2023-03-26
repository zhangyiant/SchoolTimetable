#include "SchoolTimetable.h"
#include <list>
#include <Qt>
#include <QTime>
#include <QDate>

SchoolTimetable defaultSchoolTimetable;

void initDefaultSchoolTimetable() {
	std::list<SchoolClass> classList;
	SchoolClass schoolClass;

	schoolClass.className = QString("语文");
	schoolClass.startTime = QTime(8, 0);
	schoolClass.stopTime = QTime(8, 40);
	classList.push_back(schoolClass);

	schoolClass.className = QString("体育");
	schoolClass.startTime = QTime(8, 50);
	schoolClass.stopTime = QTime(9, 30);
	classList.push_back(schoolClass);

	schoolClass.className = QString("数学");
	schoolClass.startTime = QTime(10, 10);
	schoolClass.stopTime = QTime(10, 50);
	classList.push_back(schoolClass);

	schoolClass.className = QString("英语");
	schoolClass.startTime = QTime(11, 0);
	schoolClass.stopTime = QTime(11, 40);
	classList.push_back(schoolClass);

	schoolClass.className = QString("美术");
	schoolClass.startTime = QTime(13, 10);
	schoolClass.stopTime = QTime(13, 50);
	classList.push_back(schoolClass);

	schoolClass.className = QString("劳技");
	schoolClass.startTime = QTime(14, 0);
	schoolClass.stopTime = QTime(14, 40);
	classList.push_back(schoolClass);

	schoolClass.className = QString("地理");
	schoolClass.startTime = QTime(14, 50);
	schoolClass.stopTime = QTime(15, 30);
	classList.push_back(schoolClass);

	schoolClass.className = QString("爸爸");
	schoolClass.startTime = QTime::currentTime().addSecs(60);
	schoolClass.stopTime = QTime::currentTime().addSecs(60 * 2);
	classList.push_back(schoolClass);

	defaultSchoolTimetable[Qt::DayOfWeek::Monday] = classList;;
	defaultSchoolTimetable[Qt::DayOfWeek::Tuesday] = classList;;
	defaultSchoolTimetable[Qt::DayOfWeek::Wednesday] = classList;;
	defaultSchoolTimetable[Qt::DayOfWeek::Thursday] = classList;;
	defaultSchoolTimetable[Qt::DayOfWeek::Friday] = classList;;
	defaultSchoolTimetable[Qt::DayOfWeek::Saturday] = classList;;
	defaultSchoolTimetable[Qt::DayOfWeek::Sunday] = classList;;
	return;
}

SchoolClass getNextSchoolClass()
{
	QDate currentDate = QDate::currentDate();
	Qt::DayOfWeek currentDayOfWeek = (Qt::DayOfWeek)currentDate.dayOfWeek();

	qDebug() << currentDayOfWeek;

	std::list<SchoolClass> classList = defaultSchoolTimetable[currentDayOfWeek];

	QTime currentTime = QTime::currentTime();
	bool found = false;
	SchoolClass nextClass;
	for (SchoolClass schoolClass : classList) {
		if (currentTime < schoolClass.startTime) {
			nextClass = schoolClass;
		}
	}

	return nextClass;
}
