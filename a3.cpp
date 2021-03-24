/*
Overloaded HospitalWrite a program that computes and displays the charges for a patient’s hospital stay. 
First, the program should ask if the patient was admitted as an in-patient or an out-patient. 
If the patient was an in-patient, the following data should be entered:• 
Thenumberofdaysspentinthehospital• Thedailyrate• Hospitalmedicationcharges• 
Chargesforhospitalservices(labtests,etc.)The program should ask for the following data if the patient was an out-patient:• 
Chargesforhospitalservices(labtests,etc.)• HospitalmedicationchargesThe program should use two overloaded functions to calculate the total charges. 
One of the functions should accept arguments for the in-patient data, while the other func-tion accepts arguments for out-patient information. 
Both functions should return the total charges.Input Validation: Do not accept negative numbers for any data.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

double calculateTotal(int days, double dR, double mC, double sC)
{
    return days * dR + mC + sC;
}
double calculateTotal(double mC, double sC)
{
    return mC + sC;
}

int main()
{

    int typeOfPateint, daysSettled;
    double dailyPayment, medicnePrice, hostpitalServicePayement, totalPayment;
    ofstream fout;
    fout.open("Patient'sBill.txt");
    cout << "1. In-patient. 2. Out-patient. Enter your choice: ";
    cin >> typeOfPateint;


    if (typeOfPateint == 1)
    {
        cout << "Enter the number of days spent in hospital: ";
        cin >> daysSettled;

        while (daysSettled < 0)
        {
            cout << "Please enter a positive value\n";
            cout << "Enter the number of days spent in hospital: ";
            cin >> daysSettled;
        }
        cout << "Enter the daily rate: ";
        cin >> dailyPayment;
        while (dailyPayment < 0)
        {
            cout << "Please enter a positive value\n";
            cout << "Enter the daily rate: ";
            cin >> dailyPayment;
        }
        cout << "Enter the hospital medication charges: ";
        cin >> medicnePrice;
        while (medicnePrice < 0)
        {
            cout << "Please enter a positive value\n";
            cout << "Enter the hospital medication charges: ";
            cin >> medicnePrice;
        }
        cout << "Enter the hospital service charges: ";
        cin >> hostpitalServicePayement;
        while (hostpitalServicePayement < 0)
        {
            cout << "Please enter a positive value\n";
            cout << "Enter the hospital service charges: ";
            cin >> hostpitalServicePayement;
        }
        totalPayment = calculateTotal(daysSettled, dailyPayment, medicnePrice, hostpitalServicePayement);
    }

    else
    {
        cout << "Enter the hospital medication charges: ";
        cin >> medicnePrice;
        while (medicnePrice < 0)
        {
            cout << "Please enter a positive value\n";
            cout << "Enter the hospital medication charges: ";
            cin >> medicnePrice;
        }
        cout << "Enter the hospital service charges: ";
        cin >> hostpitalServicePayement;
        while (hostpitalServicePayement < 0)
        {
            cout << "Please enter a positive value\n";
            cout << "Enter the hospital service charges: ";
            cin >> hostpitalServicePayement;
        }
        totalPayment = calculateTotal(medicnePrice, hostpitalServicePayement);
    }
    cout << "The total charges for the patient is: " << fixed << setprecision(2) << totalPayment << endl;
    if (typeOfPateint == 1){
        fout << "Patient Type: In-patient" << endl;
        fout << "Number of days spent in the hospital: " << daysSettled << endl;
        fout << "Daily rate: " << fixed << setprecision(2) << dailyPayment
             << endl;
        fout << "Medication charges: " << fixed << setprecision(2) << medicnePrice << endl;
        fout << "Service charges: " << fixed << setprecision(2) << hostpitalServicePayement << endl;
        fout << "Total charges: " << fixed << setprecision(2) << totalPayment << endl;
    }
    else
    {
        fout << "Patient Type: Out-patient" << endl;
        fout << "Medication charges: " << fixed << setprecision(2) << medicnePrice << endl;
        fout << "Service charges: " << fixed << setprecision(2) << hostpitalServicePayement << endl;
        fout << "Total charges: " << fixed << setprecision(2) << totalPayment << endl;
    }
}