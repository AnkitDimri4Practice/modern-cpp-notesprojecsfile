 /* -  UNderstanding the differences and realtionship between source and header files
-  How C  preprocessor(CPP) can be used to manage code during build?
 out-line
    -1. Source and header files 
            [[
                - Source Files : A source file is a text file on disk. IT contain instructions for the computer that are written in the C/C++ programming language.
                    - A source file Typically has extension .c for C .cpp for C++, though there are several other conventions
                    - Any source file, called a Translation Unit, can be independently complied into an object file(*.0) imp
                    - A project may contain one or more source files 
                    - All object files of the project are linked together to create the executable binary file that we run.
                    - One of the Source files must contain the main() function where the execution starts
                    - Every source file include zero or more header files to reduce code duplication
                    - In a good source code organization, evrey header file has its source file that implements functions and classes, It is called implementation file. In addition Application files would be there..
            ]]
            [[
                Header File : 
                    - A header file is a text file on disk. It contains function declarations & macro definition(C/C++) and class & template definations (C++) to be shared between several source files
                        - A header file typically has extension .h for C and .h or .hpp for C++, though there are several other conventions(or no entension for C++ standard library)
                        - A header file is included in one or more source or header files
                        - A header file is complied as a part of the source file /s it is include in
                            - Precompiled header(PCh): A header file may be compiled into an intermediate form that is faster to process for the compiler. usage of PCH may significantly reduce compilation time, especially when applied to larger header files, header files that include many other header files, or header files that are included in many translation units.
                        - There are two types of header files(more information in 19)
                            - Files that the programmer writes are included as #include "file"
                            - Files that comes with the compiler (standard libary) are included as #include<file>. for c++
                                - Thesse have no extension and are specified within std namespace 
                                - The standard library files of C are prefixed with "C" with no extension in C++
            ]]
        - sample C/C++ files

    -2. C preprocessor (CPP) : Managing Source Code 
            - 
                - The CPP is the macro preprocessor for the C and C++. CPP provides the ability for inclusion of header files. macros expensions, conditional compilation, and line control
                - The CPP is driven by a set of directives
                    - Preprocessor directives are lines include in the code of programs preceded by a #
                    - These lines are not program statements but directives for the preprocessor
                    - The CPP examines the code before actual compilation of code begins and resolves all these directives before any code is acutally grenerated by regular statements
                    - The CPP directives have the following characteristics:
                        - CPP directives extend only across a single line of code
                        - As soon as a newline character is found, the preprocessor directive is ends
                        - NO semicolon(;) is expected at the end of a preprocessor directive 
                        - THe only way a prerocessor directive can extend through more than one line is preceding the newline character at the end of the line by a backslash(\)
        - Marcos    
            - Manifest Constants and Marcos
                - C preprocessor - Marcos definitions: #define, #undef 
                    - To define preprocessor macros we can use #define. Its syntax is : 
                        #define identifier replacement 
                    - This replaces any occurence of identifier in the rest of the code by replacement. CPP dose not understand C/C++, it simply textually replaces
                        #define TABLE_SIZE  100
                        int table1[TABLE_SIZE];
                        int table2[TABLE_SIZE];
                    - After CPP has replaced TABLE_SIZE, the code becomes  equivalent to : 
                        int table1[100];
                        int table2[100];
                    - We can define a symbol by -D name option from the command line. This predefines name as a macro, with definition 1. The following code compiles and outputs 1 when compiled with
                        $ g++ Macros.cpp -D FLAG
                        #include <iostream> // File Macros.cpp
                        int main(){ 
                            std::cout << (FLAG==1) << std::endl;
                            return 0;
                        }
                    - NOtte that #define is important to define constants (like size, pi, etc..), usually in a header (or beginning of a source) and use everywhere. cosnt in a variable declaration is a better solution in C++ and C11 onward

                    - #define can work also with parameters to define function macros : 
                        #define getmax(a,b) a>b?a:b
                    - This replace a occurrence of getmax followed by two arguments by the replacement expression, but also replacing each argument by its identifier, exactly as a function:

                        // function macro
                        #include<iostream>
                        using namespace std;
                        #define getmax(a , b) ((a) > (b) ? (a) : (b))
                        int main(){
                            int x{5},y;
                            y = getmax(x,2);
                            cout << y << "\n" << getmax(7,x) << "\n";
                            return 0;
                        }
                    - Note that a #define function macro can make a small function efficient and usable with different types of parameters. In C++, inline functions & templates achieve this functionality in a  better way  
            - undef
                - Defined macros are not affected by block structure. A macro lasts until it is undefined with the #undef preprocessor directive :
                        #define TABLE_SIZE 100
                        int table1[TBALE_SIZE];
                        #undef TABLE_SIZE
                        #define TABLE_SIZE 200
                        int table2[TABLE_SIZE];
                    - This would generate the same code as
                        int table1[100];
                        int table2[200];
                    - We can un-define a symbol a symbol by -U name option from the command line. This cancels any previous definition of name, either built in or provided with a -D option
                        $ g++ file.cpp -U FLAG 
                    - Note that #undef is primarily used to ensure that a symbol is not unknowingly being defined amd used through some include path

            - # & ##
                    - Parameterized macro definitions accept two special operators (# and ##) in the replacement sequence: 
                        The operator #, followed by a parameter name, is replaced by a string literal that contains the argument passed (as if enclosed between double quotes):
                            # define str(x) #x
                            cout << str(test);
                    
                    - This would be translated into:
                            cout << "test";
                    
                    - The operator ## concatenates two arguments leaving no blank spaces between them:
                            #define glue(a,b) a ## b
                            glue(c,out) << "test";
                    
                    - This would also be translated into:
                        cout << "test";
                    
                    -   Note that # and ## operators are primarily used in standard Template Library (STL). They should be avoided at other places. As CPP replacements happen before any C++ syntx check, macro definitions can be a tricky. code that relies heavily on complicated macros become less readable, since the syntax expected  is on many occasions different from the normal expression  programmers expects in C++

        - Conditional Compilation
            - #ifdef
                    - Conditional Inclusions: #ifdef, #ifndef, #if, #endif, #else, #elif
                        - These directives allow to include or discard part of the code of a program if a  certain condtions is met. This is known as conditional Inclusion or Conditional Compilation
                        - #ifdef (if defined) allows a section of a program to be compiled  only if the macro that is specified as the parameters has been #define,  no matter which its value is. For example :
                            #ifdef TABLE_SIZE
                            int tabkle[TABLE_SIZE];
                            #endif
                        In this case, the line of code int table[TABLE_SIZE]; is only complied if TABLE_SIZE was previously defined with #define, independently of its value. If it was not defined, that line will not be included in the program compilation
                        - #ifndef (if not defined) servers for the exact opposite: the code between #ifndef and #endif directives  is only compiled if the specified identifier has not been previously defined. For example:
                            #ifndef TABLE_SIZE
                            #define TABLE_SIZE 100
                            #endif
                            int table[TABLE_SIZE];
                        IN this case, If when arriving at this piece of code, the TABLE_SIZE macro has not been defined yet, it would be defined to a value of 100, if it already existed it would keep its previous value since the 
                        #define directive would not be executed.
            - #if
                - 
                    - The #if, #else and #elif (else if) directives serve to specify some condition to be met in order for the portion of code they surround to be compiled. The condition that follows #if or #elif can only evaluate constant expressions, including macro ex-pressions. For example:

                        #if TABLE_SIZE>200
                        #undef TABLE_SIZE
                        #define TABLE_SIZE 200

                        #elif TABLE_SIZE<50
                        #undef TABLE_SIZE
                        #define TABLE_SIZE 50

                        #else
                        #undef TABLE_SIZE
                        #define TABLE_SIZE 100
                        #endif

                        int table[TABLE_SIZE];
                    - Notice how the entire structure of #if #elif
                    and #else chained directive ends with #endif

                    - The behavior of #ifdef and #ifndef can also be achived by using the special operators defined and !defined (not defined) respectively in any #if or #elif directive :

                        #if defined ARRAY_SIZE
                        #define TABLE_SIZE ARRAY_SIZE 
                        #elif !defined BUFFER_SIZE
                        #define TABLE_SIZE 128
                        #else
                        #define TABLE_SIZE BUFFER_SIZE
                        #endif
            
            - Use-Cases
                    - Typical Use- Cases
                        - Commonenting a large chunk of code: We often need to comment a large piece of code. Doing that with C/C++ - style comment is a challenge unless the Editor provides some handy support. So we can use:
                            #if 0 // "0" is taken as false and the codes till the #endif are excluded Code lines to comment
                            #endif

                        - Selective debugging of code : We often need to put a lot of code the purpose of debugging which we do not want when the code is built for release with optimization. This can be managed by a _DEBUG flag
                            #ifdef _DEBUG
                            Code for debugging like print messages
                            #endif

                        Then we build the code for debugging as:
                            $ g++ -g -D _DEBUG file_1.cpp, file_2.cpp,.........,file_n.cpp
                        And we build the code for release as (_U _DEBUG may be skipped if there is no built-in definition):
                            $ g++ -U _DEBUG file_1.cpp, file_2.cpp, ........., file_n.cpp

                        - Controlling code from bulid command line:  Suppose our project has support for 32-bit as well as 64-bit (default) and only one has to be chosen. So we can build for 32-bit using a flag _BITS32
                            $ g++ -D _BITS32 file_1.cpp, file_2.cpp,...........,file_n.cpp
                        And code as:
                            #ifndef _BITS32
                            Code for 64-bit
                            #else
                            Code for 32-bit 

        - Source File Inclusion
            - #include
                - When the preprocessor finds an #include directive it replaces it by the entire content of the specified header or file. There are two ways to use #include:

                    #include <header>
                    #include "file"
                - In the first case, a header is sopecified between angle-brackets <>. This is used to include headers rpovided by the implementation, such as the headers that compose the standard library (iostream,string,.....). Whether the headers are actually files or exits in some other form is implementation-defined, but in any case they shall be properly included with this directive.
                -  The syntax used in the second #include uses quotes, and includes  a file. The file is searched for in an implementation-defined manner, which generally includes the current path. In the case that the file is not found, the compiler interprets the directive as a header inclusion, just as if the quotes("") were replaced by angle-brackets(<>)

                - We can include a file by - include file option from the command line. So
                    using namespace std; // #include <iostream> skipped for illustration 
                    int main(){
                        cout << "Helo" << "\n";
                        return 0;
                    }
                Would still compile fine with : 
                    $ g++ "Hello.cpp" -include iostream
            - #include Guard
                - Inclusions of header files may lead to the problems of multiple inclusion and  / or Circular Inclusion
                - An #include guard, sometimes called a macro gaurd, header guard or file guard, is a particular construst used to avoid the problem of double inclusion when dealing with the include directive 
                - Mulitple Inclusion: Consider the following files:
                    - Without Guard 
                        // File "grandparent.h"
                        struct foo {int member;};
                        
                        //  File "parent.h"
                        #include "grandparent.h"
                        #include "parent.h"

                        // Expanded "child.c": WRONG
                        // Duplicate definition
                        struct foo {int member; };
                        struct foo {int member; };

                    - WIth guard
                        //  File "grandparent.h"
                        #ifndef GRANDPARENT_H /// Undefined first time 
                        #define GRANDPARENT_H // Defined for the first time
                        struct foo {int member};
                        #endif /* GRANDPARENT_H */

                        //  File "parent.h"
                        #ifndef PARENT_H
                        #define PARENT_H
                        #include "grandparent.h"
                        #endif /* PARENT_H */

                        // File "child.c"
                        #include "grandparent.h"
                        #include "parent.h"

                        //  Expand "child.c" RIGHT: Only one definition
                            struct foo{int member; };

                    - Circular Inclusion: Consider the following files:
                        - Without Guard
                            - Class Flight: Needs the info of service provider
                            - Class Service: Needs the info of flights it offers

                                #include <iostream> // File main.h
                                #include <vector>
                                using namespace std;

                                #include "main.h" // file service.h
                                #include "Flight.h"
                                class Flight;
                                class Service {
                                    vector<Flight*>m_Flt; /*.......*/
                                };
                                
                                #include "main.h" // File Flight.h
                                #include "Service.h"
                                class Service;
                                class Flight { Service* m_pServ; /*.......*/};
                                
                                #include "main.h" // File main.cpp
                                #include "Service.h"
                                #include "Flight.h"
                                int main(){
                                    /*......*/
                                    return 0;
                                }
                            - Class Flight and Class Service has cross - refrences
                            - Hence, Circular inclusion of header files lead to INFINIte loop during compilation

                        - With Guard 
                            - 
                                #include<iostream> // File main.h
                                #include<vector>
                                using namespace std;

                                #ifndef __SERVICE_H
                                #define __SERVICE_H
                                #include "main.h" // File Service.h
                                #include "Flight.h"
                                class Flight;
                                class Service {vector<Flight*> m_Flt; /*......*/};
                                #endif // __SERFVICE_H

                                #ifndef __FLIGHT_H
                                #define __FLIGHT_H
                                #include "main.h" // File Fight.h
                                #include "Service.h"
                                class Service;
                                class Flight {Service* m_pServ; /*......*/};
                                #endif // __FLIGHT_H

                                #include "main.h" // File main.cpp
                                #include "Service.h"
                                #include "Flight.h"
                                int main(){/*......*/ return 0; };


        - #line, #error
            - Line Control : #line and Error directive #error
                - When we complie a program and some error happens during the compiling process, the compiler shows an error message with refrences to the name of the file where the error happened and a line number, so it is easier to find the code generating the error.

                - #line directive allows us to control both things, the line numbers within the code files as well as the file name that we want appers when an error takes place. Its format is:
                    #line number "filename"
                Where number is the new line number that will be assigned to the next code line. The line numbers of successive lines will be increased one by one from this point on.
                "filename" is an optional parameter that allows to redefine the file name that will be shown. For example :
                #line 20 "assigning variable"
                int a?;
                This code will generate an error that will be shown as error in file "assigning variable", line 20

                - #error directive aborts the compilation process when it is found. generating a compilation error that can be specified as its parameter:
                    #ifndef __cplusplus
                    #error A C++ compiler is required!
                    #endif
                This example aborts the compilation process if the marco name __cplusplus is not defined (this macro name is defiend by default in all C++ compilers) 
        
        - #pragma
            - Pragma directive : 
                - This directive is used to specify diverse options to the compiler. These options are specific for the platfrom and the compiler you use. Consult the manual or the refrence of your compiler for more information on the possible parameters that you can define with #pragma
                - If the compiler dose not support a specific argument for #pragma, it is ignored - no syntax error is generated 
                - Many compilers, including GCC, supports #pragma one which can be used as #include guard. So 
                    #ifndef __FLIGHT_H
                    #define __FLIGHT_H
                    #include "main.h" // File Flight.h
                    #include "Service.h"
                    class Service;
                    class Flight{Service* m_pServ; /*.......*/};
                    This is clearly, but may have portability issue across machines and compilers
            t
        - Standard Marcos 
                - __LINE__, __FILE__, __DATE__, __TIME__, __cplusplus, __STDC_HOSTED__, __STDC__, __STDC_VERSION_,__STDCPP_THREADS__, __STDCPP_STRICT_POINTER_SAFETY__,__STDC_ISO_10646__,__STDC_MB_MIGHT_NEQ_WC__, // check the modern C++ screensho
            
            - Standard Macro Examples
                -Consider 
                    // standard macro names
                    #include <iostream>
                    using namespace std;
                    int main(){
                        cout << "This is the line number " <<< __LINE__;
                        cout << "\n of file " << __FILE__;
                        cout << "\nIts compilation began " << __DATE__;
                        cout << " at " << __TIME__;
                        cout << "\nThe compiler giver a __cplusplus value of " << __cplusplus;
                        return 0;
                    }
                - The output is : 
                    Modern C++ file :
                    This is the line number 170 of file practice with c++ modern.cpp Its compilation began Jul 27 2022 at 06:15:47 The compiler giver a __cplusplus value of 201703
        - Note that __LINE__, __FILE__,__DATE__,__TIME__ important for details in error reporting 
