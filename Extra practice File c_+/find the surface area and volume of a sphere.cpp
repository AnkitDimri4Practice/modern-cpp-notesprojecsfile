#include<iostream>
using namespace std;
int main()
{
    int radius; // our input variable
    float s_area, volume, PI; // our output and other variables
    PI = (float)22/7; // using explicit conversion
    cout << "Please enter the radius of the sphere!" << endl; 
    cin >> radius; // taking in input 
    /* 
    now, we will write our expression 
    */
    s_area = 4 * PI * radius * radius; // finding total surface area of sphere 
    volume = (4/3) * PI  * radius * radius * radius; // finding volume of sphere
    // now we print the output 
    cout << "Surface Area: " << s_area << endl;
    cout << "Volume: " << volume << endl;
    return 0;
}