//Program to illustrate Matrix addition.

#include <iostream>
using namespace std;
class _2darray
{
private:
    int r, c, a[100][100], b[100][100], sum[100][100], i, j;

public:
    void matrix()
    {
        cout << "Enter number of rows : ";
        cin >> r;

        cout << "Enter number of columns : ";
        cin >> c;

        cout << endl
             << "Enter elements of 1st matrix: " << endl;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
            {
                cout << "Enter element a" << i + 1 << j + 1 << " : ";
                cin >> a[i][j];
            }

        cout << endl
             << "Enter elements of 2nd matrix: " << endl;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
            {
                cout << "Enter element b" << i + 1 << j + 1 << " : ";
                cin >> b[i][j];
            }
    }

    void addmatrix()
    {
        for (i = 0; i < r; ++i)
        {
            for (j = 0; j < c; ++j)
            {
                sum[i][j] = a[i][j] + b[i][j];
            }
        }
    }

    void display()
    {
        cout << endl
             << "Sum of two matrix is: " << endl;
        for (i = 0; i < r; ++i)
        {
            for (j = 0; j < c; ++j)
            {
                cout << sum[i][j] << "  ";
                if (j == c - 1)
                    cout << endl;
            }
        }
    }
};

int main()
{
    _2darray arr;

    arr.matrix();
    arr.addmatrix();
    arr.display();

    return 0;
}