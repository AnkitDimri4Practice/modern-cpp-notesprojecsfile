#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double x = 0.439203, result;
    result = sin(x);
    cout << "sin(x) = " << result << endl;
    double xDegrees = 90.0;
    x = xDegrees*3.14159/180;
    result = sin(x);
    cout << "sin(x) = " << result << endl;
    return 0;
     
}