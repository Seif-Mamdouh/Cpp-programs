/*Phone Number ListWrite a program that has an array of at least 10 string 
objects that hold people’s names and phone numbers. You may make up your own strings, or use the following:
"Alejandra Cruz, 555-1223""Joe Looney, 555-0097""Geri Palmer, 555-8787""Li Chen, 555-1212""Holly Gaddis, 555-8878""Sam Wiggins,
555-0998""Bob Kain, 555-8712""Tim Haynes, 555-7676""Warren Gaddis, 555-9037""Jean James, 555-4939""Ron Palmer, 555-2783" 
The program should ask the user to enter a name or partial name to search for in the array. 
Any entries in the array that match the string entered should be displayed. 
For example, if the user enters “Palmer” the program should display the following names from the list:Geri Palmer, 
555-8787Ron Palmer, 555-2783*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main() {
    const int info = 18;
    const int Length = 27;
    string citizens_data[info] = {
        "Alejandra Cruz, 555-1223",
        "Joe Looney, 555-0097",
        "Geri Palmer, 555-8787",
        "Li Chen, 555-1212",
        "Holly Gaddis, 555-8878",
        "Sam Wiggins, 555-0998",
        "Bob Kain, 555-8712",
        "Tim Haynes, 555-9037",
        "Warren Gaddis, 555-9037",
        "Jean James, 555-4939",
        "Ron Palmer, 555-2783"
        };

    char search_engine[Length];
    size_t strPos;
    int data, count = 0;
    //Prompt the user to enter name or partial name
    cout << "\tPeople and Phone Numbers\n\n";
    cout << "Enter a name or partial name to search for: ";
    //read name or partial name
    cin.getline(search_engine, 27);
    //Find the name in all string objects
    for (data = 0; data < 18; data++) {
        //if the name is found in the string, the starting
        //position of name is returned into strPos
        strPos = citizens_data[data].find(search_engine);
        //strPos equal to no postions, if the name is
        //not found in the string
        if (strPos != string::npos) {
            //Print the string, in which the entered name is found
            cout << citizens_data[data] << endl;
            count++; //Increase the count
            }
        }
    if (count == 0)
        cout << "No matching was found.\n";
        return 0;
}
