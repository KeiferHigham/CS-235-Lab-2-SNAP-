#ifndef LAB02SNAP_CR_H
#define LAB02SNAP_CR_H

#include <string>
#include "Course.h"

using namespace std;

class cr :public Course  {
public:
    cr(string courseNameIn, string roomIn);
    string ToString() const;
    string GetCourse() const;
    string GetLocation() const;





private:
    string courseName;
    string room;





};

#endif //LAB02SNAP_CR_H
