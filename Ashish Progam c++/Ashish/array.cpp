#include <iostream>
using namespace std;

int main()
{
    int size, arr[50];

    cout << "Enter the size of array : " << endl;
    cin >> size;

    cout << "Enter the array element : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "\nThe numbers are: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }

    return 0;
}
