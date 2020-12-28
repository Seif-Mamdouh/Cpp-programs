#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<string.h> //strcpy() function
#include<stdio.h>
using namespace std;

void wipeOutFile();

class Student
{
    int admno;
    char name[50];
    vector<Person> employees;
public:
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
//      cout << "\nNew admission no set to: " << newAdmno;

      strcpy(name, newName);
//      cout << "\nNew name of student set to: " << newName;
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
  char answer;
  cout<<"Enter the filename ";
  //cin>>name;
  cin.ignore();
  getline(cin,name);
  cout<<endl;

  cout<<"\nCreate the file: <"<<name<<">? (y/n): ";
  cin>>answer;
  if (answer == 'y' || answer =='Y')
  {
    ofstream outFile;
    outFile.open(name, ios::binary | ios::out);
    outFile.close();
    cout<<"\n\nFile Created: <"<<name<<">.\n\n";
  }
}


void write_record(string & name) //Function to write records in a binary file.
{
  //declare and open the output file
  ofstream outFile;
  outFile.open(name, ios::binary | ios::out); 
//  ofstream ofs(path, ios_base::out | ios_base::binary);

  //declare continue variable
  char answer;

  //do (loop)
  do
  {
    //get the student's info from the user
    Student obj;
    obj.setData();
    
    //write the student info to the file
    //outFile.write((char*)&obj, sizeof(obj));
    if (outFile)
    {
      outFile.write((char*)&obj, sizeof(obj));
    }

    //ask the user if they want to continue
    cout<<"\nWould you like to enter another record?";
    cout<<"\n press y/n: ";
    //get user response
    cin>>answer;
  }
  //while the user response indicates continue
  while (answer == 'y' || answer == 'Y');
  //close the output file
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
  bool found = false, modified = false;
    fstream file;
    file.open(name,ios::in | ios::out);

    Student obj;

    while(file.read((char*)&obj, sizeof(obj)))
    {
      if(!found && obj.retAdmno() == n)
      {
        found = true;
        cout << "\nEnter the new details of student";
        obj.setData();
            
        unsigned long pos = -1 * sizeof(obj);
        file.seekp(pos, ios::cur);
			
        file.write((char*)&obj, sizeof(obj));
        modified = true;
      }
      else
      {
        found = false;
      }
    }
    if (!found && !modified)
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

void selectionSort(Student * elements, int lastindex)
{
  cout << endl << "Performing Sort..." << endl;
  int lowindex;
  for(int i = 0; i < lastindex - 1; i++)
  {
    lowindex = i;

    for (int j=(i+1); j < lastindex; j++)
    {
      if(elements[j].retAdmno() < elements[lowindex].retAdmno())
      {
        lowindex = j;//save the index of the lowest admno
      }
    }
    Student tmp;
    tmp.setData(elements[i].retAdmno(),elements[i].retName());
    elements[i].setData(elements[lowindex].retAdmno(),elements[lowindex].retName());
    elements[lowindex].setData(tmp.retAdmno(),tmp.retName());
  }
  cout << endl << "...Sorting complete." << endl;
}

void sortFile(string & filename)
{
  Student obj;
  Student objs[20];
  
  ifstream infile;
  int objcounter = 0;

//INPUT
  infile.open(filename, ios::binary | ios::in);
  while(infile.read((char*)&obj, sizeof(obj)))
  {
  //READ each record into the array of Student objects as an object
    objs[objcounter].setData(obj.retAdmno(),obj.retName());
  //  objs[objcounter].showData();//show the object in the array to make sure it is there
    //increment the object counter
    objcounter++;
  }
  infile.close();

  cout << "Found " << (objcounter) << " Student objects in file."<<endl;

//PROCESSING:
  /*CALL SORT FUNCTION ON ARRAY OF STUDENT OBJECTS*/
  selectionSort(objs,objcounter);

//OUTPUT:
  ofstream outfile;

  outfile.open(filename, ios::binary | ios::out);//OPEN the output file by DESIGNATED VARIABLE NAME in overwrite mode (use OUT FLAG instead of APP)
//LOOP UNTIL: the COUNTER reaches the LIMIT (objectcount)
  for(int i = 0; i < objcounter ; i++)
  {
    //write each object from the array into the file
    outfile.write((char*)&objs[i], sizeof(objs[i]));
  }
  outfile.close();

  cout<<"\nYour file has been Sorted\n"; 
  cout<<endl<<endl;
}//END FUNCTION DEFINITION

void wipeOutFile()
{
    string confirmation;
    cout << "All records would be lost " << endl;
    cout << "Do you want to proceed - type (Yes or No) " << endl;
    cin >> confirmation;
    
    if (strcmp(confirmation.c_str(), "Yes") == 0) // Comparing two strings
    {
        employees.clear();
        populateFile();
        cout << "All Records were deleted. " << endl;
    }
}

void populateFile(string & filename)
{
    ofstream myFile;

    myFile.open(filename, ios::out);
    if (!myFile.is_open())
    {
        cout << "Error while opening File " << endl;
    }
    else
    {
        for (auto& element : employees)
        {
            myFile.write((char*)&element, sizeof(Person));
        }
    }
    myFile.close();
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
        cout<<"10.Wipe Out the Record of the file"<<endl;
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
           
           // you can have any number of case statements.
           
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
                cout << "\nRecord Deleted";
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

           case 10 :
           cout<<"Wiping the Records from the file....."<<endl<<endl;
           if (name != "null"){
               wipeOutFile(name);
           }
           else {
               cout<<"\nplease create a data file\n\n";
           }
           
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