/*
1.How recursion works, Generalization, Recursion and stack
2.Recurrence relation and time complexity
3.Code recursion
4.Static and global variables in recursion and code
5.Tail recursion
6.Head recursion
7.Tree recursion
8.Indirect recursion
9.Nested recursion
10.Sum of natural numbers using recursion
11.Factorial using recursion
12.Power using recursion
13.Taylor series using recursion approach-1
14.Taylor series using recursion approach-2
15.Fibonacci series using recursion
16.nCr using recursion
17.Tower of hanoi
18.Tower of Hanoi implementation
  -->3. Code recursion <--
     Recursion -> if a function is calling itself, called recursion 
    there must be some base condition to terminate recursion
        type fun(paramerter){
            if(base_condition){
                fun(parameter);
            }
        }
*/
#include<iostream>
using namespace std;
void fun(int n){
    if(n>0){ // BAse Condition
        cout << n << " "; // Ascending phase 
        fun(n*(n-1)); // Recursive call
        //  Returning --- Descending phase
    }
}
int main()
{
    fun(5);
    return 0;
}
/*2. Recurrence relation-Time complexity of recursion
 Time complexity  with recurrence relation 
        void fn()               - T(n)
        {
            if(n>0)                 1
            {
                cout << n << " ";   1
                fn(n-1);            T(n-1)
            }
        }
        time complexity T(n) = 2+T(n-1)
        n=k
*/

#include<iostream>
using namespace std;
void fn_1(int n){
    if(n>0){
        cout << n << "\n";
        fn_1(n-1);
    }
}
int main()
{
    int n=6;
    fn_1(n);
    return 0;
}
//4. Recursion without static variables
#include<iostream>
using namespace std;
int fn(int n){
    if(n>0){
       return fn(n-1)+n;
    }
    return 0;
}
int main()
{
    int a=5;
    cout << fn(a) << "  ";
    return 0;
}
// With static variables 
#include<iostream>
using namespace std;
int fn(int n){
    static int x=0;
    if(n>0){
        x++;
       return fn(n-1)+x;
    }
    return 0;
}
int main()
{
    int a=5;
    cout << fn(a) << "  ";
    return 0;
}
/*5.  Tail Recursion --> Recursive call is the last statement in the function.
after the call, there is no other statement. 
Function does not do anything at the returning time. 
can be easily converted into a loop
Time -- O(n)
space = O(n)-n, activation record will be created
void fn(int n){
    if(n>0){ ----- Base condition [only Ascending phase---not descending phase] while , do-while, for
        cout << n << " ";
        fn(n-1); --- Function call
    }
}
fn (3)
6.Head Recursion-- >
    First statement in the function.
    Before the call, there is no other statement 
    Function does not do anything at the calling time..
    cannot be easily converted into a loop.
    Time = O(n);
    Space = O(n)-n activation record will be created
    Ascending -- Calling time
    Descending -- Returning time

7.Linear Recursion vs Tree Recursion -->
    
Linear Recursion                        Tree Recursion 
Function calls itself only once         
fn(){                                   fn(n){ 2 fn
    if(n>0){                                if(n>0){......
                                                cout << n << " ";1level
        fn(n-1);                                fn(n-1);.        2
                                                fn(n-1);.        3
    }                                       }
}                                       }
                                        fn(3)                    4 

*/
#include<iostream>
using namespace std;
void fn(int n){
    if(n>0){
        cout << n << " ";
        fn(n-1);
        fn(n-1);
    }
}
int main(){
    fn(3);
    return 0;
}
// 09-june-2022
/*8. Indirect recursion -->
        There are more than one functions and they are calling each other in a circular fashion.
*/
#include<iostream>
using namespace std;
void fn_A(int); // Function prototyping 
void fn_B(int);
int main()      // main method
{
    int a{20}; 
    cout << "A : "; 
    fn_A(a);    cout << "\nB : ";    fn_B(a);

    return 0;
}
void fn_A(int n){       //Recursive method B
    if(n>0){
        cout << n << " ";
        fn_B(n-1);
    }
}
void fn_B(int n){       //Recursive method B
    if(n>1){
        cout << n << " ";
        fn_A(n/2);
    }
}
//
/*9. Nested recursion -->
             Recursion function will pass parameter as a recursive call. 
*/
#include<iostream>
using namespace std;
int fun(int n){
    if(n>100){
        return n-10;
    } else {
        return fun(fun(n+11));
    }
}
int main()
{
    cout << "Nested recursive -> Value : " << fun(95) << "\n";
    return 0;

}
//
/*10. Sum of natural numbers using recursion ---b>
Sum of natural numbers 
        1+2+3+4.............+n = summation of n 
        
        Recursive definition 
        sum(n) = 1+2+3+4.......+(n-1)+n
        sum(n) = sum(n-1) + n
        sum(n) = 0          if n=0
            sum(n-1)+n      ifn>0
        using direct formula 
        sum(n) = n(n+1)/2

        int sum(int n){
    if(n==0){
        return 0;
    } else {
        return sum(n-1) + n;
    }
    Time complexity = O(n)
            Time complexity is directly proportional to the number of n
    Space complexity = O(n)
        For n, there are n+1 calls
        both are the order of n
*/
#include<iostream>
using namespace std;
int sum(int n){
    if(n==0){
        return 0;
    } else {
        return sum(n-1) + n;
    }
}
int main()
{
    int n{10};cout << "Sum of natural numbers : " << sum(n) << "\n";
    int sum_1=n*(n+1)/2;cout << "Sum : " << sum_1 << "\n";
    return 0;
}


