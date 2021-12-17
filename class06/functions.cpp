#include <sstream>
#include <iostream>
#include <memory>

#include "functions.h"
#include "student.h"
#include "course.h"

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

  return value;
}

int ask_int(std::istream& in, std::string question)
{
  std::cout << question << " ";
  return ask_int(in);
}

double ask_double(std::istream& in)
{
  auto buf = ""s;
  std::getline(in, buf);

  auto value = 0.0;
  auto sttr = std::stringstream{buf};
  sttr >> value;

  return value;
}

double ask_double(std::istream& in, std::string question)
{
  std::cout << question << " ";
  return ask_double(in);
}

std::unique_ptr<Course> ask_data_structures_cli(std::istream& in)
{
  const auto n_works = 3;
  std::vector<double> works;
  for (auto i = 0; i < n_works; ++i) {
    auto grade = ask_double(in, "Nota: ");
    works.push_back(grade);
  }
  auto exam = ask_double(in, "Nota: ");
  return std::make_unique<DataStructures>(works, exam);
}

std::unique_ptr<Course> ask_data_structures(std::istream& in)
{
  const auto n_works = 3;
  std::vector<double> works;
  for (auto i = 0; i < n_works; ++i) {
    auto grade = ask_double(in);
    works.push_back(grade);
  }
  auto exam = ask_double(in);
  return std::make_unique<DataStructures>(works, exam);
}

std::unique_ptr<Course> ask_calculus_cli(std::istream& in)
{
  const auto n_exams = 3;
  std::vector<double> exams;
  for (auto i = 0; i < n_exams; ++i) {
    auto grade = ask_double(in, "Nota: ");
    exams.push_back(grade);
  }
  return std::make_unique<Calculus>(exams);
}

std::unique_ptr<Course> ask_calculus(std::istream& in)
{
  const auto n_exams = 3;
  std::vector<double> exams;
  for (auto i = 0; i < n_exams; ++i) {
    auto grade = ask_double(in);
    exams.push_back(grade);
  }
  return std::make_unique<Calculus>(exams);
}

school::Student read_student(std::istream& in)
{
  auto name = ask_string(in);
  auto year = ask_int(in);
  auto n_courses = ask_int(in);
  
  std::vector<std::unique_ptr<Course>> courses;

  for (auto i = 0; i < n_courses; ++i) {
    auto name_course = ask_string(in);
    if (name_course == "Data Structures") {
      courses.push_back(ask_data_structures(in));
    } else {
      courses.push_back(ask_calculus(in));
    }
  }

  return school::Student(name, year, std::move(courses));
}

school::Student read_student_cli(std::istream& in)
{
  auto name = ask_string(in, "Nome do estudante: ");
  auto year = ask_int(in, "Ano de mátricula: ");
  auto n_courses = ask_int(in, "Número de disciplinas: ");
  
  std::vector<std::unique_ptr<Course>> courses;

  for (auto i = 0; i < n_courses; ++i) {
    auto name_course = ask_string(in, "Nome do curso: ");
    if (name_course == "Data Structures") {
      courses.push_back(ask_data_structures_cli(in));
    } else {
      courses.push_back(ask_calculus_cli(in));
    }
  }

  return school::Student(name, year, std::move(courses));
}

namespace school {

std::vector<Student> read_students(std::istream& in)
{
  std::vector<Student> students;

  if (dynamic_cast<std::ifstream*>(&in) != nullptr) {
    auto number_students = ask_int(in);
    
    for (auto i = 0; i < number_students; ++i) {
      students.push_back(read_student(in));
    }

    return students;
  }

  auto number_students = ask_int(in, "Número de estudantes: ");

  for (auto i = 0; i < number_students; ++i) {
    students.push_back(read_student_cli(in));
  }

  return students;
}

std::vector<Student const*> dismissed_by_time(std::vector<Student>const& students, int current_year) {
  std::vector<Student const*> dismissed;

  for(auto& student: students) {
    if(student.years_enrolled(current_year) >= 7) {
      dismissed.push_back(&student);
    }
  }

  return dismissed;
}

}