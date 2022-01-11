#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, degree;
    float x[20], y[20];
    cout << "Enter degree of polynomial: ";
    cin >> degree;
    n = -10000;
    float matrix[30][30];
    while (n < degree)
    {
        cout << "Enter the number of data: ";
        cin >> n;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Enter x and y values: ";
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < degree + 1; i++)
    {
        for (int j = 0; j < degree + 1; j++)
        {
            float sum = 0;
            for (int k = 0; k < n; k++)
            {
                sum = sum + pow(x[k], i + j);
            }
            matrix[i][j] = sum;
        }
    }

    for (int i = 0; i < degree + 1; i++)
    {
        float sum = 0;
        for (int k = 0; k < n; k++)
        {
            sum = sum + pow(x[k], i) * y[k];
        }
        matrix[i][degree + 1] = sum;
    }
    // printing out the augmented matrix

    for (int i = 0; i < degree + 1; i++)
    {
        for (int j = 0; j < degree + 2; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    // fine till here.
    for (int j = 0; j < degree + 1; j++)
    {
        if (fabs(matrix[j][j]) <= 0.00005)
        {
            cout << "Error: pivot element is zero.";
            return 1;
        }
        for (int i = 0; i < degree + 1; i++)
        {
            if (i != j)
            {
                float ratio = matrix[i][j] / matrix[j][j];
                for (int k = 0; k < degree + 2; k++)
                {
                    matrix[i][k] = matrix[i][k] - ratio * matrix[j][k];
                }
            }
        }
    }
    // cout << "print again;" << endl;
    // for (int i = 0; i < degree + 1; i++)
    // {
    //     for (int j = 0; j < degree + 2; j++)
    //     {
    //         cout << matrix[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
    cout << "The solution is: " << endl;
    for (int i = 0; i < degree + 1; i++)
    {
        cout << "A[" << i << "]= " << matrix[i][degree + 1] / matrix[i][i] << endl;
    }
    return 0;
}