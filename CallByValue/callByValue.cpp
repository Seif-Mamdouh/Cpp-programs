#include <iostream>

using namespace std;

float Circle();
int Square();
int Rectangle();

int main()
{

    int choice;
            do {
            cout << "Choices:" << endl;
            cout << " 1. Circle\n 2. Square\n 3. Rectangle" << endl;
            cout << "Enter your shape to calculate the Area of it: ";
            cin>>choice;

            switch(choice) {
            case 1:
            cout<<"The Area of the Circle is :"<<Circle()<<endl;
            break;
            case 2:
            cout<<"The Area of the Square is :"<<Square()<<endl;
            break;
            case 3: 
            cout<<"The Area of the Rectangle is :"<<Rectangle()<<endl;
            }


            }

    while(true);
    return 0;

}

    int Square() {
        int baseLength;
        cout<<"Enter the base length of Square :";
        cin>>baseLength;
        return (baseLength*baseLength);
    }

    int Rectangle() {
        int baseLength,baseHeight;
        cout<<"Enter the base length of Rectangle :";
        cin>>baseLength;
        cout<<"Enter the base height of Rectangle :";
        cin>>baseHeight;
        return (baseLength*baseHeight);
    }


    float Circle() {

        float choice;
        float radius,diameter;

        cout << " Enter 1 to input radius or 2 to input diameter:";
        cin>>choice;
            if(choice==1) {
            cout<<"Enter the radius of circle :";
            cin>>radius;

            return (3.14f*radius*radius);
            }
            else {
            cout<<"Enter the diameter of circle :";
            cin>>diameter;
            return (1/4)*(3.14f*diameter*diameter);
            }
        
    }