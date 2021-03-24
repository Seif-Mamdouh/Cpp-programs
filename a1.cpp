/* 
Write a program that calculates the occupancy rate for a hotel. 
The program should start by asking the user how many floors the hotel has. A loop should then iterate once for each floor. 
In each iteration, the loop should ask the user for the number of rooms on the floor and how many of them are occupied. 
After all the iterations, the program should display how many rooms the hotel has, how many of them are occupied, 
how many are unoccupied, and the percentage of rooms that are occupied. The percentage may be calculated by dividing 
the number of rooms occupied by the number of rooms.NOTE:  It is traditional that most hotels do not have a thirteenth floor. 
The loop in this program should skip the entire thirteenth iteration.
*/

#include <iostream>
using namespace std;

int main()
{
    //declared variables
    int i, rooms[100], floors, occupied[100];
    double total_rooms = 0, full_rooms = 0;

    do
    {
        cout << "\nEnter the total number of floors in the hotel: ";
        cin >> floors;
        if (floors < 1)
            cout << "Error:The floor cannot less than 1";
    } while (floors < 1);

    i = 0;

    for (i = 0; i < floors; ++i)
    {
        do
        {
            cout << "\nEnter the number of rooms on floor " << i + 1 << ": ";
            cin >> rooms[i];

            if (rooms[i] < 10)
                cout << "Error: Rooms must be greater than 10";
        } while (rooms[i] < 10);

        total_rooms += rooms[i];

        cout << "Enter the number of rooms that are full: ";
        cin >> occupied[i];
        full_rooms += occupied[i];
    }

    //printing results
    cout << "\n\nTotal Number of Rooms in the hotel: " << total_rooms;
    cout << "\nNumber of rooms that are full: " << full_rooms;

    cout << "\nNumber of rooms avaialable: " << total_rooms - full_rooms;
    cout << "\nPrecentenge Rate: " << full_rooms / total_rooms * 100 << "%";
    cout << "\nPress Enter To Continue...";
    cin.ignore();
    cin.get();
    return 0;
    system("pause");
}