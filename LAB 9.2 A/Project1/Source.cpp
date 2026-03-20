#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

enum Speciality {
    COMPUTER_SCIENCE,
    INFORMATICS,
    MATH_ECONOMICS,
    PHYSICS_INFORMATICS,
    LABOR_TRAINING
};

string specialityToString(Speciality s) {
    switch (s) {
    case COMPUTER_SCIENCE: return "Computer Science";
    case INFORMATICS: return "Informatics";
    case MATH_ECONOMICS: return "Math & Economics";
    case PHYSICS_INFORMATICS: return "Physics & Informatics";
    case LABOR_TRAINING: return "Labor Training";
    default: return "";
    }
}

struct Student {
    string surname;
    int course;
    Speciality speciality;
    int physics;
    int math;
    int informatics;
};

// Input
void inputStudents(Student* s, int n) {
    cout << "\n=== ENTER STUDENT DATA ===\n";

    for (int i = 0; i < n; i++) {
        cout << "\nStudent #" << i + 1 << endl;

        cout << "Surname: ";
        cin >> s[i].surname;

        cout << "Course (1-6): ";
        cin >> s[i].course;

        cout << "Choose speciality:\n";
        cout << "0 - Computer Science\n";
        cout << "1 - Informatics\n";
        cout << "2 - Math & Economics\n";
        cout << "3 - Physics & Informatics\n";
        cout << "4 - Labor Training\n";
        cout << "Your choice: ";

        int spec;
        cin >> spec;
        s[i].speciality = (Speciality)spec;

        cout << "Physics grade: ";
        cin >> s[i].physics;

        cout << "Math grade: ";
        cin >> s[i].math;

        cout << "Informatics grade: ";
        cin >> s[i].informatics;
    }
}

// Output
void printStudents(Student* s, int n) {
    cout << "\n=== STUDENT LIST ===\n";

    cout << "------------------------------------------------------------------------------------------\n";
    cout << "| # | Surname     | Course | Speciality              | Phy | Mat | Inf |\n";
    cout << "------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << "| " << setw(2) << i + 1
            << " | " << setw(11) << s[i].surname
            << " | " << setw(6) << s[i].course
            << " | " << setw(23) << specialityToString(s[i].speciality)
            << " | " << setw(3) << s[i].physics
            << " | " << setw(3) << s[i].math
            << " | " << setw(3) << s[i].informatics << " |\n";
    }

    cout << "------------------------------------------------------------------------------------------\n";
}

int main() {
    int n;

    cout << "========================================\n";
    cout << "   STUDENT PERFORMANCE SYSTEM (LEVEL A)\n";
    cout << "========================================\n";

    cout << "Enter number of students: ";
    cin >> n;

    Student* s = new Student[n];

    int choice;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Enter data\n";
        cout << "2. Show students\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";

        cin >> choice;

        switch (choice) {
        case 1:
            inputStudents(s, n);
            break;
        case 2:
            printStudents(s, n);
            break;
        case 0:
            cout << "Program finished.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    delete[] s;
}