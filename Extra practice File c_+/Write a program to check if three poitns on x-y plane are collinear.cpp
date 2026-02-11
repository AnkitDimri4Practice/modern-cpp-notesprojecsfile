#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int x1, x2, x3, y1, y2, y3;
    float a, b, c, s, area;
    // x1, y1 = 1 
    // x2, y2 = 2
    // x3, y3 = 3
    // 1-2 = a 
    // 2-3 = b
    // 3-1 = c
    cout << " Enter vlaues of first point (x and y respectively):" << endl;
    cin >> x1 >> y1;
    cout << " Enter values of second point ( x and y respectively):" << endl;
    cin >> x2 >> y2;
    cout << "Enter values of third point (x and y respectively):" << endl;
    cin >> x3 >> y3;
    // sqrt
    a = sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
    b = sqrt(pow((x2-x3), 2) + pow((y2-y3), 2));
    c = sqrt(pow((x3-x1), 2) + pow((y3-y1), 2));
    s = (a + b + c)/2;
    cout << "A: " << a << endl << "B: " << b << endl << "C: " << c << endl << "S: " << s << endl;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    cout << "Area: " << area << endl;
    if (!area) {
            cout << "Points are collinear" << endl;
    } else {
            cout << "Points are not collinear" << endl;  
    }
    return 0;
}