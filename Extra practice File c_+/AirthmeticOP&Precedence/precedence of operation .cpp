#include <iostream>
using namespace std;
int main()
{
    int f;
    float a, b, c, d, e;
    a = 7.908, b = 2.896;
    c = (a + b) * ( a - b) * (a + b) * a * a;
    d = c /(a); 
    e = d / c * (a);
    f = (e*4)+6;
       cout << "Value of c is: " << c << endl;
       cout << "Value of d is: " << d << endl;
       cout << "Value of e is: " << e << endl;
       cout << "Value of f is: " << f << endl;

    
    return 0;
}