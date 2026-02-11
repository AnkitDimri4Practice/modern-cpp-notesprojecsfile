Tutorial Objective 
    > Building a software project is a laborious, error-prone, and time consuming process. So it calls for automation by Scripting
    > make, primarily from GNU, is the most popular free and open source dependency-tracking builder tool that all software developers need to know 

Tutorial Outline 
    
    2. make Utility
        > Example Build
            > Consider a tiny project comprising three files - main.c, hello.c and hello.h in a folder 
                main.c                           |           hello.c                                 hello.h 
        ________________________________________________________________________________|_______________________________________
                #include "hello.h"               |       #include <stdio.h>             |         // example include file
                                                 |       #include "hello.h"             |         #ifndef __HEADER_H
                int main() {                     |                                      |         #ifndef __HEADER_H
            /*call a function in another file */ |       void myHello(void){            |
                    myHello();                   |           printf("Hello World!\n");  |         void myHello(void);
                    return 0;                    |           return;                    |    
                }                                |       }                              |         #endif  // __HEADER_H
        ________________________________________________________________________________________________________________________

            > We build this by executing the command in the current folder (-I.) : 
                gcc -o hello hello.c main.c -I. // Generates hello.o & main.o and removes at the end 
                Which actually expands to : 
                    gcc -c hello.c -I.  // Compile and Generate hello.o
                    gcc -o main.c -I. // Compile and Generate main.o
                    gcc -o hello hello.o main.o -I. // Link and Generate hello 
                    rm -f hello.o main.o // Is it really necessary? .hello.o & main.o may be retained 

        > Why make?
            > Why we need make Utility?
                > This manual process of build be difficult in any practical software project due to : 
                    > [Volume] projects have hundreds of folders, source and header files. They need hundreds of commands. It is time-taking to type the commands and is error-pron.
                    > [Workload] Build needs to be repeated several times a day with code changes in some file/ 
                    > [Dependency] often with the changes in one file. All translation units do not need to be re-compiled (Assuming that we do not remove .o files). For example
                        > If we changes only hello.c, we do not need to execute     
                            gcc -c main.c -I. // main.o is already correct 
                        > If we changes only main.c, we do not need to execute 
                            gcc -c hello.c -I. // hello.o is already correct 
                        > However, if we change hello.h, we need to execute all 
                        There are dependencies in build that can be exploited to optimize the build effort 
                    > [Diversity] Finally, we may need to use differnt build tools for differnt files, differnt build flags, differnt folder structure etc. 
                > This calls for automation by scripting. GNU Make is a tool which controls the generation of executables and other non-source files of a program from the program's source files.' 

    
    3. Anatomy of a makefile 
            > target [target ...]: [component ...]
            Tab[command 1]
                        .
                        .
                        .
            Tab[command n]
        > Simple makefile 
            > makefile : Anatomy 
                > A Simple make file would be like (makefile_1.txt): 
                    hello: hello.c main.c
                        gcc -o hello hello.c main.c -I. 
                    Write these lines in a text file named makefile or Makefile and run make command and it will execute the command: 
                        $ make 
                        gcc -o hello hello.c main.c -I. 
                > Make file comprises a number of Rules. Every rules has a target to build, a colon separator (:), zero or more files on which the target depends on and the commands to build on the next line
                    hello: hello.c main.c #Rule 1 
                        gcc -o hello hello.c main.c -I. 
                > Note : '
                    > There must be a tab at the beginning of any command. Spaces will not work! 
                    > If any of the file in the dependency (hello.c or main.c) changes since the last time make was done(target hello was built), the rule will fire and the command (gcc) will execute. The is decided by the last update timestamp of the files 
                    > Hash (#) starts a comment that continues till the end of the line 
                    
                   >   check the screenshot 
                  
        > Simple and Recursive Variables
            >  We can make the make file smarter(makefile_2.txt) using Variables:
                # CC is a simple Variable, gcc is its value 
                    CC := gcc 
                # CFLAGS is a Recursive Variable, -I. is its value 
                    CFLAGS = -I.

                hello: hello.c main.c           # Rule 1 
                    $(CC) -o hello hello.c main.c $CFLAGS 
                # $(CC) is value gcc of CC, $CFLAGS is value-I. of CFLAGS, Variables can be expands by $(.) or ${.}
            > If there are several commands, to change gcc to g++, we just need to change one line CC = g++. 
            > There are two types of Variables in make (chapter 3. Variables and Macros. O'Reilly.') 
                > Simply expanded varibales(defined by := operator) and evaluated as soon as encountered 
                > Recursively expanded variables (by=) and lazily evaluated, may be defined after use 
                        Simply Expanded                     Recurively Expanded 
                    MAKE_DEPEND := $(CC) -M                 MAKE_DEPEND = $(CC) -M 
                    ...                                     ... 
                    # Some time later                       # Some time later 
                    CC = gcc                                CC = gcc 
                                $(MAKE_DEPEND)$ expands to : 
                    <space>-M                               gcc -M 
        _____________________________________________________________________________________________________________________


        > Dependency 
            > We are still missing the dependency on the include(header) files. If hello.h changes, the above Rule 1 will not detect the need for a re-build. So we improve fruther (makefiles_3.txt): 
                CC = gcc 
                CFLAGS=-I.
                #Set of header files on which .c depends 
                DEPS = hello.h 

            # Rule 1: Applies to all files ending in the .o suffix 
            # The .o file depends upon the .c version of the file and the .h files in the DEPS macro 
            # To generate the .o file, make need to compile the .c file using the CC macro 
            # The -c flag says to generate the object file 
            # The -o $@ says to put the output pof the compilation in the file named on the LHS of : 
            # The $< is the first item in the dependencies list 
            %.o: %.c $(DEPS) 
                $(CC) -c -o $@ $<$(CFLAGS) 
            hello: hello.o main.o       # Rule 2 : Link .o files 
                $(CC) -o hello hello.o main.o -I. 

            > We can further simplify on the object files(makefiles_4.txt):
                CC=gcc 
                CFLAGS=-I.
                DEPS = hello.h
                #Set of object files on which executable depends 
                OBJ = hello.o main.o

                # Rule 1: Applies to all files ending in the .o suffix 
                %.o: %.c $(DEPS) 
                    $(CC) -c -o $@ $< $(CFLAGS) 

                # Rule 2: Linking dtep, Applies to the executable depending on the file in OBJ macro 
                # The -o $@ says to put the output of the Linking in the file named on the LHS of : 
                # The $^ is the files named on the RHS of : 
                hello: $(OBJ)
                    $(CC) -o $@ $^ $(CFLAGS)

        > Source Organization 
            makefile : code Organization 
                > Finally. let us introduce a source Organization that is typical of a large project where under a project Home folder, we have the following folders:
                    > Home: The make file and the following folders: 
                        > bin: The executable of the project. For example hello / hello.exe 
                        > inc: The include / header (.h) files of the project. For example hello.h 
                        > lib: The local library files(.a) of the project 
                        > obj: The object files (.o) of the project. For example hello.o & main.o 
                        > src: The source files (.c/.cpp) of the project. For example hello.c & main.c 
                    
                > makefile : Code Tree 
                    > Home // Project Home 
                    | 
                    ---bin     // Application binary 
                    |   |
                    |   -- hello.exe
                    |
                    ----inc // Headers files to be included in application 
                    |    |
                    |    ------- hello.h
                    |
                    ----lib // Library files to be linked to application. Check Tutorial Static and Dynamic Library 
                    |
                    ----obj // Object files
                    |   |
                    |   ---- hello.o 
                    |   ------ main.o
                    ---------src // source files 
                    |        |
                    |        ----- hello.o 
                    |        ----- main.o 
                    -------makefile     // Makefile 

            > Code Organization 
                > To handle this hierarchy, we modify as (makefiles_5.txt):
                    CC = gcc
                    # Folders
                    BDIR = bin 
                    IDIR = inc 
                    LDIR = lib 
                    ODIR = obj 
                    SDIR = src 
                    # flags 
                    CFLAGS = -I$(IDIR) 
                    # Macros 
                    _DEPS = hello.h # Add header files here 
                    DEPS = $(patsubst %,$(IDER)/%,$(_DEPS))
                    _SRC = hello.c main.c # Add source files here 
                    SRC = $(patsubst %,$(SDIR)/%,$(_SRC))
                    _OBJ =  hello.o main.o # Add source files here 
                    OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
                    # Rule 1: Object files 
                    $(ODIR)/%.o: $(SDIR)/%.c $(DEPS); $(CC) -c -o $@ $< $(CFLAGS) -I. 
                    # Rule 2: Binary File set binary file here 
                    $(BDIR)/hello: $(OBJ); $(CC) -o $@ $^ $(CFLAGS)
                    # Rule 3: remove Generated files.  .PHONY rule keeps make from doing something with a file named clean 
                    .PHONY: clean 
                    clean: ; del $(ODIR)\*.o $(BDIR)\*.exe
                    #        rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~  // */

    4. make Command 
        > Options and Freatures
            > The format of make command is : 
                make [ -f makefile ] [ options ] ... [ target ] ... 
             make executes commands in the makefile to update one or more target names 
                > With no -f, make looks for makefile, and Makefile. To use other files do: 
                    $ make -f makefile_1.txt 
                    gcc -o hello hello.c main.c -I. 
                > make update a target if its prerequisite files are dated. Starting empty obj & bin folders:
                    $ make -f makefile_5.txt obj/hello.o    // Build hello.o place in obj 
                    gcc -c -o obj/hello.o src/hello.c -Iinc -I. 
                > $ make -f makefile_5.txt obj/main.o   // Build main.o, place in obj 
                    gcc -c -o obj/main.o src/main.c -Iinc -I. 
                > $ make -f makefile_5.txt bin/hello   // Build hello.exe linking .o files and place in bin
                    gcc -c bin/hello obj/hello.o obj/main.o -Iinc 
                > $ make -f makefile_5.txt  clean   // Remove non-text files generated - obj/*.o & bin/*.exe
                    del obj\*.o bin\*.exe 
                > $ make -f makefile_5.txt                          // BY default target bin/hello and builds all 
                     gcc -c -o obj/hello.o src/hello.c -Iinc -I. 
                    gcc -c -o obj/main.o src/main.c -Iinc -I.  
                    gcc -o bin/hello obj/hello.o obj/main.o -Iinc

            > More make options / Freatures: 
                > To change to directory dir before reading the makefiles, use -C dir 
                > To print debugging information in addition to normal processing, use -d 
                > To specify a directory dir to search for included makefiles, use -I dir 
                > To print the version of the make program, use -v We are using 
                    GNU Make 3.81 
                    Copyright (C) 2006 Free software Foundation, Inc. 
                    This is free software; see the source for Copying conditions. 
                    There is NO warranty; not evan for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
                    This program built for i386-pc-mingw32 
                
                > make can be Recursive - one make file may include a command to make another 
                > Multiline: The backslash ("\ ") character gives us the ability to use multiple lines when the commands are too long
                    some_file: 
                        echo This line is too long, so \
                            it is broken up into multiple lines 
                > Comments: Lines starting with # are used for comments  
                > Macros: Besides simple and recursive variables, make also supports macros  

        > Capabilities and Derivatives 
            > make was created by Stuart Feldman in April 1976 at Labs and included in Unix since PWB/UNIX 1.0 He received the 2003 ACM Software Sysytem Award for make 
            > make is one of the most popular build utilities having the following major Capabilites : 
                > make enables the end user to build and install a package without knowing the details of how that is done (It is in the makefile supplied by the user)
                > make figures out automatically which files it needs to update, based on which source files have changed and automatically determines the proper order for updating files 
                > make is not limited to any particular language -C, C++, Java, and so on. 
                > make is not limited to building a package - can control installation/uninstallation etc. 
            > make has several Derivative and is available on all OS platforms: 
                > GNU Make(all types of UNIX) : Used to build many software systems, including: 
                    > GCC, the Linux kernal, Apache OpenOffice, LibreOffice, and Mozilla Firefox 
                    > Make for Windows, GnuWin32 (we are using here )
                    > Microasoft nmake, a command-line tool, part of Visual Stdio 
                    > Kati is Google's replacement of GNU Make, used in Android OS builds, It translates the makefile into Ninja (used for Chrome) for faster incremental builds 
    
    5. Tutorial Summary
        > Leran make, the most popular free and open source dependency - tracking builder tool, with its anatomy, architecture and options through a series of examples 


___________________________________________________________________________________Complete_____________________________________________________________________________