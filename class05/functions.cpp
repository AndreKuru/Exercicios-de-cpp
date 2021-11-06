#include "functions.h"
#include "student.h"
#include <sstream>

constexpr auto N_STUDENTS = 3;

using namespace std::string_literals;

std::string ask_string(std::istream& in)
{
  auto s = ""s;
  std::getline(in, s);

  return s;
}

int ask_int(std::istream& in)
{
  auto buf = ""s;
  std::getline(in, buf);

  auto value = 0;
  auto sttr = std::stringstream{buf};
  sttr >> value;

  return value;
}

float ask_float(std::istream& in)
{
  auto buf = ""s;
  std::getline(in, buf);

  auto value = 0.0;
  auto sttr = std::stringstream{buf};
  sttr >> value;

  return value;
}

namespace school {



std::vector<Student> read_students(std::istream& in)
{
  auto number_students = ask_int(in);

  std::vector<Student> students;

  for (auto i = 0; i < number_students; ++i) {
    auto name = ask_string(in);
    auto year = ask_int(in);
    std::vector<float> grades;
    for (auto j = 0; j < 3; ++j) {
      grades.push_back(ask_float(in));
    }
    students.push_back(Student(name, year, grades));
  }

  return students;
}

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