#include <iostream>

#include <string>

using namespace std;

class Student

{

private:

    string name;

    int marks[3];

public:


        void input_Details()

    {

        cout << "Enter the name of students: ";

        cin >> name;

        for (int i = 0; i < 3; i++)

            {

                cout << "Enter marks of subject " << i + 1 << ": ";

                cin >> marks[i];


                while (marks[i] < 0 || marks[i] > 100)

            {

                cout << "Your input is Invalid! The marks must be between 0 and 100. Please re-enter: ";

                cin >> marks[i];

            }
        }
    }

    int calculate_Total()

        {

            return marks[0] + marks[1] + marks[2];

        }

    double calculate_Average()

        {

            return static_cast<double>(calculate_Total()) / 3;


        }

    char calculate_Grade()

        {
            double average = calculate_Average();

            if (average >= 90)

                {
                    return 'A';

                }

        else if (average >= 80)

            {
                return 'B';

            }

        else if (average >= 70)

            {

                return 'C';

            }

        else if (average >= 60)

            {

                return 'D';
            }


        else

            {

                return 'F';
        }
    }



    void display_Results()

    {

        cout << "\nStudent Name: " << name << endl;

        cout << "Total Marks: " << calculate_Total() << endl;

        cout << "Average Marks: " << calculate_Average() << "%" << endl;

        cout << "Grade: " << calculate_Grade() << endl;

    }
};

void Student_Grading()

{
    Student s1;

    s1.input_Details();

    s1.display_Results();

}

int main()

{
    Student_Grading();

    return 0;
}

