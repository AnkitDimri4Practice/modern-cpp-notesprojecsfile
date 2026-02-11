- To understand the role of libraries in C/C++ projects 
- To learn about Static and Shared libraries - how to build and use them 
    -
    - Tutorial Outline

            1. What is a Library?
                - A Library is a package of code that is meant to be reused by many programs. Typically, a C/C++ Library comes to two pieces: 
                    - A header file that defines the functionality the Library is exposing (offering) to the programs using it. For example, stdio.h, math.h, etc. in C and iostream, vector, etc. in C++ 
                    - A pre-compiled binary that contains the implementation of that functionality pre-complied into machine language. For example, glibc is the GNU C (Standard) Library on Unix 

                    Some libraries may be split into multiple files and / or have multiple header files 

                - libraries are pre-compiled because 
                    - As libraries rarely change, they do not need to be recompiled  often. They can just be reused in binary 
                    - As pre-compiled objects are in machine language, it prevents people from accessing or changing the source code protecting IP 
                        (A.1 - Static and Dynamic libraries (Accessed  23-08-21))

                
                - Types of Library 
                    - Static Library 
                        - Consists of routines that are Compiled and linked into the program. A program compiled with a Static Library would have the functionality of the library as a part of the executable. 
                        - Extensions : 
                            - Unix: .a (archive)
                            - Windows: .lib 
                    - Dynamic / Shared Library 
                        - Consists of routines that are loaded into the application at run time 
                        - Extensions: 
                            - Unix: .so (Shared object) 
                            - Windows: .dll (Dynamic link library)                    
                    - Import Library 
                        - An import library automates the process of loading and using a Dynamic library 
                        - Extensions: 
                            - Unix: Shared object(.so) file doubles as both a Dynamic and an import library 
                            - Windows: A small Static library (.lib) of the same name as the Dynamic library (.dll). The static library is linked into the program at compile time, and then the functionality of the Dynamic  library can effectively be used as if it were a static library. 
                            

                    - Static vs Shared
                            - Static Library : Library code is internal to Application  

                                                                                                    Stack    
                                                                                                    |   | 
                                                                                                     Heap 
                        Source files -------                        Application file           Application code 
                                            |Static Linker ---------> Static libraries ------> static libraries  
                        static libraries----
                    
                        - Application needs to recompile - difficult version management 
                            - If library implementation changes regular with version upgrade / bug fixes 
                            - And naturally, if library interface changes - infrequent 
                        - large footprint - especially bad for mobile apps 
                        - multiple copies of the same library may be loaded as part of different applications - bad for mobile apps 
                        - Fast in speed as the library is already laoded and linked 

                    - Dynamic 
                            -   Shared / Dynamic Library : Only Library reference is internal to Application - Library code is external 

                                                                                                                    Stack    
                                    -------------------------------------------------------------------------| Dynamic libraries | 
                                    |                                                                                Heap 
                        Dynamic libraries -------                           Application file                    Application code 
                                                | Static Linker ---------> Dynamic library references  ------> Dynamic library references  
                            Source Files -------

                        - Application does not need to recompile - easy version management 
                            - If library implementation changes regular with version upgrade / bug fixes 
                            - However, it will need to recompile (Like the static library), if library interface changes - infrequent 
                        - Small footprint - especially good for mobile apps 
                        - Single copy of the library will be loaded for different applications - good for mobile apps 
                        - The functions in the library needs to be re-entrant. Care is needed with static variables
                        - Slow in speed as the library may need to be loaded and linked at run-time. 

                    - Static vs Shared Library 

                        Static         |program A|                    |Program B|  <--------------| Static Linking at compile Time 
                        Linking        Static libraries(*.a)        |Static libraries(*.a)--------|


                        Dynamic         |Program A|                          |Program B|                  |Application|     |Application|   |Application|    |Application|
                        Linking             |---------Shared libraries(*.so)-------|                      |  Code "A" |     |  Code "B" |   |   Code    |    |    Code   |
                                                    Dynamic Linking at run-time                           |           |     |           |   |    "A"    |    |    "B"    |
                                                                                                          | Static    |     |   Static  |   \           \    /           /
                                                                                                          | Library   |     |   Library |    \           \  /           /
                                                                                                                                              \           \/           /
                                                                                                                                               \          / \         /
                                                                                                                                                \        /   \       /
                                                                                                                                                |  Shared Library   |
                                                                                                                                                ---------------------
                    - 
                        _____________________________________________________________________________________________________________________________________________________________
                            Property       |                          Static Library                          |        Shared Library 
                        _____________________________________________________________________________________________________________________________________________________________
                           - Commpilation  | - Recompilation is required for changes in external files        | -  No need to recompile the executable 
                           - Linking time  | - Happens as the last step of the Commpilation process           | - Are added during linking when executable file 
                                           |                                                                  |  and libraries are added to the memory
                           - Import /      | - Are resolved in a caller at compile-time and copied into a     | - Get imported at the time of execution of target program by the OS 
                            Mechanism      |     target application by the linker                             |
                           - Size          | - Are bigger in size, because external programs                  | - Are smaller, because there is only one copy of shared library that
                                           |                                                                  |      is kept in memory 
                           - External      | - Executable file will have to be recompiled if any changes were | - No need to recompile the executable - only the shared library is   
                            file changes   |     applied to external files                                    |       replaced
                           - Time /        | - Takes longer to execute, as loading into memory Happens every  | - Faster because shared library is already in the memory  
                            Perfomance     |    time while executing                                          |
                           - Compatibility | - Never has Compatibility issue, since all code is in one        | - Programs are dependent on having a compatible library 
                                           |    executable module                                             |       
                        _____________________________________________________________________________________________________________________________________________________________

            2. Our Library project 
                - We present a tiny project to illustrate the ideas of static and shared / Dynamic libraries 
                - We use the same set of header and source files to create and use 
                    - Static Library 
                    - Shared / Dynamic Library 
                  and compare them 
                - First the projects are created with gcc. These can work on Unix as well as Windows (with minGW: MinGW - Minimalist GNU for Windows)
                - Then we show Microsoft-specific process on Windows 
            
                - 
                    /* lib_myMath.h: Header for my mathematical functions */ /* CPP guards omitted for brevity */
                        int myMax(int, int);
                        int myMin(int, int); 
                    /* lin_myMath.c: Implementation for my mathematical functions */
                        #include "lib_myMath.h" 
                        int myMax(int a, int b) { return a>b? a: b; }
                        int myMax(int a, int b) { return a<b? a: b; }
                    /* lib_myPrint.h: Header for my printing function */ /* CPP guards omitted for brevity */
                        void myPrint(const char*, int);
                    /* lib_myPrint.c: Implementation for my printing function */
                        #include <stdio.h>
                        #include "lib_myPrint.h"
                        void myPrint(const char *name, int a) { printf("%s : %d\n", name, a); }
                    /* myApp.c: My application */
                    #include <stdio.h>
                    #include "lib_myMath.h"
                    #include "lib_myPrint.h"
                    int main(){
                        myPrint("Max(3,5)", myMax(3,5));
                        myPrint("Min(3,5)", myMin(3,5));
                    }

                - Project : Folders and Code Organization 

                        : Home // Library demonstration project with library as well as application Home = Static or Shared 
                        |
                        -------- app Application files - will use library header from ... /inc and library from .../lib 
                        |       -------myApp.c      // Application Source File 
                        |       -------myApp.exe    // Application Executable 
                        |       -------myApp.o      // Application Object file 
                        |       -----myMakeApp.txt  // Application Makefile 
                        |
                        ----------inc // Headers to be included in application and library build 
                        |       --------lib_myMath.h 
                        |       --------lib_myPrint.h
                        |
                        -------lib // Library files 
                                |
                                --------- obj // Library object files 
                                |       ------- lib_myMath.o
                                |       ------- lib_myPrint.o 
                                |
                                -------- src // /Library source files - will use library headers from... /..../inc
                                |       ------ lib_myMath.c 
                                |       ------ lib_myPrint.c 
                                |
                                -------- lib_mylib.a    // Static Library binary file linked by the application 
                                -------- lib_mylib.so   // Shared Library binary file linked by the application 
                                -------- myMakeLibrary.txt // library Makefile 


            3. Static Library Project 
                - Build Steps 
                    - We can build  this project by 
                        $ gcc lib_myMath.c lib_myPrint.c myApp.c -o myApp 
                    - Every time myApp.c is updated, we build lib_myMath.c and lib_myPrint.c even if there is no change. We can avoid the recompile by retaining the object files as : 
                        $ gcc -c lib_myMath.c lib_myPrint.c 
                        $ GCC lib_myMath.o lib_myPrint.o myApp.c -o myApp 
                    - When we have many such files that rerely change, we would have a lot of such .o files to maintain. These can be bundled into an archive lib_mylib.a for ease of reference 
                        $ ar rcs lib_mylib.a lib_myMath.o, lib_myPrint.o 
                            - GNU ar utility creates, modifies, and extracts from archives (like ZIP) - holding a collection of multiple files in a structure that makes it possible to retrieve the individual files (called members) 
                            - Option rcs asks to create (c) an archive with replacement (r) of members and indexing (s) 
                            - For details check : ar(1) - Linux manual page 
                    - Finally we use the  .a file in place of the .o's to link to myApp.o' 
                        $ gcc -o myApp myApp.c lib_myLib.a -L.
                            Alternately, we can place lib_myLib.a in default library path and link by -l_mylib 
                        $ gcc -o myApp myApp.c -l_mylib -L. 

                - Static Library project : Makefiles
                    __________________________________________________________________________________________________________________________________________    
                            Static Library Makefile                             |           Application Makefile               
                    __________________________________________________________________________________________________________________________________________
                        # variables                                             |  # variables   
                        CC=gcc                                                  | CC=gcc 
                        AR=ar                                                   | IDIR=inc 
                        SDIR=src                                                | LDIR=lib
                        IDIR=../inc                                             | CFLAGS=-I../$(IDIR)
                        ODIR=obj                                                | LFLAGS=-L../$(LDIR)
                        CFLAGS=-I$(IDIR)                                        | DEPS= 
                        LFLAGS=-L.                                              |
                        AFLAGS=rcs                                              |    

                        # Macros                                                |
                        _DEPS  = lib_myMath.h lib_myPrint.h                     |
                        DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))               |
                        _SRC = lib_myMath.c lib_myPrint.c                       |
                        SRC = $(patsubst %,$(SDIR)/%, $(_SRC))                  |
                        _OBJ = lib_myMath.o lib_myPrint.o                       |
                        OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))                 |

                        #Rules                                                  | # Rules
                        $(ODIR)/%.o: $(SDIR)/%.c $(DEPS)                        | %.o: %.c $(DEPS)
                            $(CC) -c -o $@ $< $(CFLAGS) -I                      |   $(CC) -c -o $@ $< $(CFLAGS)
                        %.o: $(SDIR)/%.c $(DEPS)                                | myApp: myApp.o
                            $(CC) -c -o $@ $< $(CFLAGS)                         |   $(CC) -o myApp myApp.o -l_mylib $(CFLAGS)
                        lib_myLib.a: $(OBJ)                                     |
                            $(AR) $(AFLAGS) -o $@ $^                            |
                    __________________________________________________________________________________________________________________________________________
                
                - Execution Trace
                    - Static Library Project : Execution Trace 
                        - Let us build and execute the project 
                            
                            // Build Library 
                            D:\Library\Static\lib $ make -f myMakeLibrary.txt   
                            gcc -c -o obj/lib_myMath.o src/lib_myMath.c -I../inc -I. 
                            gcc -c -o obj/lib_myPrint.o src/lib_myPrint.c -I../inc -I. 
                            ar rcs -o lib_myLib.a obj/lib_myMath.o obj/lib_myPrint.o 

                            // Build Application 
                            D:\Library\Static\lib $ make -f myMakeApp.txt 
                            gcc -c -o myApp.o myApp.c -I../inc 
                            gcc -o myApp myApp.o -l_mylib -L../lib 

                            // Run Application 
                            D:\Library\Static\lib $ myApp.exe 
                            Max(3,5): 5
                            Min(3,5): 3 
                        
                        - So the static library is working as expected  
                        - Next we check on the contents of various folder

                    - Static Library Project : Directory Listing 
                        Directory of D:\Library\Static 
                            26-092021  14:58    <DIR>           app 
                            26-092021  14:58    <DIR>           inc 
                            26-092021  14:58    <DIR>           lib 
                        Directory of D:\Library\Static\app
                            24-09-2021  15:53               179 myApp.c 
                            26-09-2021  11:35               42,348 myApp.exe 
                            26-09-2021  11:35               954 myApp.o 
                            25-09-2021  13:23               215 myMakeApp.txt 
                        Directory of D:\Library\Static\inc 
                            24-09-2021  13:17               66 lib_myMath.h
                            24-09-2021  13:17               54 lib_myPrint.h 
                        Directory of D:\Library\Static\lib    
                            26-09-2021  11:33               1,722 lib_myLib.a 
                            25-09-2021  13:22               524 myMakeLibrary.txt 
                            26-09-2021  14:58    <DIR>      obj 
                            26-09-2021  14:58    <DIR>      src 
                        Directory of D:\Library\Static\lib\obj 
                            26-09-2021  11:33               716 lib_myMath.o
                            26-09-2021  11:33               778 lib_myPrint.o 
                        Directory of D:\Library\Static\lib\src 
                            24-09-2021  13:16               143 lib_myMath.c 
                            24-09-2021  13:18               144 lib_myPrint.c 
            __________________________________________________________________________________________________________________________________________                
                          
            4. Shared / Dynamic Library Project 
                - Build Steps 
                    - As in the static case, first we compile lib_myMath.c  and lib_myPrint.c to create the object (.o) files using the option -fPIC: 
                    $ gcc -fPIC -c lib_myMath.c lib_myPrint.c 
                        - -fPIC stands to mean: Compile for Position Independent Code (PIC) 
                            - For a shared Library, the binary of the library and the application are seperate  and will be seperately laoded at run time  
                            - So when the object files are generated, we need that all jump calls and subroutine calls to use relative addresses, and not absoulte addresses 
                            - -fPIC flags tells gcc to generate this type of code  

                        - Next step of building the library gets different now as we do not use ar. Rather we use gcc -shared -o lib_mylib.so lib_myMath.o lib_myPrint.o 

                        - This Creates a shared library lib_mylib.so where the extension .so stands for a shared object 
                        - Finally we use the .so file to link to myApp.o 
                            $ gcc -o myApp myApp myApp.c lib_myLib.so -L 
                        - Alternately , we can place lib_myLib.so in default library path and link by -l_mylib 
                            $ gcc -o myApp myApp.c -l_mylib 

                - Shared Library project : Makefiles 
                    __________________________________________________________________________________________________________________________________________    
                            Static Library Makefile                             |           Application Makefile               
                    __________________________________________________________________________________________________________________________________________
                        # variables                                             |  # variables   
                        CC=gcc                                                  | CC=gcc 
                                                                                | IDIR=inc 
                        SDIR=src                                                | LDIR=lib
                        IDIR=../inc                                             | CFLAGS=-I../$(IDIR)
                        ODIR=obj                                                | LFLAGS=-L../$(LDIR)
                        CFLAGS=-I$(IDIR)                                        | DEPS= 
                        LFLAGS=-L.                                              |
                                                                                |    

                        # Macros                                                |
                        _DEPS  = lib_myMath.h lib_myPrint.h                     |
                        DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))               |
                        _SRC = lib_myMath.c lib_myPrint.c                       |
                        SRC = $(patsubst %,$(SDIR)/%, $(_SRC))                  |
                        _OBJ = lib_myMath.o lib_myPrint.o                       |
                        OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))                 |

                        #Rules                                                  | # Rules
                        $(ODIR)/%.o: $(SDIR)/%.c $(DEPS)                        | %.o: %.c $(DEPS)
                            $(CC) -fPIC -c -o $@ $< $(CFLAGS) -I                |   $(CC) -c -o $@ $< $(CFLAGS)
                        lib_mylib.so: $(OBJ)                                    | myApp: myApp.o
                            $(CC) -shared -o $@ $^                              |   $(CC) -o myApp myApp.o ../$(LDIR)/lib_mylib.so
                    __________________________________________________________________________________________________________________________________________
                

                - Execution Trace 
                    - Shared Library project: Execution Trace 
                        - Let us build execute the project  
                            // Build Library 
                                 D:\Library\Shared\lib $ make -f myMakeLibrary.txt 
                                gcc -fPIC -c -o obj/lib_myMath.o src/lib_myMath.c -I../inc -I. 
                                gcc -fPIC -c -o obj/lib_myPrint.o src/lib_myPrint.c -I../inc -I. 
                                gcc -shared -o lib_mylib.so obj/lib_myMath.o obj/lib_myPrint.o 

                            // Build Application  
                            D:\Library\Shared\app $ make myApp.exe 

                        Oops! The shared library is not found! The system does not know that lib_mylib.so is in 
                        D:\Library\Shared\lib 
                                myApp.exe - system Error 
                                    * The code execution cannot processed because lib_mylib.so was not found. Reinstalling the program may fix this problem.  okay      
                    -
                                            - If we copy lib_mylib.so to the application folder D:\Library\Shared\app (where myApp.exe resides), the problem goes away and the application runs sucessfully 
                        // Run Application 
                        D:\Library\Shared\app $ myApp.exe 
                        Max(3,5): 5 
                        Min(3,5): 3 
                    - So the shared library is working as expected 
                        - However, Copying the shared library to the application folder is not preferred as we would need to copy lib_mylib.so the every application that would use it. 
                        - We shall discuss a solution to this library path problem in the next section 
                    - Next we check on the contents of various folders and compare the size of the libraries amd application in static and shared cases 

                            Static Library      ||          Shared Library      ||                  Remarks 
                        ____________________________________________________________________________________________________________________________________________
                        lib_myLib.a    |  1,722 ||  lib_mylib.so    |  27,749   ||  File .so is larger than .a  due to the overhead of exproted references. With 
                                                                                ||     large number of functions in the library (as opposed to just 3) the relative 
                                                                                ||     overhead will go down 
                        ____________________________________________________________________________________________________________________________________________
                        myApp.exe      | 42,348 || myApp.exe        | 41,849    || Shared .exe would be relatively much smaller with more functions in the library. 
                        ____________________________________________________________________________________________________________________________________________

                
                - Static Library Project : Directory Listing 
                        Directory of D:\Library\Shared 
                            26-092021  14:58    <DIR>           app 
                            26-092021  14:58    <DIR>           inc 
                            26-092021  14:58    <DIR>           lib 
                        Directory of D:\Library\Shared\app
                            24-09-2021  15:53               179 myApp.c 
                            26-09-2021  11:45               41,849 myApp.exe 
                            26-09-2021  11:45               954 myApp.o 
                            26-09-2021  09:41               220 myMakeApp.txt 
                        Directory of D:\Library\Shared\inc 
                            24-09-2021  13:17               66 lib_myMath.h
                            24-09-2021  13:17               54 lib_myPrint.h 
                        Directory of D:\Library\Shared\lib    
                            26-09-2021  11:44               27,749 lib_mylib.so 
                            25-09-2021  10:38               457 myMakeLibrary.txt 
                            26-09-2021  14:58    <DIR>      obj 
                            26-09-2021  14:58    <DIR>      src 
                        Directory of D:\Library\Shared\lib\obj 
                            26-09-2021  11:44               716 lib_myMath.o
                            26-09-2021  11:44               778 lib_myPrint.o 
                        Directory of D:\Library\Shared\lib\src 
                            24-09-2021  13:16               143 lib_myMath.c
                            24-09-2021  13:18               144 lib_myPrint.c 
            __________________________________________________________________________________________________________________________________________
            - Shared Library Project : Set Library Path
                - We managed to make the application work by Copying the shared library to the application folder.  However, this is not preferred as we would need to copy lib_mylib.so to every application that would use it.   
                - So we need to tell the location for a shared library to the system. This can be done in one of three ways: 
                    - Place the shared library file in one of the default library folder like /usr/local.lib, /usr/local/lib64, usr/lib and usr/lib64 (on Unix) or like C:\Windows\system32-64a and C:\Windows (on Windows). 
                            Refer to the system manual details on these folders 
                    - Add the folder of the library to the library search folders by setting path / environment variables : 
                        : Windows: Use PATH 
                        : UNIX : Use LD_LIBRARY_PATH 
                    - We may also Dynamically Load / Unload a library at the run-time. This is known as late binding. This is archived by using dlopen(), dlsys(), dlclose() from dlfcn.h header 

            -> Windows : 
                - Windows : Set environment variables PATH to include the folder of the shared library 
                    // Check PATH 
                    D:\library\Shared\app $ PATH 
                    PATH=C:\Windows\system32;... 

                    // Set PATH 
                    D:\Library\Shared\app $ SET PATH=%PATH%;D:\Library\Shared\lib 
                    
                    // Check PATH 
                    D:\Library\Shared\app $ myApp.exe 
                    Max(3,5): 5
                    Min(3,5): 3
                        - PATH would be rest when we end the command session. Ned to set it every time 
                        - We may set the folder in PATH Environment Variable - Use (preferred) or System to retain it accross sessions. Refer: How to set the path and environment variables in Windows 
            
            -> Set Library Path : Unix 
                - Unix : Set environment Variable LD_LIBRARY_PATH to include the Directory of the shared library as follows : 
                    > For Tcsh or csh: 
                        $ setenv LD_LIBRARY_PATH/full/path/to/library/directory:${LD_LIBRARY_PATH}
                    > For sh, bash  and similar : 
                        LD_LIBRARY_PATH=/full/path/to/library/directory:${LD_LIBRARY_PATH}
                        export LD_LIBRARY_PATH 
                Note: 
                    - LD_LIBRARY_PATH is a list of directories in which to search for ELF libraries at execution time 
                    - The items in the list are seperarted by either colons or semicolons, and there is no support for escaping either seperator 
                    - A zero-length directory name indicates the current working directory   

                __________________________________________________________________________________________________________________________________________

                - Late Binding and Dynamic Loading 
                    - Dynamic Loading 
                        - We can link shared libraries to a process anytime during its life without automatically loading the shared library by the dynamic laoder 
                        - We can do this by using the 'dl' library - load a shared library, reference any of its symbols, call any of its functions and finally detach it from the process when no longer needed 
                        - This is useful when there may be multiple shared libraries for the same (similar) purpose and we get the know which one to link only at the run-time 
                        - The steps invoked are: 
                            - Load the library from its path using dlopen() and get its handle 
                            - Use the handle to get access (function pointers) to the specific functions we intend to use by dlsym()
                            - Use the function pointers to call the functions in the shared library 
                            - Finally, Unload the library with dlclose() 
                        - We first present a simple schematic example 
                    
                    -> late Binding 
                        : Known as [Late Binding] as the actual functions to be called are decide only at the run-time  
                            __________________________________________________________________________________________________________________________________________
                                Application                                             ||                Library   
                            __________________________________________________________________________________________________________________________________________
                                #include <dlfcn.h>                                      ||      #include <iostream>
                                int main(){                                             ||      using namespace std;
                                    void* handle =                                      ||  extern "C" void hello() { cout << "hello\n"; }
                                    dlopen("hello.o", RTLD_LAZY);                       ||
                                    /*RTLD_LAZY : Relocations shall be performed at     
                                    an implementation-defined time, ranging from the 
                                    time of the dlopen() call untill the first 
                                    reference to a given symbol occurs */               ||
                                    typedef void (*hello_t)();                          ||
                                    hello_t my = 0;                                     ||
                                    myHello = (hello_t) dlsym(handle, "hello");         ||
                                    myHello();                                          ||
                                    dlclose(handle);                                    ||
                                } 
                            __________________________________________________________________________________________________________________________________________

                        - Now we present our project in the context of late binding  
                    
                    - Dynamic Loading 

                            /* myDynamicApp.c */
                            #include <stdio.h>
                            #include <stdlib.h>
                            #include "lib_myMath.h"
                            #include "lib_myprint.h"
                            #include <dlfcn.h> /* defines dlopen(), dlsym(), and dlclose() etc. */
                            int main(){
                                void* lib_handle; /* handle of the opened library */ 
                                const char* error_msg; /* Pointer to an error string */
                                /* Load the shared library */
                                lib_handle = dlopen("D:\Library\Shared\lib\lib_mylib.so", RTLD_LAZY); /* Library path - dynamic */
                                if (!lib_handle){ error_msg = dlerror(); goto Error; }
                                /* Define function pointers */
                                int (*myMax)(int, int); int (*myMin)(int, int); void (*myPrint)(const char*, int); 
                                /* Locate the functions in the library. Pick by name and assign to the function pointer */
                                myMax = dlsym(lib_handle,"myMax"); if(error_msg = dlerror()) goto Error; 
                                myMin = dlsym(lib_handle,"myMin"); if(error_msg = dlerror()) goto Error;
                                myPrint = dlsym(lib_handle,"myPrint"); if(error_msg = dlerror()) goto Error;  
                                /* Call the functions */
                                (*myPrint)("Max(3,5)", (*myMax)(3,5));
                                (*myPrint)("Min(3,5)", (*myMin)(3,5));
                                /* Unload the shared library */
                                dlclose(lib_handle);
                                return 0; /* Success */
                                Error : fprintf(stderr, "%s\n", error_msg); exit(1); /*Exit on error*/
                            }
            ____________________________________________________________________________________________________________________________________________        

            5. Dynamic Link Library (DLL) Project : Windows 
                - Microsoft Visual C++ Static and Dynamic libraries 
                - Walkthrough : Create and use a static library 
                - Walkthrough: Create and use your own Dynamic Link Library (C++)
                - How to link DLLs to C++ Projects 
                _________________________________________________________ 
            
            - White static and shared library of UNIX (specifically GNU) is available on Windows through minGW, Windows provides Microsoft specific support through MSVC 
                - Static Library : To work with a static library : 
                    - We need to create a static library and an application project (that refers to the library project) using the MSVS IDE 
                        - Check: Walkthrough: Create and use a static library 
                    - No change in the library or application codes is needed 

                - Dynamic Link Library (DLL): To work with a DLL : 
                    - We need to create a DLL and an application project (that refers to the DLL project) using the MSVS IDE 
                        - Check: Walkthrough: Create and use your own Dynamic Link Library (C++)
                    - We need to change the library and / or application codes with dllexport and dllimport - the Microsoft-specific storage-class attributes for C and C++ 
                        - Check: dllexport, dllimport 
                    - These can be specified by __declspec() to export and import functions , data, and objects to or from a DLL 
                    - We modify the library project file to illustrate  

                - Using dllexport 
                    - 
                        /* lib_myMath.h: Header for my mathematical functions*/      /*File changed for export*/ 
                        __declspec(dllexport) int myMax(int, int);      // storage-class attributes __declspec(dllexport) used 
                        __declspec(dllexport) int myMin(int, int);     //  to export function from DLL. This is MS-specific 
                    
                    - 
                        /* lib_myMath.c: Implementation for my mathematical functions */ /* No change */ 
                        #include "lib_myMath.h" 
                        int myMax(int a, int b) { rerturn a>b? a: b; }
                        int myMin(int a, int b) { rerturn a<b? a: b; }

                    - /* lib_myPrint.h : Header for my printing function */ /* File changed for export */
                    __declspec(dllexport) void myPrint(const char*, int); 

                    /* lib_myPrint.c: Implementation for my printing function */ /* Non change */
                    #include <stdio.h> 
                    #include "lib_myPrint.h" 
                    void myPrint(const char *name, int a) { printf("%s : %d\n", name, a); }

                    /* myApp.c My application */ /* No change */
                    #include <stdio.h>
                    #include "lib_myMath.h" 
                    #include "lib_myPrint.h"
                    int main(){
                        myPrint("Max(3,5)", myMax(3,5));
                        myPrint("Min(3,5)", myMin(3,5));
                    }
                _________________________________________________________
            - Using dllimport 
                - In the context of the DLL headers, 
                /* lib_myMath.h */
                __declspec(dllexport) int myMax(int, int);
                __declspec(dllexport) int myMin(int, int);

                /* lib_myPrint.h */ 
                __declspec(dllexport) void myPrint(const char*, int);
                    the application project may include the DLL headers or can just directly import the symbols by dllimport 

                    including DLL Headers                   |               using dllexport 
                    ________________________________________________________________________________________
                    /* myApp.c : My application */          | /* myApp.c : My application */
                    #include <stdio.h>                      |       --------------
                    #include "lib_myMath.h"                 |       --------------
                    #include "lib_myPrint.h"                |    Storage - class attribute __declspec(dllimport) used 
                                                            |    to import function from DLL. This is MS-specific 
                                                            |   __declspec(dllimport) void myPrint (const char*, int);
                    int main() {                            |   int main(){
                        myPrint("Max(3,5)", myMax(3,5));    |       myPrint("Max(3,5)", myMax(3,5)); 
                        myPrint("Min(3,5)", myMin(3,5));    |       myPrint("Min(3,5)", myMin(3,5));        
                    }                                       |   }
                    ________________________________________________________________________________________

            6. Tutorial Summary 
                - Understood the role of libraries in C/C++ project in reuse 
                - learn about Static and Shared libraries in Unix and Windows - how to  build and use them 
                - learn about DLLs 
    ___________________________________________________________________________Complete __________________________________________________________________________________


 