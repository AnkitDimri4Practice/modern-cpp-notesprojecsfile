- Module objectives
    Understand References in C++
    Compare and constrast References and Pointers

- module Outline
    1. Reference Variable
            - Reference :
                A reference is an alias/ synonym  for an existing variable 
                int i = 15; // i is a variable 
                int &j = i; // j is reference to i 

                    i  -- variable
                    15 -- memory content 
                    200 - address &i = &j
                    j  -- alias or reference 
                    int i = 4;
                            int &j = i;
                            cout << "A : " << i << " & B : " << j << "\n";
                2. 
                #include<iostream>
                int main(){
                    int a=10, &b = a; // b is reference of a 
                    //  a and b have the same memory location
                    std::cout << "a = " << a << " ,  b = " << b << ". &a =  " << &a << ", &b  = " << &b << "\n";
                    ++a; // Changing a appears as change in b
                    std::cout << "a = " << a << ", b = " << b << "\n";
                    ++b; // changing b also changes a 
                    std::cout << "a = " << a << ", b = " << b << "\n";
                }
                    a and b have the same memory location and hence the same value
                    changing one changes the other and vice- versa


        Pitfalls in Reference
            - wrong declaration                     Reason                                          Correct declaration
            int& i;                 No variable(address) to refer to - must be initialized          int& i = j;
            int& j = 5;             no address to refer to as 5 is a constant                       cosnt int& j = 5;
            int& i = j+k;           only tempory address (result of j + k) to refer to              const int& i = j + k;

                    #include<iostream>
                    using namespace std;
                    int main(){
                        int i = 2;  int& j = i;     
                        const int& k = 5;  // cosnt tells complier to allocate a memory with the value 5
                        const int& l = j + k;  // Similarly for j + k = 7 for l to refer to 
                        std::cout << i << ", " << &i << "\n"; 2, 0xcdf23ff8a4
                        std::cout << j << ", " << &j << "\n"; 2, 0xcdf23ff8a4
                        std::cout << k << ", " << &k << "\n"; 5, 0xcdf23ff8a0
                        std::cout << l << ", " << &l << "\n"; 7, 0xcdf23ff89c
                    }
    
    2. Call by Reference 
                #include<iostream>
                using namespace std;
                void Function_under_param_test( // Function prototype 
                    int&, // Reference parameter
                    int); // Value parameter
                int main(){
                    int a{20};
                    cout << "a = " << a << ", &a = " << &a << "\n\n";
                    Function_under_param_test(a,a); // Function call
                }
                void Function_under_param_test(int &b, int c){ // Function definition
                    cout << "b = " << b << ", &b = " << &b << "\n\n";
                    cout << "c = " << c << ", &c = " << &c << "\n\n";
                } 
                Output
                a = 20, &a = 0x7344fff73c
                b = 20, &b = 0x7344fff73c // Address of b is same as a as b is a reference of a
                c = 20, &c = 0x7344fff718 // Address different from a as c is a copy of a

                Param b is call-by-reference while param c is call-by-value
                Actual param a and formal param b get the same value in called function
                Actual param a and formal param c get teh same value in called function
                Actual param a and formal param b get the same address in called function
                However, actual param a and formal param c have different addresses in called funcion.

        Simple C program to swap
            3.Call-by-value - wrong
                    #include<iostream>
                    void swap(int, int); // call-by-value
                    int main(){
                        int a = 10,b = 15;
                        printf("a = %d &  b = %d to swap\n",a,b);
                        swap(a,b);
                        printf("a = %d & b = %d on swap\n",a,b);
                    }
                    void swap(int c, int d){
                        int t;
                        t = c; c = d; d = t; // No swap
                    }
                    Passing values of a = 10 &  b = 15 to swap
                    In callee c = 10 & d = 15 
                    swapping the values of c & d
                    No change for the values of a & b in caller
                    Swapping the values of c & d instead of a & b 
                    Here c & d do not share address with a & b
            Call by address - Right
                    #include<stdio.h>
                    void swap(int *, int *); // call-by-address
                    int main(){
                        int a = 10,b = 15;
                        printf("a = %d &  b = %d to swap\n",a,b);
                        swap(&a,&b);
                        printf("a = %d & b = %d on swap\n",a,b);
                    }
                    void swap(int *c, int *d){
                        int t;
                        t = *c; *c = *d; *d = t;
                    }
                    a = 10 &  b = 15 to swap
                    a = 15 & b = 10 on swap
                    Passing Address of a & b
                    In callee c = Addr(a) & d = Addr(b)
                    Values at the addresses is swapped
                    Desired changes for the values of a & b in caller
                    It is correct, but C++ has a better way out
            
            4.C++ program : Call-by-reference
                    
                    #include<iostream>
                    using namespace std;
                    void swap(int&, int&); // call-by-reference 
                    int main(){
                        int a{20},b{25};
                        cout << "a = " << a << " & b = " << b << " to swap \n";
                        swap(a,b); // Natural call
                        cout << "a = " << a<< " & b = " << b << " on swap \n";
                    }
                    void swap(int &x, int &y){int t;
                        t = x; x = y; y = t;
                    }
                    a = 20 & b = 25 to swap
                    a = 25 & b = 20 on swap
                    Passing values of a = 20 & b = 25
                    In callee x = 20 & y = 25
                    swapping the values of x & y
                    Deserid changes for the values of a & b in caller
                    x & y having same address as a & b respectively
        Program 5 : Reference Parameter as const
            A reference parameter may get changed in the called function
            Use const to stop reference parameter being changed
                2.// const reference - bad
                    #include<iostream>
                    using namespace std;
                    int ref_const(const int &x){
                        ++x;    // not allowed
                        return (x);
                    }
                    int main(){
                        int a{10},b;
                        b = ref_const(a);
                        cout << "a = " << a << " &  b = " << b;
                    }
                    Error: increment of read-only reference 'x'
                    Compliation Error : value of x cannot be changed  
                    Implies, a cannot be changed  through x

                1.// Const reference - good     
                    #include<iostream>
                        using namespace std;
                        int ref_const(const int &x){
                            return (x+1);
                        }
                        int main(){int a{10},b;
                            b = ref_const(a);
                            cout << "a = " << a << " & b = " << b;
                        }
                        a = 10 & b = 11
                        No Violation    

        Simple C/C++ program to swap two numbers
    
    3. Return-By-Reference 
            6. A function can return a value by reference (Return-by-reference)
                C uses Return-by-value
                    : Return-by-Value
                        #include<iostream>
                        using namespace std;
                        int Function_Return_By_Val(int &x){
                            cout << "x = " << x << " &x = " << &x << "\n";
                            return(x);
                        }
                        int main(){
                            int a{10};cout << "a = " << a << " &a = " << &a << "\n";
                            const int& b = // const needed . why?
                            Function_Return_By_Val(a);
                            cout << "b = " << b << "  &b = " << &b << "\n";
                        }
                        a = 10 &a = 0x7883ffb94
                        x = 10 &x = 0x7883ffb94
                        b = 10  &b = 0x7883ffb90 // Reference to temporary 
                        : Return Variable is temporary. 
                        : Has a different address.

                    : Return - by - Reference 
                            #include<iostream>
                            using namespace std;
                            int& Function_Return_by_Ref(int &x){
                                cout << "x = " << x << " &x = " << &x << "\n";
                                return (x);
                            }
                            int main(){
                                int a{20};
                                cout << "a = " << a << " &a = " << &a << "\n";
                                const int& b = // const optional 
                                    Function_Return_by_Ref(a);
                                    cout << "b = " << b << " &b = " << &b << "\n"; 
                            }
                            a = 20 &a = 0xbfb9ffcb4
                            x = 20 &x = 0xbfb9ffcb4
                            b = 20 &b = 0xbfb9ffcb4 // Reference to a
                            Return variable is an allas of a 
                            Has the same address 

                :: 7. Return - by - Reference can get tricky
                    Return by reference 
                        #include<iostream>
                        using namespace std;
                        int& Return_ref(int &x){
                            return (x);
                        }
                        int main(){
                            int a{11},b=Return_ref(a);
                            cout<<"b = "<<b<<" &b = "<<&b<<"\n";
                            Return_ref(a) = 3; // Change variable a
                            cout << "a = " << a;
                        }
                        b = 11 &b = 0x60151ff7a8
                        a = 3
                        NOte how a value is assigned to function call
                        This can change a local variable

                    : Return by reference - Risky!
                            #include<iostream>
                            using namespace std;
                            int& Return_ref(int &x){
                                int t = x;
                                t++;
                                return (t);
                            }
                            int main(){
                                int a{11},b=Return_ref(a);
                                cout <<"b = "<<b<<" &b = "<<&b<<"\n";
                                Return_ref(a) = 3;
                                cout << " a = " << a;
                            }
                            We expect a to be 3. but it has not changed
                            It returns reference to local. This is risky


        Pitfalls of Return-By-Reference
    
    4. I/O Parameters of a Function
            : In C++ we can change values with a Function as follows:
            I/O of Function                     Purpose                     Mechanism
            value Parameter                     Input                       Call-by-value
            Reference parameter                 In-Out                      call-by-reference 
            const Reference Parameter           Input                       call-by-reference
            Return value                        Output                      Return-by-value
                                                                            Return-by-reference 
                                                                            cosnt Return-by-refernece 

            In addition, we can use the call-by-address(call-by-value with pointer) and Return-by-addresss (Return-by-Value with pointer ) as in C
            But it is neither required noe advised

    5. Recommended call and Return Mechanisms
            : Recommended Mechanisms 
                Call
                    Pass parameters of built-in types by value
                        Recall : Array parameters are passed by reference in C and C++
                    Pass parameters of user-defined types by reference
                        Make a reference parameter const if it is not used for output

                Return 
                    Return built-in types by value
                    Return user-defined types by reference 
                        Return value is not returning a value
                        May be faster than returning a value
                        Beware : calling function can change returned object 
                        Never return A local variables by reference 


    6. Difference between Reference Mechanisms
            : Pointers
                Refers to an address(exposed)
                Pointers can point to NULL
                int *p = NULL; // P is not pointing
                Pointers can point to different variables at different times
                int a, b, *p;
                p = &a; // p points to a 
                ....
                p = &b; // p points to b
                NULL checking is required
                Allows users to operate on the address
                diff pointers, increment, etc
                Array of pointers can be defined 
            
            : Refernces 
                    Refers to an address(hidden)
                    Reference cannot be NULL
                    int &j; // wrong
                    For a reference, its referent is fixed
                    int a,c,&b=a; // OKAY
                    ....
                    &b = c //ERROR
                    Does not required NULL checking 
                    Makes code faster
                    Does not allow users to operate on the add

    7. Module Summary 
            : Introduced reference in C++
            : Studied the difference between call-by-value and call-by-reference 
            : Studied the difference between return-by-value and return-by-reference 
            : Discussed the difference between References and Pointers
            
    

#include<iostream>
using namespace std;
#define SQUARE(x) (x)*(x)
inline int SQAURE(int y){
    return y+y;
}
int main(){
    double a,b,e,f; 
    cin>>a;
    b=SQUARE(a);// b=SQUARE(a); macro 
    cin >> e;
    f = (e+1)*(e+1);
    cout << "SQUARE : 1 : " << b << "\n";
    cout << "SQAURE :: 2 :: " << f << "\n";
    cout << "======2nd One=======\n";
    double c,d;cin >>c; d= c*c;
    cout << "Sqaure : " << d << "\n";
    cout << "INline Concept : \n\n";
    double g,h;cin>>g;
    h=SQUARE(g);
    cout << "SQUARE :: " << h << "\n";
    cout << "========================" << "\n\n";
    int i = 4;
    int &j = i;
    cout << "A : " << i << " & B : " << j << "\n";
    return 0;
}