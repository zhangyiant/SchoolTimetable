#pragma once

#include <map>
#include <list>
#include <Qt>
#include "SchoolClass.h"

#include <QTime>
#include <QString>

class SchoolClass {
    QString className;
    QTime startTime;
    QTime stopTime;
};

typedef std::map<Qt::DayOfWeek, std::list<SchoolClass>> SchoolTimetable;
