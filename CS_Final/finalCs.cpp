#include<iostream>
#include<fstream>
#include<cstdio>
#include<curses.h>
#include<string>
#include<string.h>//strcpy() function
#include<stdio.h>
using namespace std;

class Student
{
public:
    int admno;
    char name[50];
    //string name = "";
    void setData()
    {
        cout << "\nEnter admission no: ";
        cin >> admno;
        cin.ignore();
        cout << "Enter name of student: ";
        cin.getline(name,50);
    }

    void setData(int newAdmno, char newName[])
    {
      admno = newAdmno;
      cout << "\nNew admission no set to: " << newAdmno;

      strcpy(name, newName);
      cout << "New name of student set to: " << newName;
    }

    void showData()
    {
        cout << "\nAdmission no. : " << admno;
        cout << "\nStudent Name : " << name;
    }
	 
    int retAdmno()
    {
        return admno;
    }

    char* retName()
    {
      return name;
    }
};

void Create(string & name) //Function to Create Data File
{  
    cout<<"What would like to name it? ";
           cin>>name;
           cout<<endl;
   
   ofstream outFile;
   outFile.open( name ,ios::out| ios::binary);
   

   outFile.close();
}


void write_record(string & name) //Function to write records in a binary file.
{
  //declare and open the output file
  ofstream outFile;
  outFile.open(name, ios::binary | ios::out); 
  
  //declare continue variable
  char answer;

  do
  {
      Student obj;
      obj.setData();

    if (outFile)
    {
        outFile.write(reinterpret_cast<const char*>(&obj), sizeof(obj));
    }

    cout<<"\nWould you like to enter another record?";
    cout<<"\n press y/n: ";
    cin>>answer;
  }
  while (answer == 'y' || answer == 'Y');
  outFile.close();
}

void display(string & name)   //function to display records of file
{
    ifstream inFile;
    inFile.open(name, ios::binary);

    Student obj;
    
    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        obj.showData();
    }        
    
    inFile.close();
    cout<<endl<<endl;
}

void search(int n, string & name) //function to search and display from binary file
{
    ifstream inFile;
    inFile.open(name, ios::binary);
    
    Student obj;

    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() == n)
        {
            obj.showData();
        }
    }
    
    inFile.close();
    cout<<endl<<endl; 
}


void delete_record(int n, string & name) //function to delete a record
{
    Student obj;
    ifstream inFile;
    inFile.open(name, ios::binary);

    ofstream outFile;
    outFile.open("Output.dat", ios::out | ios::binary);
    
    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() != n)
        {
            outFile.write((char*)&obj, sizeof(obj));
        }
    }

    inFile.close();
    outFile.close();
    cout<<endl<<endl<<endl;
    
    remove(name.c_str());
    rename("Output.dat", name.c_str());

}


void modify_record(int n, string & name)  //function to modify a record
{
  bool found = false;
    fstream file;
    file.open(name,ios::in | ios::out);

    Student obj;

    while(file.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() == n)
        {
          found = true;
            cout << "\nEnter the new details of student";
            obj.setData();
            
            int pos = -1 * sizeof(obj);
            file.seekp(pos, ios::cur);
			
            file.write((char*)&obj, sizeof(obj));
        }
        else
        {
          found = false;
        }
    }
    if (!found)
    {
          cout << "\nRecord #"<<n<<" not found\n\n";
    }
  
    file.close();
    cout<<endl<<endl;
}


void append(string & name)   //function to write and append records in a binary file.
{
    ofstream outFile;
    outFile.open(name, ios::binary | ios::app); 

    Student obj;
    obj.setData();
    
    outFile.write((char*)&obj, sizeof(obj));
    
    outFile.close();
    cout<<"\n Data has been appended to file"<<endl<<endl;
}

void quickSort(Student * elements, unsigned int first, unsigned int last)
{
//SHOW THE ARRAY OF STUDENTS
  for (int j = 0; j < last; j++)
  {
    elements[j].showData();
  }
cout << endl;
  if(first < last)                        
  {
    Student t = elements[first];          
    unsigned lastLow = first;           
    unsigned i;                         
    for(i = first + 1; i <= last; i++)  
    if(elements[i].admno < t.admno)
    {
      cout << " adding one onto lastLow...";
      lastLow++;                  
      Student tmp;
      tmp.setData(elements[i].admno,elements[i].name);
      elements[i].setData(elements[lastLow].admno,elements[lastLow].name);
      elements[lastLow].setData(tmp.admno,tmp.name);
    }

    Student tmp;
    tmp.admno = elements[lastLow].admno;
    strcpy(tmp.name,elements[lastLow].name);
    elements[lastLow].admno = elements[first].admno;
    strcpy(elements[lastLow].name,elements[first].name);
    elements[first].admno = tmp.admno;
    strcpy(elements[first].name,tmp.name);
    if(lastLow != first)                
    quickSort(elements, first, lastLow - 1);
    if(lastLow != last)                 
    quickSort(elements, lastLow + 1, last);
  }
  cout << endl << "Sorting complete." << endl;
  cout << endl;
  for (int j = 0; j < last; j++)
  {
      elements[j].showData();
  }
}



