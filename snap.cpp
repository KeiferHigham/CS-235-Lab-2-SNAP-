#include <climits>
#include "snap.h"
#include <sstream>
#include <vector>

using namespace std;

snap::snap(string StudentIdIn, string studentNameIn, string studentAddressIn, string studentPhoneIn) {

    studIdNum = StudentIdIn;
    studentName = studentNameIn;
    studentAddress = studentAddressIn;
    studentPhoneNum = studentPhoneIn;

}

string snap::ToString() const {
    ostringstream out;
    out << "snap(" << studIdNum << "," << studentName << "," << studentAddress << ","
    << studentPhoneNum << ")";
    return out.str();
}

string snap::GetName() const  {
return studentName;


}

snap::snap() {

}

string snap::GetId() const {
    return studIdNum;
}

string snap::StudentInfo() const {
    ostringstream out;
    out << studentName << ", " << studIdNum << ", " << studentAddress << ", " << studentPhoneNum;


    return out.str();
}

string snap::GetAdress() const {
    return studentAddress;
}







