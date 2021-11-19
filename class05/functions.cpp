#include "functions.h"
#include "student.h"
#include <sstream>
#include <iostream>

using namespace std::string_literals;

std::string ask_string(std::istream& in)
{
  auto s = ""s;
  std::getline(in, s);

  return s;
}

std::string ask_string(std::istream& in, std::string question)
{
  std::cout << question << " ";
  return ask_string(in);
}

int ask_int(std::istream& in)
{
  auto buf = ""s;
  std::getline(in, buf);

  auto value = 0;
  auto sttr = std::stringstream{buf};
  sttr >> value;

  std::cout << "Value: " << value << std::endl;

  return value;
}

int ask_int(std::istream& in, std::string question)
{
  std::cout << question << " ";
  return ask_int(in);
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

float ask_float(std::istream& in, std::string question)
{
  std::cout << question << " ";
  return ask_float(in);
}

school::Student read_student(std::istream& in)
{
  auto name = ask_string(in);
  auto year = ask_int(in);
  
  std::vector<float> grades;
  for (auto j = 0; j < 3; ++j) {
    grades.push_back(ask_float(in));
  }

  return school::Student(name, year, grades);
}

school::Student read_student_cli(std::istream& in)
{
  auto name = ask_string(in, "Nome do estudante: ");
  auto year = ask_int(in, "Ano de mátricula: ");
  
  std::vector<float> grades;
  for (auto j = 0; j < 3; ++j) {
    grades.push_back(ask_float(in, "Nota: "));
  }

  return school::Student(name, year, grades);
}

namespace school {

std::vector<Student> read_students(std::istream& in)
{
  std::vector<Student> students;

  if (dynamic_cast<std::ifstream*>(&in) != nullptr) {
    auto number_students = ask_int(in);
    
    for (auto i = 0; i < number_students; ++i) {
      auto student = read_student(in);
      students.push_back(student);
    }

    return students;
  }

  auto number_students = ask_int(in, "Número de estudantes: ");

  for (auto i = 0; i < number_students; ++i) {
    auto student = read_student_cli(in);
    students.push_back(student);
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