// Program to merge two sorted arrays

#include <iostream>
using namespace std;

class array
{
    int i, j, k;

public:
    void display(int ar[], int);
    void merge(int ar1[], int ar2[], int, int);
};

void array ::display(int ar[], int n)
{
    for (i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}

void array ::merge(int a1[], int a2[], int n1, int n2)
{
    int a[n1 + n2];
    i = j = k = 0;
    while (i < n1 && j < n2)
    {
        if (a1[i] < a2[j])
        {
            a[k] = a1[i];
            i++;
            k++;
        }
        else
        {
            a[k] = a2[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        a[k] = a1[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        a[k] = a2[j];
        k++;
        j++;
    }
    cout << "\nAfter merging the two sorted arrays, we get :" << endl;
    for (i = 0; i < n1 + n2; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    array arr;
    int s1, s2;

    cout << "\nEnter the size of first sorted array : ";
    cin >> s1;
    int arr1[s1];
    cout << "\nEnter the elements of first array in sorted order :  ";
    for (int i = 0; i < s1; i++)
    {
        cin >> arr1[i];
    }

    cout << "\nEnter the size of second sorted array : ";
    cin >> s2;
    int arr2[s2];
    cout << "\nEnter the elements of second array in sorted order : ";
    for (int i = 0; i < s2; i++)
    {
        cin >> arr2[i];
    }
    cout << "\nThe elements of first sorted array are : " << endl;
    arr.display(arr1, s1);
    cout << "\nThe elements of second sorted array are : " << endl;
    arr.display(arr2, s2);
    cout << "" << endl;
    //Calling the merging function
    arr.merge(arr1, arr2, s1, s2);
    return 0;
}