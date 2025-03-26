#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r1;
    int c1;
    cout << "Enter rows of first matrix  ";
    cin >> r1;
    cout << "Enter columns of first matrix  ";
    cin >> c1;
    int a[r1][c1];

    for (int i = 1; i <= r1; i++)
    {
        for (int j = 1; j <= c1; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= r1; i++)
    {
        for (int j = 1; j <= c1; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
    int r2;
    int c2;

    cout << "Enter rows of second matrix  ";
    cin >> r2;
    cout << "Enter columns of second matrix  ";
    cin >> c2;
    int b[r2][c2];

    for (int i = 1; i <= r2; i++)
    {
        for (int j = 1; j <= c2; j++)
        {
            cin >> b[i][j];
        }
    }

    for (int i = 1; i <= r2; i++)
    {
        for (int j = 1; j <= c2; j++)
        {
            cout << b[i][j];
        }
        cout << endl;
    }

    if (c1 != r1)
    {
        cout << "multiplication not possible.";
    }

    else
    {
        int result[r1][c2];
        for (int i = 1; i <= r1; i++)
        {
            for (int j = 1; j <= c2; j++)
            {
                result[i][j] = 0;
            }
        }

        for (int i = 1; i <= r1; i++)
        {
            for (int j = 1;                                                                                                                                                                                                                                                                                                                                                                                                         = c2; j++)
            {
                for (int k = 1; k <= r2; k++)
                {
                    result[i][j] = result[i][j] + a[i][k] * b[k][j];
                }
            }
        }

        for (int i = 1; i <= r1; i++)
        {
            for (int j = 1; j <= c2; j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}