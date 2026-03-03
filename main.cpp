/*
Digital Attendance System
Name: ALI IDDRISU
Course Code: EEE227
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    string index;
    string name;

    Student(string i = "", string n = "") {
        index = i;
        name = n;
    }

    void display() {
        cout << index << " - " << name << endl;
    }
};

vector<Student> students;

void loadStudents() {
    ifstream file("students.txt");

    string idx, name;

    while (file >> idx) {
        file.ignore();
        getline(file, name);
        students.push_back(Student(idx, name));
    }

    file.close();
}

void saveStudents() {
    ofstream file("students.txt");

    for (int i = 0; i < students.size(); i++) {
        file << students[i].index << " "
             << students[i].name << endl;
    }

    file.close();
}

void registerStudent() {
    string idx, name;

    cout << "Index: ";
    cin >> idx;

    cin.ignore(); // clear newline

    cout << "Name: ";
    getline(cin, name);

    students.push_back(Student(idx, name));

    saveStudents();

    cout << "Student Registered!\n";
}

void viewStudents() {
    if (students.empty()) {
        cout << "No students.\n";
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        students[i].display();
    }
}

void createSession() {
    string course, date;

    cout << "Course Code: ";
    cin >> course;

    cout << "Date (YYYY-MM-DD): ";
    cin >> date;

    ofstream file("session_" + course + "_" + date + ".txt");

    int present = 0, late = 0, absent = 0;
    int status;

    for (int i = 0; i < students.size(); i++) {
        cout << "Mark " << students[i].index
             << " (1=Present 2=Late 3=Absent): ";

        cin >> status;

        if (status == 1) {
            file << students[i].index << " Present\n";
            present++;
        }
        else if (status == 2) {
            file << students[i].index << " Late\n";
            late++;
        }
        else {
            file << students[i].index << " Absent\n";
            absent++;
        }
    }

    file << "\nSummary:\n";
    file << "Present: " << present << endl;
    file << "Late: " << late << endl;
    file << "Absent: " << absent << endl;

    file.close();

    cout << "Session Saved!\n";
}

int main() {

    loadStudents();

    int choice;

    do {
        cout << "\n=== DIGITAL ATTENDANCE SYSTEM ===\n";
        cout << "1. Register Student\n";
        cout << "2. View Students\n";
        cout << "3. Create Attendance Session\n";
        cout << "4. Exit\n";
        cout << "Choice: ";

        cin >> choice;

        if (choice == 1)
            registerStudent();
        else if (choice == 2)
            viewStudents();
        else if (choice == 3)
            createSession();
        else if (choice == 4)
            cout << "Goodbye!\n";
        else
            cout << "Invalid choice.\n";

    } while (choice != 4);

    return 0;
}



      
    
