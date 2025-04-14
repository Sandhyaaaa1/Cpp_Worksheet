#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

class NumberSorter

{

public:


    static void sortNumbers(vector<int>& numbers)

    {

        sort(numbers.begin(), numbers.end());

    }
};

class numberInput


{
public:

    static vector<int> getNumbers()

    {
        int a;

        cout << "Enter the no. of elements: ";

        cin >> a;

        vector<int> numbers(a);

        cout << "Enter a numbeer " << a << " integers: ";


        for (int i = 0; i < a ; i++)

            {

            cin >> numbers[i];


            }

        return numbers;

    }
};

class NumberSorting


{

public:


    static void run()

    {
        vector<int> numbers = numberInput::getNumbers();

        NumberSorter::sortNumbers(numbers);

        cout << "Sorted numbers  in ascending order: ";

        for (int num : numbers)

            {

                cout << num << " ";

            }
            cout << endl;
    }
};

int main()
{
    NumberSorting::run();


    return 0;
}
