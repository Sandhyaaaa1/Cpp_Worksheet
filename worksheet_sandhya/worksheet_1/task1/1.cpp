#include <iostream>

#include <limits>

using namespace std;

class ConvertTemperature

{

public:

    static double toFahrenheit(double temp)

    {

        return (temp * 9.0 / 5.0) + 32;

    }

    static double toCelsius(double temp)

    {

        return (temp - 32) * 5.0 / 9.0;

    }
};

int main()

{
    double temp;

    char choice;

    cout << "Enter temperature: ";

    while (!(cin >> temp))

        {

            cin.clear();

            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

            cout << "Your input is Invalid. Enter a numeric value: ";


        }

    cout << "Convert to  Enter C (For celcius) or F (For Fahreneight): ";

    cin >> choice;

    choice = toupper(choice);


    if (choice == 'C')


        cout << "Converted temperature: " << ConvertTemperature::toCelsius(temp) << "°C" << endl;

    else if (choice == 'F')

        cout << "Converted temperature: " << ConvertTemperature::toFahrenheit(temp) << "°F" << endl;

    else

        cout << "Your choice is Invalid." << endl;

    return 0;
}
