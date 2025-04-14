#include <iostream>
using namespace std;

class Maximum

{

public:


    int findMax(int a, int b)

    {

        return (a > b) ? a : b;

    }

    float findMax(float a, float b)

    {

        return (a > b) ? a : b;

    }


    int findMax(int a, int b, int c)

    {

        return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);

    }


    float findMax(int a, float b)

    {

        return (a > b) ? a : b;

    }
};

int main()

{
    Maximum maximum;

    int int1, int2, int3;

    float float1, float2;


    cout << "Enter two integers: ";

    cin >> int1 >> int2;


    cout << "Enter two floating-point numbers: ";

    cin >> float1 >> float2;


    cout << "Enter three integers: ";

    cin >> int1 >> int2 >> int3;

    cout << "Maximum between two integers: " << maximum.findMax(int1, int2) << endl;

    cout << "Maximum between two floating-point numbers: " << maximum.findMax(float1, float2) << endl;

    cout << "Maximum among three integers: " << maximum.findMax(int1, int2, int3) << endl;

    cout << "Maximum between an integer and a float: " << maximum.findMax(int1, float1) << endl;

    return 0;
}

