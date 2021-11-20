#include <iostream>
using namespace std;
#define SIZE 5

//creating the queue using array
int A[SIZE];
int front = -1;
int rear = -1;

//function to check if the queue is empty
bool isempty()
{
    if (front == -1 && rear == -1)
        return true;
    else
        return false;
}

//function to enter elements in queue
void enqueue(int value)
{
    //if queue is full
    if ((rear + 1) % SIZE == front)
        cout << "Queue is full \n";
    else
    {
        //now the first element is inserted
        if (front == -1)
            front = 0;
        //inserting element at rear end
        rear = (rear + 1) % SIZE;
        A[rear] = value;
    }
}

//function to remove elements from queue
void dequeue()
{
    if (isempty())
        cout << "Queue is empty\n";
    else
        //only one element
        if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

//function to show the element at front
void showfront()
{
    if (isempty())
        cout << "Queue is empty\n";
    else
        cout << "element at front is:" << A[front];
}

//function to display the queue
void displayQueue()
{
    if (isempty())
        cout << "Queue is empty\n";
    else
    {
        int i;
        if (front <= rear)
        {
            for (i = front; i <= rear; i++)
                cout << A[i] << " ";
        }
        else
        {
            i = front;
            while (i < SIZE)
            {
                cout << A[i] << " ";
                i++;
            }
            i = 0;
            while (i <= rear)
            {
                cout << A[i] << " ";
                i++;
            }
        }
    }
}

//function to check if Queue is empty
bool isEmpty()
{
    bool empty = true;
    bool isNotEmpty = false;

    if (isempty())
        return empty;
    else
        return isNotEmpty;
}

//function to check if Queue is full
bool fullCheck()
{
    bool check = false;
    bool full = true;

    if ((rear + 1) % SIZE == front)
        return full;
    else
        return check;
}

//function to purge the Queue
void purge_queue()
{

    cout << "Deleting the entire queue..." << endl;

    //  delete[] isempty();

    exit(1);
}

//driver program
int main()
{
    int choice, flag = 1, value;
    while (flag == 1)
    {
        cout << "\n1.Enqueue 2.Dequeue 3.Show Front 4.Display Queue 5.Empty Check 6.Full Check 7.Pruge\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the Value to insert in queue:\n";
            cin >> value;
            enqueue(value);
            break;

        case 2:
            dequeue();
            displayQueue();
            break;

        case 3:
            showfront();
            break;

        case 4:
            displayQueue();
            break;

        case 5:
            std::cout << std::boolalpha << isEmpty() << std::endl;
            break;

        case 6:
            std::cout << std::boolalpha << fullCheck() << std::endl;
            break;

        case 7:
            purge_queue();
            break;
        }
    }

    return 0;
}