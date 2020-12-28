#include<iostream>
using namespace std;

struct employee{ 
   string first_name;
   string middle_initial;
   string last_name;
   int no_of_hours_worked;
   float rate_per_hour;
   float gross_income;
   float state_tax;
   float federal_tax;
   float union_fees;
   float net_income;
};

float GROSS_INCOME(float rate , float hours){ 
   float overtime;
   float normal_hours;
  
   if(hours > 40){
       overtime = hours - 40;
       normal_hours = 40;
   }
   else{
       overtime = 0;
       normal_hours = hours;
   }
   float gross_income = (rate * normal_hours) + (rate * overtime * 1.5);
   return gross_income;
}

float STATE_TAX(float gross_income){ 
   return (0.06 * gross_income);
}

float FEDERAL_TAX(float gross_income){ 
   return (0.12 * gross_income);
}

float UNION_FEES(float gross_income){ 
   return (0.02 * gross_income);
}

float NET_INCOME(float gross_salary , float state_tax , float federal_tax , float union_fees){ 
   return (gross_salary - state_tax - federal_tax - union_fees);
}

int main(){
   float state_tax;
   float union_tax;
   float federal_tax;
   employee e1;
   cout << "Enter employee first name " << endl;
   cin >> e1.first_name;
   cout << "Enter employee middle initial " << endl;
   cin >> e1.middle_initial;
   cout << "Enter employee last name " << endl; 
   cin >> e1.last_name;
   cout << "Enter number of hours worked " << endl;
   cin >> e1.no_of_hours_worked;
   while(e1.no_of_hours_worked >= 60 || e1.no_of_hours_worked < 0){ 
       cout << "Wrong information " << endl;
       cout << "Enter number of hours worked " << endl;
       cin >> e1.no_of_hours_worked;
   }

   cout << "Enter the rate per hour " << endl;
   cin >> e1.rate_per_hour;
   while(e1.rate_per_hour > 50 || e1.no_of_hours_worked < 0){
       cout << "Wrong information " << endl; 
       cout << "Enter the rate per hour " << endl;
       cin >> e1.rate_per_hour;
}
   system("clear");
   e1.gross_income = GROSS_INCOME(e1.rate_per_hour , e1.no_of_hours_worked); 
   e1.state_tax = STATE_TAX(e1.gross_income);    
   e1.union_fees = UNION_FEES(e1.gross_income); 
   e1.federal_tax = FEDERAL_TAX(e1.gross_income); 
   e1.net_income = NET_INCOME(e1.gross_income , e1.state_tax , e1.federal_tax , e1.union_fees);
   cout << "Data Housing corp. Weakly Payroll ~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
   cout << e1.first_name << " " << e1.middle_initial << " " << e1.last_name << " $" << e1.rate_per_hour << " " << e1.no_of_hours_worked;
   cout << endl;
   cout << "Your gross income: \t" << "$" << e1.gross_income << endl;
   cout << "State Tax: \t\t" << "$" << e1.state_tax << endl;;
   cout << "Federal Tax: \t\t" << "$" << e1.federal_tax << endl;
   cout << "Union Fees: \t\t" << "$" << e1.union_fees << endl;
   cout << "Your net income: \t" << "$" << e1.net_income << endl;
}

