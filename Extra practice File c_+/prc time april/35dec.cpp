#include<iostream>
using namespace std;
int main()
{
    float n1,n2;
    char OP;
    cout<<"Enter the 1st value: ";
    cin >> n1;
    cout<<"Enter the second value: ";
    cin >> n2;
    cout<<"Please enter the Operator: ";
    cin >> OP;
    if(OP=='+'){
        cout<<n1+n2<<"\n";
    }
    else if(OP=='/'){
        cout<<n1/n2<<"\n";
    }
    else if(OP=='*'){
        cout<<n1*n2<<"\n";
    }
    else if(OP=='-'){
        cout<<n1-n2<<"\n";
    }
    else{
        cout<<"Invalid Input"<<"\n";
    }
    cout << "-----Thank You-------" << "\n";
    return 0;
}
// Calculator 
#include<bits/stdc++.h>
using namespace  std;
int main()
{
    char OP;
    float n1,n2;
    cout << "please enter the opeartor: " << "\n";
    cin >> OP;
    cout << "please enter the operands: " << "\n";
    cin >> n1 >> n2;
    switch (OP)
    {
    case '+':
        cout << n1+n2;
        break;
    
    case '-':
        cout << n1-n2;
        break;
    case '*':
        cout << n1*n2;
        break;
    case '/':
        cout << n1/n2;
        break;
    
    default:
        cout << "OPerator is not valid!" << "\n";
        break;
    }
    return 0;
}
// POwer function
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, n,base,val=1;
    cout << "please enter the exponent of n: ";
    cin >> base >> n;
    while(i<n){
        cout << val << " ";
        val *=base;
        i++;
    }
    cout << " x raised to the power of " << n << " is " << val << "\n";
    return 0; 
}
2.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ex,base,val=1;
    cout << "please enter the exponent of n: ";
    cin >> base >> ex;
    while(ex!=0){
        cout << val << " ";
        val *=base;
        --ex;
    }
    cout << " x raised to the power of " << ex << " is " << val << "\n";
    return 0; 
}
// number series:-
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,i,n;
    cout << "please enter the number of terms: ";
    cin >> n;
    a = -1;
    cout << a << " ";
    for(i = 1; i<=n; i++) {
        
        cout << (i*i)-i << " ";
    }
    return 0;
}

// ptint array :- 
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    float score[6];
    cout << "please input the array: " << "\n";
    for(i=0; i<6; i++){
        cin >> score[i];
    }
    cout << "the array you input is as follow: " << "\n";
    for(i=0;i<6;i++){
        cout << score[i] << "\t";
    }
    return 0;
}

// n order of matrix : -
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, n;
    cout << "enter the order of the matrix: " << "\n";
    cin >> n;
    int arr[n][n], sol[n][n];
    cout << "enter all the elememnts of the matrix: " << "\n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    cout << "calculating the transpose...." << "\n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            sol[i][j] = arr[j][i];
        }
    }
    cout << "the Matrix is as follow: " << "\n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout << sol[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}
// number series : - 
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    a = 0;
    while(a<10){
        cout << a << " ";
        a++;
    }
    return 0;
}

// * print n times :
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i= 0, n;
    char c;
    cout << "please enter the value of n : " << "\n";
    cin >> n;
    c = '*';
    while(i<n){
        cout << c << " ";
        i++;
    }
    return 0;
}


//sum Series
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, n, val;
    cout << "please enter the value of n : " << "\n";
    cin >> n;
    i = 0, val = 0;
    while(i<n){
        cout << val << " ";
        val += 5;
        i++;
    }
    return 0;
}

//Gemomatric prograssion:
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int isum = 0;
    int i, j, iFirstTerm, iConstantRatio, iNumTerms;
    cout << "please enter the Constant Ratio:" << "\n";
    cin >> iConstantRatio;
    cout << "please enter the number of terms: " << "\n";
    cin >> iNumTerms;
    for(i=0;i<=iNumTerms;i++){
        iFirstTerm = 1;
        for(j=0;j<i;j++){
            iFirstTerm *= iConstantRatio;
            cout << iFirstTerm << " ";
        }
        isum += iFirstTerm;
        cout << "[" << isum << "]" << "\n";
    } 
    cout << "\n" << "Sum = " << isum << "\\n";
    return 0;
}



