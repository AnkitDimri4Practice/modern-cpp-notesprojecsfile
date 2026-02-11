#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    /*int x1, x2, x3, y1, y2, y3;
    float a, b, c, s, area;
    cout << " enter value of first pointa (x and y respecively): " << endl;
    cin >> x1 >> y1;
     cout << " enter value of 2nd pointa (x and y respecively): " << endl;
    cin >> x2 >> y2;
     cout << " enter value of 3rd pointa (x and y respecively): " << endl;
    cin >> x3 >> y3;
    a = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    b = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));
    c = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
    s = (a+b+c)/2;
    cout << "A: " << a << endl << "B: " << b << endl << "C: " << c << endl << "S: " << s << endl;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    cout << "Area: " << area << endl;
    if (!area) {
        cout << "points are collinear!" << endl;
    } else {
        cout << "Points are not collinear!" << endl;
    }
    return 0;
}*/
    int gpa;
    cout << "Please enter ur Gpa: " << endl;
    cin >> gpa;
    switch (gpa)
    {
    case 0:
        cout << "terrible" << endl;
        break;
    case 1:
        cout << "satisfactory" << endl;
        break;
    case 2:
        cout << "average" << endl;
        break;
    case 3:
        cout << "good" << endl;
        break;
    case 4:
        cout << "Brilliant!" << endl;
        break;
    default:
        cout << "invalid GPA entered " << endl;
        break;
    }
}