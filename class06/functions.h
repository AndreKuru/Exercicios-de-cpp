#ifndef SCHOOL_FUNCTIONS_H
#define SCHOOL_FUNCTIONS_H

#include "student.h"
#include <vector>
#include <fstream>

namespace school {
  
std::vector<Student const*> dismissed_by_time(std::vector<Student>const& students, int current_year);
std::vector<Student> read_students(std::istream& in);

}

#endif