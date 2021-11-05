#include "functions.h"
#include "student.h"

namespace school {

std::vector<Student> approved(std::vector<Student>const& students) {
  std::vector<Student> approved;

  for(auto& student: students) {
    if(student.average() >= 6) {
      approved.push_back(student);
    }
  }

  return approved;
}

std::vector<Student> dismissed_by_time(std::vector<Student>const& students, int current_year) {
  std::vector<Student> dismissed;

  for(auto& student: students) {
    if(student.years_enrolled(current_year) >= 7) {
      dismissed.push_back(student);
    }
  }

  return dismissed;
}



}