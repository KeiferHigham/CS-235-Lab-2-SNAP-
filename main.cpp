#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include "snap.h"
#include "csg.h"
#include "cdh.h"
#include "cr.h"
#include "csgs.h"
#include <sstream>

#define CONSOLE 1




using namespace std;



int FindComma(string inputLine) {
    int indexComma = 0;
    for(int i = 0; i < inputLine.size(); ++i) {
        if(inputLine.at(i) == ',') {
            indexComma = i;
            return indexComma;
        }
    }

}
int FindParent(string lineInput) {
    int indexParent;
    for(int i = 0; i < lineInput.size(); ++i) {
        if(lineInput.at(i) == '(' || lineInput.at(i) == ')') {
            indexParent = i;
            return indexParent;
        }
    }

}

int main(int argc, char* argv[]) {

    if (argc < 3) {
        cerr << "Please provide name of input and output files";
        return 1;
    }
    cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);
    if (!in) {
        cerr << "Unable to open " << argv[1] << " for input";
        return 2;
    }
    cout << "Output file: " << argv[2] << endl;
    ofstream out(argv[2]);
    if (!out) {
        in.close();
        cerr << "Unable to open " << argv[2] << " for output";
        return 3;
    }


    vector<snap> snapInfo;
    vector<csg> csgInfo;
    vector<cdh> cdhInfo;
    vector<cr> crInfo;


    out << "Input Strings:" << endl;
char e;

        for (string line; getline(in, line);) {
            try {
                if (line.substr(0, 4) == "snap") {
                    string idNum = line.substr(FindParent(line) + 1, FindComma(line) - 1 - FindParent(line));
                    string nameLine = line.substr(FindComma(line) + 1, line.size() - 1 - FindComma(line) + 1);
                    string name = nameLine.substr(0, FindComma(nameLine));

                    string addressLine = nameLine.substr(FindComma(nameLine) + 1,
                                                         nameLine.size() - 1 - FindComma(nameLine) + 1);
                    string address = addressLine.substr(0, FindComma(addressLine));
                    string phoneNumLine = addressLine.substr(FindComma(addressLine) + 1,
                                                             addressLine.size() - 1 - FindComma(addressLine) + 1);
                    string phoneNumber = phoneNumLine.substr(0, FindParent(phoneNumLine));
                    snap tempSnap(idNum, name, address, phoneNumber);
                    snapInfo.push_back(tempSnap);

                    out << line << endl;
                    //cout << phoneNumber << endl;
                    //cout << address << endl;
                    //cout << name << endl;
                    // cout << idNum << endl;

                } else if (line.substr(0, 4) == "csg(") {
                    string courseNum = line.substr(FindParent(line) + 1, FindComma(line) - 1 - FindParent(line));
                    //cout << courseNum << endl;
                    string idLine = line.substr(FindComma(line) + 1, line.size() - 1 - FindComma(line) + 1);
                    string id = idLine.substr(0, FindComma(idLine));
                    // cout << id << endl;
                    string gradeLine = idLine.substr(FindComma(idLine) + 1, line.size() - 1 - FindComma(line) + 1);
                    string grade = gradeLine.substr(0, FindParent(gradeLine));
                    //cout << grade << endl;
                    csg tempCsg(courseNum, id, grade);
                    csgInfo.push_back(tempCsg);
                    out << line << endl;

                } else if (line.substr(0, 3) == "cdh") {
                    string courseNum = line.substr(FindParent(line) + 1, FindComma(line) - 1 - FindParent(line));
                    string dayLine = line.substr(FindComma(line) + 1, line.size() - 1 - FindComma(line) + 1);
                    string day = dayLine.substr(0, FindComma(dayLine));
                    string timeLine = dayLine.substr(FindComma(dayLine) + 1, line.size() - 1 - FindComma(line) + 1);
                    string time = timeLine.substr(0, FindParent(timeLine));
                    cdh tempCdh(courseNum, day, time);
                    cdhInfo.push_back(tempCdh);
                    out << line << endl;
                    //*cout << time << endl;
                    //cout << day << endl;
                    //cout << courseNum << endl;
                } else if (line.substr(0, 3) == "cr(") {
                    string courseNum = line.substr(FindParent(line) + 1, FindComma(line) - 1 - FindParent(line));
                    string locationLine = line.substr(FindComma(line) + 1, line.size() - 1 - FindComma(line) + 1);
                    string location = locationLine.substr(0, FindParent(locationLine));
                    //cout << location << endl;
                    // cout << courseNum << endl;
                    cr tempcR(courseNum, location);
                    crInfo.push_back(tempcR);
                    out << line << endl;


                } else {
                    throw '**';
                }


            }
            catch (char e) {
                out << e << "Error:" << line << endl;

            }
        }
    out << endl;
    out << "Vectors:" << endl;
    for (int i = 0; i < snapInfo.size(); ++i) {
        out << snapInfo.at(i).ToString() << endl;
    }
    for (int i = 0; i < csgInfo.size(); ++i) {
        out << csgInfo.at(i).ToString() << endl;
    }
    for (int i = 0; i < cdhInfo.size(); ++i) {
        out << cdhInfo.at(i).ToString() << endl;
    }
    for (int i = 0; i < crInfo.size(); ++i) {
        out << crInfo.at(i).ToString() << endl;
    }
    out << "Course Grades:" << endl;


    for (int i = 0; i < csgInfo.size(); ++i) {
        for (int j = 0; j < snapInfo.size(); ++j) {
            if (csgInfo.at(i).GetId() == snapInfo.at(j).GetId()) {
                out << csgInfo.at(i).GetCourse() << "," << snapInfo.at(j).GetName() << "," << csgInfo.at(i).GetGrade()
                    << endl;
            }
        }
    }

    ostringstream os;
    string schedule = "";
    for (int i = 0; i < crInfo.size(); ++i) {
        for (int j = 0; j < cdhInfo.size(); ++j) {
            schedule = schedule + cdhInfo.at(j).GetDay();
        }
        os << crInfo.at(i).GetCourse() << " " << schedule << " " << cdhInfo.at(i).GetTime() << ", "
           << crInfo.at(i).GetLocation();
    }

    string totalSchedule;
    totalSchedule = os.str();


    out << "Student Schedules:" << endl;

    /*  for(int i = 0; i < snapInfo.size(); ++i) {
          out << snapInfo.at(i).StudentInfo() << endl;
          out << totalSchedule << endl << endl;
      }*/

    string studSchedule = "";
    string time;
    string day;
    string location;

    string sched = "";
    ostringstream ss;
    string dayOfClass;
    vector <string> days;

string daySched = "";
    for (int i = 0; i < snapInfo.size(); ++i) {
        out << snapInfo.at(i).StudentInfo() << endl;
        for (int j = 0; j < csgInfo.size(); ++j) {
            if (snapInfo.at(i).GetId() == csgInfo.at(j).GetId()) {
                out << csgInfo.at(j).GetCourse() << days.at(j);
                cout << csgInfo.at(j).GetCourse();

            }
        }
    }


















  /* for (int f = 0; f < csgInfo.size(); ++f) {
        for (int b = 0; b < cdhInfo.size(); ++b) {
            if (csgInfo.at(f).GetCourse() == cdhInfo.at(b).GetCourse()) {
                studSchedule = studSchedule + cdhInfo.at(b).GetDay();
                time = cdhInfo.at(b).GetTime();
            }

        }
        out << " " << studSchedule << " " << time << endl;
        studSchedule = ""; */
    }





