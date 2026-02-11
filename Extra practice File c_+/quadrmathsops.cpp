#include<iostream>
using namespace std;
int main()
{
   int a, b, c;
   a = 6, b = -9;
   c = ((a + b)^2* (a)^2)/((a + b)^2 * (a^2)) * 2;
   // c = 3
   c++;
   c++;
   c++;
   c--;
   c--;
   b++;
   a++;
    cout << "Value of c is " << c << endl;
    cout << "Value of b is " << b << endl;
    cout << "Value of a is " << a << endl;


    return 0;
}