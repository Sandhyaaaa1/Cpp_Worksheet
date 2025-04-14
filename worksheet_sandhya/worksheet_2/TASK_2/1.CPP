#include <iostream>
#include <cmath>
using namespace std;


class Circle;

void compareTwoCircles(Circle &c1, Circle &c2);

class Circle

{
private:
    float radius;

public:

    Circle(float r)
    {
        radius = r;
    }


    float area()

    {
        return M_PI * radius * radius;
    }


    friend void compareTwoCircles(Circle &c1, Circle &c2);

};


void compareTwoCircles(Circle &c1, Circle &c2)

{
    float area1 = c1.area();

    float area2 = c2.area();

    cout << "Area of Circle 1: " << area1 << endl;

    cout << "Area of Circle 2: " << area2 << endl;



    if (area1 > area2)

        {

        cout << "Circle 1 has the larger area." << endl;
        }
    else if (area1 < area2)
        {
        cout << "Circle 2 has the larger area." << endl;
        }
    else
        {
        cout << "Both circles have the same area." << endl;
        }
}

int main()
{
    float radius1, radius2;

    cout << "Enter radius of Circle 1: ";

    cin >> radius1;

    cout << "Enter radius of Circle 2: ";

    cin >> radius2;

    Circle circle1(radius1);

    Circle circle2(radius2);

    compareTwoCircles(circle1, circle2);

    return 0;
}
