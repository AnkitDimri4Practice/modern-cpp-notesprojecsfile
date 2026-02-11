#include<iostream>
#include<cmath>
using namespace std;
float addFun(float, float);
float subFun(float, float);
float mulFun(float, float);
float divFun(float, float);
int powFun(int, int);
int main()
{
    float n1,n2, Result;
    int choice;
    while(choice!=6){
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Divison\n";
        cout << "5. Power\n";
        cout << "6. Exit\n\n";
        cout << "Enter your choice(1-6)";
        cin >> choice;
        if(choice>=1 && choice<=5){
            cout << "\n Enter any two numbers = ";
            cin >> n1 >> n2;
        } switch(choice){
            case 1:
                Result = addFun(n1,n2);
                cout << "\nResult = " << Result;
                break;
            case 2:
                Result = subFun(n1,n2);
                cout << "\n Result = " << Result;
                break;
            case 3:
                Result = mulFun(n1,n2);
                cout << "\n Result = " << Result;
                break;
            case 4:
                Result = divFun(n1,n2);
                cout << "\n Result = " << Result;
                break;
            case 5:
                Result = powFun(n1,n2);
                cout << "\n Result = " << Result;
                break;
            case 6:
                return 0;
            default:
                cout << "\nWrong Choice!";
                break;
        }cout << "\n ------------------------------\n\n";
    }cout << "\n";
    return 0;
}float addFun(float a, float b){
    return (a+b);
}float subFun(float a, float b){
    return (a-b);
}float mulFun(float a, float b){
    return (a*b);
}float divFun(float a, float b){
    return (a/b);
}int powFun(int a, int b){
    return (pow(a,b));
}