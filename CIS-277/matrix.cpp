// #include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

using namespace std;
void menu()
{
    cout << "Press 1 to Matrix Addition\n";
    cout << "Press 2 to Matrix Subtraction\n";
    cout << "Press 3 to Scalar multiplication\n";
    cout << "Press 4 to Matrix multiplication\n";
    cout << "Press 5 to Inverse of matrix\n";
    cout << "Press 6 to exit\n";
}
void result(int choice)
{
    switch (choice)
    {
    case 1:
    {
        double m1[2][2], m2[2][2], calc_sum[2][2];
        int i, j;
        cout << "Enter 4 Elements for First Matrix\n";
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
            {
                cout << "Enter element a" << i + 1 << j + 1 << " : ";
                cin >> m1[i][j];
            }
        cout << "Enter 4 Elements for Second Matrix\n";
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
            {
                cout << "Enter element b" << i + 1 << j + 1 << " : ";
                cin >> m2[i][j];
            }
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
            {
                calc_sum[i][j] = m1[i][j] + m2[i][j];
            }
        cout << "\nSubtraction of Two Matrix is:\n";
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
                cout << m1[i][j] << "   ";
            if (i == 1)
                cout << "  +\t";
            else
                cout << "\t";
            for (j = 0; j < 2; j++)
                cout << m2[i][j] << "   ";
            if (i == 1)
                cout << "  =\t";
            else
                cout << "\t";
            for (j = 0; j < 2; j++)
                cout << calc_sum[i][j] << "   ";
            cout << endl;
        }
        cout << "\nEnter your choice:\n";
        cin >> choice;
        cout << "Choice is " << choice << endl;
        result(choice);
        break;
    }
    case 2:
    {
        double m1[2][2], m2[2][2], calc_diff[2][2];
        int i, j;
        cout << "Enter 4 Elements for First Matrix\n";
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
            {
                cout << "Enter element a" << i + 1 << j + 1 << " : ";
                cin >> m1[i][j];
            }
        cout << "Enter 4 Elements for Second Matrix\n";
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
            {
                cout << "Enter element b" << i + 1 << j + 1 << " : ";
                cin >> m2[i][j];
            }
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
            {
                calc_diff[i][j] = m1[i][j] - m2[i][j];
            }
        cout << "\nSubtraction of Two Matrix is:\n";
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
                cout << m1[i][j] << "   ";
            if (i == 1)
                cout << "  -\t";
            else
                cout << "\t";
            for (j = 0; j < 2; j++)
                cout << m2[i][j] << "   ";
            if (i == 1)
                cout << "  =\t";
            else
                cout << "\t";
            for (j = 0; j < 2; j++)
                cout << calc_diff[i][j] << "   ";
            cout << endl;
        }
        cout << "\nEnter your choice:\n";
        cin >> choice;
        cout << "Choice is " << choice << endl;
        result(choice);
        break;
    }
    case 3:
    {
        int i, j, k;
        double m[2][2], scalar_multi[2][2];
        cout << "\nEnter the 4 elements for Matrix Values\n";
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                cout << "Enter element a" << i + 1 << j + 1 << " : ";
                cin >> m[i][j];
            }
        }

        cout << "\nPlease Enter the k(mul) Value: ";
        cin >> k;
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                scalar_multi[i][j] = k * m[i][j];
            }
        }

        cout << "\nThe Scalar Matrix Multiplication is :\n";
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                cout << scalar_multi[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\nScalar Multiplication is:\n";
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
                cout << k << "   ";
            if (i == 1)
                cout << "  x\t";
            else
                cout << "\t";
            for (j = 0; j < 2; j++)
                cout << m[i][j] << "   ";
            if (i == 1)
                cout << "  =\t";
            else
                cout << "\t";
            for (j = 0; j < 2; j++)
                cout << scalar_multi[i][j] << "   ";
            cout << endl;
        }
        cout << "\nEnter your choice:\n";
        cin >> choice;
        cout << "Choice is " << choice << endl;
        result(choice);
        break;
    }
    case 4:
    {
        double m1[2][2], m2[2][2], clac_prod[2][2];
        int i, j;
        cout << "Enter 4 Elements for First Matrix\n";
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
            {
                cout << "Enter element a" << i + 1 << j + 1 << " : ";
                cin >> m1[i][j];
            }
        cout << "Enter 4 Elements for Second Matrix\n";
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
            {
                cout << "Enter element b" << i + 1 << j + 1 << " : ";
                cin >> m2[i][j];
            }
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
            {
                clac_prod[i][j] = m1[i][j] * m2[i][j];
            }
        cout << "\nSubtraction of Two Matrix is:\n";
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
                cout << m1[i][j] << "   ";
            if (i == 1)
                cout << "  x\t";
            else
                cout << "\t";
            for (j = 0; j < 2; j++)
                cout << m2[i][j] << "   ";
            if (i == 1)
                cout << "  =\t";
            else
                cout << "\t";
            for (j = 0; j < 2; j++)
                cout << clac_prod[i][j] << "   ";
            cout << endl;
        }
        cout << "\nEnter your choice:\n";
        cin >> choice;
        cout << "Choice is " << choice << endl;
        result(choice);
        break;
    }
    case 5:
    {
        int clac_inve[2][2], i, j;
        double determinant = 0;
        cout << "Enter the 4 elements value for matrix:\n";
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
                cin >> clac_inve[i][j];
        cout << "\nGiven matrix is:";
        for (i = 0; i < 2; i++)
        {
            cout << "\n";
            for (j = 0; j < 2; j++)
                cout << clac_inve[i][j] << "\t";
        }
        for (i = 0; i < 2; i++)
            determinant = determinant + (clac_inve[0][i] * (clac_inve[1][(i + 1) % 3] * clac_inve[2][(i + 2) % 3] - clac_inve[1][(i + 2) % 3] * clac_inve[2][(i + 1) % 3]));
        cout << "\n\ndeterminant: " << determinant;
        cout << "\n\nInverse of matrix is: \n";
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
                cout << ((clac_inve[(j + 1) % 2][(i + 1) % 2] * clac_inve[(j + 2) % 2][(i + 2) % 2]) - (clac_inve[(j + 1) % 2][(i + 2) % 2] * clac_inve[(j + 2) % 2][(i + 1) % 2])) / determinant << "\t";
            cout << "\n";
        }
        cout << "\nEnter your choice:\n";
        cin >> choice;
        cout << "Choice is " << choice << endl;
        result(choice);
        break;
    }
    case 6:
    {
        cout << "Thank you\n";
        break;
    }
    default:
        printf("Wrong Input\n");
    }
}

int main()
{
    int choice;
    menu();
    cout << "Enter your choice:\n";
    cin >> choice;
    cout << "Choice is " << choice << endl;
    result(choice);
    return 0;
}