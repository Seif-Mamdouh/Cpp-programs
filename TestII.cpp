#include <iostream>
#include<iomanip>
using namespace std;
struct taxes{
    float state;
    float fed;
    float union_fees;
};
struct employee{
    char first_name[50];
    char middle_name[50];
    char last_name[50];
    int hours;
    float rate;
    float overtime=0;
    float gross;
    float net;
    struct taxes tax;
};
int main()
{
    int number_of_emp=3;
    float total_gross;
    struct employee E[3];
    for(int i=0;i<number_of_emp;i++)
{ 
    cout<<"\nENTER DATA FOR EMPLOYEE "<<i+1<<endl;
    cout<<"First Name: ";
    cin>>E[i].first_name;
    cout<<"Middle Name: ";
    cin>>E[i].middle_name;
    cout<<"Last Name: ";
    cin>>E[i].last_name;
    cout<<"Total working hours: ";
    cin>>E[i].hours;
    cout<<"Rate per hour: ";
    cin>>E[i].rate;
    if(E[i].hours>40)

E[i].overtime=(E[i].hours-40)*E[i].rate*1.5;

E[i].gross=(E[i].rate*E[i].hours)+E[i].overtime;


E[i].tax.state=E[i].gross*6/100;
E[i].tax.fed=E[i].gross*12/100;
E[i].tax.union_fees=E[i].gross*2/100;

E[i].net= E[i].gross-( E[i].tax.state+ E[i].tax.fed+ E[i].tax.union_fees);
total_gross= E[i].gross+total_gross;
  
}

cout<<endl<<"Data Housing Corp. Weekly Payroll\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
cout<<"First Name Middle Name Last Name Rate per hour Total hours Overtime";
cout<<" Gross income State Tax Federal Tax Union Fees Net income\n";
cout<<"========== =========== ========= ============= =========== ========";
cout<<" ============ ========= =========== ========== ==========\n";
for(int i=0;i<number_of_emp;i++)
{
    cout<<setw(10)<<std::left<<E[i].first_name<<setw(13)<<std::left<<E[i].middle_name;
    cout<<setw(11)<<std::left<<E[i].last_name<<"$"<<setw(15)<<std::left<<E[i].rate<<setw(13)<<std::left<<E[i].hours;
    cout<<"$"<<setw(10)<<std::left<<E[i].overtime<<"$"<<setw(14)<<std::left<<E[i].gross<<"$"<<setw(11)<<std::left<<E[i].tax.state;
    cout<<"$"<<setw(13)<<std::left<<E[i].tax.fed<<"$"<<setw(12)<<std::left<<E[i].tax.union_fees<<"$"<<setw(12)<<std::left<<E[i].net;
    cout<<endl;
}
cout<<"========== =========== ========= ============= =========== ========";
cout<<" ============ ========= =========== ========== ==========\n";
cout<<"Total gross income of all employee= $"<<total_gross<<endl;
cout<<"Average gross income of all employee= $"<<total_gross/number_of_emp<<endl;
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
return 0;
}
