#include <iostream>

#include <fstream>

#include <string>

#include <vector>

#include <stdexcept>

using namespace std;

class Student

{

private:

    int roll;

    string name;

    int marks;

public:


    Student(int r, const string& n, int m) : roll(r), name(n), marks(m) {}

    int getRoll() const

    {

        return roll;

    }

    string getName() const

    {

        return name;

    }

    int getMarks() const

    {

        return marks;

    }

    static void validateMarks(int marks)

    {

        if (marks < 0 || marks > 100)

            {
                throw out_of_range("Marks must be between 0 and 100.");
            }
    }

    void display() const

        {
            cout << "Roll Number: " << roll << ", Name: " << name << ", Marks: " << marks << endl;
        }
};

class StudentManager

    {
private:

    vector<Student> students;

    string filename;

public:


    StudentManager(const string& file) : filename(file)

            {
                readStudentRecords();
            }

        void readStudentRecords()

            {

                ifstream file(filename);

        if (!file)

            {

                cerr << "Error opening file for reading." << endl;
                return;
            }


        int roll, marks;


        string name;

        while (file >> roll)

            {
                file.ignore();

                getline(file, name);

                file>> marks;

                file.ignore();

                students.push_back(Student(roll, name, marks));
            }

                file.close();
    }


    void addStudentRecord()

    {
        int roll, marks;

        string name;

        cout << "Enter student roll number: ";

        cin >> roll;

        cin.ignore();

        cout << "Enter student name: ";

        getline(cin, name);

        cout << "Enter student marks: ";

        cin >> marks;

        try

        {
            Student::validateMarks(marks);

            students.push_back(Student(roll, name, marks));

            cout << "New student record added successfully!" << endl;
        }

        catch (const out_of_range& e)


        {

            cout << "Error: " << e.what() << endl;

        }

    }

    void displayStudentRecords() const

    {

        if (students.empty())

                {

                    cout << "No records available." << endl;
                    return;
                }

                    cout << "\nStudent Records:\n";

            for (const auto& student : students)

                {

                    student.display();

                }
    }

    void saveStudentRecords() const

        {
            ofstream file(filename);

            if (!file)

            {

                cerr << "Error opening file for writing." << endl;

                return;
        }

        for (const auto& student : students)

            {

                file << student.getRoll() << endl;

                file << student.getName() << endl;

                file << student.getMarks() << endl;
            }

                file.close();
    }
};

int main()

    {

        string filename = "students.txt";

        StudentManager manager(filename);

    int choice;
    bool running = true;

    while (running)

        {

        cout << "\nMenu:\n";

        cout << "1. Show student records\n";

        cout << "2. Add new student record\n";

        cout << "3. Exit\n";

        cout << "Enter your choice (1-3): ";

        cin >> choice;

        switch (choice)

        {
            case 1:

                manager.displayStudentRecords();

                break;

            case 2:

                manager.addStudentRecord();

                break;

            case 3:


                manager.saveStudentRecords();

                cout << "Exiting program...\n";

                running = false;

                break;

            default:

                cout << "Invalid choice, please try again.\n";

                break;
        }
    }

    return 0;
}
