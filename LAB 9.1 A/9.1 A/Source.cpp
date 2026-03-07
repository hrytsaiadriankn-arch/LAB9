#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

enum Specialnist {
    COMPUTER_SCIENCE,
    INFORMATICS,
    MATH_ECONOMICS,
    PHYSICS_INFORMATICS,
    LABOR_TRAINING
};

struct Student {
    string surname;
    int course;
    Specialnist spec;
    int physics;
    int math;
    int informatics;
};

string getSpecName(Specialnist s) {
    switch (s) {
    case COMPUTER_SCIENCE: return "Комп'ютерні науки";
    case INFORMATICS: return "Інформатика";
    case MATH_ECONOMICS: return "Математика та економіка";
    case PHYSICS_INFORMATICS: return "Фізика та інформатика";
    case LABOR_TRAINING: return "Трудове навчання";
    }
    return "";
}

bool validGrade(int g) {
    return g >= 3 && g <= 5;
}

void inputStudents(Student* s, int n) {

    for (int i = 0; i < n; i++) {

        cout << "\nСтудент №" << i + 1 << endl;

        cout << "Прізвище: ";
        cin >> s[i].surname;

        cout << "Курс: ";
        cin >> s[i].course;

        int t;
        do {
            cout << "Спеціальність (0-4): ";
            cin >> t;
        } while (t < 0 || t > 4);

        s[i].spec = (Specialnist)t;

        do {
            cout << "Оцінка з фізики (3-5): ";
            cin >> s[i].physics;
        } while (!validGrade(s[i].physics));

        do {
            cout << "Оцінка з математики (3-5): ";
            cin >> s[i].math;
        } while (!validGrade(s[i].math));

        do {
            cout << "Оцінка з інформатики (3-5): ";
            cin >> s[i].informatics;
        } while (!validGrade(s[i].informatics));
    }
}

void printStudents(Student* s, int n) {

    cout << "\n=============== ТАБЛИЦЯ СТУДЕНТІВ ===============\n";

    cout << left
        << setw(4) << "№"
        << setw(15) << "Прізвище"
        << setw(6) << "Курс"
        << setw(25) << "Спеціальність"
        << setw(6) << "Фіз"
        << setw(6) << "Мат"
        << setw(6) << "Інф"
        << endl;

    for (int i = 0; i < n; i++) {

        cout << setw(4) << i + 1
            << setw(15) << s[i].surname
            << setw(6) << s[i].course
            << setw(25) << getSpecName(s[i].spec)
            << setw(6) << s[i].physics
            << setw(6) << s[i].math
            << setw(6) << s[i].informatics
            << endl;
    }
}

double percentGood(Student* s, int n) {

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (s[i].physics >= 4 && s[i].math >= 4)
            count++;
    }

    return (double)count / n * 100;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;

    cout << "Кількість студентів: ";
    cin >> n;

    Student* s = new Student[n];

    inputStudents(s, n);

    printStudents(s, n);

    double p = percentGood(s, n);

    cout << "\nПроцент студентів з оцінками 4 або 5 з фізики і математики: "
        << p << "%" << endl;

    delete[] s;

    return 0;
}