// 10-06-2022
/*11. FActorial using recursion --->
        n! = 1*2*3*4.....*n
        fact(n) = fact(n-1)*n
        fact(n)=1       if n=0
            fact(n-1)*n if n>0

        Time complexity = O(n)- order of (n)
        space complexity = O(n)
        for n, there are n+1 calls 
*/
#include<iostream>
using namespace std;
long double fact(int n){
    // if (n>=2) 
    if(n==0 || n==1) //-- (n==0)
    return 1;
    else
    return fact(n-1)*n;
}
int main()
{
    long double n{35};cout << "\nFactorial : " << fact(n) << "\n";
    return 0;
}
//
/*12. Power using recursion 
    m^n = m*m*m.......*n times
        Recursive definition 
    pow(m,n) = m*m*m*m.......*(n-1) times * m
    pow(m,n) = pow(m, n-1)*m
    pow(n) = 1          if n=0
        pow(m, n-1)*m   if n>0

    Time Complexity = O(n)
    Space Complexity = O(n)
    For n, there are n+1 calls
*/

#include<iostream>
int pow(int m,int n){
    if(n==0)
    return 1;
    if(n%2==0)
    return pow(m*m,n/2); // even 
    else 
    return m*pow(m*m,(n-1)/2); //odd
}
int pow_1(int m, int n){
    if(n==0)
    return 1;
    else 
    return pow_1(m,n-1)*m;
}
int main(){
    int m{3},n{7};std::cout << "Power : " << pow(m,n);
    int m1{5},n1{3};std::cout << "\nPower_1 : " << pow_1(m1,n1);
    return 0;
}
//
/*13. Taylor series using recursion Approach -1 
    e^x = 1+(x/1)+(x^2/2!)+(x^3/3!)+(x^4/4!)+........+n terms

    Combination of following functions 
    sum(n) = 1+2+3+4+......+n           sum(n-1)+n
    fact(n)= 1*2*3*4*......*n           fact(n-1)*n
    pow(m,n)=m*m*m*.....n times         pow(m,n-1)*m
    using static variables  hold the result , when this iteration [iterate] is going on....

*/
#include<iostream>
long double e(int x,int n){  // e= taylor series
    static long double p{1},f{1}; // using static variables 
    long double r;
    if(n==0){
        return 1;
    }
    else{
        r=e(x,n-1);
        p=p*x;
        f=f*n; // previous term
        return r+p/f; 
    } // use double while implementation
}
int main(){
    int x{15},n{31}; std::cout << "\nTaylor Series : " << e(x,n) << "\n";
    return 0;
}
/*14. Taylor series using recursion Approach -1 
Reducing number of miltiplications
    e^x = 1+(x/1)+(x^2/2!)+(x^3/3!)+(x^4/4!)+........+n terms     |      Reducing  number of multiplications
    Total multiplication in approach -1                           |      Open factorial
    Eg - e^6                                                      |      Take x as common
    Multiplication = 0+0+2+4+6+8+10                               |      1+x/1[1+x/2 + x^2 / 3!]
                    = 2[1+2+3+4...]                               |
                    = 2n(n+1)/2                                   |
                    = O(n^2)                                      |     Take x/2 as common
        Total multiplications in approach-2                       |     1+x/1[1+x/2[x / 3]]
        Eg- e^4                                                   |     Take x/3 as common
        Multiplications = 4 = O(n)                                |     1+x/1[1+x/2[x / 3[x/4]]
*/
#include<iostream>
double calculate_e(int x,int n){  // e= taylor series
    static double s{1}; // using static variables
    if(n==0){
        return s;
    }
    else{
        s=1+x*s/n; 
        return calculate_e(x,n-1);
    } // use double while implementation
}
int main(){
    int x{2},n{10}; std::cout << "\nTaylor Series : " << calculate_e(x,n) << "\n";
    return 0;
}
You are correct, the number of multiplications in the first approach should be 0, 0, 2, 3, 4, 5, 6... and so on.
In the first approach, the number of multiplications is calculated as the number of terms multiplied by the number of operations required to compute each term. For example, the first term (1) does not require any multiplication, the second term (x/1) requires one multiplication, the third term (x^2/2!) requires two multiplications, and so on.
So, for the example of e^6, the number of multiplications in
Multiplications = 0 + 0 + 2 + 3 + 4 + 5 + 6 + ... + n
= 2 + 3 + 4 + 5 + 6 + ... + n
= (n-1)n/2
= O(n^2)
//  14-06-22
/*15.  Fibonacci Series using recursion 
        0,1,1,2,3,5,8,13....
        Frist two terms are required

        Mathematiical Defination
        Fib(n)= 0           if n=0
              = 1           if n=1
              fib(n-2) + fib(n-1) if n>1

    For fib(5), number of calls = 15
    For fib(4), number of calls = 9
    For fib(3), number of calls = 5

    No pattern here......

    Recursive function..
    Time Complexity 
    Function calling = 2fib(n-1)
    Time complexity = O(2^n)

Improving time complexity 
    Problem : 
    - There is repletion in calling 
    - Excessive Recursion
    Solution
        - USe static/global
        variables to retain values
        - Static/global array initialized with-1

    - New procedure 
        - Before making recursive calls, check for the values in the array.
        - After calculating results, store values in the Array and uuse them later.
        - This approach is called Memoization. 
                - For fib(5), number of calls = 6
                For n, n+1, calls
                Time complexity = O(n);
                return fib(n-2)+fib(n-1);
        for complete series 
        for(int i=2; i<n; i++){
        n3 = n1+n2;
        cout << n3 << " ";
        n1=n2;
        n2=n3;
    }
*/
// at first for populating global array i followed the video in which it was being populated by for loo[p outside of  function and as we cannot use loops outside of functions i declared it inside function just like in the video
#include<iostream>
int  fib(int n){
    if(n<=1)
    return n;
    else 
    return fib(n-2)+fib(n-1);
}
//  using memoization --> New Recursive Function
int F[10];
int mfib_1(int n){
    if(n<=1){
        F[n]=n;
        return n;
    } else {
        if(F[n-2]==-1)
            F[n-2]=mfib_1(n-2);
        if(F[n-1]==-1)
            F[n-1]=mfib_1(n-1);
        return F[n-2]+F[n-1];
    }
}
int main(){
    int n{8};for(int i{0}; i<10;i++){
    F[i]=-1;
}std::cout <<n<< "th term in the fibonaccci series is : " << mfib_1(n-1) << "\n";
    return 0;
}
//16. nCr using  Recursive Function -->
/* Combination Formula and non-recursive function 
Selection Formula nCr = n!/(r!(n-r)!)
Example : in how many ways 4 alphabets can be selected out of {A,B,C,D,E}
Time Complexity - > n+n+n = O(n)
    //  Normal Function
int C(int n, int r){
    int t1,t2,t3;
    t1=fact(n);
    t2=fact(r);
    t3=fact(n-r);
    return t1/(t2*t3);
    )
*/
#include<iostream>
int C(int n, int r){
    if(r==0||n==r)
    return 1;
    else
    return C(n-1,r-1)+C(n-1,r);
}
int main(){
    int n{5},r{4};std::cout << "\nThe value of "<<n<<"C"<<r<<" is "<<C(n,r);
    return 0;
} 