void sortFile(string & filename)
{
    Student objs[20];
    Student obj;
  
//DECLARE an object of TYPE: input filestream (ifstream)
  ifstream infile;
  
  cout<<"\nOpening File..."<<endl;

  infile.open(filename, ios::binary | ios::in | ios::ate); 
  
  int objcounter = 0;
  if (infile)
  {
      while(infile.read((char*)&objs[objcounter], sizeof(objs[objcounter])))
      {
          objcounter++;
      }
    }
  infile.close();
  
  cout << "Found " << (objcounter + 1) << " Student objects."<<endl;
  cout<<"Rearranging the Data...";
  cout << endl;
  for (int j = 0; j < objcounter; j++)
  {
    objs[j].showData();
  }
  
  quickSort(objs,0,objcounter);
  
  cout << endl;
  for (int j = 0; j < objcounter; j++)
  {
    objs[j].showData();
  }

  ofstream outfile;
  outfile.open(filename, ios::binary | ios::app); 
  


//LOOP UNTIL: the COUNTER reaches the LIMIT, after incrementing the COUNTER in POSTFIX MODE
for(int i = 0; i < objcounter ; i++) {
  outfile.write((char*)&objs[i], sizeof(objs[i]));
}

  cout<<"Your file has been Sorted\n"; 
  cout<<endl<<endl; 
}


int main()
{
    bool going_on = true;
    int option; 
    string name = "null";
    int record_num;
    char answer;
    do{

        cout<<"1.Create Data File"<<endl;
        cout<<"2.Add New Record in Data File"<<endl;
        cout<<"3.Display Record From Data File"<<endl;
        cout<<"4.Display Particular Record From Data File"<<endl;
        cout<<"5.Modify Paricular Record From Data File"<<endl;
        cout<<"6.Append Record From Data File"<<endl;
        cout<<"7.Sort Record From Data File"<<endl;
        cout<<"8.Delete Particular Record From Data File"<<endl;
        cout<<"9.Exit From the Program"<<endl;
        cout<<"Enter your Option : ";
        cin>>option;

       switch(option) {
           case 1 :
           cout<<"\nCreate a Data File\n";
           Create(name);
           break; 
           
           case 2 :
           cout<<"\nAdd Whatever You like\n";
           if (name != "null"){
               write_record(name);   
           }
           else {
               cout<<"\nplease create a data file\n\n";
           }
           break; 
           
           case 3 :
           //Display Record From Data File
           cout << "\nList of records\n";
           if (name != "null") {
               display(name);
           }
           else {
               cout<<"\nplease create a data file\n\n";
           }
           break; 

           case 4 :
           //Search record
           cout<<"\nSearch record\n";
           if (name != "null"){
               cout<<"\nWhich Record would like to search for? ";
               cin>>record_num;
               cout << "\nSearch result";
               search(record_num, name);
           }
           else {
               cout<<"\nplease create a data file\n\n";
           }
           break; 
           
           case 5 :
           //Modify Paricular Record From Data File
           cout << "\nModify Record\n";
           if (name != "null"){
               cout<< "\nWhich Record would you like to modify? ";
               cin>>record_num;
               modify_record(record_num, name);
           }
           else {
               cout<<"\nplease create a data file\n\n";
           }
           break; 

           case 6: 
           //append
           cout<<"\nAppend Record\n";
           if (name != "null"){
               append(name);
           }
           else {
               cout<<"\nplease create a data file\n\n";
           }
           
           break;
           
           case 7:
           cout<<"\nSort File\n";
           if (name != "null"){
               sortFile(name);
           }
           else {
               cout<<"\nplease create a data file\n\n";
           }
           
           break;


           case 8 :
           //Delete record 
           cout<<"\nDelete Record\n";

          if (name != "null")
          {
            cout<<"\nAre you sure you want to delete the record?";
            cout<<"\n press y/n: ";
            cin>>answer;
              if (answer == 'y' || answer == 'Y' || name != "null" ){
                cout<<"\nWhich record would you like to delete? ";
                cin>>record_num;
                delete_record(record_num, name);
                cout << "\nRecord Deleted\n\n";
            }
            else if(answer == 'n' || answer =='N'){
                break;
            }
          }
           else {
               cout<<"\nplease create a data file\n\n";
           }
           break; 
           
           case 9 :
           cout<<"C Ya!"<<endl;
           exit(0);
           going_on = false;
           break; 

           default :
           //invalid input 
           cout<<"Invalid number, please choose 1-9"<<endl;
           cout<<endl<<endl;
           going_on = true;
           }


    } while ( going_on == true );
    return 0;
    
}