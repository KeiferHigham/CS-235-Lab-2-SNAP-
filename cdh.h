#ifndef LAB02SNAP_CDH_H
#define LAB02SNAP_CDH_H
#include "Course.h"
#include <string>

using namespace std;

class cdh :public Course  {
public:
cdh(string courseNameIn, string dayIn, string timeIn);
    string ToString() const;
    string GetDay() const;
    string GetCourse() const;
    string GetTime() const;




private:
string courseName;
string day;
string time;


};

#endif //LAB02SNAP_CDH_H
