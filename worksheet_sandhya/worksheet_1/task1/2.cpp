#include <iostream>

#include <cstdlib>

#include <ctime>

using namespace std;

class NumberGenerator
{

public:

    static int generateRandomNumber(int maxRange)

    {
        srand(time(0));

        return rand() % maxRange + 1;
    }
};

class UserInput

{

public:

    static int getDifficultyLevel()


    {
        int choice;

        cout << "Selecttype of difficulty level:\n1.";
        cout<<"Easy (1-8)\n2.";
        cout<<" Medium (1-30)\n3. Hard (1-50)\nEnter choice: ";

        cin >> choice;

        return choice;
    }

    static int getGuess(int maxRange)



    {
        int guess;

        while (true)

            {

            cout << "Guess a number between 1 and " << maxRange << ": ";


            cin >> guess;

            if (cin.fail() || guess < 1 || guess > maxRange)


                {
                    cin.clear();

                    cin.ignore(10000, '\n');

                    cout << "Try again.Your input is Invalid. " << endl;

                }

             else
                {

                return guess;
            }
        }
    }
};

class NumberGuessingGame

{

private:

    int maxRange;

    int randomNumber;

public:

    NumberGuessingGame(int range) : maxRange(range), randomNumber(NumberGenerator::generateRandomNumber(range)) {}

    void play()

    {
        while (true)

            {

            int guess = UserInput::getGuess(maxRange);

            if (guess == randomNumber)

            {
                cout << "Congratulations!!! You guessed the correct number." << endl;

                break;
            }

        else if (guess < randomNumber)


            {
                cout << "Try again.It's Too low! " << endl;
            }

        else

            {
                cout << " Try again.It's Too high!" << endl;
            }
        }
    }
};

int main()

{
    int choice = UserInput::getDifficultyLevel();

    int range;

    switch (choice)

    {
        case 1: range = 8;
        break;

        case 2: range = 30;
        break;

        case 3: range = 50;
        break;

        default:

            cout << "Your choice of number Invalid . Defaulting to Easy (1-8)." << endl;
            range = 8;
    }

    NumberGuessingGame game(range);

    game.play();

    return 0;
}

