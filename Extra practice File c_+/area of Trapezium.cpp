#include<iostream>
using namespace std;
int main()
{
    int area, h;
    float a , b;
    cout << "Please enter the value of a and b Trapezium: " << endl;
    cin >> a >> b;
    cout << "please enter the value of h: " << endl;
    cin >> h;
    area = (((float)1/(float)2) * h * ( a + b));
    cout << "Area of the Trapezium: " << area << endl;
    return 0;
} 