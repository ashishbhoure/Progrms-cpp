// Program to illustrate use of objects and class

#include <iostream>
using namespace std;

class Room
{
public:
    double length;
    double breadth;
    double height;

    double Area()
    {
        return length * breadth;
    }

    double Volume()
    {
        return length * breadth * height;
    }
};

int main()
{

    Room r1;

    r1.length = 42.5;
    r1.breadth = 30.8;
    r1.height = 19.2;

    cout << "Area of Room =  " << r1.Area() << endl;
    cout << "Volume of Room =  " << r1.Volume() << endl;

    return 0;
}