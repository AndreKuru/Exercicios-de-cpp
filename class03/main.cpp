#include <iostream>
#include <string>
#include <vector>

#include "student.h"
#include "functions.h"

int main()
{
    using namespace std::string_literals;
    using school::Student;

    auto students = std::vector<Student>{
      Student("Gabriel", 2020, std::vector<float>{6.0, 8.0, 7.0}),
      Student("Tarcisio", 2009, std::vector<float>{10.0, 10.0, 10.0}),
      Student("Reprovenson", 2018, std::vector<float>{2.0, 5.5, 3.2})
    };

    for (auto s: school::approved(students)) {
        std::cout << s.name()
                  << " is approved by grade with average "
                  << s.average() << ".\n";
    }

    for (auto s: school::dismissed_by_time(students, 2021)) {
        std::cout << s.name()
                  << " was dismissed for being in the course for too long: "
                  << s.years_enrolled(2021) << " years.\n";
    }
}
