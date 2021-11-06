//Seif Momdouh, Emily Morel
//CIS-277-603: Stack ADT Implementation Using Arrays
#include <iostream>
using namespace std;

const int MAX = 10;
int stack[MAX], i, j, choice = 0, n, top = -1;
void push();
void pop();
void purge();
void show();
void top_of_stack();

int main()
{
    cout << "\n*********Stack operations using array*********";
    cout << "\n----------------------------------------------\n";
    while (choice != 5)
    {
        cout << "\nMenu\n-----";
        cout << "\nChose one of the options below...\n";
        cout << "\n1.Push\n2.Pop\n3.Top\n4.Purge\n5.Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            push();
            cout << "\n\nStack contents is:";
            show();
            cout << "\n";
            break;
        case 2:
            pop();
            cout << "\n\nStack contents is:";
            show();
            cout << "\n";
            break;
        case 3:
            top_of_stack();
            cout << "\n\nStack contents is:";
            show();
            cout << "\n";
            break;
        case 4:
            purge();
            show();
            cout << "\n";
            break;
        case 5:
            cout << "Exiting....";
            break;
        default:
            cout << "\n[!] Please enter a valid choice.\n";
        }
    }
}

void push()
{
    int val;
    if (top == MAX - 1)
        cout << "\n[!] Overflow.\n";
    else
    {
        cout << "\nEnter a value between 0 and 99: ";
        cin >> val;
        while (val < 0 || val > 99)
        {
            cout << "\n[!] Elements must be numbers between 0 and 99.\nPlease enter a new value: ";
            cin >> val;
        }
        top = top + 1;
        stack[top] = val;
    }
}

void top_of_stack()
{
    if (top == -1)
    {
        cout << "\n[!] Underflow.\n";
    }
    else
    {
        cout << "\nTop of stack is: " << stack[top];
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "\n[!] Underflow.\n";
    }
    else
    {
        cout << "\nElement popped was: " << stack[top];
        top = top - 1;
    }
}

void purge()
{
    int val;
    if (top == -1)
    {
        return;
    }
    else
    {
        for (i = top; i >= 0; i--)
        {
            top = top - 1;
        }
        cout << "\nStack is purged.\n";
        top = -1;
    }
}

void show()
{
    for (i = top; i >= 0; i--)
    {
        cout << "\n"
             << stack[i];
    }
    if (top == -1)
    {
        cout << "\nStack is empty.\n";
    }
}