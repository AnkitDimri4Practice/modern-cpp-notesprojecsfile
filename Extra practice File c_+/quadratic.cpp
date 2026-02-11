#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    float a, b, c, x1, x2, RealPart, ImaginaryPart, Discriminant;
    cout << " Please enter the value of a b and c respectively: " << endl;
    cin >> a >> b >> c;
 Discriminant = (b*b - 4*a*c);
    if(Discriminant>0) {
        x1 = (-b + sqrt(Discriminant))/(2*a);
        x2 = (-b - sqrt(Discriminant))/(2*a);
        cout << "Roots are real and different." << endl;
        cout << " x1 = " << x1 << endl;
        cout << " x2 = " << x2 << endl;
    } else if(Discriminant == 0) {
        cout << " Roots are real and same. " << endl;
        x1 = -b/(2*a);
        cout << "x1 = x2 = " << x1 << endl;
    } else {
        RealPart = -b/(2*a);
        ImaginaryPart = sqrt(-Discriminant)/(2*a);
        cout << " x1 = " << RealPart << "+" << ImaginaryPart << endl;
        cout << " x2 = " << RealPart << "-" << ImaginaryPart << endl;
    }
    return 0;
}