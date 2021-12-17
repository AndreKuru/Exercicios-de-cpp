#ifndef SCHOOL_STUDENT_H
#define SCHOOL_STUDENT_H

#include <string>
#include <vector>
#include <memory>

#include "course.h"

namespace school {

class Student {
public:
  Student(Student const&) = delete;

  Student(Student &&) = default;

  Student(std::string name, int year, std::vector<std::unique_ptr<Course>> courses):
    name_{std::move(name)},
    year_{year},
    courses_{std::move(courses)}
  {}

  std::string name() const {
    return name_;
  }

  std::vector<std::unique_ptr<Course>> const& courses() const {
    return courses_;
  }

  int years_enrolled(int current_year) const {
    return current_year - year_;
  }

private:
  std::string name_;
  int year_;
  std::vector<std::unique_ptr<Course>> courses_;
};

}

#endif