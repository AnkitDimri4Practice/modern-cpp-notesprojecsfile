#include <iostream>
using namespace std;

int main()
{
    int height, base;
    float area;

    cout << "Please enter the height of the triangle!" << endl;
    cin >> height;
    cout << "Please enter the base of the triangle!" << endl;
    cin >> base;
    area = (float)height *(float) base / 2;
    cout << "Area of triangle come out to be as: " << area << endl;
    return 0;
}  
