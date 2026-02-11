Module Outline : 
    1.Classes 
        :: A class is an implementation of a type. It is the only way to implement User-defined Data Type (UDT)
        :: A class contains data members / attributes 
        :: A class has operations / member functions / methods 
        :: A class defines a namespace 
        :: Thus, classes offer data abstraction / encapsulation of object Oriented  Programming 
        :: Class are similar to structures that aggregate data logically 
        :: A class is defined by class keyword 
        :: Classes provide access specifiers for members to enforce data hiding that seperates implementation form interface 
        ::     private - accessible inside the definition of the class 
        ::     public - accessible everywhere 
        :: A class is a bule print for its instances (objects)

    2.Objects 
        :: An object of a class is an instance created according to its blue print. Objects can be automatically, statically, or dynamically created 
        :: A object comprises data members that specify its state 
        :: A object supports member functions that specify its behavior 
        :: Data members of an object can be accessed by  "." (dot) operator on that object 
        :: Member functions are invoke by "." (dot) operator on the object 
        :: An implicit this pointer holds the address of an object. This serves the identity of the object in C++ 
        :: this pointer is implicitly passes to methods 

    3.Data Members
        Complex Numbers : Attributes 
            C program : 
                // File Name : Complex_object.c
                #include<stdio.h>
                typedef struct Complex {  // struct 
                    double re,im;           // Data members 
                } Complex;
                int main(){
                    //  Varibale c declared, initialized 
                    Complex c = {4.54,6.44};
                    printf("%lf + %lfi", c.re,c.im); // use by dot  
                }
                    :: struct is a keyword in C for data aggregation 
                    :: struct Complex is defined as compsoite data type containing two double (re,im) data members 
                    :: struct Complex is a derived data type used to create Complex type varibale c 
                    :: Data memebers are accessed using '.' operator 
                    :: struct only aggregate 

            --> C++ program : 
                // File Name: Complex_object_c++.cpp
                        #include<iostream>
                        using namespace std;
                        class Complex{
                            public: // class 
                            double re,im;         // data members
                        };
                        int main(){
                            // Object c declared, initialized 
                            Complex c = {3.32,4.33};
                            cout << c.re << " + " << c.im << "i\n";
                        }
                        
                            :: class is a new keyword in C++ for data aggregation 
                            :: class Complex is defined as composite data type containing two double(re,im) data members 
                            :: class Complex is User-defined Data type(UDT) used to create Complex type object c 
                            :: Data members are accessed using '.' operator 
                            :: class aggregates and helps build a UDT 

        Rectangle 
            :Points and Rectangles : Attributes 
                C program 
                    //  File Name : Rectangle_object.c 
                    // File Name : Rectangle_Object.c 
                    #include<stdio.h>
                    typedef struct { // struct Point 
                        int x;int y;
                    } Point;
                    typedef struct {    // Rect uses Point 
                        Point TL;       // Top-Left. Member of UDT 
                        Point BR;       // Bottom-Right. Member of UDT 
                    } Rect;
                    int main(){
                        Rect r= {{0,2}, {5,7}};
                        // r.TL <-- {0,2}; r.BR <-- {5,7}
                        // r.TL.x <-- 0; r.TL.y <-- 2
                        // Members of Structure r accessed 
                        printf("[(%d %d) (%d %d)]", r.TL.x, r.TL.y, r.BR.x, r.BR.y);
                    }

                C++ Program :    
                        //  File Name: Rectangle_object.c++.cpp
                        #include<iostream>
                        using namespace std;
                        class Point{ public:    // class Point 
                            int x,y;            // Data members 
                        };
                        class Rect { public:    // Rect uses Point 
                            Point TL;           // Top-Left. Member of UDT
                            Point BR;           // Bottom-Right. Member of UDT
                        }; 
                        int main(){ Rect r = {{0,2}, {5,7}};
                            // r.TL <-- {0,2}; r.BR <-- {5,7}
                            // r.TL.x <-- 0; r.TL.y <-- 2 
                            // Rectangle Object r accessed  
                            cout << "[(" << r.TL.x << " " << r.TL.y << ") (" << r.BR.x << " " << r.BR.y <<  ")]";
                        }

                ---------------------------------------------
                   Data members of user defined data types 
                ---------------------------------------------
                                
        Stack 
            Stacks : Attributes 
                C program :
                    // File Name: Stack_Object.c 
                    #include<stdio.h>
                    typedef struct Stack {      // struct Stack 
                        char data[100];         // Container for elements 
                        int top;                // Top of stack marker 
                    } Stack;
                    //  Codes for push(), pop(), top(), empty()
                    int main(){
                            //  Variable s declared 
                        Stack s;
                        s.top = -1;
                        //  Using stack for solving problems 
                    }
                
                C++ Program : 
                    //  File Name :: Stack_object_c++.cpp
                    #include<iostream>
                    using namespace std;
                    class Stack { public:   // class stack 
                        char data[100];     // Container for elements
                        int top;            // Top of stack marker 
                    };
                    //  Codes for push(), pop(), top(), empty()
                    int main() {
                        //  Object s declared
                        Stack s;
                        s.top = -1;
                        //  Using stack for solving problems 
                    }

                    Data members of mixed data types 

    4. Member Functions 
        Complex 
            : C program : 
                // File Name : Compplex_func.c 
                    #include<stdio.h>
                    #include<math.h>
                    // types as alias 
                    typedef struct Complex { double re,im; } Complex;
                    // Norm of Complex Number - global fn.
                    double norm(Complex c){ // Parameter explicit 
                        return sqrt(c.re*c.re + c.im*c.im);
                    }
                    // Print number with Norm - global fn.
                    void print(Complex c){ // Parameter explicit 
                        printf("|%lf+j%lf| = ", c.re, c.im);
                        printf("%lf", norm(c)); //call global
                    }
                    int main(){Complex c = {4.3,5.3};
                        print(c); // call global fn. with c as param
                    }

                        Access functions are global 
                        
            : C++ Program :  
                // File Name:Complex_func_c++.cpp
                        #include<iostream>
                        #include<cmath>
                        using namespace std;
                        // Type as UDT 
                        class Complex{ public: double re,im;
                            double norm(){ // PArameter implicit 
                                return sqrt(re*re+im*im);}
                                // Print number with Norm - Method 
                            void print(){ // Parameter implicit 
                            cout << "|" << re << "+j" << im << "| = ";
                            cout << norm();        // call method 
                            }
                        }; // End of class complex 
                        int main(){ Complex c = {4.2, 5.3};
                            c.print();  // Invoke method print of c 
                        }

                        Access functions are members

        Rectangle 
            :: Rectangles: Member Functions 
                 using struct                    
                    #include<iostream>
                    #include<cmath>
                    using namespace std;
                    typedef struct { int x; int y;} Point;
                    typedef struct {
                        Point TL; // Top-Left 
                        Point BR; // Bottom-Right
                    } Rect;
                    // Global function 
                    void computeArea(Rect r){ // Parameter  explicit 
                        cout << abs(r.TL.x-r.BR.x) * abs(r.BR.y - r.TL.y);
                    }
                    int main(){Rect r = {{0,2},{5,7}};
                        computeArea(r);     // Global fn. call
                    }
                        Access functions are global  
                
                :: using class ::
                    #include<iostream>
                    #include<cmath>
                    using namespace std;
                    class Point { public: int x; int y;};
                    class Rect {public: 
                        Point TL;   // Top-Left 
                        Point BR; // Bottom-Right
                        void computerArea(){ // Parameter implicit 
                            cout << abs(TL.x-BR.x)*abs(BR.y-TL.x);
                        }
                    };
                    int main(){ Rect r = {{0,2},{5,7}};
                        r.computerArea();
                    }

        Stack 
            :: Stacks : Member Functions 
                #include<iostream>
                using namespace std;
                typedef struct Stack { char data_[100]; int top_;  
                } Stack;
                // Global functions 
                bool empty(const Stack& s) { return (s.top_ == -1); }
                char top(const Stack& s){ return s.data_[s.top_]; }
                void push(Stack& s, char x) { s.data_[++(s.top_)] = x; }
                void pop(Stack& s) {--(s.top_); }
                int main(){ Stack s; s.top_ = -1;
                    char str[10] = "ABCDE"; int i;
                    for(i = 0; i<5; i++) push(s, str[i]);
                    while(!empty(s)){
                        cout << top(s); pop(s);
                    }
                }
                    Access functions are global 
                
            :: Using class 
                #include<iostream>
                using namespace std;
                class Stack { public : 
                    char data_[100]; int top_;
                    // Member functions
                    bool empty(){ return (top_ == -1); }
                    char top(){ return data_[top_]; }
                    void push(char x){ data_[++top_] = x; }
                    void pop(){ --top_; }
                };
                int main(){ Stack s; s.top_ = -1; 
                    char  str[10] = "ABCDE"; int i;
                    for(i = 0; i < 5; ++i) s.push(str[i]);
                    while(!s.empty()){
                        cout << s.top(); s.pop();
                    }
                } 
                    Access functions are members       

    5. this POinter 
        :: An implicit this pointer holds the address of an object 
        :: this pointer serves as the identity of the object in C++ 
        :: Type of this pointer for a class X object object: X * const this;
        :: this pointer is accessible only in member functions 
            #include<iostream>
            using namespace std;
            class X { public: int m1,m2;
                void f(int k1, int k2){             // Sample member function 
                    m1 = k1;                        // Implicit access without this pointer
                    this->m2 = k2;                   // Explicit access with this pointer 
                    cout << "ID = " << this << "\n"; // Identity (address) of the object 
                }
            };
            int main() { X a;
                a.f(2,3);
                cout << "Addr :: " << &a << "\n";           // Address (identity) of the object 
                cout << "a.m1 = " << a.m1 << " a.m2 = " << a.m2 << "\n";
                return 0;
            }

        --> this pointer is implicity passed to methods 
                In Source Code                       |       In Binary Code 
               -------------------------------------------------------------------------------------
                class X{void f(int, int);......}     |       void X::f(X*const this, int, int);
                X a; a.f(2,3);                       |       x::f(&a,2,3); // &a = this 
               -------------------------------------------------------------------------------------

            USe of this pointer 
                :: Distinguish member from non-member 
                    class X { public: int m1, m2;
                        void f(int k1, int k2){
                            m1 = m2;  // this->m1(member) is valid: this->k1 is invalid 
                            this->m2 = k2; // m2 (member) is valid; this->k2 is invalid 
                        }
                    };

                :: Explicit Use 
                    //  Link the object 
                        class DoubleLinkedNode{ public: DoubleLinkedNode *prev, *next; int data; 
                            void append(DoubleLinkedNode *x){ next = x; x->prev = this;}
                        }
                        //  Return the object 
                        Complex inc(){ ++re; ++im; return *this;}
    6. State of an Object 
        Complex 
            :: The state of an object is determined by the combined value of all its data members 
                class Complex {
                    public:
                    class re_, im_;
                    double get_re { return re_;  }          // Read re_
                    void set_re(double re) {re_ = re;}      // Write re_
                    double get_im { return im_; }           // Read im_ 
                    void set_im(double im){im_ = im; }      // Write im_ 
                }; 
                Complex c = {4.2,5.3};
                //  State 1 of c = {4.2,5.3} // DenoteS a tuple / sequence  
            :: A method may change the state :
                Complex c = {4.2, 5.3};
                //  STATE 1 of c = {4.2,5.3};
                c.set_re(6.4);
                //  STATE 2 of c = {6.4,5.3};
                c.get_re();
                //  STATE 2 of c = {6.4,5.3}; // No change of state 
                c.set_im(7.8);
                //  STATE2 of c = {6.4,7.8};
       
        Rectangle
            ::
                // Data members of Rect class: point Tl; point BR; // Point class type object 
                // Data members of Point class : int x , int y ;
                Reectangle r = {{0,5},{5.0}}; // Initialization 
                // STATE 1 of r =  {{0,5},{5.0}}
                {r.TL.x = 0; r.TL.y = 5; r.BR.x = 5; r.BR.y = 0}
                r.TL.y = 9;
                // STATE 2 of r = {{0,9},{5.0}};
                r.computeArea();
                // STATE 2 of r = {{0,9},{5.0}}; // No change in state 
                Point p = {3,4};
                r.BR = p;
                //  STATE 3 of r = {{0,9},{3.4}}

        Stack 
            :: 
            State of an Object : Stack 
                : // Data members of Stack class: char data[5] and int top;
                Stack s;
                // State 1 of s = {{?,?,?,?,?},?} // NO data member is initialized 
                s.top_ = -1;
                // STATE 2 of s  = {{?,?,?,?,?},-1}
                s.push('b');
                // STATE 3 of s = {{'b',?,?,?,?},0}
                s.push('a');
                // STATE 4 of s  = {{'b','a',?,?,?},1}
                s.empty();
                // STATE 4 of s = {{'b','a',?,?,?},1} // NO change of state 
                s.push('t');
                // STATE 5 of s = {{'b','a','t',?,?},2}
                s.top();
                // STATE 5 of s = {{'b','a','t',?,?},2} // NO change of state 
                s.pop();
                // STATE 6 of s = {{'b','a','t',?,?},1}

    7. Module Summary
                        class COmplex { public: 
                            double re_, im_;
    Class                   double norm() { // NOrm of complex NUmber 
                                return sqrt(re_ *re_ + im_ * im_);
                            }       
                        } ;
    Attributes          Complex::re_, Complex::im_;
    Member  Functions   double Complex::norm();
    Object              Complex c = {2.6,3.9};
                        c.re_ = 4.6;
    Access              cout << c.im_;
                        cout << c.norm();
    this Pointer        double Complex::norm(){cout <<this; return..} 
                        Rectangle r = {{0,5},{5,0}}; // STATE 1 r = {{0,5},{5,0}}
                        r.TL.y = 9;                  // STATE 2 r = {{0,9},{5,0}} 
    State of Object     r.computeArea();             // STATE 3 r = {{0,9},{5,0}}                  
                        Point p = {3,4}; r.BR = p;   // STATE 4 r = {{0,9},{3,4}}

    --------------------------------Complete---------------------------------