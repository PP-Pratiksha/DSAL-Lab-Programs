#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int MAX_RECORDS = 100;

class Student {
    int rollNumber;
    char name[50];
    char address[100];

public:
    void readData() {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore(); // Ignore the newline character left by cin
        cout << "Enter Name: ";
        cin.getline(name, 50);

        cout << "Enter Address: ";
        cin.getline(address, 100);
    }

    void displayData() {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "---------------------" << endl;
    }

    int getRollNumber() const {
        return rollNumber;
    }
};
class StudentManagement {
    ofstream file;
    ifstream inputFile;
public:
    void addStudent() {
        file.open("students.txt", ios::binary | ios::app);

        Student s1;
        s1.readData();
        file.write(reinterpret_cast<char*>(&s1), sizeof(Student));
        file.close();
        cout << "Student added successfully!" << endl;
    }

    void deleteStudent() {
        int rollNumber;
        cout << "Enter Roll Number of the student to delete: ";
        cin >> rollNumber;

        inputFile.open("students.txt", ios::binary);
        if (!inputFile) {
            cout << "File not found!" << endl;
            return;
        }

        ofstream tempFile;
        tempFile.open("temp.txt", ios::binary);

        Student s1;
        while (inputFile.read(reinterpret_cast<char*>(&s1), sizeof(Student))) {
            if (s1.getRollNumber() != rollNumber) {
                tempFile.write(reinterpret_cast<char*>(&s1), sizeof(Student));
            }
        }

        inputFile.close();
        tempFile.close();

        remove("students.txt");
        rename("temp.txt", "students.txt");

        cout << "Student deleted successfully!" << endl;
    }

    void displayStudents() {
        inputFile.open("students.txt", ios::binary);
        if (!inputFile) {
            cout << "File not found!" << endl;
            return;
        }

        Student s1;
        while (inputFile.read(reinterpret_cast<char*>(&s1), sizeof(Student))) {
            s1.displayData();
        }

        inputFile.close();
    }
};
int main() {
	StudentManagement s;
        int choice;

        do {
            cout << "Menu" << endl;
            cout << "1. Add Student" << endl;
            cout << "2. Delete Student" << endl;
            cout << "3. Display Students" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    s.addStudent();
                    break;
                case 2:
                    s.deleteStudent();
                    break;
                case 3:
                    s.displayStudents();
                    break;
                case 4:
                    exit(0);
                default:
                    cout << "Invalid choice!" << endl;
            }
        }while(choice!=5);
        return 0;
    }
