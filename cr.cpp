//
// Created by Keifer Higham on 9/21/20.
//

#include "cr.h"
#include <sstream>

cr::cr(string courseNameIn, string roomIn) {
room = roomIn;
courseName = courseNameIn;
}

string cr::ToString() const {
    ostringstream out;
    out << "cr(" << courseName << "," << room << ")";

    return out.str();
}

string cr::GetCourse() const {
    return courseName;
}

string cr::GetLocation() const {
    return room;
}

