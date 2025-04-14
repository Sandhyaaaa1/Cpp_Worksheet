#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Student

{

private:

    string roll;
    string name;
    int marks;

public:


    Student(string r = "", string n = "", int m = 0) : roll(r), name(n), marks(m) {}


    int getMarks() const

    {

        return marks;

    }

    void setMarks(int m)

    {

        if (m >= 0 && m <= 100)

            {

                marks = m;
            }

        else

            {
                cout << "Error: Marks should be between 0 and 100." << endl;
                marks = -1;
            }
    }

    void setDetails()

    {
        cout << "Enter student roll: ";
        cin >> roll;

        cin.ignore();

        cout << "Enter student name: ";
        getline(cin, name);

        cout << "Enter student marks (0-100): ";

        int m;
        while (true)

            {
                cin >> m;
            if (m >= 0 && m <= 100)

                {
                    setMarks(m);

                    break;

                }

            else

                {

                cout << "Error: Marks should be between 0 and 100. Please enter again: ";

                }
        }
    }

    void displayDetails() const

    {

        cout << "Roll: " << roll << ", Name: " << name << ", Marks: " << marks << endl;

    }

    void saveToFile() const

    {

        ofstream outFile("student_records.txt", ios::app);

        if (outFile.is_open())

            {

                outFile << roll << " " << name << " " << marks << endl;
                outFile.close();

        }

        else

            {

                cout << "Error opening file!" << endl;

            }
    }

    static void readFromFile()

    {
        ifstream inFile("student_records.txt");
        string roll, name;
        int marks;

        if (inFile.is_open())

            {
                while (inFile >> roll >> name >> marks)
                {

                    cout << "Roll: " << roll << ", Name: " << name << ", Marks: " << marks << endl;
                }

                inFile.close();
            }
         else

            {

                cout << "Unable to open file!" << endl;
            }
    }
};

int main()

{
    int choice;

    while (true)

        {

        cout << "\n--- Student Record System ---\n";
        cout << "1. View Student Records\n";
        cout << "2. Add New Student Record\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)

            {

                Student::readFromFile();

            }

        else if (choice == 2)

            {

            Student student;

            student.setDetails();

            if (student.getMarks() >= 0 && student.getMarks() <= 100)

                {

                student.saveToFile();

                cout << "Record added successfully!" << endl;

            }

            else

                {

                cout << "Failed to add record due to invalid marks." << endl;

                }

        }
         else if (choice == 3)

            {

            cout << "Exiting the program!" << endl;
            break;
        }

        else

            {

            cout << "Invalid choice! Please enter 1, 2, or 3." << endl;

            }
    }

    return 0;
}

