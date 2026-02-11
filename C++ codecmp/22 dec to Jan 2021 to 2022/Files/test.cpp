// #include<iostream>
// #include<bits/stdc++.h>
// #include<cmath>
// using namespace std;
// void display(inendl {
//     iendl200000){
//         cout <endl<< "  ";
//         displaendl1));
//     }
// }
// int main()
// {
//     int num = 1;
//     display(1); 
//     cout << " " << endl;
//     int i= 0, n1, val = 0;
//     int x = 3;
//     char c;
//     c = 'A';
//     cout << "enter the value oendl " << endl;
//     cin >> n1;
//     while (x<200) 
//     {
//         if(i<200) 
//         {
//             cout <<  "  " << c << "  " <<  val << "   ";
//             val += 20;
//             i++;
//         }
//         cout << "   " << x << " ";
//         x++;
//         x++;
//         x++;
//         x++;
//         x++;
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main() 
// {
//     int i;
//     float scores[6];
//     cout << endlplease input your array : " << endl;
//     for(i=0;i<6;i++){
//         cin >> scores[i];
//     } 
//     cout << "the array you input is as follow! " << endl;
//     for(i=0;i<6;i++) {
//         cout << scores[i] << "\t";
//     }
//     return 0;
// }

// // GEOMETRIC SERIES SUMMATION IN C++
// #include<bits/stdc++.h>
// using namespace std;
// int main(void)
// {
//     int iBase, iExponent, iSum;
//     cout << "enter the value of the base: " << endl;
//     cin >> iBase;
//     cout << "Enter the value of exponent: " << endl;
//     cin >> iExponent;
//     iSum = 1;
//     for(int i = 0; i < iExponent; i++) {
//         iSum *= iBase; 
//     }
//     cout << iBase << endl;
//     return 0;
// }
// #include<iostream>
// using namespace std;
// int main(void){
// 	int iFirstTerm;
// 	int iCommonRatio = 3;
// 	int iNumberOfTerms = 6;
// 	int iSum = 0;
// 	int i, j;
// 	for(i = 0; i <= iNumberOfTerms; i++){
// 		iFirstTerm = 1;
// 		for(j = 0; j <= i; j++){
// 			iFirstTerm *= iCommonRatio;
// 			cout << iFirstTerm << " ";
// 		}
// 		iSum += iFirstTerm;
// 		cout << '[' << iSum << ']' << endl;
// 	}
// 	cout << "Sum: " << iSum << endl;
// 	return 0;
// }
// #include <iostream>
// using namespace std;
// int main(void){
// 	int iNumTerms, iConstantRatio, iIteration;
// 	int iSum = 0;
//     cout << "Please enter the constant ratio: "; 	cin >> iConstantRatio;
// 	cout << "Please enter the number of terms: "; 	cin >> iNumTerms;
// 	for(iIteration = 0; iIteration <= iNumTerms; iIteration++){
// 		iSum = iSum * iConstantRatio + 1;
// 	}
// 	cout << "The sum is " << iSum << endl;
// 	return 0;
// }
// #include<iostream>
// using namespace std;
// int main(void){
// 	int iSum = 0;
// 	int i, j, iFirstTerm;
// 	int iNumTerms, iConstantRatio;
// 	cout << "Please enter the constant ratio: "; 	cin >> iConstantRatio;
// 	cout << "Please enter the number of terms: "; 	 cin >> iNumTerms;
// 	for(i = 0; i <= iNumTerms; i++){
// 		iFirstTerm = 1;
// 		for(j = 0; j < i; j++){
// 			iFirstTerm *= iConstantRatio;
//             cout << iFirstTerm << " ";
// 		}
// 		iSum += iFirstTerm;
// 		cout << '[' << iSum << ']' << endl;
// 	}
// 	cout << endl << "Sum = " << iSum << endl;
// 	return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int a, b, c, d;
//     cout << "enter the 1st nummber of the AP. ";    cin >> a;
//     cout << "enter the common difference: ";    cin >> b;
//     cout << " Enter the last terms of the AP: ";    cin >> c;
//     d = a;
//     z:
//     if(a<=c) {
//         cout << a << "\t";
//         a = a+b;
//         goto z;
//     } else {
//         if(d<c) {
//             cout << "its not valid";
//         }
//     }
//     return 0;
// }
// #include<bits/stdc++.h>
// #include<iostream>
// #include<cmath>
// using namsespace std;
// int main()
// {
//     int a, Dendl L;
//     float s;
//     cout << " please enter the first term of AP: " << endl;
//     cin >> a;
//     cout << "PLease enter the common difference : " << endl;
//     cin >> D;
//     cout << "Please enter the no of terms : " << endl;    
//     cin >endl
//     L = (aendl1)*D);
//     cout << "nth terms : = " << L << endl;
//     s = ((0.endla)+(0.endlL));
//     cout << "The Sum of AP = " << s << endl;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     float a, b, c, x1, x2, Discriminant, ImaginaryPart, RealPart;
//     cout << "please enter the value of a b and c respectively: " << endl;
//     cin >> a >> b >> c;
//     Discriminant = (b*b-4*a*c);
//     if(Discriminant > 0) {
//         x1 = (-b + sqrt(Discriminant))/(2*a);
//         x2 = (-b - sqrt(Discriminant))/(2*a);
//         cout << " Roots are real and different." << endl;
//         cout << "x1 = " << x1 << endl;
//         cout << "x2 = " << x2 << endl;
//     } else if(Discriminant == 0) {
//         cout << "Roots are real and same." << endl;
//         x1 = -b/(2*a);
//         cout << "x1 = x2 = " << x1 << endl;
//     } else {
//             RealPart = -b/(2*a);
//             ImaginaryPart = sqrt(-Discriminant)/(2*a);
//             cout << " x1 = " << RealPart << "+" << ImaginaryPart << endl;
//             cout << "x2 = " << RealPart << "-" << ImaginaryPart << endl;
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x1,x2,x3,x4,y1,y2,y3,y4;
    float a,c,b,d,slope,Tengential,area,S;
    cout << "please enter the 1st points of (x and y respectively)" << "\n";
    cin >> x1 >> y1;
    cout << "please enter the 1st points of (x and y respectively)" << "\n";
    cin >> x2 >> y2;
    cout << "please enter the 1st points of (x and y respectively)" << "\n";
    cin >> x3 >> y3;
    cout << "please enter the 1st points of (x and y respectively)" << "\n";
    cin >> x4 >> y4;
    a = sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
    b = sqrt(pow((x2-x3), 2) + pow((y2-y3), 2));
    c = sqrt(pow((x3-x4), 2) + pow((y3-y4), 2));
    d = sqrt(pow((x4-x1), 2) + pow((y4-y1), 2));
    S = (a+b+c+d)/(2.0);
    cout << "A: " << a << "\n" << "B: " << b << "\n" << "C: " << c << "\n" << "D: " << d << "\n" << "S: " << S << "\n";
    area = sqrt(S*(S-a)*(S-b)*(S-c)*(S-d));
    cout << "Area = " << area << "\n";
    slope = area/(2.0);
    cout << "Slope = " << slope << "\n";
    Tengential = (slope*area)/(2.0);
    cout << "Tengential = " << Tengential << "\n";
    if(!area){
        cout << "points are collinear!" << "\n";
    } else {
        cout << "points are not collinear" << "\n";
    }
    return 0;
}
