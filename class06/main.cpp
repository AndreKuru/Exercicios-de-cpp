#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "student.h"
#include "functions.h"


int _main(std::istream& in)
{
    auto students = school::read_students(in);

    for (auto& student: students) {
        std::cout << "Student: " << student.name() << '\n';
        for (auto& course: student.courses()) {
            std::cout << "Average on " << course->name() << ": " << course->average() << '\n';
        }
    }

    for (auto s: school::dismissed_by_time(students, 2019)) {
        std::cout << s->name()
                  << " was dismissed for being in the course for too long: "
                  << s->years_enrolled(2019) << " years.\n";
    }

    return 0;
}

int main(int argc, char** argv)
{
    if (argc == 1) {
        return _main(std::cin);
    }

    auto file = std::ifstream{argv[1]};

    return _main(file);
}
