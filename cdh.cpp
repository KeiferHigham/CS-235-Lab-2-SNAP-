
#include "cdh.h"
#include <sstream>

cdh::cdh(string courseNameIn, string dayIn, string timeIn) {
courseName = courseNameIn;
day = dayIn;
time = timeIn;
}

string cdh::ToString() const {
    ostringstream out;

    out << "cdh(" << courseName << "," << day << "," << time << ")";
    return out.str();
}

string cdh::GetDay() const {
    return day;
}

string cdh::GetCourse() const {
    return courseName;
}

string cdh::GetTime() const {
    return time;
}

