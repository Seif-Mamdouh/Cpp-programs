#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
class MATRIX
{
private:
    double elements[2][2]; //the elements of a 2x2 matrix

public:
    MATRIX()
    {
        //initialize all to 0
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                elements[i][j] = 0;
    }

    //return the element in specified row and col
    double getElement(int row, int col)
    {
        return elements[row][col];
    }

    //set teh element in the specified row and col to the specified value
    void setElement(int row, int col, double value)
    {
        elements[row][col] = value;
    }
};

void get_matrix(string &name, MATRIX &mat);

//sum is passed by reference so the changes are preserved, the sum of m1 and m2 is stored in sum
void calc_sum(MATRIX m1, MATRIX m2, MATRIX &sum);

//diff is passed by reference so the changes are preserved, the difference of m1 and m2 is stored in diff
void calc_diff(MATRIX m1, MATRIX m2, MATRIX &diff);

void get_scalar(double &b);

//k_m is passed by reference so the changes are preserved, the result of scalar multiplication is stored in k_m
void scalar_mult(double k, MATRIX m, MATRIX &k_m);

//prod is passed by reference so the changes are preserved, the result of matrix product is stored in prod
void calc_prod(MATRIX m1, MATRIX m2, MATRIX &prod);

//m_inv is passed by reference so the changes are preserved, hte inverse of matrix is stored in m_inv
void calc_inv(MATRIX m, MATRIX &m_inv);

void print_matrix(ofstream &out, string name, MATRIX m);

int main()
{
    string name1, name2;
    MATRIX m1, m2;
    double scalar;
    MATRIX sum, diff, prod, scal_prod, inv;
    get_matrix(name1, m1);
    get_matrix(name2, m2);
    get_scalar(scalar);
    calc_sum(m1, m2, sum);
    calc_diff(m1, m2, diff);
    calc_prod(m1, m2, prod);
    calc_inv(m1, inv);
    scalar_mult(scalar, m1, scal_prod);

    string filename = "output.txt";
    ofstream outfile(filename.c_str());

    if (!outfile.is_open())
    {
        cout << "Error opening output file " << filename << endl;
        return 1;
    }

    print_matrix(outfile, name1, m1);
    print_matrix(outfile, name2, m2);
    print_matrix(outfile, "Sum = m1 + m2 ", sum);
    print_matrix(outfile, "Difference = m1 - m2 ", diff);
    print_matrix(outfile, "Product = m1 * m2", prod);
    print_matrix(outfile, "Inverse of m1", inv);
    print_matrix(outfile, "Scalar product of m1 and " + to_string(scalar), scal_prod);

    outfile.close();

    cout << "output written to file " << filename << endl;
}

void get_matrix(string &name, MATRIX &mat)
{
    double value;
    cout << "Enter the name of the matrix: ";
    cin >> name;
    cout << "Enter the elements row-wise for Matrix " << name << endl;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            cin >> value;
            mat.setElement(i, j, value);
        }
}
//sum is passed by reference so the changes are preserved, the sum of m1 and m2 is stored in sum
void calc_sum(MATRIX m1, MATRIX m2, MATRIX &sum)
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            double value = m1.getElement(i, j) + m2.getElement(i, j);
            sum.setElement(i, j, value);
        }
}

//diff is passed by reference so the changes are preserved, the difference of m1 and m2 is stored in diff
void calc_diff(MATRIX m1, MATRIX m2, MATRIX &diff)
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            double value = m1.getElement(i, j) - m2.getElement(i, j);
            diff.setElement(i, j, value);
        }
}

void get_scalar(double &b)
{
    cout << "Enter a scalar value: ";
    cin >> b;
}

//k_m is passed by reference so the changes are preserved, the result of scalar multiplication is stored in k_m
void scalar_mult(double k, MATRIX m, MATRIX &k_m)
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            double value = m.getElement(i, j) * k;
            k_m.setElement(i, j, value);
        }
}

//prod is passed by reference so the changes are preserved, the result of matrix product is stored in prod
void calc_prod(MATRIX m1, MATRIX m2, MATRIX &prod)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            double value = 0;

            for (int k = 0; k < 2; k++)
            {
                value = value + m1.getElement(i, k) * m2.getElement(k, j);
            }

            prod.setElement(i, j, value);
        }
    }
}

//m_inv is passed by reference so the changes are preserved, hte inverse of matrix is stored in m_inv
void calc_inv(MATRIX m, MATRIX &m_inv)
{
    double det = m.getElement(0, 0) * m.getElement(1, 1) - m.getElement(1, 0) * m.getElement(0, 1);
    //set diagnoal elemnts top left and bottom right
    m_inv.setElement(0, 0, m.getElement(1, 1) / det);
    m_inv.setElement(1, 1, m.getElement(0, 0) / det);

    //set diagnoal elemnts top right and bottom left
    m_inv.setElement(0, 1, -m.getElement(0, 1) / det);
    m_inv.setElement(1, 0, -m.getElement(1, 0) / det);
}

//prints the given matrix in the output stream
void print_matrix(ofstream &out, string name, MATRIX m)
{
    out << fixed << setprecision(2); //show decimal point and 2 places after point
    out << name << endl;

    out << "====================" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            out << setw(10) << m.getElement(i, j);
        out << endl;
    }

    out << endl;
}
