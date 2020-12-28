#include <iostream>

using namespace std;

float GROSS(float RAte,float HOurs)
{
float overtime;
float normal_hours;
if(HOurs > 120)
{
overtime = HOurs - 120;
normal_hours = 120;
}
else{
overtime = 0;
normal_hours = HOurs;
}
float gross_income = (RAte * normal_hours) + (RAte * overtime * 1.5);
return gross_income;
}
float STAX(float GROSs)
{
 return (0.06 * GROSs);  
}
 float FTAX(float GROss)
 {
    return (0.12 * GROss);
 }
 float UFEES(float Gross)
 {
     return (0.02 * Gross);
 }
 float NET(float GRoss, float STax, float FTax, float UFees)
{
    return( GRoss-(STax+FTax+UFees));
}
 struct tax{
     
     double gross,stax,ftax,ufees,net;
    };

 struct employee {
     
     string fname;
     char minitial;
     string lname;
     double hours;
     double rate;
     tax totalgross,avggross,overtime;
    };
   

int main()
{
   {
       employee e1;
       double gross,stax,ftax,ufees,net;
     double totalgross=0,avggross,overtime;
char op='y';
int i=0;
while (op=='y')
{
  cout<<"\n Enter details of employee "<<i+1<<":";
cout<<"\n First Name : ";
cin>>e1.fname;
cout<<"\n Middle Inital : ";
cin>>e1.minitial;
cout<<"\n Last Name : ";
cin>>e1.lname;
do
{
cout<<"\n Hours worked : ";
cin>>e1.hours;
}
while(e1.hours<0 || e1.hours>60);
do
{
cout<<"\n Enter Rate : ";
cin>>e1.rate;
}
while(e1.rate<0 || e1.rate>50);

cout<<"\n\n Do you want to continue : (y or n)";
cin>>op;
i++;
}
int j = i;
for(i=0;i<j;i++)
{
if(e1.hours>40)
{
overtime = (e1.hours-40)*e1.rate*1.5;
e1.hours = 40;
}
else
overtime = 0;
gross =  GROSS(e1.rate,e1.hours);
stax =   STAX(gross) ;
ftax = FTAX(gross);
ufees = UFEES(gross);
net = NET(gross, stax, ftax, ufees);
totalgross += gross;
}



// Output
cout<<"\n Data Housing Corp.Weekly Payroll";
cout<<"\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
cout<<"\n First Name \t MI \t Last Name \t Rate \t Hours \t Gross Pay \t State tax \t  Federal Tax \t Union fees \t Net Pay\n ";
for(i=0;i<j;i++)
{
cout<<e1.fname<<"\t\t\t";
cout<<e1.minitial<<"\t\t\t";
cout<<e1.lname<<"\t\t";
cout<<e1.rate<<"\t\t";
cout<<e1.hours<<"\t\t";
cout<<gross<<"\t\t\t";
cout<<stax<<"\t\t";
cout<<ftax<<"\t\t";
cout<<ufees<<"\t\t\t";
cout<<net<<"\t\t\n";
}
cout<<"\n Total gross pay "<<totalgross;
avggross = totalgross/j;
cout<<"\n Average gross pay "<<avggross;
}

}
