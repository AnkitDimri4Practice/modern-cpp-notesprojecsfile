1. Default Parameters
    : Example CreateWindow in MSVC++
                Declaration of CreateWindow
                    HWND WINAPI CreateWindow{
                        _In_opt_ LPCTSTR lpClassName,
                        _In_opt_ LPCTSTR lpWindowName,
                        _In_     DWORD      dwStyle,
                        _In_     int        x,
                        _In_     int        y,
                        _In_     int        nWidth,
                        _In_     int        nHeight,
                        _In_opt_ HWND       hWndParent,
                        _In_opt_ HMENU      hMenu,
                        _In_opt_ HINSTANCE  hInstance,
                        _In_opt_ LPVOID     lpParam
                    };
                Calling CreateWindow 
                    hWnd = CreateWindow{
                        ClsName,
                        WndName,
                        WS_OVERLAPPEDWINDOW,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        NULL,
                        NULL,
                        hInstance,
                        NULL
                    };
                : There are 11 parameters in CreateWindow()
                : of these 11, 8 parameters (4 are CW_USEDEFAULT, 3 are NULL, and 1 is hInstance) usually get same values in most calls 
                : Instead of using these 8 fixed valued Parameters at call, we may assign the values in formal parameter 
                : C++ allows us to do so through the mechanism called default parameters
        : Examples
            Function with a default parameter 
                    #include<iostream>
                    using namespace std;
                    int  IdentifyFunction(int a=10){ // Default value for parameter a
                        return (a);
                    }
                    int main(){
                        int x{3},y;
                        y = IdentifyFunction(x); // Usual function call. Actual parameter taken as x = 3
                        cout << "y = " << y << "\n";
                        y = IdentifyFunction(); // Uses default parameter. Actual parameter taken as 10
                        cout << "y = " << y << "\n";
                    }
                    y = 3
                    y = 10
           
            Function with 2 default parameteres
                    #include<iostream>
                    using namespace std;
                    int ADD(int a=10,int b=20){
                        return (a+b);
                    }
                    int main(){
                        int x{5},y{7},z;
                        z=ADD(x,y); // usual function call -- a = x = 5 & b = y = 7
                        cout << "Sum : " << z << "\n";
                        z = ADD(x); // One parameter defaulted -- a = x = 5 & b = y = 20
                        cout << "Sum : " << z << "\n";
                        z = ADD(); // Both parameter defaulted -- a = 10 & b = 20
                        cout << "Sum : " << z << "\n";
                        z = ADD(y); // Both parameter defaulted -- a = 10 & b = 20
                        cout << "Sum : " << z << "\n";
                    }
                    Sum : 12
                    Sum : 25
                    Sum : 30
                    Sum : 27
        : Highlights
            : C++ allows programmer to assign default values to the function parameters
            : Default values are specified while prototyping the function 
            : Default parameters are required while calling functions with fewer arguments or without any argument
            : Better to use default value for less used parameters 
            : Default arguments may be expression also 

        : Restrictions on default parameters
            :  All parameters to the right for a parameter with default argument must have default arguments(Function f violates)
            : Default arguments cannot be re-defined (second signature of function g violates)
            : All  non-defaulted parameters needed in a call (first call of g() violates)
                #include<iostream>
                void f(int, double = 0.0, char *);
                // Error c2548 : f : missing default parameter for parameter 3
                void g(int, double = 0, char * = NULL); // OKAY
                void g(int, double = 1, char * = NULL);
                // ERROR c2572: g : redefinition of default parameter : parameter 3
                // ERROR c2572: g : redefinition of default parameter : parameter 2
                int main(){
                    int i{5};double d = 1.2; char c = 'b';
                    g(); // ERROR c2660 g : Function does not take 0 arguments
                    g(i);
                    g(i,d);
                    g(i,d,&c);
                }
        : Restriction on default parameters
            : Default parameters to be supplied only in a header file and not in the definition of a funcition
                // Header file: myFunc.h
                void g(int, double,char = 'a'); // Defaults ch
                void g(int i, double f = 0.0, char ch); // A new overload, defaults f & ch
                void g(int i = 0, double f, char ch); // A new overload. Defaults i,f & ch
                // void g(int i=0,double f = 0.0,char ch = 'a); // Alternate signature. Defaults all in one go 
                ---------------------------------------------------
                //  Source file
                #include<iostream>
                using namespace std;
                #include "myFunc.h" // Defaults taken from header      
                void g(int i, double d, char c) {
                    cout << i << ' ' << d << ' ' << c << "\n"; // NO defaults here 
                } 
                ----------------------------------------------------
                //  Application file 
                #include<iostream>
                #include "myFunc.h"
                int main(){
                    int i {5}; double d = 1.2; char c = 'b';
                    g();      // Prints : 0  0 a
                    g(i);     // Prints : 5 0 a
                    g(i,d);   // Prints : 5 1.2 a
                    g(i,d,c); // Prints : 5 1.2 b
                }
