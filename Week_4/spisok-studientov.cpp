#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

struct Student
{
    std::string name;
    std::string surname;
    unsigned long day = 0;
    unsigned long month = 0;
    unsigned long year = 0;
};

int main()
{
    long number = 0;
    std::cin >> number;
    std::vector<Student> students;
    for (long i = 0; i < number; ++i)
    {
        Student student;

        std::string name;
        std::string surname;
        unsigned long day = 0;
        unsigned long month = 0;
        unsigned long year = 0;

        std::cin >> name;
        std::cin >> surname;
        std::cin >> day;
        std::cin >> month;
        std::cin >> year;

        student.name = name;
        student.surname = surname;
        student.day = day;
        student.month = month;
        student.year = year;

        students.push_back(student);
    }

    std::cin >> number;

    for (long i = 0; i < number; ++i)
    {
        std::string command;
        std::cin >> command;
        if (command == "name") {
            long order = 0;
            std::cin >> order;
            if (order > students.size() || order <= 0)
            {
                std::cout << "bad request" << '\n';
                continue;
            }
            std::cout << students[order-1].name  << ' ' << students[order-1].surname << "\n";
            continue;
        } else if (command == "date") {
            long order = 0;
            std::cin >> order;
            if (order > students.size() || order <= 0)
            {
                std::cout << "bad request" << '\n';
                continue;
            }
            std::cout << students[order-1].day << '.' <<  students[order-1].month << '.'
                      << students[order-1].year << "\n";
            continue;
        } else{
            long escape = 0;
            std::cin >> escape;
            std::cout << "bad request" << '\n';
            continue;
        }
    }


    return 0;
}