//19-06-22
/*  Tower of hanoi problem using recursion ->
    1. One dice can be moved at a time.
    2. At an instance, no bigger disc should be above smaller disc.
    initial 1.A,B,C 2. 3.  all the tower have a b and c
    Goal    1. 2. 3 A,B,C
     TOH (1,A,B,C) - MOVE disc from A to C using B
    2 DISC Source ---> Destination --> Auxiliary 
     TOH (2,A,B,C)
        TOH(1,A,B,C)
        TOH(1,B,A,C)
    3 DISC 
        TOH(3, A,B,C)
            TOH(2,A,C,B)
            TOH(1,A,B,C)
            TOH(2,B,A,C)
            Time complexity 
    for n==3. total function calls = 15;
    for n==2,total function calls = 7;
    for  n, total calls = 1+2+2^2+2^4........2^n-1-1
                                            O(2^n)
    Recursive function for TOH 
    void TOH(int n, int A,int B, int C){
        if(n>0){
            TOH(n-1,A,B,C)
            TOH(1,A,B,C) // cout << A << C;
            TOH(n-1,B,C)
        }
    }
    
    */
#include<iostream>
using namespace std;
void TowerOfHanoi(int n, int A, int B, int C){
    if(n>0){
        TowerOfHanoi(n-1,A,B,C);
        cout << A << ", " << C << "\n";
        // TowerOfHanoi(1,A,B,C);
        TowerOfHanoi(n-1,B,A,C);
    }
}
int main()
{
    TowerOfHanoi(3,2,1,3);
    return 0;
}





