2. Funcition Overloading 
    : Matrix Multiplication in C
        // : Similar functions with different data types and algorithms
        typedef struct { int data[10][10]; } Mat; // 2D Matrix
        typedef struct { int data[1][10]; } VecRow; // Row Vector
        typedef struct { int data[10][1]; } VecCol; // Column Vector

        void Multiply_M_M (Mat a,      Mat b,       Mat* c);    // C = a * b
        void Multiply_M_VC (Mat a,     VecCol b,    VecCol* c); // C = a * b
        void Multiply_VR_M (VecRow a,  Mat b,       VecRow* c); // C = a * b
        void Multiply_VC_VR (VecCol a, VecRow b,    Mat* c);    // C = a * b
        void Multiply_VR_VC (VecRow a, VecCol b,    int* c);    // C = a * b

        int main(){
            Mat m1,m2,rm; VecRow rv, rrv; VecCol cv, rcv; int r;
            Multiply_M_M (m1, m2, &rm);    // rm = m1 * m2
            Multiply_M_VC (m1, cv, &rcv); // rcv = m1 * cv
            Multiply_VR_M (rv, m2, &rrv); // rrv = rv * m2
            Multiply_VC_VR (cv, rv, &rm);    // rm = cv * rv
            Multiply_VR_VC (rv, cv, &r);    // r = rv * cv
        }
            5 Multiplication functions share similar functionality but different argument types 
            C treats them by 5 different function names. Makes it defficult for the user to remember and use
            C++ has an elegant solution 

    -------------------------------------------------- 

    : Matrix Multiplication in C++
        // : Functions having the same name, similar functionality but different algorithms, and identified by different interfaces data types 
        typedef struct { int data[10][10]; } Mat; // 2D Matrix
        typedef struct { int data[1][10]; } VecRow; // Row Vector
        typedef struct { int data[10][1]; } VecCol; // Column Vector

        void Multiply(const Mat& a,    const Mat& b,    Mat& c);    // C = a * b
        void Multiply(const Mat& a,    const VecCol& b, VecCol& c); // C = a * b
        void Multiply(const VecRow& a, const Mat& b,    VecRow& c); // C = a * b
        void Multiply(const VecCol& a, const VecRow& b, Mat& c);    // C = a * b
        void Multiply(const VecRow& a, const VecCol& b, int& c);    // C = a * b

        int main(){
            Mat m1,m2,rm; VecRow rv, rrv; VecCol cv, rcv; int r;
            Multiply(m1, m2, &rm);    // rm <-- m1 * m2
            Multiply(m1, cv, &rcv); // rcv <-- m1 * cv
            Multiply(rv, m2, &rrv); // rrv <-- rv * m2
            Multiply(cv, rv, &rm);    // rm <-- cv * rv
            Multiply(rv, cv, &r);    // r <-- rv * cv
        }
        These 5 functions having different argument types are represented as one function name (Multiply) in C++ 
        This is called function Overloading or static Polymorphism( poly - Multiple, many ; morphism - changes and forms ,  somthing which is in multiple froms in common,  why static because the complier itself can findout what is the right function to bind to. ) 
    
    -----------------------------------------------------

        : Examples
            Function Overloading 
                Define multiple functions having the same name
                Binding happens at complie time 

                    Same # of Parameters
                        #include<iostream> 
                        using namespace std;
                        int  Add(int a, int b){
                            return (a+b);
                        }
                        double Add(double c, double d){
                            return (c+d);
                        }
                        int main(){
                            int x{5},y{6},z;
                            z = Add(x,y); // int Add(int, int)
                            cout << "Int Sum : " << z << "\n";
                            double s{3.4},t{4.54},u;
                            u = Add(s,t); // double Add(double, double)
                            cout << "Double Sum : " << u << "\n"; 
                        } 
                        Int Sum : 11
                        Double Sum : 7.94
                        Same Add function to add two ints or two doubles
                        Same # of parameters but different types

                ----------------------------------------------------------------
                    
                    Different # of parameters
                        #include<iostream> 
                        using namespace std;
                        int  Area(int a, int b){
                            return (a*b);
                        }
                        double Area(int c){
                            return (c*c);
                        }
                        int main(){
                            int x{10},y{12},z{5},t;
                            t = Area(x,y); // int Area(int, int)
                            cout << "Area of Rectangle : " << t << "\n";
                            int u;
                            u = Area(z); // int Area(int)
                            cout << "Area of Square : " << u << "\n"; 
                        }
                        Area of Rectangle : 120
                        Area of Square : 25
                        Same Area function for rectangles and for squares 
                        Different number of parameters 

        : Restrictions
            Restrictions in Function Overloading 
                Two functions having the same signature but different return types cannot be overloaded 
                    #include<iostream> 
                    using namespace std;
                    int  Area(int a, int b){
                        return (a*b);
                    }
                    double Area(int a,int b){ // Area_1
                        return (a*b); // Error c2556 : double Area(int, int): overloaded function differs only by return type from int Area(int, int)
                        // Error C2371 : Area : redefinition; different basic types
                    }
                    int main(){
                        int x{10},y{12},z{5},t;
                        double f;
                        t = Area(x,y); // int Area(int, int)
                        // Error c2568 : Unable to resolve funciton overload
                        // Error c3861 : Area identifier not found 
                        cout << "Multiplication :: " << t << "\n";
                        f = Area(y,z); // Error C2568 and C3861 as above 
                        cout << "Multiplication :: " << f << "\n"; 
                    }
        : Rules 
            Summary of Rules 
                The same function name may be used in several definitions 
                Funcitons with the same name must have different number of formal parameters and / or differnt types of formal parameters 
                Function selection is based on the number and the types of the actual parameters at the places of invocation
                Function selection (Overload Resolution) is Performed by the Complier 
                Two functions having the same signature but different return types will result in a compliation error due to attempt to re-declare 
                Overloading allows Static Polymorphism 

