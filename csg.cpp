

#include "csg.h"
#include <sstream>

csg::csg(string courseNameIn, string studentIdIn, string studentGradeIn) {
    courseName= courseNameIn;
    studentId = studentIdIn;
    studentGrade = studentGradeIn;

}

string csg::ToString() const {
    ostringstream out;
    out << "csg(" << courseName << "," << studentId << "," << studentGrade << ")";



    return out.str();
}

string csg::GetGrade() const {
return studentGrade;
}

string csg::GetId() const {
    return studentId;
}

string csg::GetCourse() const {
    return courseName;
}



