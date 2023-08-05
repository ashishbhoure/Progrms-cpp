// Program for selection sort

#include <iostream>

using namespace std;
class sort
{
    int i, j, n, temp, a[30];

public:
    void input()
    {
        cout << "Enter the number of elements:";
        cin >> n;
        cout << "\nEnter the elements\n";

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }
    void isort()
    {
        for (i = 1; i <= n - 1; i++)
        {
            temp = a[i];
            j = i - 1;
            while ((temp < a[j]) && (j >= 0))
            {
                a[j + 1] = a[j];
                j = j - 1;
            }
            a[j + 1] = temp;
        }
    }
    void display()
    {
        for (i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }
};
int main()
{
    sort s;
    int n;

    s.input();
    cout << "Entered list is :\n";
    s.display();

    s.isort();
    cout << "\n\nSorted list is \n";
    s.display();

    return 0;
}