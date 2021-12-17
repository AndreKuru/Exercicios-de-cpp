#include "course.h"

double DataStructures::average() const {
  auto worksTotal = 0.0;
  for (auto work: works_) {
    worksTotal += work;
  }
  return worksTotal/works_.size() * 0.8 + exam_ * 0.2;
}

double Calculus::average() const {
  auto examsTotal = 0.0;
  for (auto exam: exams_) {
    examsTotal += exam;
  }
  return examsTotal/exams_.size();
}
