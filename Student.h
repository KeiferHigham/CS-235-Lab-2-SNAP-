#ifndef LAB02SNAP_STUDENT_H
#define LAB02SNAP_STUDENT_H
#include <string>
using namespace std;

class Student     {
public:
   Student(string id);
   Student();
     string GetStudId( ) const;
    string ToString() const;






private:
   string studId;









};

Student::Student(string id) {
    studId = id;

}

string Student::GetStudId() const {

    return studId;


}

#endif //LAB02SNAP_STUDENT_H
