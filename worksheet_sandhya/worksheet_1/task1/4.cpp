#include <iostream>


using namespace std;

class DayWeek

{

public:


    void getDayWeek(int day)


{
        switch (day)


        {

            case 1:

                cout << "Sunday" << endl;

                break;

            case 2:

                cout << "Monday" << endl;

                break;

            case 3:

                cout << "Tuesday" << endl;
                break;

            case 4:

                cout << "Wednesday" << endl;
                break;

            case 5:

                cout << "Thursday" << endl;
                break;

            case 6:

                cout << "Friday" << endl;
                break;


            case 7:

                cout << "Saturday" << endl;
                break;

            default:

                cout << "Your Input is Invalid. Please enter numbers between 1 and 7." << endl;

                break;

        }
    }
};

void getUserInput()

{
    int day;

    cout << "Enter a num for a day of the week: ";

    cin >> day;

    DayWeek W1;

    W1.getDayWeek(day);

}

int main()

{
    getUserInput();

    return 0;

}
