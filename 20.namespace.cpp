> Module objectives 
    > Understand namespace as a free scoping mechanism to organize code better. 
        
        - Module Outline 
            1. namespace Fundamental
                - namespace Fundamental 
                    > A namespace is a declarative region that provides a scope to the identifiers (the names of types, funtions, variables, etc) inside it 
                    > It is used to organize code into logical groups and to prevent name collisions that can occur especially when your code base includes multiple libraries 
                    > namespace provides a class-like modularization without class-like semantics 
                    > Obliviates the use of File Level Scoping of C (file) static 

                        > NameSpace Fundamental 
                            #include<iostream>
                            using namespace std;
                            namespace MyNameSpace {
                                int myData;                                                              // Variable in namespace 
                                void myFunction() { cout << "MyNameSpace myFunction\n"; }               // Function in namespace 
                                class MyClass { int data;                                               // class in namespace 
                                    public: 
                                    MyClass(int d) : data(d) { }
                                    void display() { cout << "MyClass data : " << data << "\n"; }
                                };
                            }
                            int main(){
                                MyNameSpace::myData = 10;       // variable name qualified by namespace name 
                                cout << "MyNameSpace::myData : " << MyNameSpace::myData << "\n";
                                MyNameSpace::myFunction();      // Function name qualified by namespace name 
                                MyNameSpace::MyClass obj(25);   // Class name qualified by namespace name 
                                obj.display();
                            }
                                > A name in a namespace is prefixed by the name of it 
                                > Beyond scope resolution, all namespace items are treated as global  
            
            2. namespace Scenarios 
                > Redefining a Library Function 
                    - cstdlib has a funtion int abs(int n); that returns the absolute value of parameter n 
                    - You need a special int abs(int n); function that returns the absolute value of parameter n if n is between -128 and 127. Otherwise, it returns 0 
                    - Once You add your abs, you cannot use the abs from library! It is hidden and gone! 
                    - namespace comes to your rescue 
                        _______________________________________________________________________________________________________________________________________
                                    Name-hiding: abs()                      |                                    namespace: abs()
                        _______________________________________________________________________________________________________________________________________
                            #include<iostream>                              |                        #inlcude<iostream>
                            #include<cstdlib>                               |                        #inlcude<cstdlib>
                                                                            |                        namespace myNS {
                            int abs (int mianint n){                        |                            int abs(int n) {
                                if(n<-128) return 0;                        |                                if(n < -128) return 0;
                                if(n>127) return 0;                         |                                if(n > 127) return 0;
                                if(n<0) return -n;                          |                                if(n < 0) return -n;
                                return n;                                   |                                return n;
                            }                                               |                             }
                                                                            |                        }
                            int main(){ std::cout << abs(-203) << " "       |                        int main(){
                                    << abs(-6) << " "                       |                                std::cout << myNS::abs(-203) << " " 
                                    << abs(77) < " "                        |                                << myNS::abs(-6) << " " 
                                    << abs(179) << std::endl;               |                                << myNS::abs(77) << " " 
                                                                            |                                << myNS::abs(179) << "\n";
                                // Output : 0 6 77 0                                                         // Output: 0 6 77 0
                            }                                               |                                 std::cout << abs(-203) << " " << abs(-6) 
                                                                            |                                << " " << abs(77) << " " << abs(179) << std::endl;
                                                                            |                                //output : 203 6 77 179 
                                                                            |                        }
                        _______________________________________________________________________________________________________________________________________

                
                > Students Record Application: The Setting 
                    - An organization is developing an application to process students records 
                    - class St for Students and class StReg for list of Students are: 

                        #include<iostream>
                        #include<cstring>
                        using namespace std;
                        class Students{
                            public:     // A student 
                            typedef enum GENDER { male = 0, female }; 
                            Students(char *n, GENDER g) : name(strcpy(new char[strlen(n) + 1], n)), gender(g){ }
                            void setRoll(int r) { roll = r; }   // Set roll while adding the student 
                            GENDER getGender() {return gender; }    // Get the gender for processing 
                            friend ostream& operator<< (ostream& os, const Students& s) {   // Print a record 
                                cout << ((s.gender == Students::male) ? "Male " : "Female ") << s.name <<  " " << s.roll << "\n";
                                return os;
                            }
                            private: char *name; GENDER gender; // name and gender provided for the student 
                            int roll;   // roll is assigned by the system 
                        };
                        class Students_Regestered { // Student's Register 
                            Students **rec; // List of students 
                            int nStudents;  // Number of students 
                            public: Students_Regestered(int size) : rec(new Students*[size]), nStudents(0) { }
                            void add(Students* s){ rec[nStudents] = s; s->setRoll(++nStudents); }
                            Students *getStudent(int r){ return (r == nStudents + 1) ? 0 : rec[r-1]; }
                        };
                            - The classes are included in a header file Students.h  
                        
                
                > Students Record Application : Team at Wc 
                        - Two engineers - Sabita and Niloy - are assigned to develop processing applications for male and female students respectively. Both are given the students.h file 
                        -  The lead Prunima of Sabita and Niloy has the responsbility to integrate what they produce and prepare a single application for both male and female students. The engineers produce:  
                        _______________________________________________________________________________________________________________________________________
                        Processing for males by Sabita                              |               Processing for females by Niloy 
                        _______________________________________________________________________________________________________________________________________
                                        App1.cpp                                    |                       App2.cpp
                        #inlcude<iostream>                                          |    #inlcude<iostream>
                        using namespace std;                                        |   -------------------------
                        #inlcude "Students.h"                                       |   -------------------------
                        extern Students_Regestered *reg;                            |   -------------------------
                        void ProcSt(){ cout << "MALE STUDENTS : \n";                |   ------------------------
                            int r = 1; Students *s;                                 |   ------------------------
                            while(s = reg->getStudent(r++))                         |   ------------------------
                                if(s->getGender() == Students::male) cout << *s;    |   ----------------- :: female
                            cout << "\n\n";                                         |   -------------------
                            return;                                                 |   ---------------------
                        }

                    ///////////////////////////main.cpp////////////////////////////////////////////////main.cpp/////////////////////////////////////////////
                    staring 3 lines are as alike above---
                    Students_Regestered *reg = new Students_Regestered(1000);       |       -------------------------
                    int main(){
                        Students s("Ravi", Students::male); reg->add(&s); ProcSt(); |       ----------------female 
                    }
                    _______________________________________________________________________________________________________________________________________


                > Students Record Application : integration Nightmares
                    > To integrate, Prunima prepares the following main() in her main.cpp where she intends to call the processing function for males (as prepareed by Sabita) and for females (as prepared by Niloy) one after the order: 
                            #include<iostream>
                            using namespace std;
                            #include "Students.h"
                            void ProcSt();  // Function from App1.cpp by Sabita 
                            void ProcSt();  // Function from App2.cpp by NIloy
                            Students_Regestered *reg = new Students_Regestered(1000);
                            int main(){
                                Students s1("Rhea", Students::female); reg->add(&s1);
                                Students s2("Ravi", Students::male); reg->add(&s2);
                                ProcSt();   // Function from App1.cpp by Sabita 
                                ProcSt();   // Function from App2.cpp by Niloy
                            }
                                > But the integration failed due to name clashes 
                                > Both use the same signature void ProcSt(); for their respective processing function. Actually, they have several function, classes, and variables in their respective development with the same name and with same / different purpose 
                                > how does Purnima perform the integration without major changes in the codes> - namespace 
                
                > students Record Application: Wrap in namespace 
                    > Introduce two namespaces - App1 for sabita and App2 for Niloy 
                    > Wrap the respective codes : 
                        _______________________________________________________________________________________________________________________________________
                        Processing FOR MALES BY SABITA                                  |                       Processing FOR FEMALE BY NILOY 
                        _______________________________________________________________________________________________________________________________________
                                        App1.cpp                                        |                       App2.cpp
                        #inlcude<iostream>                                              |    #inlcude<iostream>
                        using namespace std;                                            |   -------------------------
                        #inlcude "Students.h"                                           |   -------------------------
                        extern Students_Regestered *reg;                                |   -------------------------
                        namespace App1{ 
                            void ProcSt(){ cout << "MALE STUDENTS : \n";                |   ------------------------
                                int r = 1; Students *s;                                 |   ------------------------
                                while(s = reg->getStudent(r++))                         |   ------------------------
                                    if(s->getGender() == Students::male) cout << *s;    |   ----------------- :: female
                                cout << "\n\n";                                         |   -------------------
                                return;                                                 |   ---------------------
                            }                                                           |
                        };                                                              |
                        _______________________________________________________________________________________________________________________________________
                
                > Students Record Application : A Good Nights Sleep 
                    > Now the integration gets Smooth : 

                        using namespace std;
                        #include "Students.h"
                        namespace App1 { void ProcSt(); } // App1.cpp  cpp by sabita
                        namespace App2 { void ProcSt(); }  // App2.cpp  cpp by Niloy
                        Students_Regestered *reg = new Students_Regestered(1000);
                        int main(){
                            Students s1("Rhea", Students::female); reg->add(&s1);
                            Students s2("Ravi", Students::male); reg->add(&s2);
                            App1::ProcSt(); // App1.cpp by sabita 
                            App2::ProcSt(); // App2.cpp by Niloy
                            return 0;
                        }
                            - clashing names are made distinguishable by distinct names 
                            
            3. namespace Features 
                - Nested namespace
                    > A namespace may be nested in another namespace 
                        -  
                            #include<iostream>
                            using namespace std;
                            int data_1 = 0;               // Global name ::
                            namespace name1 {
                                int data_1 = 1;           // In namespace name_1
                                namespace name2 {
                                    int data_1 = 2;       // In nested namespace name_1::name_2 
                                }
                            }
                            int main(){
                                cout << data_1 << endl; // The data which is global is called data 
                                cout << name1::data_1 << endl;
                                cout << name1::name2::data_1 << endl;
                                return 0;
                            }

                - using namespace 
                    > Using using namespace we can avoid lengthy prefixes 
                        - 
                            #include<iostream>
                            using namespace std;
                            namespace name1 {
                                int v11 = 1; 
                                int v12 = 2;              
                            }
                            namespace name2 {   
                                int v21 = 3;
                                int v22 = 4; 
                            }
                            using namespace name1;  // All symbols of namespace name1 will be available 
                            using name2::v21;       // Only  v21 symbol of namespace name2 will be available 
                            int main(){
                                cout << v11 << endl;             // name1::v11
                                cout << name1::v12 << endl;     // name1::v12
                                cout << v21 << "\n";           // name2::v21
                                cout << name2::v21 << endl;   // name2::v21
                                cout << v22 << "\n";         // Treated as undefined 
                                // 'v22' was not declared in this scope; did you mean 'name2::v22'? 
                                return 0;
                            }

                - Global namespace 
                    > using or using namespace hides some of the names 
                        - 
                            #include<iostream>
                            using namespace std;
                            int data_1 = 0;             // Global Data 
                            namespace Name_1 {
                                int data_1 = 1;         // namespace Data 
                            }
                            int main(){
                                using Name_1::data_1;
                                cout << data_1 << "\n";             // name_1::data --- Hides global data_1
                                cout << Name_1::data_1 << "\n";     // 1
                                cout << ::data_1 << "\n";       // 0 // ::data_1 -- global data 
                            }
                                - Items in Global namespace may be accessed by scope resolution operator (::)

                - std namespace 
                    - Entire C++ standard Library  is put in its own namespace, called std 
                        _____________________________________________________________________________________________________________________________________________
                                    without using using std                             |                       With using using std
                        _____________________________________________________________________________________________________________________________________________
                            #include<iostream>                                          |   ---------------same
                                                                                        |   using namespace std;
                            int main(){                                                 |    -------------       
                                int num;                                                |       ----------
                                std::cout << "Enter the value : ";                      |       without std:: 
                                std::cin>>num;                                          |
                                std::cout << "Value is : ";                             |       -----------
                                std::cout << num;                                       |
                            }                                                           |       -----------
                                                                                        |
                            - Here, cout, cin are explicitly qualified by their         |   - By the statement using namespace std; std namespace is brought into
                            namespace. So to write to standard output, we specify       |   the current namespace which gives us direct access to the names of the 
                            std::cout; to read from standard input . we use std::cin    |   functions and classes defined within the library without having to 
                                                                                        |   qualify each one with std::
                            - It is useful if a few library is to be used; no need to   |   - When several libraries are to be used it is a convenient method 
                            add entire std library to the global namespace              |
                        _____________________________________________________________________________________________________________________________________________

                
                - namespace are Open 
                    - namespaces are Open 
                        - namespace are open: New Declarations can be added 
                            #include<iostream>
                            using namespace std;
                            namespace open{         // First definition 
                                int x = 30; 
                            }
                            namespace open {       // Additions to the last definition 
                                int y = 40;
                            }
                            int main(){
                                using namespace open;   // Both x and y would be available 
                                x = y = 20;
                                cout << "Output : " << x << " " << y << "\n";
                            }
            
            4. namespace vis-a-vis class 
                _______________________________________________________________________________________________________________________________________
                        namespace                                                          |                                  class 
                _______________________________________________________________________________________________________________________________________
                    - Every namespace is not a class                                       |  - Every class defines a namespace 
                    - A namespace can be reopened and more Declaration added to it         |  - A class cannot be reopened 
                    - No instance of a namespace can be created                            |  - A class has multiple instance 
                    - using-Declarations can be used to shortcut namespace qualification   |  - No using-like Declaration for a class 
                    - A namespace may be unnamed                                           |  - An unnamed class is not allowed 
                _______________________________________________________________________________________________________________________________________

            5. Lexical Scope 
                - The scope of a name binding - an association of a name to an entity, such as a variable - is the part of a computer program where the binding is valid: where the name can be used to refer to the entity 
                - C++ supports a variety of scopes: 
                    - Expression Scope - restricted to one expression, mostly used by compiler 
                    - Block Scope - created local context 
                    - Function Scope - created local context associated with a function 
                    - Class Scope - context for data members and member functions
                    - Namespace Scope - grouping of symbols for code organization 
                    - File Scope - limit symbols to a single file 
                    - Global Scope - outer-most, singleton scope containing the whole program 
                
                - Scopes may be named or unnamed 
                    - Named Scope - option to refer to the scope from outside 
                        - Class Scope - class name 
                        - Namespace Scope - namespace name or unnamed 
                        - Global Scope - "::"
                    
                    - unnamed Scope 
                        - Expression Scope 
                        - Block Scope 
                        - Function Scope 
                        - File Scope 
                    
                - Scopes may or may not be nested 
                    - Scope that may be nested 
                        - Block Scope 
                        - Class Scope 
                        - Namespace Scope 
                    
                    - Scopes that cannot be nested 
                        - Expression Scope 
                        - Function Scope - may contain Class Scopes 
                        - File Scope - will contain several other scopes 
                        - Global Scope - will contain several other scopes 

            6. Module Summary 
                - Understood namespace as a scoping tool in C++ 
                - Analyzed typical scenarios that namespace helps to address 
                - Studied several features of namespace 
                - Understood how namespace is placed in respect of different Lexical scopes of C++  

    _____________________________________________________________________________Complete______________________________________________________________________________