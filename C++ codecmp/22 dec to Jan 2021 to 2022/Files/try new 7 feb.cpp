#include<iostream>
#include<math.h>
using namespace std;
float addFun(float, float);
float subFun(float, float);
float mulFun(float, float);
float divFun(float, float);
int powFun(int, int);
int main()
{
    float n1,n2,Result;
    int choice;
    while(choice!=6){
        cout << "1. Addicition \n";
        cout << "2. Substraction \n";
        cout << "3. Multiplication \n";
        cout << "4. Division \n";
        cout << "5. Power \n";
        cout << "6. Exit \n";
        cout << " Enter your choice (1-6)";
        cin >> choice;
        if(choice >= 1 && choice<=5){
            cout << "Enter any two no = \n";
            cin >> n1 >> n2;
        } switch(choice){
            case 1:
                Result = addFun(n1,n2);
                cout << "\n Result = " << Result;
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
                break;
            default:
                cout << "\n Wrong choice!" << "\n";
                break;
        } cout << "\n ---------------------------\n";
    }cout << "\n";
    return 0;
} float addFun(float a, float b){
    return(a+b);
} float subFun(float a, float b){
    return(a-b);
} float mulFun(float a, float b){
    return(a*b);
} float divFun(float a, float b){
    return(a/b);
} int powFun(int a, int b){
    return(pow(a,b));
}