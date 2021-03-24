/*Array ExpanderWrite a function that accepts an int array and the array’s 
size as arguments.The function should create a new array that 
is twice the size of the argument array.The function should copy
the contents of the argument array to the new array and initialize the 
unused elements of the second array with 0. The function should return 
a pointer to the new array.*/

#include <iostream>
using namespace std;

int *ArrayExpander(int ar[], int arguments)
{
    int *arr1 = new int[arguments * 2];
    for (int i = 0; i < arguments; i++)
    {
        arr1[i] = ar[i];
    }
    for (int i = arguments; i < 2 * arguments; i++)
    {
        arr1[i] = 0;
    }
    return arr1;
}

int *ElementShifter(int ar[], int arguments)
{

    int *arr2 = new int[arguments + 1];

    for (int i = 0; i < (arguments); i++)
    {
        arr2[i + 1] = ar[i];
    }
    arr2[0] = 0;
    return arr2;
}

int main()
{
    int n;
    cout << "enter the size of array : ";
    cin >> n;
    int ar[n];
    cout << "enter the elements of array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    int *ptr = ArrayExpander(ar, n);
    cout << "the elements of Expander Array : ";
    for (int i = 0; i < (2 * n); i++)
    {
        cout << ptr[i] << " ";
    }
    cout << "\n";
    int *ptr1 = ElementShifter(ar, n);
    cout << "the elements of Element shifter : ";

    for (int i = 0; i < n + 1; i++)
    {
        cout << ptr1[i] << " ";
    }
    return 0;
}
