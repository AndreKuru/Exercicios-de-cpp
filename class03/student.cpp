#include "student.h"

namespace school {

float Student::average() const {
  auto total = 0.0;

  for(auto grade: grades_) {
    total += grade;
  }

  return total / grades_.size();
}

}