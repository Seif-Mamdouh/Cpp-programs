#include <iostream>
using namespace std;

float Gross_Income(float a, float b)
{
    float afterHours;
    float paidHours;

    if (b > 120)
    {
        afterHours = b + 120; 
        paidHours = 120;
    }
    else{
        afterHours = 0;
        paidHours = b;
    }

float gross = (a * paidHours ) + (a * afterHours * 1.5);
return gross;
}
float stateTax(float a)
{
    return (0.06 * a);
}
float fedTax(float a)
{
    return (0.12 * a);
}
float unionFees(float a)
{
    return (0.02 * a );
}
float net_income(float a, float b, float s, float z)
{
    return (a-(b+s+z));
}

int main()
{
    const int size = 20;
    string first_name[size];
    char middle_initial[size];
    string last_name[size];
    double hours[size];
    double rate[size];
    double gross[size],stax[size],ftax[size],ufees[size],net[size];
    double totalgross=0,avggross,overtime;
    char op='b';
    int i=0;


    while(op=='b')
{
    cout<<"\nEnter information of the employee"<<i+1<<":";
    cout<<"\nWhat's the First Name of the employee: ";
        cin>>first_name[i];
    cout<<"\nWhat's the Middle Initial of the employee: ";
        cin>>middle_initial[i];
    cout<<"\n What's the Last Name of the employee: ";
        cin>>last_name[i];
    l1 :cout<<"\n Hours worked: ";
        cin>>hours[i];
        
        if(hours[i]<0 || hours[i]>60)
        {
            cout<<"\n Invalid data : Hours worked";
            break;
        }
        l2:cout<<"\n Enter Rate : ";
        cin>>rate[i];
        if(rate[i]<0 || rate[i]>50)
        {
            cout<<"\n Invalid data : Rate";
            break;
        }
        cout<<"\n\n Do you want to continue : (y or n)";
        cin>>op;
        i++;
}


int j = i;
for(i=0; i<j; i++)
{
    if(hours[i]>40)
{
    overtime = (hours[i]-40)*rate[i]*1.5;
    hours[i] = 40;
}
else
overtime = 0;

gross[i] =  Gross_Income(rate[i],hours[i]);
stax[i] =   stateTax(gross[i]) ;
ftax[i] = fedTax(gross[i]);
ufees[i] = unionFees(gross[i]);
net[i] = net_income(gross[i], stax[i], ftax[i], ufees[i]);
totalgross += gross[i];
}

cout<<"Payroll";
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
cout<<"\n First Name \t MI \t Last Name \t Rate \t Hours \t Gross Pay \t State tax \t  Federal Tax \t Union fees \t Net Pay\n ";
for(i=0;i<j;i++)
{
cout<<first_name[i]<<"\t\t\t";
cout<<middle_initial[i]<<"\t\t\t";
cout<<last_name[i]<<"\t\t";
cout<<rate[i]<<"\t\t";
cout<<hours[i]<<"\t\t";
cout<<gross[i]<<"\t\t\t";
cout<<stax[i]<<"\t\t";
cout<<ftax[i]<<"\t\t";
cout<<ufees[i]<<"\t\t\t";
cout<<net[i]<<"\t\t\n";
}
cout<<"\n Total gross pay "<<totalgross;
avggross = totalgross/j;
cout<<"\n Average gross pay "<<avggross;
}