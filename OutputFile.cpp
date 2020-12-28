#include<iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main()
{
  char fName[20];  // ="pricesx.dat"; // place file name upfront
  char [10];
  ifstream inFile;
  float price;
  cout <<"Enter file name";
  cout <<" Enter the messege ";
  cin>>filename;
  inFile.open(filename);

  if(inFile.fail()) // check for successfully open , can be written as if(! input) exit;

    {
	cout << "file named can not be found \n";
	exit(1);
   }
	 // read and display the files cont
	inFile>>discriptionn>>price;
	while(inFile.good()) // check next char
	{
	 cout <<discriptionn<< ' ' <<price<<endl;
	 inFile>>discriptionn>>price;
	 }inFile.close();
	 system("pause");
	return 0;
}
