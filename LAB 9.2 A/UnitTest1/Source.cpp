#include <iostream>
#include <iomanip>
#include <string>

struct Student {
    std::string surname;
    int course;
    std::string specialty;
    int physics;
    int math;
    int informatics;
};

// Функція вводу однієї оцінки
int inputGrade(const std::string& subj) {
    int grade;
    while (true) {
        std::cout << "Оцінка з " << subj << " (0-100): ";
        std::cin >> grade;
        if (std::cin.fail()  grade < 0  grade > 100) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Помилка! Введіть число від 0 до 100.\n";
        }
        else return grade;
    }
}

// Введення студентів
void inputStudents(Student* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "Студент #" << i + 1 << "\n";
        std::cout << "Прізвище: ";
        std::cin >> arr[i].surname;

        while (true) {
            std::cout << "Курс (1-6): ";
            std::cin >> arr[i].course;
            if (std::cin.fail()  arr[i].course < 1  arr[i].course>6) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Помилка! Введіть число від 1 до 6.\n";
            }
            else break;
        }

        std::cin.ignore(); // очищення буфера
        std::cout << "Спеціальність: ";
        std::getline(std::cin, arr[i].specialty);

        arr[i].physics = inputGrade("фізики");
        arr[i].math = inputGrade("математики");
        arr[i].informatics = inputGrade("інформатики");

        std::cout << "\n";
    }
}

// Вивід таблиці
void printTable(Student* arr, int n) {
    std::cout << std::left << std::setw(5) << "№"
        << std::setw(15) << "Прізвище"
        << std::setw(7) << "Курс"
        << std::setw(20) << "Спеціальність"
        << std::setw(10) << "Фізика"
        << std::setw(10) << "Матем"
        << std::setw(10) << "Інформ" << "\n";

    for (int i = 0; i < n; i++) {
        std::cout << std::setw(5) << i + 1
            << std::setw(15) << arr[i].surname
            << std::setw(7) << arr[i].course
            << std::setw(20) << arr[i].specialty
            << std::setw(10) << arr[i].physics
            << std::setw(10) << arr[i].math
            << std::setw(10) << arr[i].informatics
            << "\n";
    }
}

int main() {
    int n;
    while (true) {
        std::cout << "Введіть кількість студентів: ";
        std::cin >> n;
        if (std::cin.fail() || n <= 0) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Помилка! Введіть додатнє число.\n";
        }
        else break;
    }

    Student* students = new Student[n];
    inputStudents(students, n);
    printTable(students, n);
    delete[] students;

    return 0;
}