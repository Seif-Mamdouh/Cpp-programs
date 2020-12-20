#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cstdlib>
using namespace std;

struct Person
{
     char name[20];
     int accno;
     float balance;
        
};
int main()
{
     struct Person p;
     FILE *fp;
     char c;
     int ch;
     while(1)
     {
          cout<<"\n\n 1. Add Records in the File";
          cout<<"\n 2. Display Content of File";
          cout<<"\n 3. Display Name of Person whose Balance is Greater than 10,000";
          cout<<"\n 4. Exit";
          cout<<"\n\n Enter Your Choice : ";
          cin>>ch;
          switch(ch)
          {
               case 1:
                    fp=fopen("person.txt","ab");
                    while (1)
                    {
                         cout<<"\n Enter Person Name   :  ";
                         cin>>p.name;
                         fflush(stdin);
                         cout<<"\n Enter Account No.   :  ";
                         cin>>p.accno;
                         fflush(stdin);
                     
                         cout<<"\n Enter Balance       :  ";
                         cin>>p.balance;
                         fflush(stdin);
                      
                         fwrite(&p,sizeof(p),1,fp);
                         fflush(stdin);
                         cout<<"\n\n Do You Want to Continue?(Y/N) : ";
                         cin>>c;
                         if(c=='n' || c=='N')
                              break;
                    }
                    fclose(fp);
                    break;
                    
               case 2:
                    fp=fopen("person.txt","rb");
                    while (fread(&p,sizeof(p),1,fp))
                    {
                         while(1)
                         {
                              cout<<"\n Account No : "<<p.accno;
                              cout<<"\n Name       : "<<p.name;
                              cout<<"\n Balance    : "<<p.balance<<endl;
                              break;
                         }
                    }
                    fclose(fp);
                    break;

               case 3:
                    fp=fopen("person.txt","rb");	
                    while(fread(&p,sizeof(p),1,fp))
                    {
                         if(p.balance>10000)
                         {

                              while(1)
                              {
                                   cout<<"\n Account No : "<<p.accno;
                                   cout<<"\n Name       : "<<p.name;
                                   cout<<"\n Balance    : "<<p.balance<<endl;
                                   break;
                              }
                         }
                    }	
                    fclose(fp);
                    break;
               case 4:
                    exit(0);
               default: 
                    cout<<"\n Invalid Choice";
          }
     }
     return 0;
}
/*#include<iostream>
#include<fstream>
using namespace std; 
  
class abc { 
    int roll; 
    char name[20]; 
  
public: 
    void getdata(int, char[]); 
    void update(int, int, char[]); 
    void testcase1(); 
    void testcase2(); 
    void putdata(); 
}; 
  
// Code to display the data of the 
// data of the object 
void abc::putdata() 
{ 
    cout << "roll no: "; 
    cout << roll; 
    cout << "\nname: "; 
    cout << name; 
} 
  
// Code to set the value to the object 
void abc::getdata(int a, char str[]) 
{ 
    // setting the new roll no 
    roll = a; 
  
    // setting new name 
    strcpy(name, str); 
} 
  
void abc::update(int rno, int r, char str[]) 
{ 
    // code to update and modify 
    // the content of the binary file 
    int pos, flag = 0; 
  
    // rno=9 
    fstream fs; 
    fs.open("he.dat", 
            ios::in | ios::binary | ios::out); 
  
    while (!fs.eof()) { 
        // storing the position of 
        // current file pointeri.e. at 
        // the end of previously read record 
        pos = fs.tellg(); 
  
        fs.read((char*)this, sizeof(abc)); 
        if (fs) { 
  
            // comparing the roll no with that 
            // of the entered roll number 
            if (rno == roll) { 
                flag = 1; 
  
                // setting the new (modified ) 
                // data of the object or new record 
                getdata(r, str); 
  
                // placing the put(writing) pointer 
                // at the starting of the  record 
                fs.seekp(pos); 
  
                // writing the object to the file 
                fs.write((char*)this, sizeof(abc)); 
  
                // display the data 
                putdata(); 
                break; 
            } 
        } 
    } 
    fs.close(); 
  
    if (flag == 1) 
        cout << "\nrecord successfully modified \n"; 
    else
        cout << "\nrecord not found \n"; 
} 
  
// Sample input 1 
void abc::testcase1() 
{ 
    int rno, r; 
    char name[20]; 
  
    // roll no to be searched 
    rno = 1; 
  
    // new roll no 
    r = 11; 
  
    // new name 
    strcpy(name, "Geek"); 
  
    // call update function with new values 
    update(rno, r, name); 
} 
  
// Sample input 2 
void abc::testcase2() 
{ 
    int rno, r; 
    char name[20]; 
  
    // roll no to be searched 
    rno = 4; 
  
    // new roll no 
    r = 14; 
  
    // new name 
    strcpy(name, "Geek2"); 
  
    // call update function with the new values 
    update(rno, r, name); 
} 
  
// Driver code 
int main() 
{ 
    abc s; 
  
    // sample case 1 
    s.testcase1(); 
  
    // sample case 2 
    s.testcase2(); 
  
    return 0; 
} */