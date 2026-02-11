1.  Hello world: handling IO

        #include<stdio.h>
        int main(){
            printf("Hello World in C"); printf to print to console 
            printf("\n");  Console is stdout file ... printf is a variadic function...\n new line 
            return 0; \n is escaped newline character 
        } 
#include<iostream>
int main(){
    std::cout<<"HEllo World in C++"; Operator << is a binary stream to console 
    std::cout << std::endl; operator << is binary operator ... std::endl is stream manipulator (newline) functor
    return 0;
}

2.    Add two numbers and handling IO
#include<stdio.h>
int main(){
    int a,b;
    printf ("Input two numbers : ");
    scanf("%d%d",&a, &b); // formating(%d) needed for variables    
    int sum = a+b; // Declaration of sum 
    printf("Sum of %d and %d",a,b);
    printf(" is : %d", sum);
    return 0;
}

#include<iostream>
using namespace std;
float D(float n, float m){
    cout << "enter two numbers : "; 
    cin >> m >> n;
    if(n<0 && m<0)
    return 1;
    else 
    cout << "Sum : ";
    return m+n;
}
int main(){
    float n,m,val=6;cout<< D(m,n) << "\n";
    return 0; 
}
//Sum 
#include<iostream>
using namespace std;
int Sum(int a,int b){
    cout << "\n Enter the numbers : ";
    cin >> a >> b;
    int sum{a+b};
    cout << "\nThe a and b are :" << a << "," << b;
    cout << "\nSum : " << sum << "\n";
}
int main(){
    int a,b;Sum(a,b);return 0;
}
3.    Square Root : math Library 
#include<stdio.h>
#include<math.h>
int main(){
    double x, sqrt_X;
    printf("Input the number : ");
    scanf("%lf",&x); //Formatting (%lf) needed for variables 
    sqrt_X = sqrt(x);
    printf("sq. Root of %lf is :", x); 
    printf(" %lf\n", sqrt_X); //default precision in print is 6 
    return 0;
}

#include<iostream>
#include<cmath> //math header is cmath (C standard library in c++)
using namespace std; 
int main(){
    double x;
    cout << "Input the number : ";
    cin>>x;
    double sqrt_x=sqrt(x);
    cout << "sq. Root of " << x << " is : " << sqrt_x << "\n";
    return 0;  // default precision in print is 5.(deifferent)
}

#include<iostream>
#include<cmath>
using namespace std;
double Sqrt(double x){
    double sqrt_x;
    cout <<"enter the number : ";
    cin >> x;
    sqrt_x=sqrt(x);
    cout << "The square root of the " << x << " is : " << sqrt_x << "\n";
}
int main(){
    double x;cout << "Square Root : "<<Sqrt(x);
    return 0;
}
// Power function 
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double Power_x,x,y;
    cout << "Enter the base value : ";cin >> x;
    cout << "Enter the power : ";cin >> y;
    Power_x = pow(x,y);
    cout << "SQrt of No. " << Power_x << "\n";
    return 0;
}
4. C and C++ standard Library Headers & std
        - std:: for every standard library name .. all namse are global
    - Headers Conventions
        - [Prefix c, no .h]
        - C std. library header is used in C++ with prefix 'c' and without the .h. These are in std namespace
        - #include<cmath> // In c it's <math.h>
        - std::sqrt(5.0);
            - Using .h with C++ header files, like iostream.h, is disatrous. These are deprecated. It is dangerous, yet true, that some compiler do not error out on such use. Excerise caution.
5. Sum of n Numbers : Variables Declaration

#include<stdio.h>
int main(){
    int n,i,sum =0; // i must be declared at the beginning c89
    printf("Enter the limit : ");
    scanf("%d",&n);
    for(i=0; i<=n; i++)
        sum = sum + i;
    printf("The sum of %d", n);
    printf(" numbers is : %d", sum);
}

#include<iostream>
using namespace std;
int main(){
    int n,sum{0};
    cout << "Enter the limit : ";
    cin >> n;
    for(int i{0};i<=n; i++){
        sum = sum +i;
    }
    cout << "\nThe sum of " << n << " numbers is : " << sum << "\n";
    return 0;
}
// i declared locally in for loop. allowed from c99 too
6. Using Boolean in C and C++
#include<stdio.h>
#define TRUE 1
#define FALSE 0
int main(){
    int x=TRUE;
    printf("Bool is %d",x);
}
#include<stdio.h>
#include<stdbool.h>
int main(){
    bool x=true;
    printf("bool is %d",x);
}
- using int and #define for bool
- only way to have bool in K&R

- stdbool.h include for bool
- _Bool type & macros in c89 expanding: 
    bool to _Bool
    true to 1
    false to 0
    __bool_true_false_are_defined to 1

for C++
#include<iostream>
using namespace std;
int main(){
    bool x=true;
    cout << " bool is : " << x << "\n";
}
    - no additional headers required
    - bool is a built-in type
    - true is a literals
    - false is a literals
7. Module summary 
