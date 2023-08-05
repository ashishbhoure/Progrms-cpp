// Program for linear search

#include <iostream>
using namespace std;

class linear_seacrh
{
public:
    int arr[10], i, n, num, index;

    linear_seacrh()
    {
        cout << "Enter the size of array : ";
        cin >> n;
        cout << "Enter the Numbers: ";
        for (i = 0; i < n; i++)
            cin >> arr[i];
    }

    void search()
    {
        cout << "\nEnter a Number to Search: " << endl;
        cin >> num;
        for (i = 0; i < n; i++)
        {
            if (arr[i] == num)
            {
                cout << "\nFound at Index No. : " << i << endl;
                return;
            }
        }
        cout << "Entered Element is not found : " << endl;
        cout << endl;
    }
};

int main()
{
    linear_seacrh ls;
    ls.search();

    return 0;
}