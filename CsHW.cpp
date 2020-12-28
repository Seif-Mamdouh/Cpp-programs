#include <fstream>
#include <iostream>
#include <string>
using namespace std; 

int main() {
    //Declare a file-stream variable 
    ofstream fileOut;
    ofstream filename;
    string message; 

    //Get the file we will create.
    cout <<"Enter filename: ";
    cin >> filename;

    // Open a file to write to 
    fileOut.open(filename);
    
    // Write information to the file
    fileOut<<"This is my first programmatically created text file!"<<endl;

    //Close the file stream.
    fileOut.close();

    return 0;

}