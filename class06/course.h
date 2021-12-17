#ifndef COURSE_H
#define COURSE_H

#include <vector>
#include <string>

class Course {
 public:
  virtual ~Course() = default;
  virtual double average() const = 0;
  virtual std::string name() const = 0;
};

class DataStructures: public Course {
 public:
  DataStructures(std::vector<double> works, double exam): 
    works_{std::move(works)},
    exam_{exam}
  {}
  double average() const;

  std::string name() const {
    return "Data Structures";
  }

 private:
  std::vector<double> works_;
  double exam_;
};

class Calculus: public Course {
 public:
  Calculus(std::vector<double> exams): 
    exams_{std::move(exams)}
  {}
  double average() const;

  std::string name() const {
    return "Calculus";
  }

 private:
  std::vector<double> exams_;
};

#endif
