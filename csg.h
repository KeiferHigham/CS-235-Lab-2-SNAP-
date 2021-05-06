#include <climits>

#ifndef LAB02SNAP_CSG_H
#define LAB02SNAP_CSG_H
#include "snap.h"
#include <string>
#include "Course.h"
#include "snap.h"
using namespace std;

class csg: public snap, public Course   {
public:
    csg(string courseNameIn, string studentIdIn, string studentGradeIn);
    string ToString() const;
    string GetGrade() const;
    string GetId() const;
    string GetCourse() const;




private:
    string courseName;
    string studentId;
    string studentGrade;









};

#endif //LAB02SNAP_CSG_H
