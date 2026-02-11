#include<iostream>
#include<math.h>
using namespace std;
// Write a program to find the roots of a quadratic equation. Implement exception handling to handle the case where a = 0;
int main(){
    int a,b,c,d;
    float x1,x2;
    cout << "given the following formula for a quadratic equation  a*(x^2)+b*(x)+c=0 " << "\n";
    cout << " Enter the value of a b and c" << "\n";
    try{
        cin >> a >> b >> c;
        if(a==0){
            throw 101;
        }
    } 
    catch(int e){
        cout << "cannot proceed with calculating the roots...." << "Quadratic equation's quadratic part is missing" << "\n";
        cout << " a cannot be zero.. Error Code" << e << "\n";
        return 0;
    }
    d = (b*b)-(4*a*c);
    if(d==0){
        cout << "Roots are real and equal " << "\n";
        x1 = -b/(2.0*a);
        x2 = x1;
        cout << "ROOTS are " << x1 << " and " << x2 << "\n";
    } else if(d>0){
        cout << "roots are real but unequal" << "\n";
        x1 = (-b + sqrt(d))/(2.0*a);
        x2 = (-b - sqrt(d))/(2.0*a);
        cout << "Roots are " << x1 << " and " << x2 << "\n";   
    } else {
        cout << "Roots are not real. They are imaginary" << "\n";
    }
    return 0;
}