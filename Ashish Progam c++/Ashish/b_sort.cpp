// BUBBLE SORT
#include<iostream>
using namespace std;

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void bsort(int a[], int n)
{
    int temp;
    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n - 1 - i; j++)
        {
            if (a[j] < a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    int size;
    cout << "Enter the size of array : ";
    cin >> size;
    int arr[size];

    cout << "Enter the elements of array : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Before sorting : " << endl;
    display(arr, size);
    //sorting fuction
    bsort(arr, size);

    cout << "After sorting : " << endl;
    display(arr, size);

    return 0;
}