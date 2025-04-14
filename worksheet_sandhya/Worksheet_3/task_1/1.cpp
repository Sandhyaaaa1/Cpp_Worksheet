#include <iostream>

using namespace std;

class Time

{
private:
    int hours;
    int minutes;

public:

    Time(int h = 0, int m = 0)

    {
        hours = h;
        minutes = m;
        validate();
    }


    void inputTime()

    {
        cout << "Enter the time in hours (0 - 24): ";
        cin >> hours;

        cout << "Enter the time in  minutes (0 - 60): ";
        cin >> minutes;
        validate();
    }


    void displayTime()

    {

        cout << hours << " hours and " << minutes << " minutes" << endl;

    }


    void validate()

    {
        if (hours < 0 || hours > 24 || minutes < 0 || minutes >= 60)

            {

                cout << "Error: Invalid time! Hours must be <= 24 and Minutes must be <= 60." << endl;

                exit(1);
        }
    }


    Time operator+(Time t)

    {
        Time temp;
        temp.minutes = minutes + t.minutes;
        temp.hours = hours + t.hours;

        if (temp.minutes >= 60)

            {

                temp.minutes -= 60;
                temp.hours++;
            }

        return temp;
    }

    bool operator>(Time t)

    {
        if (hours > t.hours)

            {
                return true;
            }
        else if (hours == t.hours && minutes > t.minutes)

            {
                return true;

            }

        else

            {

                return false;
            }
    }
};

int main()

{
    Time t1, t2, sum;

    cout << "Enter first time:" << endl;
    t1.inputTime();

    cout << "Enter second time:" << endl;
    t2.inputTime();

    cout << "\nFirst Time: ";
    t1.displayTime();

    cout << "Second Time: ";
    t2.displayTime();

    sum = t1 + t2;
    cout << "\nSum of times: ";

    sum.displayTime();

    if (t1 > t2)

        {

        cout << "First time is greater than second time." << endl;
        }

    else

        {

            cout << "Second time is greater than or equal to first time." << endl;
        }

    return 0;
}
