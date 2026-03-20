#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

enum Speciality {
    COMPUTER_SCIENCE,
    INFORMATICS,
    OTHER
};

union ThirdMark {
    int programming;
    int numerical;
    int pedagogy;
};

struct Student {
    string surname;
    int course;
    Speciality speciality;
    int physics;
    int math;
    ThirdMark third;
};

// Input
void inputStudents(Student* s, int n) {
    cout << "\n=== ENTER STUDENT DATA ===\n";

    for (int i = 0; i < n; i++) {
        cout << "\nStudent #" << i + 1 << endl;

        cout << "Surname: ";
        cin >> s[i].surname;

        cout << "Course: ";
        cin >> s[i].course;

        cout << "Choose speciality:\n";
        cout << "0 - Computer Science\n";
        cout << "1 - Informatics\n";
        cout << "2 - Other\n";
        cout << "Your choice: ";

        int spec;
        cin >> spec;
        s[i].speciality = (Speciality)spec;

        cout << "Physics grade: ";
        cin >> s[i].physics;

        cout << "Math grade: ";
        cin >> s[i].math;

        if (s[i].speciality == COMPUTER_SCIENCE) {
            cout << "Programming grade: ";
            cin >> s[i].third.programming;
        }
        else if (s[i].speciality == INFORMATICS) {
            cout << "Numerical methods grade: ";
            cin >> s[i].third.numerical;
        }
        else {
            cout << "Pedagogy grade: ";
            cin >> s[i].third.pedagogy;
        }
    }
}

// Output
void printStudents(Student* s, int n) {
    cout << "\n=== STUDENT LIST ===\n";

    cout << "---------------------------------------------------------------------------------------------\n";
    cout << "| # | Surname   | Course | Spec | Phy | Mat | Prog | Num | Ped |\n";
    cout << "---------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << "| " << setw(2) << i + 1
            << " | " << setw(9) << s[i].surname
            << " | " << setw(6) << s[i].course
            << " | " << setw(4) << s[i].speciality
            << " | " << setw(3) << s[i].physics
            << " | " << setw(3) << s[i].math << " | ";

        if (s[i].speciality == COMPUTER_SCIENCE)
            cout << setw(4) << s[i].third.programming << " |  -  |  -  |\n";
        else if (s[i].speciality == INFORMATICS)
            cout << "  -  | " << setw(4) << s[i].third.numerical << " |  -  |\n";
        else
            cout << "  -  |  -  | " << setw(4) << s[i].third.pedagogy << " |\n";
    }

    cout << "---------------------------------------------------------------------------------------------\n";
}

int main() {
    int n;

    cout << "========================================\n";
    cout << "   STUDENT PERFORMANCE SYSTEM (LEVEL B)\n";
    cout << "========================================\n";

    cout << "Enter number of students: ";
    cin >> n;

    Student* s = new Student[n];

    int choice;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Enter data\n";
        cout << "2. Show table\n";
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