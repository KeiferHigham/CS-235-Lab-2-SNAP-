#ifndef LAB02SNAP_COURSE_H
#define LAB02SNAP_COURSE_H

#include <string>
#include <iostream>
using namespace std;

class Course {
public:
string GetCourse() const;

    virtual string ToString() const = 0;
friend std::ostream& operator<< (ostream& os, const Course& mycourse) {
  os << mycourse.ToString();
    }

protected:
string course;

};


#endif //LAB02SNAP_COURSE_H
