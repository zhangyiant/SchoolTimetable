#pragma once

#include <map>
#include <list>

#include <Qt>
#include <QTime>
#include <QString>

struct SchoolClass {
    QString className;
    QTime startTime;
    QTime stopTime;
};

using SchoolTimetable = std::map<Qt::DayOfWeek, std::list<SchoolClass>>;

extern SchoolTimetable defaultSchoolTimetable;

void initDefaultSchoolTimetable();