#include<iostream>
using namespace std;
class Stack {
    private: // Protected Data 
    char data_[10]; int top_;
    public:void init()
    {
        top_=-1;
    } int empty() {
        return (top_==-1);
    } void push(char x){
        data_[++top_] = x;
    } void pop(){
        --top_;
    } char top() {
        return data_[top_];
    }
};
class Stack_1{
    private:
    char data_[10]; int top_1;
    public:Stack_1() : top_1(-1){}
    int empty(){
        return (top_1==-1);
    } void push(char x){
        data_[++top_1]=x;
    } void pop(){
        --top_1;
    } char top(){
        return data_[top_1];
    }
};
int fact(int n){
    if(n==1 || n==0)
    return 1;
    else 
    return n*fact(n-1);
}
void D(int n){
    bool prime[n+1]
}
int main(){
    char str[10]="ABCDE";
    Stack s; s.init(); // Clean initialization
    for(int i{0};i<5; ++i) s.push(str[i]);
    // s.top_ = 2; // Complie error - SAFE
    while(!s.empty()){
        cout <<s.top();s.pop();
    }
    char str1[10] = "ABCDE";
    Stack_1 s1; 
    for(int i{0};i<5; i++)s.push(str[i]);
    while(!s.empty()){
        std::cout <<s.top();s.pop();
    }
    int n{4};std::cout << "\nFActorial : " << fact(n) << "\n";
    return 0;
}

