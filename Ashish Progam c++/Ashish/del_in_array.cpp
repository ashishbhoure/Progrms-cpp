// Program to delete any element from an array

#include <iostream>
using namespace std;

class del_element
{
public:
    int arr[100], tot, i, elem, j, found = 0;

    del_element()
    {
        cout << "Enter the Size: "<<endl;
        cin >> tot;
        cout << "Enter " << tot << " Array Elements: "<<endl;
        for (i = 0; i < tot; i++)
            cin >> arr[i];
    }

    void dalete()
    {
        cout << "\nEnter Element to Delete: \n";
        cin >> elem;
        for (i = 0; i < tot; i++)
        {
            if (arr[i] == elem)
            {
                for (j = i; j < (tot - 1); j++)
                    arr[j] = arr[j + 1];
                found = 1;
                i--;
                tot--;
            }
        }
    }

    void dispaly()
    {
        if (found == 0)
            cout << "\nElement doesn't found in the Array!";
        else
        {
            cout << "\nElement Deleted Successfully!";
            cout << "\n\nThe New Array is:\n";
            for (i = 0; i < tot; i++)
                cout << arr[i] << "  ";
        }
        cout << endl;
    }
};
int main()
{
    del_element D;
    D.dalete();
    D.dispaly();

    return 0;
}