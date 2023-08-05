// Program for binary search.

#include <iostream>
using namespace std;

class binary_searh
{
    int len, i, arr[50], num, j, temp, first, last, middle;

public:
    binary_searh()
    {
        cout << "Enter the Size: ";
        cin >> len;
        cout << "Enter " << len << " Elements: ";
        for (i = 0; i < len; i++)
            cin >> arr[i];
    }

    void sort()
    {
        for (i = 0; i < (len - 1); i++)
        {
            for (j = 0; j < (len - i - 1); j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        cout << "\nThe New Sorted Array is:\n";
        for (i = 0; i < len; i++)
            cout << arr[i] << " ";
    }

    void B_search()
    {
        cout << "\n\nEnter Element to be Search: ";
        cin >> num;
        first = 0;
        last = (len - 1);
        middle = (first + last) / 2;
        while (first <= last)
        {
            if (arr[middle] < num)
                first = middle + 1;
            else if (arr[middle] == num)
            {
                cout << "\nThe number : " << num << " found at Position : " << middle + 1;
                break;
            }
            else
                last = middle - 1;
            middle = (first + last) / 2;
        }
        if (first > last)
            cout << "\nThe number : " << num << " is not found in given Array";
        cout << endl;
    }
};

int main()
{
    binary_searh bs;
    bs.sort();
    bs.B_search();

    return 0;
}