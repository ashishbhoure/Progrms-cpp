// Program to merge two unsorted array than to create a new sorted array.

#include <iostream>
using namespace std;

void sort(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void merge(int a[], int b[], int size1, int size2)
{
    int newarr[size1 + size2];
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2)
    {
        if (a[i] < b[j])
        {
            newarr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            newarr[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < size1)
    {
        newarr[k] = a[i];
        i++;
        k++;
    }
    while (j < size2)
    {
        newarr[k] = b[j];
        j++;
        k++;
    }
    for (int i = 0; i < (size1 + size2); i++)
    {
        cout << newarr[i] << " ";
    }
}

int main()
{
    int a[100];
    int b[100], size1, size2;
    cout << "enter the size of first array " << endl;
    cin >> size1;
    cout << "enter the elements of first array" << endl;
    for (int i = 0; i < size1; i++)
    {
        cin >> a[i];
    }

    cout << "enter the size of second array " << endl;
    cin >> size2;
    cout << "enter the elements of second array" << endl;
    for (int i = 0; i < size2; i++)
    {
        cin >> b[i];
    }

    sort(a, size1);
    sort(b, size2);
    merge(a, b, size1, size2);
    
    return 0;

}