Summary:
        - Understood the differences and relationships between source and header files
        - Understood how CPP can be harnessed to manage code during bulid

- Weekly Recap 
    - Understood the importantce and ease of C++ in programming 
    - KYC - Pre- requisites, Outline, Evaluation and Textbooks and References 
    - Understood some fundamental differences between C & C++:
        - IO, VAriable Declaration, and loops
        - Arrays and Strings
        - Sorting and Seraching 
        - Stack and common containers in C++
        - Various Standard Library in C and C++ 
*/ 
/* Sample Source and header files in C
 Header File: fact.h: includes the header for fact() funciton
 Source File: fact.c: Provides the implementation of fact()  function
 Source File: main.c: Uses fact() function to compute factorial of given values

 File fact.h
 Header for factorial function
 */
#ifndef __FACT_H // include Guard. check
#define __FACT_H // include Guard . define 
int fact(int);
#endif // __FACT_H // include Guard. Close 
// File fact.c
// Implementation of factorial function 
#include "fact.h" // user Header 
int fact(int n){
    if(0==n)
    return 1;
    else 
    return n*fact(n-1);
}
//  File main.c
// Application using factorial funciton
#include<stdio.h> // c std. library header 
#include "fact.h" // user header 
int main(){
    int n,f;
    printf("Input n : "); // from stdio.h
    scanf("%d",&n);
    f=fact(n);
    printf("Fact(n) = %d", n,f); // from stdio.h
    return 0;
}

