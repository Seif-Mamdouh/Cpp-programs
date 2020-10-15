#include <iostream>
using namespace std;
int main()
{
cout << "\nEnter the number of employees\n";
int n;
cin>>n;
double nn=n;
double total_gross=0;
while(n-->0)
{
string name[3];
double hours_worked=1,rate_per_hour=1;
cout<<"\nEnter the First Name\n";
cin>>name[0];
cout<<"\nEnter Middle Name\n";
cin>>name[1];
cout<<"\nEnter Last Name\n";
cin>>name[2];

while(1)
{
cout<<"\nEnter the number of hours worked\n";
cin>>hours_worked;
if(hours_worked>0 && hours_worked<60)
break;
}
while(1)
{
cout<<"\nEnter the Rate per hour\n";
cin>>rate_per_hour;
if(rate_per_hour>0 && rate_per_hour<50)
break;
}
double overtime,gross_income,state_tax,fed_tax,union_tax;
double net,overtime_hours;

if(hours_worked-40>0)
overtime_hours=hours_worked-40;
else
overtime_hours=0;

gross_income=rate_per_hour*hours_worked+overtime_hours*1.5*rate_per_hour;
overtime=overtime_hours*1.5*rate_per_hour;
state_tax=gross_income*0.06;
fed_tax=gross_income*0.12;
union_tax=gross_income*0.02;
net=gross_income-(state_tax+fed_tax+union_tax);

total_gross+=gross_income;

cout<<"\n Gross Income = "<<gross_income;
cout<<"\n Overtime = "<<overtime;
cout<<"\n State Tax = "<<state_tax;
cout<<"\n Federal Tax = "<<fed_tax;
cout<<"\n Union Fees = n"<<union_tax;
cout<<"\n Net = "<<net;
}
cout<<"\nTotal Gross Income = "<<total_gross;
cout<<"\nAverage Gross Income = "<<total_gross/nn;
return 0;
}