// Sum and average :
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, n, val, sum = 0;
    float average;
    cout << "how many numbers u want to enter : " << "\n";
    cin >> n;
    i = 0, val = 1;
    for(i=1;i<n; i++){
        for(i=0; i<n; i++){
            cout << "\n" << "enter the numbers:: " << "\n";
            cin >> val;
            sum += val;
        }
        
    }
    average = (float)sum/(float)n;
        cout << "\n" << "Sum of " << n << "Numbers is :: " << sum << "\n";
        cout << "Average of " << n << "Numbers is :: " << average << "\n";

    return 0;
}

//in this program we will find x^n
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, n, val, sum = 0;
    cout << "in this program we will find x^n " << "\n";
    cout << "please enter the value of n : " << "\n";
    cin >> n;
    i = 0, val = 1;
    while(i<n){
        cout << val << " ";
        val *= 3;
        i++;
    }
    cout << "x raised to the power of " << n << " is " << val << "\n";
    return 0;
}

// write a program to check if an input matrix is symmetric or skewed symmetric or neither: 
#include<bits/stdc++.h>
using namespace std;
int main()
{    //program to check if a  matrix is a) symmetric, oor b) skewed symmetric or nither.
    int n; // order of my matrix..
    cout << "only a square matrix has the property to be symmetric or skewed - symmetric. " << "\n";
    cout << "please enter the squre matix order (n), such that the order would be n*n: " << "\n";
    cin >> n;
    int arr_a[n][n], arr_temp[n][n];
    cout << "please input all the elements of the array : " << "\n";
    for(int i = 0; i<n; i++){
        for(int j=0;j<n;j++){
            cin >> arr_a[i][j];
        }
    }
    cout << "calculating the transpose....." << "\n"; // finding transpose to array:: 
    for(int i = 0; i<n; i++){
        for(int j=0;j<n;j++){
            arr_temp[i][j] = arr_a[j][i];
        }
    }
    cout << "Checking if transpose is equal to input array (Checking for symmetry)" << "\n";
    bool is_symmetric = true;
    for(int i = 0; i<n; i++){
        for(int j=0;j<n;j++){
            if(arr_a[i][j] == arr_temp[i][j]) {
                continue;
            } else {
                is_symmetric = false;
                break;
            }
        }
        if(!is_symmetric){
            break;
        }
    }
    if(is_symmetric) {
        cout << "Input array is symmetric" << "\n";
    } else {
        cout << "input array is not symmetric" << "\n";
    }
    cout << "\n" << "now checking if it is skewed symmetric..." << "\n";
    bool is_skewed_symmetric = true;
    for(int i = 0; i<n; i++){
        for(int j=0;j<n;j++){
            if (arr_a[i][j] == -arr_temp[i][j]) {
                continue;
            } else {
                is_skewed_symmetric = false;
                break;
            }
        } 
        if(!is_skewed_symmetric){
            break;
        }
    }
    if (is_skewed_symmetric){
        cout << "Input matrix is skewed symmetric" << "\n";
    } else {
        cout << "input matrix is not skewed symmetric" << "\n";
    }
    return 0;
}

//Greatest Common Divisor//
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
   if (a == 0 || b == 0)
   return 0;
   else if (a == b)
   return a;
   else if (a > b)
   return gcd(a-b, b);
   else return gcd(a, b-a);
}
int main() {
   int a = 105, b =30;
   cout<<"GCD of "<< a <<" and "<< b <<" is "<< gcd(a, b);
   return 0;
}


//Greatest Common Divisor//
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n1,n2,GCD;
    cout << "Find the Greatest Common Divisor of two numbers - " << "\n";
    cout << "Please Input the first number: " << "\n";   cin >> n1;
    cout << " Input the second number: " << "\n";    cin >> n2;
    for (i=1; i<=n1 && i<=n2; i++) {
        if (n1 % i == 0 && n2 % i == 0) {
            GCD = i;
        }
    }
    cout << " The Greatest Common Divisor is :: " << GCD << "\n";
    return 0;
}

//Perfect number between 1-500//
#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int i, a,Sum = 0;
    i = 1, a = 1;
    cout << "\n" << "The Perfect numbers between 1 to 500 are :: ";
  while (i<=500) {
    while (a<=500) {
      if (a<i) {
        if (i%a ==0)
          Sum = Sum + a;
      }
      a++;
    }
    if(Sum == i) {
      cout << i << " ";
    }
    i++;
    a = 1, Sum = 0;
  }
  return 0;
}

