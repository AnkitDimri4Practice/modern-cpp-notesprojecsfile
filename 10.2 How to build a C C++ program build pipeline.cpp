 :: What is the build pipelines? Especially with reference to GCC
 :: HOw to work with C/C++ dialects during build?
 :: Understanding C/C++ standard Libraries  

    1. Build pipeline 
        The C preprocessor (CPP) has the ability for the inclusion of header files, macro expansions, conditional compilation, and line control. It works on .c, .cpp and .h files and produces .i files 
        The Compiler translate the pre-processed C/C++ code into assembly language, which is a machine level code in text that contains instructions that manipulate the memrory and processor directly. It works on .i files and produces .s files 
        The Assembler translates the assembly program to binary machine language or object code. It works on .s files and produces .o files 
        The Linker links our program with the pre-complied libraries for using their functions and generates the executable binary. It works on .o (static library), .so (shared library or dynamically linked library), and .a (library archive) files and produces a.out file 
            File extentions mentioned here are for GCC running on Linux. These may very on other OSs and for other Compilers. Check the respective doucumentation for details. The build pipeline, however, would be the same. 
            
        Compilers, IDE, and Debuggers
            :: The recommended compiler for the course is GCC, the GNU Compiler Collection - GNU Project. To install it (with gbd, the debugger) on your system, follow::
                Windows:: How to install gdb in windows 10 on YOUTube
                Linux:: USually comes bundle in Linux distribution. Check manual 
            You may also use online versions for quick tasks 
                GNU online compiler 
                    From language Drop-down, choose C(C99), C,C++(C++11),C++14 or C++17
                    To mark the language for gcc compilation, set -std=<compiler_tag>
                        Tags for C are: ansi, C89,C90,C11,C17,C18 etc..
                        Tags for C++ are : ansi, C++98, C++03,C++11,C++14,C++17,C++20 etc.
                        Check options Controlling C Dialect and Language Standard Supported by GCC (Accessed 13-sept-21)

                Code::Blocks is a free, open source Cross-platfrom IDE that supports multiple compilers including GCC, Clang and Visual C++
                Programiz Online Complier Supports C18 and C++14 
                OneCompiler supports C18 and C++17 

            For a compiler, you must know the language version you are compiling for - check to conform   

        gcc and g++
            What is GCC ?
            GCC stands for GNU Compiler Collections which is used to compile mainly C and C++ language 
            It can also be used to compile Objective C, Objective C++m Fotran, Ada, Go, and D 
            The most important option required while compiling a source code file is the name of the source program, rest every argument is optional like a warning, debugging, linking libraries, object file, etc.
            The different options of GCC command allow the user to stop the compilation process at different stages. 
            g++ Command  is a GNU C++ compiler invocation command, which is used for preprocessing, compilation, assembly and linking of source code to generate an executable file, The different "option" of g++ command allow us to stop this process at the intermediate stage. 

        What is the difference between gcc and g++?
        
            g++                                                         gcc
            g++ is used to compile C++ program                          gcc is used to compile C proram 
            g++ can compile any .c or .cpp files but they               gcc can compile any .c or .cpp files but they will
                will be treated as C++ files only                           be treated as C and C++ respectively 
            Command to compile C++ program by g++ is:                   Command to compile C program by gcc is :
                g++ fileName.cpp -o binary                                  gcc fileName.c -o binary -lstdc++
            Using g++ to link the object files, files automatically     gcc does not do this and we need to specify -lstdc++
                links in the std C++ libraries.                             in the command line 
            g++compiling .c/.cpp files has a few extra macros           gcc compiling .c files has less predefined macro
                                                                        -s. gcc compiling .cpp files has a few extra
                                                                        macros.
            #define __GXX_WEAK__ 1
            #define __cplusplus 1 
            #define __DEPRECATED 1 
            #define __GNUG__ 4
            #define __EXCEPTIONS 1
            #define __private_extern__ extern          
        ------------------------------------------------------------------------------------------------------------------
        
        --> Build with GCC
            Options : 
                [1] : Place the source (.c) and header (.h) files in current directory 
                        11-09-2021    10:46             157 fact.c
                        11-09-2021    10:47             124 fact.h
                        11-09-2021    10:47             263 main.c
                [2] : Compile source files (.c) and generate object (.o) files using option "-c". Note additions of files to directory 
                    $ gcc -c fact.c
                    $ gcc -c main.c

                    11-09-2021    11:02             670 fact.c
                    11-09-2021    11:02             1,004 main.c 
                [3] : Link object (.o) files and generate executable (.exe) file of preferred name (fact) using option "-o". Note added file directory 
                    $ gcc fact.o main.o -o fact
                    11-09-2021    11.03             42,729 fact.exe
                [4] : Execute 
                    $ fact 
                    Input n 
                    5 
                    fact(5 = 120
                [5] : We can combine steps [2] and [3] to generate executable directly by compiling and linking source files in one command
                    $ gcc fact.c main.c -o fact 
                [6] : We can only compile and generate assembly language (.s) file using option "-S"
                    $ gcc -S fact.c main.c
                    11-09-2021    11.34             519 fact.s
                    11-09-2021    11.34             1,023 main.s
                [7] : To stop after  prepossessing use option "-E". The Output us generated in stdout (redirected here to cppout.c)
                    $ gcc -E fact.c main.c > cppout.c 
                    11-09-2021    11.32             21,155 cppout.c
                    Note that CPP:
                        Produces a single file containing the source from all .c files 
                        Includes all required header files(like fact.h stdio.h) and strips off unnecessary codes present there 
                        Strips off all comments 
                        Textially replaces all manifest constants and expands all macros 
                [8] : We can know the version of the compiler 
                    $ gcc --version 
                        gcc (MinGw.org GCC-6.3.0-1) 6.3.0
                        Copyright (C) 2016 Free software Foundation, Inc.
                        This is free software; see the source for copying conditions. There us NO warranty; not evan for MERCHANTABLITY or FITNESS FOR A PARTICULAR PURPOSE. 
                [9] : When we intend to debug our code with gdb we need to use "-g" option to tell GCC to emit extra information for use by a debugger 
                    $ gcc -g fact.c main.c -o fact 
                [10] : We should always compile keeping it clean of all warning. This can be done by "-Wall" flag.  For example if we comment out f = fact(n); and try to build we get warning, w/o "-wall", it is silent 
                    $ gcc -Wall main.c  
                    main.c: In function 'main':
                    main.c:14:5: warning: 'f' is used uninialized in this function [-Wuninitilaized]
                        printf("fact(%d) = %d\n",n,f);
                        ----------------------------
                    $ gcc main.c

                With "-Werror", all warnings are treated as errors and no output will be produced 

                [11] : We can trace the commands being used by the compiler using option "-v", that is, verbose mode 
                    $ gcc -v fact.c main.c -o fact
                     
                    Using built-in specs. 
                    COLLECT_GCC=gcc 
                    COLLECT_LTO_WRAPPER=c:/mingw/bin/../libexec/gcc/mingw32/6.3.0/lto-wrapper.exe 
                    Target:mingw32 
                    [truncated]
                    Thread model: win32 
                    gcc version 6.3.0 (MinGW.org GCC-6.3.0-1)
                    [truncated] 

        --> Build with GCC: Summary of options anD Extensions
            gcc options and file extentsions. Note that .c  is shown as a placeholder for user provided source file. A detailed list of source file extension are given in the next point 

            option                          Behaviour                                           Input               Output
                                                                                             Extension              Extension 
                -c          Compile or assemble the source files, but do  not link                .c,.s,.i                   .o
                -S          Stop after the stage of compilation proper; do not assemble              .c,.i                   .s
                -E          Stop after the preprocessing stage                                          .c            To stdout
                -o file     Place the primary output in file file(a.out w/o -o)                   .c,.s,.i       Default for OS 
                -v          Print the commands executed to run the stages of compilation          .c,.s,.i            To stdout 

            Source file (user provided) extentions 
                Extension           File Type                   Extension                   File Type 
                .c            C source code that must be        .cpp, .cc, .cp, .cxx        C++ source code that
                                Preprocessed                      .CPP, .c++, .C            must be preprocessed 
                .h          C/C++ header file                   .H, .hp, .hxx, .hpp      C++ header file
                                                                   .HPP,.h++, .tcc         
                .s          Assembler code                      .S, .sx                     Assembler code that 
                                                                                           must be preprocessed
            
            * Varied extensions for C++ happened during its evolution due various adoption practices 
            * We are going to follow the extensions  marker in red 
   
    2. C/C++ Dialects
        C Dialects 
            K&R C       C89/C90     C95     C99        C11      C18 
                We check the language version (dialect) of C being used by GCC in compilation using the following code 
                    File check C Version.c // Comment
                    #include<stdio.h>
                    int main(){
                        if (__STDC_VERSION__ == 201710L) printf("C18\n");       // C11 with bug fixes 
                        else if (__STDC_VERSION__ == 201112L) printf("C11\n");
                        else if (__STDC_VERSION__ == 199901L) printf("C99\n");
                        else if (__STDC_VERSION__ == 199409L) printf("C89\n");
                        else printf("Unrecognized version of C\n");
                        return 0;
                    }
                We can ask GCC to use a specific dialect by using -std flag and check with the above code for three cases 
                    $ gcc -std=c99 "Check C Version.c"
                    C99 
                    $ gcc "Check C Version.c"
                    C11
                    $ gcc -std=c11 "Check C Version.c"
                    C11 
                Default for this gcc is c11 

        C++ Dialects 
            C++98       C++11       C++14       C++17       C++20
                Checking for a dialect 
                    We check the language version (dialect) of the C++ being used by GCC in Compilation using the following code 
                        // File check C++ version.cpp 
                        #include<iostream>
                        int main(){
                            if (__cplusplus == 201703L) std::cout << "C++17\n";
                            else if (__cplusplus == 201402L) std::cout << "C++14\n";
                            else if (__cplusplus == 201103L) std::cout << "C++11\n";
                            else if (__cplusplus == 199711L) std::cout << "C++98\n";
                            else std::cout << "Unrecoginized version of C++\n";
                            return 0;
                        } 
                    We can ask GCC to use a specific dialect by using -std flag and check with the above code for four cases 
                        $ g++ -std=gnu++98 "Check C++ Version.cpp"
                        C++98
                        $ g++ -std=gnu++11 "Check C++ Version.cpp"
                        C++11
                        $ g++ -std=gnu++14 "Check C++ Version.cpp"
                        C++14
                        $ g++ "Check C++ Version.cpp" 
                        C++14

                        Default for this g++ is C++14

    3. Standard library 
        What is standard library ?
            A standard library in programming is the library made available across implementations of a language.
            These libraries are usually described in language specifications (C/C++); however, they may also be determined (in part or whole) by informal practices of a language's community (Python)
            A language's standard library is often treated as part of the language by its users, although the designers may have treated it as a seperate entity 
            Many language specifications define a core set that must be made available in all implementations, in addition to other portions which may be optionally implemented 
            The line between a language and its libraries therefore differs from language to language 
            Bjarne Stroustrup, desginer of C++, writes 
                What ought to be in the standard C++ library? One ideal is for a programmer to be able to find every interesting, significant, and reasonably general class, function, template, etc. in a library. However, the question here is not, "What ought to be in some library? but "What ought to be in  the standard library?" The answer "Everything!" is a reasonable first approximation to an answer to the former question but not the latte. A standard library is something every implementer must supply so that every programmer can rely on it. 
            This suggest a relatively small standard library, containing only the construct that "every programmer" might reasonably require when building a large collection of software
            This is the philosophy that is used in the C and C++ standard libraries 

        C standard library 
            
            C Standard Library: Common Library Components 
            Component           Data Types, Manifest Constants, Macros, Functions......
            stdio.h             Formatted and un-Formatted file input and output including functions 
                                printf, scanf, fprintf,fscanf, sprintf, sscanf, feof, etc
            stdlib.h            Memory allocation, process control, conversions, pseudo-random numbers, searching, sorting 
                                malloc, free, exit, abortm atoi, strtoldm rand, bsearch, qsort, etc 
            string.h            Manipulation of C strings and arrays 
                                strcat, strcpy, strcmp, strlen, strtok,memcpy,memmove,etc
            math.h              Common mathematical operations and transformations 
                                cos, sin, tan, acos, asin, atan, exp,log, pow, sqrt.etc 
            errno.h             Macros for reporting and retrieving error conditions throgh error codes stored in a startic memory location called errno 
                                EDOM (parameter outside a function's domain - sqrt(-1)),
                                ERANGE(result outside a function's range), or 
                                EILSEQ (an illegal byte sequence), etc. 
                            
            A header file typically contains manifest constants, macros, necessary struct / union types typedef's, function prototype, etc...\
        
        C++ Standard Library    
                Common Library Components 
                    Components           DataTypes, Manifest Constants, MAcros, Functions, Classes...
                    iostream             Stream input and output for standard I/O
                                         cout, cin,endl.....etc 
                    string              Manipulation of string objects 
                                        Relational operators, IO operators, Iterators, etc..
                    memory              high-level memory management 
                                        Pointers : unique_ptr, shared_ptr, weak_ptr, auto_ptr & allocator etc. 
                    exception           Genric Error Handling exception, bad_exception, unexpected_handler, 
                                            terminate_handler, etc 
                    stdexcept           Standard Error Handling     Logic_error, invalid_argument, domain_error, 
                                        length_error, out_of_range, runtime_error, range_error, overflow_error,
                                        underflow_error, etc

                                        Adopted from C standard Library 
                                ----------------------------------------------------------
                                
                    cmath               Common mathematical operations and transfromations
                                        cos, sin, tan, acos, asin, atan, exp, log, pow, sqrt, etc
                    cstdlib             memory alloc,. process control, convesions, pseudo-rand nos,
                                        malloc, free, exit, abort, atoi, strtold, rand, bsearch, qsort, etc 
                                    

            std
                namespace std for C++ Standard Library 
                    C Standard Library                                  C++ Standard Library 
                    All names are globle                                All names are within std namespace 
                    stdout, stdin, printf, scanf                        std::cout, std::cin
                                                                        Use using namespace std;
                                                                        to get rid of writing std:: for every standard library name

                        W/o using                                               W/using 
                        #include<iostream>                                  #include<iostream>
                        int main(){                                         using namespace std;
                            std::cout << "Hello World in C++"               int main(){
                            << std::endl;                                       cout << "Hello " << endl;
                            return 0;                                              return 0;
                        }                                                    } 

            Header Conventions
                :: C/C++ Header Conventions 
                                                    C Header                                C++ Header 
                    C program       Use .h Example: #include<stdio.h>                       Not applicable 
                                    Names in global namespace                           
                    C++ Program     prefix c, no .h Example: #inlcude<cstdio>               No. .h Example: 
                                    Names in std namespace                                  #include<iostream>
                    A C std library header is used in C++ with prefix 'c' and without the .h These are in std namespace 
                        #include<cmath>     // IN C it is <math.h>
                        .....
                        std::sqrt(5.0); // use with std::
                        It is possible that a C++ program include a C header as in C like:
                        #include<math.h> // Not in std namespace 
                        .....
                        sqrt(5.0); // Use with std:: 
                        This however, is not preferred 
                    
                    Using .h with C++ header files, like iostream.h, is disastrous. These are deprecated. It is dangerous, yet true, that some compilers do not error out on such use. Exercise caution. 
 
    4. Tutorial Summary 
        Understood the overall build process for a C/C++ project with specific reference to the build pipeline of GCC 
        Understood the management of C/C++ dialects and C/C++ Standard Libraries 

        ----------------------Complete---------------------------