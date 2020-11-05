/*#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Prototype functions
double calcWage ();
void getEmployeeInfor();
void printWages();
void printTable();
void repeat();
void read();

// Defining terms for the program.
int id,result;
double payRate, hours, wage;
ofstream outputFile;
ifstream inputFile;
string file,strings;

int main() 
{

   cout << "Please enter the name of the file you wish to save to: ";
   cin >> file;
   outputFile.open(file.c_str());

   // Get employee information
   getEmployeeInfor();
   // Calculate the total wage
   wage = calcWage();
   // Prints the Table to the outputFile
   printTable();   
   // Prints the  wages to the output File
   printWages();
   // Ask if more informations wants to be added/ calculated
   repeat();
   // Call read function to read information to console
   read ();

 return 0;

}

// Function for asking user for Employee Id, pay rate, and the hours worked
void getEmployeeInfor()

{
 cout << "Please enter your employee id, payrate, and hours worked: " << endl;
 cin >> id >> payRate >> hours;

 //Loop to check for valid numbers.
   while ((id < 0) || payRate < 0 || hours < 0)
  {
   cout << "Please enter valid values (Positive numbers): " << endl;
   cin >> id >> payRate >> hours;
  }
}

// Function for calculating the Wage
double calcWage()
{
  double wages;
  return wages = payRate * hours;
}

// Function for printing information to the outputFile
void printWages()
{
  outputFile << setw(10) << id 
  << setprecision(2) << fixed <<  setw (10)
  << payRate 
  << setprecision(2) << fixed <<  setw (10)
  << hours
  << setprecision(2) << fixed <<  setw (10)
  << wage << endl;
} 

// Function to print table to the outputFile
void printTable()

{
  outputFile << setw(10) << "ID" << setw (10) << "Rate" << setw(10) << "Hours"
             << setw(10) << "Wage"<<endl;
  outputFile << "---------------------------------------------------------\n";
}

// Function that asks the user if the process wants to be repeated
void repeat()
{  
  char answer;
  cout << "Would you like to continue entering values? (y/n): ";
  cin >> answer;
  if (answer == 'y'|| answer == 'Y')
  {
    getEmployeeInfor();   // gets employee information
    wage = calcWage();    // calculates wage
    printWages();         // prints wage to the outputfile
    // calls repeat function again;
     repeat();
   }
  else
   {
    // Close the outputfile
    outputFile.close();
    cout << file << " was closed succesfully" << endl;
   }
}

// Function that reads the data to the console
void read()
 {
   char repeatAnswer;
   cout << "Would you like to read the file? (y/n): ";
   cin  >> repeatAnswer; 
   if (repeatAnswer == 'y' || repeatAnswer == 'Y')
    {
        inputFile.open(file.c_str());
        while (!inputFile.eof())
         {
           getline(inputFile, strings);
           cout << strings<< endl;
         }

    cout << "Reading " << file << " completed." << endl;
    }

  // Close inputFile
  inputFile.close();
  // Terminate the program
  exit(0);
 }*/

#include <iostream>
using namespace std;

 int main() {
    char oper;
    float num1, num2;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> oper;
    cout << "Enter two numbers: " << endl;
    cin >> num1 >> num2;

    switch (oper) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2;
            break;
        case '/':
            cout << num1 << " / " << num2 << " = " << num1 / num2;
            break;
        default:
            // operator is doesn't match any case constant (+, -, *, /)
            cout << "Error! The operator is not correct";
            break;
    }

    return 0;
}