/* Header file: Solver.h include the header for quadraticEquationSolver() function
Source file : solver.c: Provides the implementation of quardaticEquationSolver() function
Source file: main.c : USe quadraticEquationSolver() to solver a quadratic equation
*/
// File solver.h
// user header files
#ifndef __SOLVER_H // Include Guard. Check 
#define __SOLVER_H // Include Guard. define
int quadraticEquationSolver(double,double,double,double*,double*);
#endif // __SOLVER_H // include Guard. close 
//  file Solver.c
//  user implementation files
#include<math.h> // s std library header 
#include "Solver.h" // user header 
int quadraticEquationSolver(double a, double b, double c, double* r1, double* r2){
    uses double sqrt(double) from math.h
    return 0;
}
//  file main.c
//  application files
#include<stdio.h> // C std. Library header
#include "Solver.h" // user header
int main(){
    double a,b,c,r1,r2;
    // .....
    // Invoke the solver function from solver.h
    int status = quadraticEquationSolver(a,b,c,&r1,&r2);
    //  int prinf(char *format .......)from stdio.h
    printf("Sol. for %dx^2+%dx+%d=0 is %d %d",a,b,c,r1,r2);
    //  ....
    return 0;
}
//  in C++
/* Header file: Solver.h include the header for quadraticEquationSolver() function
Source file : solver.cpp: Provides the implementation of quardaticEquationSolver() function
Source file: main.cpp : USe quadraticEquationSolver() to solver a quadratic equation
*/
// File solver.h  ... user header files
#ifndef __SOLVER_H // Include Guard. Check 
#define __SOLVER_H // Include Guard. define
int quadraticEquationSolver(double,double,double,double*,double*);
#endif // __SOLVER_H // include Guard. close 
//  file Solver.cpp
//  user implementation files
#include<math.h> // s std library header in c++
using namespace std;
#include "Solver.h" // user header 
int quadraticEquationSolver(double a, double b, double c, double* r1, double* r2){
    uses double sqrt(double) from math.h
    return 0;
}
//  file main.c
//  application files
#include<iostream> // C++ std. Library header
using namespace std;
#include "Solver.h" // user header
int main(){
    double a,b,c,r1,r2;
    // .....
    // Invoke the solver function from solver.h
    int status = quadraticEquationSolver(a,b,c,&r1,&r2);
    //  int prinf(char *format .......)from stdio.h
    cout <<"Sol. for" << a << "x^2+ " << b << "x+" << c << " = 0";
    cout << r1  << r2 << "\n;
        //  ....
    return 0;
}

