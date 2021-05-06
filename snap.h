#ifndef LAB02SNAP_SNAP_H
#define LAB02SNAP_SNAP_H

#include <string>
#include <vector>
#include "Student.h"
using namespace std;

class snap : Student  {
public:
    snap(string studentIdIn, string studentNameIn, string studentAddressIn, string StudentPhoneIn);
    snap();
    string ToString() const;
    string GetName() const;
    string GetId() const;
    string StudentInfo() const;
    string GetAdress() const;


    /**friend operator* << (ofstream& of, Course& course){
     *      of << course.toString();
     * }
     *
     *  ...
     *
     *  //without friend funtcion
     *  outputFile << cr.toString();
     *
     *  //with friend function
     *  outputFile << cr;
     */





protected:
string studIdNum;
string studentName;
string studentAddress;

string studentPhoneNum;


};


#endif //LAB02SNAP_SNAP_H
