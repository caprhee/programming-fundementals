#include <iostream>
#include <string>
using namespace std;

// Structure for Subject
struct Subject {
    string subjectName;
    int credit;
    float mark;
    char grade;
};

// Structure for Student
struct Student {
    string name;
    int age;
    Subject subjects[5];
    int subjectCount;
    float cpa;
};

// Function to calculate grade based on mark
char calculateGrade(float mark) {
    if (mark >= 85) return 'A';
    else if (mark >= 70) return 'B';
    else if (mark >= 55) return 'C';
    else if (mark >= 40) return 'D';
    else return 'F';
}

// Function to calculate CPA (simple average based on marks)
float calculateCPA(Student s) {
    float total = 0;
    for (int i = 0; i < s.subjectCount; i++) {
        total += s.subjects[i].mark;
    }
    return total / s.subjectCount / 25; // Convert to a 4.0 scale roughly
}

// Function to input student information
void insertStudent(Student &s) {
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, s.name);

    cout << "Enter age: ";
    cin >> s.age;

    cout << "Enter number of subjects (max 5): ";
    cin >> s.subjectCount;

    if (s.subjectCount > 5) {
        cout << "Too many subjects! Limiting to 5.\n";
        s.subjectCount = 5;
    }

    for (int i = 0; i < s.subjectCount; i++) {
        cout << "\n--- Subject " << i + 1 << " ---\n";
        cout << "Enter subject name: ";
        cin.ignore();
        getline(cin, s.subjects[i].subjectName);

        cout << "Enter credit hour: ";
        cin >> s.subjects[i].credit;

        do {
            cout << "Enter mark (0 - 100): ";
            cin >> s.subjects[i].mark;
            if (s.subjects[i].mark < 0 || s.subjects[i].mark > 100)
                cout << "Invalid mark! Please enter between 0 and 100.\n";
        } while (s.subjects[i].mark < 0 || s.subjects[i].mark > 100);

        s.subjects[i].grade = calculateGrade(s.subjects[i].mark);
    }

    s.cpa = calculateCPA(s);
}

// Function to display all students
void displayStudents(Student students[], int count) {
    cout << "\n======= STUDENT LIST =======\n";
    for (int i = 0; i < count; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "CPA: " << students[i].cpa << endl;
        cout << "Subjects:\n";
        for (int j = 0; j < students[i].subjectCount; j++) {
            cout << "  " << students[i].subjects[j].subjectName
                 << " | Credit: " << students[i].subjects[j].credit
                 << " | Mark: " << students[i].subjects[j].mark
                 << " | Grade: " << students[i].subjects[j].grade << endl;
        }
    }
    cout << "=============================\n";
}

// Main function
int main() {
    Student students[10];
    int studentCount = 0;
    int choice;

    do {
        cout << "\n===== Lecturer's Student Record System =====\n";
        cout << "1. Add new student\n";
        cout << "2. Display all students\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (studentCount < 10) {
                insertStudent(students[studentCount]);
                studentCount++;
            } else {
                cout << "Cannot add more students! Limit reached.\n";
            }
            break;
        case 2:
            displayStudents(students, studentCount);
            break;
        case 3:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}

