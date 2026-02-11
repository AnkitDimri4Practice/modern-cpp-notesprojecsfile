#include<iostream>
using namespace std;
int main()
{
    int radius, area;
    float circumference, PI, s_area;
    PI = (float)22/(float)7; 
    cout << "Please enter the radius of the Semi_circle: " << endl;
    cin >> radius;
    s_area = (float)1/(float)2 * PI * radius * radius;
    circumference = (PI * radius + 2 * radius);
    cout << " Area of Semi cicle: " << s_area << endl;
    cout << " circumference: " << circumference << endl;
    return 0;
}