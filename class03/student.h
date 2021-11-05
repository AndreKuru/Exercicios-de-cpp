#ifndef SCHOOL_STUDENT_H
#define SCHOOL_STUDENT_H

#include <string>
#include <vector>

namespace school {

class Student {
public:
  Student(std::string name, int year, std::vector<float> grades):
    name_{std::move(name)},
    year_{year},
    grades_{std::move(grades)}
  {}

  std::string name() const {
    return name_;
  }

  float average() const;

  int years_enrolled(int current_year) const {
    return current_year - year_;
  }

private:
  std::string name_;
  int year_;
  std::vector<float> grades_;
};

}

#endif