 //Group 2: Seif Mohamed, Anthony Ruano, Darsh Savalia, Emily Morel
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Matrix{
	string name;
	double var1,var2,var3,var4;	
}m1,m2,sum,diff,k_m,prod,m_inv; //variables of the structure
//Function Prototypes
void get_matrix(Matrix &);
void get_scalar(double &);
void calc_sum(Matrix &, Matrix &, Matrix &);
void calc_diff(Matrix &, Matrix &, Matrix &);
void scalar_mult(double &, Matrix &, Matrix &);
void calc_prod(Matrix &, Matrix &, Matrix &);
void calc_inv(Matrix &, Matrix &);
void print_matrix(fstream &, Matrix &);
int Menu(int &, Matrix &, Matrix &, double &);
	
int main(){
	int choice;
	double k;
	
	get_matrix(m1);
	get_matrix(m2);
	get_scalar(k);
	
	string fileStr = "matrix.txt";
	fstream outfile;
	
	char repeat;
	
	do{
		Menu(choice, m1, m2, k);	
		switch(choice)
		{
			case 1: //Calculates the sum of m1 and m2
				calc_sum(m1,m2,sum);
				cout << "\tCalculation complete.";
				break;
			case 2: //Calculates the difference of m1 and m2
				calc_diff(m1,m2,diff);
				cout << "\tCalculation complete.";
				break;
			case 3: //Calculates the scalar product of m and k
				scalar_mult(k,m1,k_m);
				cout << "\tCalculation complete.";
				break;
			case 4: //Calculates the product of m1 and m2
				calc_prod(m1,m2,prod);
				cout << "\tCalculation complete.";
				break;
			case 5: //Calculates the inverse of m
				calc_inv(m1,m_inv);
				cout << "\tCalculation complete.";
				break;
			case 6: //Prints out the matrices and their corresponding names to the file
				outfile.open(fileStr, ios::out);
				if(outfile.fail()){
					cout << "\n\tThe file does not exist.";
					outfile.close();
				}
				else{
					print_matrix(outfile, m1);
					print_matrix(outfile, m2);
					print_matrix(outfile, sum);
					print_matrix(outfile, diff);
					print_matrix(outfile, k_m);
					print_matrix(outfile, prod);
					print_matrix(outfile, m_inv);	
					outfile.close();
					cout << "\n\tMatrices printed to " << fileStr << " file.";
				}
				break;
			default: break;
		}
		cout << "\n\n\tWould you like to do something else with the matrices?\n\tEnter Y for yes or N for no.\n\t--> ";
		cin	>> repeat;
	} while(repeat == 'Y'|| repeat == 'y');
	return 0;
}
//*Seif*
int Menu(int &choice, Matrix &m1, Matrix &m2, double &k){
	cout << "\n\n\t-----------Matrix Options------------\n" <<
	"\t1. Calculate " << m1.name << " + " << m2.name << "\n\t"<<
	"2. Calculate " << m1.name << " - " << m2.name << "\n\t"<<
	"3. Calculate scalar product of " << k << " * " << m1.name << "\n\t"<<
	"4. Calculate product of " << m1.name << " * " << m2.name << "\n\t"<<
	"5. Calculate inverse of " << m1.name << "\n\t"<<
	"6. Print all matrices to a file\n\t"<<
	"--> ";
	cin >> choice;
	if(choice <= 0 || choice > 6){
		while(choice <= 0 || choice > 6){
			cout << "\n\tThe options listed are from 1-6. \n\tPlease enter a new choice: ";
    	cin >> choice;
		}
	}
	return choice;
}

//Retrieves scalar input
void get_scalar(double &sc){
	cout << "\n\tPlease enter a scalar integer:\n\t--> ";
	cin >> sc;
}

//Retrieves information for matrices
void get_matrix(Matrix &mat){
	cout << "\n\tPlease enter a name for the matrix:\n\t--> ";
	cin >> mat.name;
	cout << "\n\tPlease enter the elements for the 2x2 matrix:\n\t";
	cin >> mat.var1 >> mat.var2 >> mat.var3 >> mat.var4;
}
//*Seif
//*Anthony
//Calculating sum of matrices
void calc_sum(Matrix &mat1, Matrix &mat2, Matrix &sum){
	sum.name = "Sum";
	sum.var1 = mat1.var1 + mat2.var1; 
  sum.var2 = mat1.var2 + mat2.var2;
  sum.var3 = mat1.var3 + mat2.var3;
  sum.var4 = mat1.var4 + mat2.var4;
}

//Calculating difference of matrices
void calc_diff(Matrix &mat1, Matrix &mat2, Matrix &diff){
	diff.name = "Diff.";
  diff.var1 = mat1.var1 - mat2.var1;
  diff.var2 = mat1.var2 - mat2.var2;
  diff.var3 = mat1.var3 - mat2.var3;
  diff.var4 = mat1.var4 - mat2.var4;
}

//Calculating scalar multiplication with a matrix
void scalar_mult(double &k, Matrix &mat1, Matrix &k_m){
	k_m.name = "S.M.";
  k_m.var1 = mat1.var1 * k;
  k_m.var2 = mat1.var2 * k;
  k_m.var3 = mat1.var3 * k;
  k_m.var4 = mat1.var4 * k;
}
//*Anthony
//*Darsh
//Calculating product of matrices
void calc_prod(Matrix &mat1,Matrix &mat2,Matrix &prod){
	prod.var4 = static_cast<double>((m1.var4 * m2.var4) + (m1.var3 * m2.var2));
  prod.var3 = static_cast<double>((m1.var4 * m2.var3) + (m1.var3 * m2.var1));
  prod.var2 = static_cast<double>((m1.var2 * m2.var4) + (m1.var1 * m2.var2));
  prod.var1 = static_cast<double>((m1.var2 * m2.var3) + (m1.var1 * m2.var1));
  prod.name = "Product";
  
}

//Calculating inverse of a matrix
void calc_inv(Matrix &mat1, Matrix &m_inv){  //The prototype for this function only calls for m1 so you can get rid of m2
	m_inv.name = "Inverse";
	double det_a;

  det_a =(mat1.var4 * mat1.var1) - (mat1.var2 * mat1.var3);
  
  m_inv.var3 = static_cast<double>((mat1.var2 * (-1))/ det_a);
  m_inv.var2 = static_cast<double>((mat1.var3 * (-1))/ det_a);
  m_inv.var4 = static_cast<double>(mat1.var1 / det_a);
  m_inv.var1 = static_cast<double>(mat1.var4 / det_a);
}

//Prints Matrices to the file
void print_matrix(fstream &outfile, Matrix &m){
	outfile << fixed << setprecision(2);
	outfile << "\n" << m.name << " =\n\t" << setw(10) << m.var1 << setw(11) << m.var2 << "\n\t" << setw(10) << m.var3 << setw(11) << m.var4;
}