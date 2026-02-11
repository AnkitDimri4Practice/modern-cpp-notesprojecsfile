#include<iostream>
#include<cmath>
using namespace std;
int main() 
{
    float a , b, c;
    /*char op;
    cout << "Enter the opeartors : " << endl;
    cin >> op;*/
    cout << "Enter the value of a and b : " << endl;
    cin >> b >> a;
    c = (a/b)*(a+b)+(a+b)-(a-b);
    cout << c << endl;

    
    return 0;

}