//natural numbers series//
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, n;
    cout << "\n" << "The Natural numbers are: ";
    for(i=1;i<=10; i++){
        cout << i << " ";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
void PascalTringle(int n){
    for(int i = 1; i<=n; i++){
        int coef = 1;
        for(int k = n-i; k>0; k--){
            cout << " ";
        }
        for(int j = 1; j<=i; j++){
            cout << coef << " ";
            coef = (coef*(i-j)/j);        
        }
        cout << "\n";
    }
}
int main()
{
    int n;
    cout << "please enter the levels u want to print: ";
    cin >> n;
    PascalTringle(n);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
void A(int n){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            cout << "*";
        }
        cout << "\n";
    }
}
void B(int n){
    for(int i = n; i>=1; i--){
        for(int j = i; j>0; j--){
            cout << "*";
        }
        cout << "\n";
    }
}
    
void C(int n){
    for(int i = 1; i<=n; i++){
        for(int k = n-i; k>0;k--){
            cout << " ";
        }
        for(int j = 1; j<=i; j++){
            cout << "*";
        }
        cout << "\n";
    }
}
    
void D(int n){
    for(int i = n; i>=1; i--){
        for(int k = n-i; k>0;k--){
            cout << " ";
        }
        for(int j = i; j>0; j--){
            cout << "*";
        }
        cout << "\n";
    }
}
    
int main()
{
    int n;
    cout << "please enter the levels of the pattern: ";
    cin >> n;
    A(n);
    B(n);
    C(n);
    D(n);
    return 0;
}
//HollowDiamondPattern
#include<bits/stdc++.h>
using namespace std;
void HDP(int n){
    for(int i = 1; i<n; i++){
        for(int j = i; j<n; j++){
            cout << " ";
        }
        for(int j=1;j<i;j++){
            if(j==1){
                cout << "* ";
            } else {
                cout << " ";
            }
        }
        for(int j =1;j<=i;j++)
        {
            if(j==i){
                cout << "* ";
            } else {
                cout << " ";
            }                
        }
        cout << "\n";
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<i;j++){
            cout << " ";
        }
        for(int j = i; j<n;j++){
            if(j==i){
                cout << "* ";
            } else {
                cout << " ";
            }
        }
        for(int j = i;j<=n;j++){
             if(j==n){
                cout << "* ";
            } else {
                cout << " ";
            }
        } 
        cout << "\n";           
    }
}
int main()
{
    int n;
    cout << "please enter the level of pattern: ";
    cin >> n;
    HDP(n);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
void D(int n){
    for(int i=1;i<=n;i++){
        int coef = 1;
        for(int k = n-i; k>0;k--){
            cout << " ";
        }
        for(int j = 1; j<=i;j++){
            cout << coef << " ";
            coef = (coef*(i-j)/j);
        }
        cout << "\n";
    }
}
void E(int n){
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= n;j++){
            if(i==n/2+1 || j==n/2+1){
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << "\n";
    }
}
void F(int n){
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= n;j++){
            if(i==j || j==n-i+1){
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << "\n";
    }
}
void G(int n){
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= n;j++){
            if(i==1 || j==1 || j==n || i==n){
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << "\n";
    }
}
void H(int n){
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= n;j++){
            if(i==j){
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << "\n";
    }
}
void HollowDecreasingTriangle(int n){
    for(int i = 1; i<= n; i++){
        for(int j = i; j<= n;j++){
            if(i==1 || j==i || j==n){
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << "\n";
    }
}
void HollowHillTriangle(int n){
    int i;
    for(int j = 1; j<i; j++){
        if(i==n || j==1){
            cout << "* ";
        } else {
            cout << " ";
        }
        for(int j = 1; j<=i; j++){
            if(i==n || j==i){
                cout << "* ";
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

int main()
{
    int n;
    cout << "please enter the levels of the pattern: ";
    cin >> n;
    D(n);
    E(n);
    F(n);
    G(n);
    H(n);
    HollowDecreasingTriangle(n);
    HollowHillTriangle(n);
    return 0;
}