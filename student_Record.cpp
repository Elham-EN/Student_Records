#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string student_id {""}, student_name {""}, student_grade {""}, student_course {""}, student_unit {""};
    string stuff_id {""}, stuff_name {""}, staff_course {""}, staff_unit {""}, staff_timetable {""};
    string line {""};
    int choice {0}, flag {0};

    while (flag == 0) {
        cout << "\n1. Enter Student Details" << endl;
        cout << "2. Enter Staff Details" << endl;
        cout << "3. Display Student Details" << endl;
        cout << "4. Display Staff Details" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            ofstream student_file_write; //creates and writes to files
            //ios_base -> represent stream opening mode flags
            //app -> (append) Set the stream's position indicator to the end 
            //of the stream before each output operation.
            student_file_write.open("student.txt", ios_base::app);
            cout << "Enter the Student's ID: ";
            cin >> student_id;
            cin.sync();
            cout << "Enter the Student's name: ";
            getline(cin, student_name);
            cout << "Enter the Student's course: ";
            getline(cin, student_course);
            cout << "Enter the Student's unit: ";
            getline(cin, student_unit);
            cout << "Enter the Student's grade: ";
            cin >> student_grade;

            if (!student_file_write.is_open()) {
                cout << "File was not created!" << endl;
            } else {
                //Insert into the file 
                student_file_write << student_id << endl;
                student_file_write << student_name << endl;
                student_file_write << student_course << endl;
                student_file_write << student_unit << endl;
                student_file_write << student_grade << endl;
                student_file_write.close(); //close the file stream
            }
        }
        if (choice == 3) {
            fstream student_file_read;
            //Open for input operations.
            student_file_read.open("student.txt", ios::in);
            if (!student_file_read) {
                cout << "No such file exist" << endl;
            } else {
                //extract each line into line variable
                while (getline(student_file_read, line)) {
                    cout << line << endl;
                }
            }
            student_file_read.close();
        }
        if (choice == 5) {
            flag = 1;
        }
    }
    
}