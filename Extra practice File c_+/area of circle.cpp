#include<iostream>
using namespace std;
int main()
{
   int radius;
   float c_area, circumference, diameter, PI;
   PI = (float)22/(float)7;
   cout << "Please enter the radius of the circle!" << endl;
   cin >> radius;
   c_area = PI * radius * radius;
   diameter = 2 * radius;
   circumference = 2 * PI * radius;
   cout << " Area of circle: " << c_area << endl;
   cout << " circumference: " << circumference << endl;
   cout << " Diameter: " << diameter << endl;
   return 0;
}