3. Overload Resolution
    To resolve overloaded functions with one parameter 
        Identiy the set of Candidate Functions
        From the set od candidate functions identify the set of Viable Functions
        Select the Best viable function through (Order is important)
        : Exact Match    
            Exact Match 
                : lvalue-to-rvalue conversion : Read the value from an object  l-left r- right
                    Most common 
                : Array-to-pointer conversion 
                    Definitions : int sr[10];
                                  Void f(int *a);
                    Call :        f(ar)
                                                Definitions : typedef int (*fp) (int);
                                                              void f(int , fp);
                                                              
                : Function-to-pointer conversion              int g(int);
                                                Call:          f(5, g)
                : Qualification conversion  
                    : COnverting pointer (only) to const pointer 

            Promotion 
            Standard type conversion 
            User defined type conversion 
 
        : Promotion & Conversion 
            Promotion 
                Objects of an integral type can be converted to another wider integral type, that is s type that can represent a larger set of values. This widening type conversion is called integral promotion
                C++ promotions are value-preserving, as the value after the promotion is guaranteed to be the same as the value before the promotion 
                Examples
                    char to int; float to double 
                    enum to int / short / unsigned int / ....
                    bool to int 
            Standard Conversions
                Integral  conversions between integral types - char, short, int and long with or without qualifers signed or unsigned 
                Floating point Conversions from less precise floating type to a more precise floating type like float to double or double to long doble. Conversion can happen to a less precise type, if it is in a range representable by that type 
                Conversions between integral and floating point types: Certain expressions can cause objects of floating type to be converted to integral types, or vice versa. MAy be Dangerous!
                When an object of intergral type is converted to a floating type, and the orignal value is not representable exactly, the result is either the next higher or the next lower representable value
                When an object of floating type is converted to an integral type, the fractional part is truncated, or rounded toward zero. A number like 1.3 is converted to 1, and -1.3 is converted to -1
                Pointer Conversions : Pointers can be conerted during assignment, initialization, comparison, and other expressions
                Bool conversion: int to bool or vice versa based on the context 

        : Examples
            Overload Resolution with one parameter 
                IN the context of a list of function prototypes:
                    int g(double);                  // F1
                    void f();                       // F2
                    void f(int);                    // F3
                    double h(void);                 // F4
                    int g(char, int);               // F5
                    void f(double, double = 3.4);   // F6
                    void h(int, double);            // F7
                    void f(char, char *);           // F8
                    The call site to resolve is : 
                    f(5.6);

                    Resolution: 
                        Candidate function (by name) : F2, F3, F6, F8
                        Viable functions (by # of parameters) : F3,F6
                        Best viable function(by type double - Exact Match) : F6 
        : Amiguity 
            Ambiguity in Overlaod Resolution 
                Consider the overloaded function signatures : 
                    int fun(float a){....}          // Function 1
                    int fun(float a, int b){...}    // Function 2
                    int fun(float x, int y = 5){...}// Function 3
                    int main(){
                        float p = 4.5, t= 10.5;
                        int s =  30;
                        fun(p,s); // Call - 1
                        fun(t);   // Call - 2
                        return 0;
                    }
                    Call -1 : Matches Function 2 & Function 3
                    Call - 2: Matches Function 1 & Function 3
                    Results in Ambiguity for both calls
        :
        Program : Default Parameter & Function Overloading
            Comopliers deal with default  parameters as a special case of function overloading 
            These need to be mixed carefully 
                Default Parameters 
                    #include<iostream>
                    using namespace std;
                    int f(int a = 1, int b = 2);
                    int main(){
                        int x=5,y=6;
                        f();    // a=1,b=2
                        f(x);   // a = x = 5, b = 2
                        f(x,y); // a = x = 5, b = y = 6
                    }

                    Function f has 2 parameters defaulted 
                    f can have possible forms of call 
       
            ----------------------------------------
       
                Function Overload
                    #include<iostream>
                    using namespace std;
                    int f();
                    int f(int);
                    int f(int,int);
                    int main(){
                        int x=5,y=6;
                        f();    // int f();
                        f(x);   // int f(int);
                        f(x,y); // int f(int,int);
                    }

                    Function f is overload with upto 2 parameters 
                    f can have 3 possible forms of call
                    No overload here use default parameters, can it?  
4. How to overload default Parameter 
    Function overloading can use default parameter 
    However, with default parameters, the overloaded functions should still be resolvale 
        #include<iostream>
        using namespace std;
        int Area(int a, int b = 10){
            return(a*b);
        }
        double Area(double  c, double d){
            return (c*d);
        }
        int main(){
            int x{10},y{12},t; double z {20.5},u{5.0},f;
            t = Area(x);        // binds int Area (int, int  = 10)
            cout << "Area:: " << t << "\n";  
            t = Area(x,y);      // Binds int Area(int, int = 10)
            cout << "Area :: " << t << "\n"; 
            f = Area(z,u);      // Binds double Area(double, double)
            cout << "Area :: " << f << "\n"; 
            f = Area(z);            // Binds int Area(int, int = 10)
            cout << "Area :: " << f << "\n"; 
            // Un-resolvable between int Area(int a, int b = 10) and double Area(double c, double d)
            // f = Area(z,y);
            // cout << "Area:: " << f << "\n"; // error: call of overloaded 'Area(double&, int&)' is ambiguous
        }
        Area:: 100
        Area :: 120
        Area :: 102.5
        Area :: 200
    
    ------------------------------------------
    Default parameter & Function Overload 
        : Function overloading with default parameters may fail
            #include<iostream>
            using namespace std;
            int f();
            int f(int = 0);
            int f(int, int);
            int main(){
                int x{5}, y{6};
                f();        // Error c2668 : f : ambiguous call to overload  function more than one instance of overloaded function f mathches the argument list: 
                f(x);       // int f(int);
                f(x,y);     // int f(int, int);
                return 0;
            }

5. Module Summary 
        Introduced the notion of default parameters and discussed several examples 
        Indentified the necessity of function overloading 
        Introduced static Polymorphism and discussed examples and restrictions
        Discussed an outline for overload resolution
        Discussed the mix of default parameters and function overloading 


---------------------------------------- Complete-----------------------------------------------
    