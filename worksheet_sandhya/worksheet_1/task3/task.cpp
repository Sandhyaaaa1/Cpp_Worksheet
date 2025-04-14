#include <iostream>

using namespace std;

class Cinema

{

private:

    char seats[5][5];

public:

    Cinema()

    {

        for (int i = 0; i < 5; ++i)

            for (int j = 0; j < 5; ++j)

                seats[i][j] = 'O';
    }

    void displaySeating()

    {

        cout << "\n Seating Arrangement:\n";

        for (int i = 0; i < 5; ++i)

            {

            for (int j = 0; j < 5; ++j)

            {

                cout << seats[i][j] << " ";

            }

            cout << endl;

        }
    }

    void bookSeat()

    {

        int row, col;

        while (true)

            {

            displaySeating();

            cout << "\n Enter seat row and column (1-5) or 0 to exit: ";

            cin >> row;

            if (row == 0)

                {

                    cout << "Booking ended.\n";

                    break;

                }

            cin >> col;


            row--;
            col--;

            if (row >= 0 && row < 5 && col >= 0 && col < 5)

                {

                if (seats[row][col] == 'O')

                    {

                        seats[row][col] = 'X';


                        cout << "Seat successfully booked!\n";

                    }

                 else

                    {

                    cout << "Seat already booked. Try another one.\n";

                }

            }

                else

                    {

                        cout << "Invalid input. Please choose between 1 and 5.\n";

            }
        }
    }
};

int main()

{
    Cinema c1;

    c1.bookSeat();

    return 0;
}
