
Module Objectives:- 
        - Understood const in C++ and constrast with Manifest Constants
        - Understand inline in C++ and constrast with Macros

        - Manifest constants are defined by #define
        - Manifest constants are replaced by CPP (C pre-processor). Check Tutorial on C preprocessor (CPP)
        
            - Source Program
                #include<iostream>
                #include<cmath>
                using namespace std;

                #define TWO 2 // Manifesrt const
                #define PI 4.0*atan(1.0) // Const expr.

                int main(){ int r {10};
                    double peri = TWO * PI * r;
                    cout << "Perimeter = " << peri << "\n";
                }
            - TWO is a manifest constant 
            - PI is a manifest constant macro 
            - Two & PI look like variables

            - Program after CPP
                // Contents of <iostream> header replaced by CPP
                // Contents of <cmath> header replaced by CPP
                #include<iostream>
                #include<cmath>
                using namespace std;
                // #define of TWO consumed by CPP
                // #define of PI consumed by CPP 
                int main(){
                    int r{10};double peri = 2*4.0*atan(1.0)*r; // BY CPP 
                    cout << "Perimeter :" << peri << "\n";
                }
            OutPut: Perimeter : 62.8319
            - CPP replaces the token TWO by 2 
            - CPP replaces the token PI by 4.0*atan(1.0) and evaluates 
            - Compiler sees them as __cpp_lib_math_constants
            - TWO*PI = 6.28319 by constant folding of compiler
    
    
    - Notion of const-ness
    - The value of a const variable cannot be changed after definition
        const int n = 10; // n is an int type variable with value 10 n is A constant
        .......
        n=5; // Is a compilation error as n cannot be changed
        .......
        int m;
        int *p = 0;
        p = &m; // Hold m by pointer p
        *p = 7; // change m by p; m is now 7
        ....
        p = &n; // Is a compilation erro r as n may be changed by *p = 5;
    - Naturally, a const variable must be initialized when defined 
        const int n; // Is a compilation error as n must be initialized
    - A variable of any data type can be declared as const  
        typedef struct _Complex {
            double re;
            double im;
        }    Complex;
        const Complex x = {2.3, 7.5}; // c is a complex type variable 
                                    // It is initialized with c.re = 2.3 and c.in = 7.5 c is constant 
        ....
        c.re = 3.5; // Is a compilation error as no part of c can be changed

    
    ::- Compare #define and const
        using #define 
            #include<iostream>
            #include<cmath>
            using namespace std;

            #define Two 2
            #define PI 4.0*atan(1.0)

            inr main(){int r = 10;
                // Replaced by CPP
                double peri = 2*4.0*atan(1.0)*r;
                cout << "Perimeter : " << peri << "\n";             
            } 
            - Two is a manifest constant 
            - PI is a manifest constant
            - TWO & PI look like variable 
            - Types of TWO & PI may be indeterminate
            - TWO * PI = 6.28319 by constant folding of compiler

        - Using const 
            #include<iostream>
            #include<cmath>
            using namespace std;

            const int TWO = 2;
            const double PI = 4.0*atan(1.0);

            int main(){int r {10};
                // No replacement by CPP
                double peri = TWO * PI * r;
                cout << "Perimeter : " << peri << "\n";
            }
        --       
        - TWO is a const variable initialized to 2
        - PI is a const variable initialized to 4.0*atan(1.0)
        - TWO & PI are variables
        - Type of TWO is const int 
        - Type of PI is const double 
    
    
    
    -- Advantage of const ::- 
            - Natural Constants like phi,e ,fi(Golden Ratio) etc. can be compactly defined and used 
                cosnt double pi = 4.0*atan(1.0);        // pi = 3.14159
                const double e = exp(1.0);              // e = 2.71828
                const double phi = (sqrt(5.0) + 1)/2.0; // phi = 1.61803
                const int TRUE = 1;                     // TRUTH VALUES
                const int FALSE = 0;

                const int null = 0;                     // null value

                        Note : NULL is a manifest constant in C/C++ set to 0
            - Program Constants like number of elements, array size etc. can be defined at one place (at times in a header) and used all over the program
                const int nArraySize = 100;
                const int nElements = 10;

                int main(){
                    int A[nArraySize];                      // Array size 
                    for(int i = 0; i<nElements; i++)        // Number of elements
                        A[i] = i*i;
                }
        - Prefer const over #define 
            - using #define  
            - Manifest Constant
                - Is not type safe 
                - Replaced tetually by CPP
                - Cannot be watched in debugger 
                - Evaluated as many times as replaced
            - Using const
            - Constant Variable
                - Has its type 
                - Visible to the compiler
                - Can be watched in debugger
                - Evaluated only on initialization
                
                
                - const-ness can be used with Pointers  in one of the two ways:
                    - Pointer to Constant data where the pointee (pointed data) cannot be changed
                    - Constant Pointer where the pointer (address) cannot be changed
                - Consider usual pointer-pointee computation (without const):
                    int m = 4;
                    int n = 5;
                    int * p = &n; // p points to n. *p is 5
                    ...
                    n = 6;      // n and *p are 6 now
                    *p = 7;     // n and *p are 7 now. POINTEE changes
                    ...
                    p = &m;     // p points to m. *p is 4. POINTER changes
                    *p = 8;     // m and *p are 8 now. n is 7. POINTEE changes
            - Consider pointed data
                - int m = 4;
                    const int n = 5;
                    const int * p  = &n;
                    ......
                    n =  6; // ERROR: n is constant and cannot be changed
                    *p = 7; // ERROR: p points to a constant data (n) that cannot be changed 
                    p = &m; // OKAY
                    *p = 8; // ERROR: p points to a constant data. Its pointee cannot be changed 

                    Interestingly 
                        int n = 5;
                        cosnt int * p = &n;
                        ....
                        n = 6; // OKAY
                        *p = 6; // Error : p points to a constant data (n) that cannot be changed
                        FINALLY 
                            const int n = 5;
                            int *p = &n; // ERROR: If this were allowed, we would be able to change constant n
                            ....
                            n = 6; // ERROR : n is constant and cannot be changed 
                            *p = 6; // Would been okay, if declaration of p were valid
                    
                    
                    - Consider pointer 
                        int m = 4, n =  5;
                        int * const p = &n;
                        ...
                        n = 6; // OKAY
                        *p = 7;  // Okay, Both n and *p are 7 now
                        ...
                        // p = &m;  Error : p is a constant pointer and cannot be changed
                        By extension, both can be const
                        const int m = 4;
                        const int n =  5;
                        const int * const p = &n;
                        ...
                        n = 6; // Error : n is constant and cannot be changed 
                        *p = 7; // Error: p points to a constant data (n) that cannot be changed
                        ...
                        p = &m; // ERROR : p is a constant pointer data cannot be changed
                        FINALLY, TO DECIDE ON CONST - NESS, DRAW A MENTAL LINE THROUGH *
                        int n = 5; 
                        int * p = &n;       // non-const-pointer to non-const-Pointee
                        const int * p = &n;     // non-const-Pointer to const-Pointee
                        int * const p = &n;     // const-Pointer to non-const-Pointee 
                        const int * const p = &n; // Const-Pointer to Const-Pointee

                
                - const and Pointers: The case of C-string
                Consider the example:
                    char * str = strdup(" -Bhatiya, Uttarkashi");
                    str[0] = 'N';       // Edit the name 
                    cout << str << "\n";
                    str = strdup(" -Bhatiya, Uttarkashi");    // Change the name
                    cout << str << "\n";
                Output is : 
                N-Bhatiya, Uttarkashi
                 -Bhatiya, Uttarkashi
                To stop editing the name:
                    const char * str = strdup("Seema, Headache");
                    str[0] = 'N';                       // Error : cannot Edit the name 
                    str = strdup("Ankita, Exam");       // change the name 
                To stop changing the name:
                    char * const str = strdup("Formation", "Need to be");
                    str[0] = 'N';       // Edit the name 
                    str = strdup("JIT, DELHI"); // ERROR : cannot change the name 
                To stop both : 
                    const char * const str = strdup("IIT,Kharagpur");
                    str[0] = 'N';       // Error : cannot edit the name 
                    str = strdup("IIT, Kanpur");      // ERROR: cannot change the name
            
            - Variable Read- Write 
                - The value of avariable can be read and / or assigned at any point of time 
                - The value assigned to a variable does not change till a next assignment is made(value is presistent)
            - Const 
                - The value of a const variable can be set only at initialization - cannot be changed afterwards
            - volatile 
                - In constrast, the value of a volatile variable mayv be different every time it is read - even if no assignment has been made to it..
                - A variable is taken as volatile if it can be changed by hardware, the kernel, another thread etc.
                - cv-qualifier : A declaration may be prefixed with a qualifier - const or volatile

            - using volatile
            - Consider :
                static int i;
                void fun(void){
                    i = 0;
                    while (i != 100);
                }
                This is an infinite loop! Hence the compiler sholud optimize as : 
                static int i;
                void fun(void){
                    i = 0;
                    while (1); // Compiler optimzes
                }
                Now quilifer i as volatile:
                static volatile int i;
                    void fun(void){
                        i=0;
                        while(i != 100); // Compiler dosen't optimize 
                    }
                Being volatile, i can be changed by hardware anytime. It waits till the value become 100(possibly some hardware writes to port).
            
        - Macros with Parameters
            - Macros with Parameters are defined by #define 
            - Macros with Parameters are replaced by CPP 
                - Source Program
                     #include<iostream>
                    using namespace std;

                    #define SQUARE(x) x*x
                    int main(){
                       int a{3},b;
                       b=SQUARE(a);
                       cout << "Square : " << b << "\n";
                    }       
                    - SQUARE(x) is a macro with one param
                    - SQUARE(x) looks like a function

                - Program after CPP
                    #include<iostream> // Header repalced by CPP
                    using namespace std;
                    // # define of SQUARE(x) consumed by CPP
                    int main(){
                        int a{3},b;
                        b=a*a; // Replaced by CPP
                        cout << "Square : " << b << "\n";
                    }
                    - Compiler does not see it as function.
                    - CPP replaced the SQUARE(x) substituting x with a 
           
            - Pitfalss of macros 
            Consider the example :
                #include<iostream>
                using namespace std;
                int main(){
                    int a{3},b;
                    b=SQUARE(a+1); // ERROR : Wrong macro expansion
                    cout << "Square : " << b << "\n";
                }
                OutPut is 7 in stead of 16 as expected. on the expansion line it gets:
                b = a + 1 * a + 1;
                To fix :
                #define SQUARE(x) (x) * (x)
                NOW
                b = (a + 1) * (a + 1);

            - Pitfalls of macros 
            continuing....
            #include<iostream>
            using namespace std;
            #define SQUARE(x)(x)*(x)
            int main(){
                int a{3},b;
                b = SQUARE(++a);
                cout << "Square : " << b << "\n";
            }
            OUTPUT : is 25 in stead of 16 as expected. On the expansion line it gets:
            b = (++a) * (++a);
            and a is incremented twice before being used! There is no easy fix.

            Inline Function : 
                - An inline function is just a function like any other 
                - The function prototype is preceded by the keyword inline
                - An inline function is expanded (inline) at the site of its call and the overhead of passing parameters between caller and callee (or called) functions is avoided.

            - Macros as inline Functions

                - Define the function
                - Prefix function header with inline 
                - Compile function body and function call together 
                    - using macro
                    #include<iostream>
                    using namespace std;
                    #define SQUARE(x) x * x
                    int main(){
                        int a{3},b;
                        b = SQUARE(a);
                        cout << "Square : " << b << "\n";
                    }
                    - SQUARE(x) is a macro with one param 
                    - Macro SQUARE(x) is efficient 
                    - SQUARE(a+1);
                    - SQUARE(++a) fails
                    - SQUARE(++a) does not check type

                - using inline :- 
                    #include<iostream>
                    using namespace std;
                    inline int SQUARE(int x){
                        return x*x;
                    }
                    int main(){
                        int a{3},b; b= SQARE(a);
                        cout << "Square : " << b << "\n";
                    }
                    - SQUARE(x) is a function with one param 
                    - inline SQUARE(x) is equally efficient 
                    - SQUARE(a+1) works
                    - SQUARE(++a) works
                    - SQUARE(++a) check type


        - Macros & inline functions : Compare and Contrast
            - Macros 
                - Expanded at the place of cells
                - Efficient in ececution
                - Code bloats
                - Has syntactic and semantic pitfalls
                - Type checking for parameters is not done
                - Helps to write max/swap for all types
                - Errors are not checked during compilation 
                - Not available to dubugger 
            
            - inline Functions: -
                - Expanded at all place of cells 
                - Efficient in execution
                - Code bloats
                - no pitfalls
                - Type checking for parameters is robust
                - Needs template to support all types
                - Errors are checked during compilation
                - Available to debugger in DEBUG build
        
        - Limitations of Function inlineing 
            - Inlineing is a directive - compiler may not inline functions with large body 
            - inline functions may not be recursive 
            - Function body is needed for inlineing at the time of function call. Hence, implementation hiding is not possible. IMplement inline functions in header files
            - inline functions must not have two different definitions 

    - Module Summary 
        - Revisited manifest constant from C 
        - Understood const-ness, its use and advantages over manifest constants, and its interplay with pointers 
        - Understood the notion and use of volatile data
        - Revistied macros with parameters from C 
        - Understood inline functions, their advantages over macros, and their limitations.
    --
--





























