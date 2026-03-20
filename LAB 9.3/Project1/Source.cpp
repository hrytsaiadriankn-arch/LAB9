#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

struct Note {
    string surname;
    string name;
    string phone;
    int birth[3]; // day, month, year
};

// --- Input integer with validation ---
int inputInt(const string& prompt, int minVal, int maxVal) {
    int x;
    while (true) {
        cout << prompt;
        cin >> x;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number.\n";
        }
        else if (x < minVal || x > maxVal) {
            cout << "Value must be in range [" << minVal << "; " << maxVal << "]\n";
        }
        else {
            return x;
        }
    }
}

// --- Phone validation ---
string inputPhone() {
    string phone;
    while (true) {
        cout << "Phone: ";
        cin >> phone;

        bool valid = true;
        for (char c : phone) {
            if (!isdigit(c)) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            cout << "Phone must contain only digits!\n";
        }
        else {
            return phone;
        }
    }
}

// --- Input one record ---
Note inputNote() {
    Note n;

    cout << "Surname: ";
    cin >> n.surname;

    cout << "Name: ";
    cin >> n.name;

    n.phone = inputPhone();

    n.birth[0] = inputInt("Day (1-31): ", 1, 31);
    n.birth[1] = inputInt("Month (1-12): ", 1, 12);
    n.birth[2] = inputInt("Year (1900-2100): ", 1900, 2100);

    return n;
}

// --- Print one record ---
void printNote(const Note& n) {
    cout << n.surname << " " << n.name
        << ", phone: " << n.phone
        << ", birth date: "
        << n.birth[0] << "." << n.birth[1] << "." << n.birth[2]
        << endl;
}

// --- Input array ---
void inputArray(Note*& arr, int& size) {
    delete[] arr;

    size = inputInt("Enter number of elements: ", 1, 1000);
    arr = new Note[size];

    for (int i = 0; i < size; i++) {
        cout << "\nElement " << i + 1 << ":\n";
        arr[i] = inputNote();
    }
}

// --- Print array ---
void printArray(Note* arr, int size) {
    if (arr == nullptr || size == 0) {
        cout << "Array is empty!\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        printNote(arr[i]);
    }
}

// --- Sort ---
void sortByPhone(Note* arr, int size) {
    if (arr == nullptr || size == 0) {
        cout << "No data to sort!\n";
        return;
    }

    sort(arr, arr + size, [](const Note& a, const Note& b) {
        return a.phone < b.phone;
        });

    cout << "Sorted successfully.\n";
}

// --- Search ---
int findBySurname(Note* arr, int size, const string& surname) {
    if (arr == nullptr || size == 0) {
        return -1;
    }

    for (int i = 0; i < size; i++) {
        if (arr[i].surname == surname) {
            return i;
        }
    }
    return -1;
}

// --- Save to file ---
void saveToFile(Note* arr, int size) {
    if (arr == nullptr || size == 0) {
        cout << "No data to save!\n";
        return;
    }

    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    ofstream fout(filename);
    if (!fout) {
        cout << "File open error!\n";
        return;
    }

    fout << size << endl;
    for (int i = 0; i < size; i++) {
        fout << arr[i].surname << " "
            << arr[i].name << " "
            << arr[i].phone << " "
            << arr[i].birth[0] << " "
            << arr[i].birth[1] << " "
            << arr[i].birth[2] << endl;
    }

    cout << "Data saved.\n";
}

// --- Load from file ---
void loadFromFile(Note*& arr, int& size) {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    ifstream fin(filename);
    if (!fin) {
        cout << "File open error!\n";
        return;
    }

    delete[] arr;

    fin >> size;

    if (size <= 0) {
        cout << "Invalid file data!\n";
        arr = nullptr;
        size = 0;
        return;
    }

    arr = new Note[size];

    for (int i = 0; i < size; i++) {
        fin >> arr[i].surname
            >> arr[i].name
            >> arr[i].phone
            >> arr[i].birth[0]
            >> arr[i].birth[1]
            >> arr[i].birth[2];
    }

    cout << "Data loaded.\n";
}

// --- Menu ---
void menu() {
    cout << "\n===== MENU =====\n";
    cout << "1. Input data\n";
    cout << "2. Show data\n";
    cout << "3. Sort by phone\n";
    cout << "4. Search by surname\n";
    cout << "5. Save to file\n";
    cout << "6. Load from file\n";
    cout << "0. Exit\n";
    cout << "Choice: ";
}

// --- Main ---
int main() {
    Note* arr = nullptr;
    int size = 0;
    int choice;

    do {
        menu();
        choice = inputInt("", 0, 6);

        switch (choice) {
        case 1:
            inputArray(arr, size);
            break;

        case 2:
            printArray(arr, size);
            break;

        case 3:
            sortByPhone(arr, size);
            break;

        case 4: {
            if (arr == nullptr || size == 0) {
                cout << "No data!\n";
                break;
            }

            string surname;
            cout << "Enter surname: ";
            cin >> surname;

            int idx = findBySurname(arr, size, surname);
            if (idx != -1)
                printNote(arr[idx]);
            else
                cout << "Not found.\n";
            break;
        }

        case 5:
            saveToFile(arr, size);
            break;

        case 6:
            loadFromFile(arr, size);
            break;

        case 0:
            cout << "Exit...\n";
            break;
        }

    } while (choice != 0);

    delete[] arr;
    return 0;
}