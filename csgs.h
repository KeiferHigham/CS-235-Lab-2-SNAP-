#ifndef LAB02SNAP_CSGS_H
#define LAB02SNAP_CSGS_H
#include <string>

using namespace std;

class csgs {
public:
csgs();
csgs(string courseNum, string id, string grade);

private:
string numOfCourse;
string studentId;
string studentGrade;

};



#endif //LAB02SNAP_CSGS_H
