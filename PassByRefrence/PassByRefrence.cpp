#include<iostream>

using namespace std;

int Square(int side)
{
    return(side * side);
}

int Circle(int radius)
{
    return(3.14 * radius * radius);
}

int Rectangle(int base, int width)
{
    return(base * width);
}

int main()
{
   int radius,base,width,side;
   cout<<"Enter side of a square:";
   cin>>side;
   cout<<"Enter radius of circle:";
   cin>>radius;
   cout<<"Enter base and height of Rectangle:";
   cin>>base>>width;
   cout<< "Area of square is :" <<Square(side) << "\n";
   cout<< "Area of circle is :" <<Circle(radius) << "\n";
   cout<< "Area of rectangle is :" <<Rectangle(base,width) << "\n";
}