// 
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
# define NO_OF_CHARS 256
using namespace std;
class D1{
    public:
    void D2(char *s,int *c){
        int i;
        for(i=0;*(s+i);i++)
        c[*(s+i)]++;
    }
    void D3(char *s){
        int *c = (int*)calloc(NO_OF_CHARS,sizeof(int));
        D2(s,c);
        for(int i=0;i<NO_OF_CHARS;i++)
            if(c[i]>1)
                printf("%c\t\t\t%d \n",i,c[i]);
        free(c);
    }
};
void D(int n){
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    for(int p{n};p*p>=2;p--){
        if(prime[p]==true){
            for(int i{n};i>=p*p;i-=p)
            prime[i]=false;
        }
    }
    for(int p{n};p>=2;p--)
        if(prime[p])
            cout << p << " ";
}
int C(const void * a,const void * b){
    if(*(int*)a < *(int*)b)
    return -1;
    if(*(int*)a == *(int*)b)
    return 0;
    if(*(int*)a > *(int*)b)
    return 1;
}
class Array_x{
    private:
        int *A;
        int size;
        int length;
    public:
        Array_x(int size){
            this->size=size;
            A=new int[size];
        }
        void create(){
            length = 5;
            for(int i{0};i<length;i++){
                A[i]=10;
            }
        }
        void display(){
            cout << "\n\nThe array elements are : ";
            for(int i{0};i<length;i++){
                cout << A[i] << " ";
            }
        }
        ~Array_x(){
            delete[] A;
            cout << "\nThe array is destroyed! \n\n";
        }
};
// Array_insertion 
struct Array{
    int A[10];
    int size;
    int length;
};
void display(struct Array arr_x){
    cout << "The arr_xay elements are : ";
    for(int i{0};i<arr_x.length;i++){
        cout << arr_x.A[i] << " ";
    }
}
void append(struct Array *arr_x, int x){
    if(arr_x->length < arr_x->size){
        arr_x -> A[arr_x -> length] = x;
        arr_x -> length++;
    }
}
void insert(struct Array *arr_x, int index, int x){
    if(index>=0 && index<arr_x -> length){
        for(int i{arr_x -> length}; i>index; i--){
            arr_x -> A[i] = arr_x -> A[i-1];
        }
        arr_x -> A[index] = x;
        arr_x -> length++;
    }
}
int main(){
    int d[]={12,3,2,4,5,21,34},k=0;
    if(bsearch(&k,d,7,sizeof(int),C))
        printf("found!");
    else
        printf("\n\nnot found!\n\n");
    cout << "\n";rotate(d,d+2,d+7);
    for(int i{0};i<7;i++)
        cout << d[i] << " ";
    D1 a;
    char s[]="I want this for my better future..please try to understand..";
    cout << "\nThe duplicate character in this string : ";
    cout << "\nCharacter\tCount\n";
    a.D3(s);
    int n{124};cout<<"\nPrime descending order series : " << n << "\n"; 
    D(n);cout << "\n\nArray : - ";
    Array_x a5(10);
    a5.create();
    a5.display();

    struct Array a_x = {{1,2,3,4,5},10,5};
    cout << "\n\nThe initial array is : \n";
    display(a_x);

    append(&a_x, 100);
    cout << "\nArrat after appending 100 : \n";
    display(a_x);

    insert(&a_x, 0 , 200);
    cout << "\nArray after insertion of 200 : \n";
    display(a_x); 
    
    int A[10];
    cout << "\n\nA : [";
    for(int i{0};i<10;i++){
        cout << A[i] << " "; // All are garbage value.
    }
    int B[5]{10,20,30,40,50};
    cout << "]\nB : [";
    for(int i{0};i<5;i++){
        cout << B[i] << " ";
    }
    float C[7]{1.2,2.3,4.4,5.5,7.7,6.87,9.01};
    cout << "]\nC : [";
    for(int i{0};i<7;i++){
        cout << C[i] << " ";
    } 
    int D[]{100,200,300};
    cout << "]\nD : ";
    for(int i{0};i<3;i++){
        cout << D[i] << " ";
    }
    cout << "]\n";
    int a_xx[5]{1,2,3,4,5};
    cout << a_xx[3] << "\n";
    int *p;p=new int[5];p[0]=1;p[1]=2;p[2]=3;p[3]=4;p[4]=5;
    cout << p[2] << "\n";

    int P[3][4];
    int Q[2][3]{{1,2,3},{3,4,5}};

    int  *CC[2];
    CC[0] = new int[3];
    CC[1] = new int[3];

    int **DD;
    DD = new int*[2];
    DD[0] = new int[3];
    DD[1] = new int[3];

    cout << "Modern C++ file : " << "\n";
    cout << "This is the line number " << __LINE__;
    cout << "\n of file " << __FILE__;
    cout << "\nIts compilation began " << __DATE__;
    cout << " at " << __TIME__;
    cout << "\nThe compiler giver a __cplusplus value of " << __cplusplus;
    return 0;
}
// #include<iostream>
// using namespace std;
// #define getmax(a,b) ((a)>(b) ?(a):(b))
// int main(){
//     int x{5},y;
//     y=getmax(x,3);
//     cout << y << "\n" << getmax(7,x) << "\n";
//     return 0;
// }
