#include<iostream>
using namespace std;
class A
{
    Public:
    int i, j;
    void logic1();
    void logic2();
    void logic3();
    void input()
    {
        cout << "Choose your Alphabets";
        cout << "\n1.uppercase";
        cout << "\n2.lowercase";
        cout << "\n3.print number";
        }
        void logic()
        {
            cout << "\n enter your choice: ";
            cin >> i;

            switch(i)
            {
            case 1:
                cout << "\n You choose upper case alphabets: " << endl;
                logoc1();
                break;

            case 2:
                cout << "\n you choose lowercase alphabets: ";
                logic2();
                break;

            case 3:
                cout << "\n you choose number ";
                cout << "enetr your destination: ";
                cin >> j;
                logic3();
            break;
        }
    }
};
    void A::logic1()
    {
        for(int k=65;k<=90;k++)
        cout << (char)k;
    }
    void A::logic2()
    {
        for(int k=97;k<=122;k++)
        cout<<(char)k;
    }
    void A::logic3()
    {
        for(int k =1;k<=j;k++)
        cout<<k;
    }
int main()
{
    A x;
    x.input();
    x.logic();
    return 0;
}
    float a, b , c, x1, x2, discriminant, realPart, imaginaryPart;
    cout << " enter coefficient a, b and c: ";
    cin >> a >> b >> c;
    discriminant = b*b - 4*a*c;
    if (discriminant > 0) 
    {
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b + sqrt(discriminant)) / (2*a);
        cout << "roots are real and different: " << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else if(discriminant == 0) {
        cout << "ROOTS are real and same: " << endl'
        x1 = -b/(2*a);
        cout << " x1 = x2 = " << x1 << endl;
    }
     else {
        realPart = -b/(2*a);
        imaginaryPart = sqrt(-discriminant)/(2*a);
        cout << "Roots are complex and different!" << endl;
        cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
        cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
    }
    return 0;
}


    int n, i, val;
    cout << "in this program we will find 4^n: " << endl;
    cout << "Enter the value of exponent n: " << endl;
    cin >> n;
    i = 0; val = 1;
    while (i<n)
    {
        val *= 4;
        i++;
    }
    cout << " 4 raised to the power of : " << n << " is " << val << endl;
    

    int n, i, val;
    cout << "Enter the value of n: " << endl;
    cin >> n;
    i = 0; val = 0;
    while (i<n)
    {
        cout << val << endl;
        val += 2;
        i++;
    }
    
    int n, i = 0;
    char a;
    a = '*';
    cout << "PLease enter the value of n: " << endl;
    cin >> n;
    while (i < n)
    {
        cout << a;
        i++;
    }
    
    while (a<20)
    {
        cout << a << endl;
        a++;
    }
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    float area, PI, h, r;
    PI = (float)22/(float)7;
    int height = h;
    int radius = r;
    cout << "The area of the cone: " << endl;
    cout << "Please enter the height of cone: " << endl;
    cin >> h;
    cout << " pleaee enter the radius of cone :" <<  endl;
    cin >> r;
    area =  (float)1/(float)3*PI*r*r*h;
    cout << "Area: " << area << endl;
    return 0;
}
#include<iostream>
#include<cmath>
using namespace std;
void display(int n) {
    if(n>0 && n<20) {
        cout << n << " ";
        //display(pow((n), 2)+ n);
        display(pow((n), 4) - n);
    }
} 
int main(){
    int num = 2;
    display(2);
    return 0;
}
    int a=-1, b = 0, c;
    c = a+b;
    cout << a << " " << b << " ";
    cout << " " <<  c << " ";
    return 0; 
}

    int c, c2;
    float a, b, c1;// : Terminator / Punctuator / instruction:
    cout << "Please enter the value of a and b: " << endl;
    cin >> a >> b;
    c = a*b;
    c1 = a/b;
    c2 = a+b;
    cout << "the multiple of a & b " << " = " <<  c  << ";"<< endl;
    cout << "the ratio of a & b " << " = " << c1 << ";" << endl;
    cout << "the sum of a & b " << " = " << c2 << ";" << endl;
