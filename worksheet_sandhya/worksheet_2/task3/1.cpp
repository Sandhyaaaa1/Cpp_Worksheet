#include <iostream>

#include <fstream>

#include <string>

#include <vector>

#include <limits>

#include <stdexcept>

using namespace std;

const int MAX_BOOKS = 10;

const int MAX_TITLE_LENGTH = 150;



void writeBookTitles(const string& filename, char books[][MAX_TITLE_LENGTH])

{

    ofstream outFile(filename, ios::binary);

    if (!outFile)

        {

            cout << "Error opening file for writing.\n";

            return;
        }

    for (int i = 0; i < MAX_BOOKS; ++i)

        {

            outFile.write(books[i], MAX_TITLE_LENGTH);
        }

        outFile.close();
}

bool searchBookTitle(const string& filename, const string& title)

    {


        ifstream inFile(filename, ios::binary);

        if (!inFile)

            {
                cout << "Error opening file for reading.\n";

                return false;
            }

        char buffer[MAX_TITLE_LENGTH];

        while (inFile.read(buffer, MAX_TITLE_LENGTH))

            {

            if (title == buffer)

                {

                    return true;
        }
    }


    inFile.close();

    return false;
}


struct Student
{

    int roll;

    string name;

    float marks;

};


void readStudentsFromFile(const string& filename, vector<Student>& students)

{

    ifstream inFile(filename);

    if (!inFile) {

        cout << "Student file not found. A new one will be created.\n";

        return;
    }

    Student s;

    while (inFile >> s.roll >> ws && getline(inFile, s.name, ',') && inFile >> s.marks) {

        if (s.marks < 0 || s.marks > 100)

            throw out_of_range("Invalid marks found in file.");

        students.push_back(s);
    }

    inFile.close();
}

void addStudentRecord(vector<Student>& students) {

    Student s;

    cout << "\nEnter new student details:\n";

    cout << "Roll: ";

    cin >> s.roll;

    cin.ignore();

    cout << "Name: ";

    getline(cin, s.name);

    cout << "Marks: ";

    cin >> s.marks;


    if (s.marks < 0 || s.marks > 100)

        throw out_of_range("Marks must be between 0 and 100.");

    students.push_back(s);
}


void saveStudentsToFile(const string& filename, const vector<Student>& students)

{


    ofstream outFile(filename);

    if (!outFile)

        {

        cerr << "Failed to save students.\n";

        return;
    }

    for (const auto& s : students)

        {

        outFile << s.roll << " " << s.name << "," << s.marks << endl;
    }

    outFile.close();
}


int main()

{

    char books[MAX_BOOKS][MAX_TITLE_LENGTH];

    string bookFile;

    cout << "Enter binary filename to store book titles: ";

    getline(cin, bookFile);

    cout << "Enter 10 book titles:\n";

    for (int i = 0; i < MAX_BOOKS; ++i)

        {

        cout << "Book " << i + 1 << ": ";

        cin.getline(books[i], MAX_TITLE_LENGTH);
    }

    writeBookTitles(bookFile, books);


    string searchTitle;

    cout << "\nEnter book title to search: ";

    getline(cin, searchTitle);

    if (searchBookTitle(bookFile, searchTitle))


        cout << "The book \"" << searchTitle << "\" is in the file.\n";

    else

        cout << "The book \"" << searchTitle << "\" is not in the file.\n";


    vector<Student> students;

    string studentFile = "students.txt";

    try

     {

        readStudentsFromFile(studentFile, students);

    }

     catch (const exception& e)

     {

        cerr << "Exception while reading students: " << e.what() << endl;

    }

    char choice;

    cout << "\nDo you want to add a new student record? (y/n): ";

    cin >> choice;

    if (choice == 'y' || choice == 'Y') {

        try

        {
            addStudentRecord(students);

            saveStudentsToFile(studentFile, students);

            cout << "Student record added and saved successfully.\n";

        }

         catch (const exception& e) {

            cerr << "Error adding student: " << e.what() << endl;
        }
    }

    return 0;
}
