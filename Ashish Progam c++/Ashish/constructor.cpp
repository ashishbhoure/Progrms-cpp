//program to demonstrate the use of default constructor

#include <iostream>
using namespace std;

class Constructor
{
private:
  float length;
  float height;

public:
  //Default Constuctor
  Constructor()
  {
    length = 5.5;
    cout << "Creating a wall." << endl;
    cout << "Length = " << length << endl;
  }

  //Parameterized Constructor
  Constructor(float len, float hgt)
  {
    length = len;
    height = hgt;
  }

  float Area()
  {
    return length * height;
  }

  //Copy Constructor
  Constructor(Constructor &obj)
  {
    length = obj.length;
    height = obj.height;
  }

  float calculateArea()
  {
    return length * height;
  }
};

int main()
{
  cout << "\nDefault Consturctor Called " << endl;
  Constructor wall;

  Constructor wall1(10.5, 8.6);
  Constructor wall2(8.5, 6.3);

  cout << "\nParameterized Constructor Called " << endl;
  cout << "Area of Wall 1: " << wall1.Area() << endl;
  cout << "Area of Wall 2: " << wall2.Area() << endl;

  Constructor wall_a(10.5, 8.6);
  Constructor wall_b = wall_a;

  cout << "\nCopy Constructor Called " << endl;
  cout << "Area of wall 1: " << wall_a.calculateArea() << endl;
  cout << "Area of wall 2: " << wall_b.calculateArea() << endl;

  return 0;
}
