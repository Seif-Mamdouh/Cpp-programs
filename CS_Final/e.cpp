#include<iostream>
#include<fstream>
#include<cstdio>
#include<curses.h>
#include<string>

class student
{
 char name[20];
 int rollno;
 int marks;
 public:
 void getdata()
  {
  cout<<"Enter the name of the student:";
  gets(name);
  cout<<"Enter the rollno of the student:";
  cin>>rollno;
  cout<<"Enter the marks of the student:";
  cin>>marks;
 }
 void putdata()
  {
  cout<<"\nName:"<<name<<endl;
  cout<<"Rollno:"<<rollno;
  cout<<"\tMarks:"<<marks;
 }
 int getrno()
 {
  return rollno;
 }
};

void insert()
{
 student insert;
 ofstream f("file2.dat",ios::binary|ios::app);
 if(!f)
 {
  cout<<"file didn't open";
  getch();
  return;
 }
 insert.getdata();
 f.write((char*)&insert,sizeof(insert));
 f.close();
}

void Delete()
{
 ifstream f1("file2.dat",ios::binary);
 ofstream f2("temp.dat",ios::binary);
 student del;
 int rollno;
 f1.seekg(0);
 cout<<"Enter the roll no of the record whose record to be deleted:";
 cin>>rollno;
 char record='n';
 while(!f1.eof())
  {
   f1.read((char*)&del,sizeof(del));
   if(del.getrno()!=rollno)
   f2.write((char*)&del,sizeof(del));
   else
   record='y';
  }
  if(record=='n')
  cout<<"Record does not exist";
  else
  cout<<"Record with roll number "<<rollno<<" has been deleted";
 f1.close();
 f2.close();
 remove("file2.dat");
 rename("temp.dat","file2.dat");
}

void display()
{
 student disp;
 ifstream f("file2.dat",ios::binary);
 while(f.read((char*)&disp,sizeof(disp)))
 {
  disp.putdata();
 }
}
void Sort()
{
 fstream f1("file2.dat",ios::binary|ios::ate|ios::in|ios::out);
 int i=0;
 student obj1,obj2;
 long size=f1.tellg()/sizeof(student);
 for(i=0;i<size-1;++i)
 {
  for(int j=i+1;j<size-1-i;++j)
  {
    f1.read((char*)&obj1,sizeof(obj1));
    f1.read((char*)&obj2,sizeof(obj2));
    if(obj1.getrno() > obj2.getrno())
    {
      f1.seekp(-48,ios::cur);
      f1.write((char*)&obj2,sizeof(obj2));
      f1.write((char*)&obj1,sizeof(obj1));
      f1.seekp(-24,ios::cur);
    }
  }
 }
 f1.close();
}

void main()
{
 clrscr();
 int choice1=0;
 char choice2='y';
 do
 {
  cout<<"\n1.Insert a record";
  cout<<"\t2.Display a record";
  cout<<"\n3.Delete a record";
  cout<<"\t4.Sort the file";
  cout<<"\t\t5.Exit\n";
  cout<<"Enter the choice:";
  cin>>choice1;
  switch(choice1)
  {
   case 1: insert();  break;
   case 2: display(); break;
   case 3: Delete();  break;
   case 4: Sort();    break;
   case 5: exit(0);   break;
   default: cout<<"\nWrong choice entered";
  }
  cout<<"\nFurther file handling(y/n):";
  cin>>choice2;
 }while(choice2=='y');
 getch();
}