#include<iostream>
using namespace std;
void display1(int n) {
    if(n>-50 && n<100) {
        cout << n << " ";
        display1(n-2);
    }
}
void display2(int n2) {
    if(n2>0 && n2<51) {
        cout << n2 << endl;
        display2(n2-4);
    }
}
int main()
{
    int num = 1;
    
    display2(50);
    display1(1);
    return 0;
}
#include<iostream>
#include<cmath>
using namespace std;
int main() 
{
    int x1, x2, x3, x4, y1, y2, y3, y4;
    float a, b, c, d, s, tengential, slope, area;
    cout << "Please enter the 1st point (x and y respectively) : " << endl;
    cin >> x1 >> y1;
    cout << "Please enter the 2nd point (x and y respectively) : " << endl;
    cin >> x2 >> y2;
    cout << "Please enter the 3rd point (x and y respectively) : " << endl;
    cin >> x3 >> y3;
    cout << "Please enter the 4th point (x and y respectively) : " << endl;
    cin >> x4 >> y4;
        a = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
        b = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));
        c = sqrt(pow((x3 - x4), 2) + pow((y3 - y4), 2));
        d = sqrt(pow((x4 - x1), 2) + pow((y4 - y1), 2));
    s = (a+b+c+d)/2;
    area = sqrt(s*(s-a)*(s-b)*(s-c)*(s-d));
    tengential = (area)/2;
    slope = (tengential*(area/2));
    cout << "A: " << a << endl << "B: " << b << endl << "C: " << c << endl << "D: " << d << endl << "S: " << s << endl;
    cout << "Tengential: " << tengential << endl << "Area : " << area << endl << " Slope : " << slope << endl;
    if(!area) {
        cout << " points are collinear ! " << endl;
    } else {
        cout << "points are not collinear! " << endl;
    }
    return 0;
}
#include<iostream>
using namespace std;
void display(float n) {
	if(n>0 && n<700) {
		cout << n << " ";
		display(((n+1)*(n-1)) * (n) + 2);
	}
}
int main()
{
	int num = 1;
	display(1);
	return 0;
}
#include<iostream>
using namespace std;
int main()
{
    int quotient, dividend, divisor, remainder;
    cout << "Please enter the Divisor: " << endl;
    cin >> divisor;
    cout << "please enter the dividend: " << endl;
    cin >> dividend;
    quotient = dividend / divisor;
    remainder = dividend % divisor;
    cout << "Remainder: " << remainder << endl << "Quotient: " << quotient << endl; 
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    cout << "size of int" << sizeof(int) << " bytes  " << endl;
    cout << "size of float" << sizeof(float) << " bytes  " << endl;
    cout << "size of character " << sizeof(char) << "  bytes  " << endl;
    cout << "size of double " << sizeof(double) << " bytes  " << endl;
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    int a, b, temp;
    cout << "please enter the value of b & a: " << endl;
    cin >> b >> a;
    temp = a;
    a = b;
    b = temp;
    cout << "after swapping:" << endl << "b = " << b  << "  "  << "a = " << a << endl;
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    char a, b, c, d;
    cout << "enter your 1st charatcer : " << endl;
    cin >> a;
    cout << "enter your 2nd charatcer : " << endl;
    cin >> b;
    cout << "enter your 3rd  charatcer : " << endl;
    cin >> c;
    cout << "enter your 4th charatcer : " << endl;
    cin >> d;
    cout << "1ASCII value of: " << a << " is " << " " <<  int(a) << endl;
    cout << "2ASCII value of: " << b << " is " << " " << int(b) << endl;
    cout << "3ASCII value of: " << c << " is " << " " << int(c) << endl;
    cout << "4ASCII value of: " << d << " is " << " " << int(d) << endl;
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    double a, b , C;
    cout << "PLease enter the value of a & b: " << endl;
    cin >> a >> b;
    C = a*b;
    cout << "The product of Two no is:  " << C << endl;
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "please enter the integer:" << endl;
    cin >> n;
    // if (n % 2 == 0) {
    //     cout << n << "is even";
    // }else {
    //     cout << n << "is odd:";
    // }
    (n % 2 == 0) ? cout << n << " is even." : cout << n << "  is odd.";
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    char c;
    bool isLowercasevowel, isUppercasevowel;
    cout << "enter an alphabet: ";
    cin >> c;
    isUppercasevowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'); 
    isLowercasevowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    if(!isalpha(c)) {
        cout << "!Error, non-alphabetic character ";
    } else if(isLowercasevowel || isUppercasevowel) {
        cout << c << " is vowel!";
    } else {
        cout << c << " is consonant.";
    }
    return 0;
}  
#include<iostream>
using namespace std;
int main()
{
    float num1, num2, num3;
    cout << "Please enter the three number: = ";
    cin >> num1 >> num2 >> num3;
    if((num1>=num2 && num1>=num3))
        cout << "Largest number! " << num1;
    if((num2>=num1 && num2>=num3))
        cout << "Largest number." << num2;
    if((num3>=num1 && num3>=num2))
        cout << "Largest number." << num3;
        return 0;
} 




















