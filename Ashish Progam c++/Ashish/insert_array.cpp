// Program to insert new elements in an already filled array.

#include <iostream>
using namespace std;

class array
{
public:
    int arr[50], i, element, position, n;

    void Array()
    {
        cout << "Enter the Size for Array: " << endl;
        cin >> n;
        cout << "Enter " << n << " Array Elements: " << endl;
        for (i = 0; i < n; i++)
            cin >> arr[i];
    }

    void insert()
    {
        cout << "\nEnter Element to Insert: " << endl;
        cin >> element;
        cout << "At What Position ? : " << endl;
        cin >> position;
        for (i = n; i >= position; i--)
            arr[i] = arr[i - 1];
        arr[i] = element;
        n++;
    }

    void display()
    {
        cout << "\nThe New Array is:\n";
        for (i = 0; i < n; i++)
            cout << arr[i] << "  ";
        cout << endl;
    }
};

int main()
{
    array arr;
    arr.Array();
    arr.insert();
    arr.display();
    return 0;
}