> Module Objectives 
    > More on Object Lifetime 
    > Understand Copy Construction
    > Understand Copy Assignment Operator 
    > Understand Shallow Deep Copy 

    1. Object Lifetime Examples 
        > Order of Initialization: Order of Data Members 
            > 
                #include<iostream>
                using namespace std;
                int init_m1(int m) { // Func. to init m1_
                    cout << "Init m1_: " << m << "\n";
                    return m;
                }
                int init_m2 (int m){ // Func. to init m2_
                    cout << "Init m2_ : " << m << "\n";
                    return m;
                }
                class X{
                    int m1_; // Initialize 1st 
                    int m2_; // Initialize 2nd 
                public: X(int m1, int m2):
                    m1_(init_m1(m1)),m2_(init_m2(m2)){ // called 1st and 2nd 
                        cout << "Ctor : \n"; 
                    }
                    ~X(){
                        cout << "Dtor : \n";
                    }
                };
                int main(){
                    X a(2,3);
                    return 0;
                }
                Init m1_: 2
                Init m2_ : 3
                Ctor :      
                Dtor : 
                    > Order of Initialization does not depend on the order in the initialization list. It depends on the order of data members.
            
            >   
                #include<iostream>
                using namespace std;
                int init_m1(int m) { // Func. to init m1_
                    cout << "Init m1_: " << m << "\n";
                    return m;
                }
                int init_m2 (int m){ // Func to init m2_ 
                    cout << "Init m2_ : " << m << "\n";
                    return m;
                }
                class X{ // Order of data members swapped 
                    int m2_;
                    int m1_;
                public: X(int m1, int m2):
                    m1_(init_m1(m1)),m2_(init_m2(m2)){ // called 1st and 2nd 
                        cout << "Ctor : \n"; 
                    }
                    ~X(){ 
                        cout << "Dtor : \n";
                    }
                };
                int main(){
                    X a(2,3);
                    return 0;
                }
                Init m2_ : 3
                Init m1_: 2 
                Ctor :      
                Dtor :    
        
    > String    
        > A Simple String Class  -- C Style 
                #include<iostream>
                #include<cstring>
                #include<cstdlib>
                using namespace std;
                struct String{  char *str_;  // Container
                    size_t len_;        // Length 
                };
                void print(const String& s){
                    cout << s.str_ << ": " << s.len_ << "\n";
                }
                int main(){ String s;
                    s.str_ = strdup("AnkitDimri");
                    s.len_ = strlen(s.str_);
                    print(s);
                    free(s.str_);
                }
                AnkitDimri: 10

                    > Note the order of initialization between str_ and len_ What if we swap them?
        
        > C++ Style 

                #include<iostream>
                #include<cstring>
                #include<cstdlib>
                using namespace std;
                class String{
                    char *str_;
                    size_t len_;
                public: String(char *s) : str_(strdup(s)), 
                                        len_(strlen(str_)){
                        cout << "ctor : ";print();
                    }
                    ~String(){ 
                        cout << "dtor : ";print();
                        free(str_);
                    }
                    void print(){
                        cout << "(" << str_ << ": " << len_ << ")\n";
                    }
                    size_t len(){
                        return len_;
                    }
                };
                int main(){
                    String s = " Ankit Dimri";
                    s.print();
                }

            > A Simple String class : 
                Fails for wrong order of data members 
                #include<iostream>
                #include<cstring>
                #include<cstdlib>
                using namespace std;
                class String {
                    size_t len_;
                    char *str_;
                public:
                    String(char *s): str_(strdup(s)), len_(strlen(str_)){
                        cout << "ctor :: \n"; print();
                    }
                    ~String(){
                        cout << "dtor :: \n"; print(); free(str_); 
                    }
                    void print(){
                        cout << "(" << str_ << ": " << len_ << ")\n";
                    }
                };
                int main(){
                    String s = "Ankit";
                    s.print();
                }
                    > len_ precedes str_ in list of data members 
                    > len_(strlen(str_)) is executed before str_(strdup(s))
                    > When strlen(str_) is called str_ is still uninitialized 
                    > May causes the program to crash 
        
        > A simple Date Class 
            > Practice : 
                >   #include<iostream>
                    using namespace std;
                    char monthNames[][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
                    char dayNames[][10] = {"Monday","Tuesday","Wednesday","Tuesday","Friday","Saturday","Sunday"};
                    class Date {
                        enum Month {Jan = 1, Feb, Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec};
                        enum Day {Mon,Tue,Wed,Thr,Fri,Sat,Sun};
                        typedef unsigned int UNIT;
                        UNIT date_; Month month_; UNIT year_;
                    public:
                        Date(UNIT d, UNIT m, UNIT y) : date_(d), month_((Month)m), year_(y){ cout << "ctor : ";print();}
                        ~Date(){ cout << "dtor : "; print(); }
                        void print(){cout << date_ << "/" << monthNames[month_ -1 ] << "/" << year_ << "\n";}
                        bool validDate(){ /* Check Validity */ return true;} // Not implemented
                        Day day(){ /* Compute day from date using time.h*/ return Mon; } // Not implemented 
                    };
                    int main(){
                        Date d(30,7,1961);
                        d.print();
                    }
                        ctor : 30/Jul/1961
                        30/Jul/1961
                        dtor : 30/Jul/1961
                    
 
        > Date: Practice 
        > Rect: Practice 
            > Point and Rect classes : Lifetime of Data Members or Embedded Objects 
                #include<iostream>
                using namespace std;
                class Point {
                    int x_; int y_; 
                public: Point(int x, int y):x_(x),y_(y){
                        cout << "Point ctor : ";
                        print(); cout << "\n";
                    }
                    ~Point(){
                        cout << "Point dtor : ";
                        print(); cout << "\n";
                    }
                    void print(){
                        cout << "(" << x_ << ", "<<y_ << ")";
                    }
                };
                class Rect {
                    Point TL_; Point BR_; public:
                    Rect(int tlx, int tly, int brx, int bry):
                    TL_(tlx,tly),BR_(brx,bry){
                        cout << "Rect ctor : ";
                        print();cout << "\n";
                    }
                    ~Rect(){
                        cout << "Rect dtor : ";print();cout << "\n";
                    }
                    void print(){
                        cout << "[";TL_.print();cout << " ";BR_.print();cout <<"]"; 
                    }
                };
                int main(){
                    Rect r (0,2,5,7);
                    cout << "\n"; r.print();cout << "\n\n";
                }
                Point ctor : (0, 2)
                Point ctor : (5, 7)
                Rect ctor : [(0, 2) (5, 7)]

                [(0, 2) (5, 7)]

                Rect dtor : [(0, 2) (5, 7)]
                Point dtor : (5, 7)
                Point dtor : (0, 2)
                    
                    > Attempt is to construct a Rect Object
                    > That, in turn, needs constructions of point data members (or embedded objects) - TL_ and BR_ respectively 
                    > Destruction, initiated at the end of scope of destructor's body. Naturally follows a reverse order. 


        > NAme & Address: Practice 
                #include<iostream>
                using namespace std;
                #include "String.h" // Containing class string from slide 14.7
                #include "Date.h"
                
                class Name {
                    String firstName_, lastName_;;
                    public: Name (char* fn, char* ln) : firstName_(fn), lastName_(ln) {
                        cout << "Name ctor :: ";print();
                    }
                    ~Name() {
                        cout << "\nName Dtor : ";print();cout << "\n";
                    }
                    void print() {
                        firstName_.print(); cout << " ";lastName_.print();
                    }
                };
                class Address {
                    unsigned street_, city_, pin_;
                    public: Address(unsigned int hn, char* sn, char* cn, char* pin) : houseNo_(hn), street_(sn),city_(cn), pin_(pin){
                        cout << "Address ctor : ";print();cout << "\n";
                    }
                    ~Address(){
                        cout << "Address dtor : ";print();cout << "\n";
                    }
                    void print(){
                        cout << houseNo_ << " ";
                        street_.print();cout << " ";
                        city_.print();cout << " ";
                        pin_.print();
                    }
                };

        > CreditCard: Practice
                typedef unsigned int UNIT;
                class CreditCard{
                    char cardnNumber_[17];
                    Name holder_; Address addr_;
                    Date issueDate_; expiryDate_; UNIT cvv_;
                };
                class Name {
                    string firstName_, lastName_;
                };
                class Address {
                    unsigned int houseNo_; String street_, city_, pin_;
                };
                class Date {
                    enum Month;
                    UNIT date_; Month month_; UNIT year_;
                };
                //
                class CreditCard {
                    typedef unsigned int UNIT;
                    char cardNumber_[17]; // 16 digit (character) card number as C-String 
                    Name holder_;Address addr_;
                    Date issueDate_; expiryDate_;
                    UNIT cvv_;
                public:
                    CreditCard(char* cNumber, char* fn, char* ln, unsinged int hn, char* sn, char* cn, char* pin, UNIT issueMonth, UNIT issueYear, UNIT expiryMonth, UNIT expiryYear, UNIT cvv): 
                    holder_(fn,ln),addr_(hn,sn,cn,pin),issueDate_(1,issueMonth,issueYear), expiryDate_(1,expiryMonth,expiryYear),cvv_(cvv){
                        strcpy(cardNumber_, cNumber); cout << "CC ctor : ";print();cout << "\n";
                    }
                    ~CreditCard(){
                        cout << "CC dtor : ";print();cout << "\n";
                    }
                    void print(){
                        cout << cardNumber_ << " ";holder_.print();cout << " ";addr_.print();cout << " ";
                        issueDate_.print();cout << " ";expiryDate_.print();cout << " ";cout << cvv_;
                    }
                };
                int main(){
                    CreditCard cc("670702010005604", "Sherlock","Holmes",221,"Banker Street", "London", "Nw1 ^XE", 7,2014,12,2016,881);
                    cout << "\n";cc.print();cout << "\n\n";
                } 

    
    2. Copy Constructor
        >
            >  We know :
                Complex : c1 (4.3,2.3);
               invoks
                Constructor Complex::Complex(double, double):
            > Which constructor is invoked for?
                Complex c2(c1);
              Or for?
                Complex c2 = c1;
            > It is the copy Constructor that takes an object of the same type and constructs a copy:
                Complex::Complex(const Complex &);

            > Copy Constructor :: 
                    #include<iostream>
                    #include<cmath>
                    using namespace std;
                    class Complex {
                        double re_, im_; 
                        public: Complex(double re, double im): re_(re), im_(im) {
                            cout << "Complex ctor : "; print();
                        }
                        Complex(const Complex& c): re_(c.re_), im_(c.im_){
                            cout << "Complex copy ctor : "; print();
                        }
                        ~Complex(){
                            cout << "Complex dtor : ";print();
                        }
                        double norm(){
                            return sqrt(re_*re_ + im_ * im_);
                        }
                        void print() {
                            cout << "|" << re_ << "+j" << im_ << "| = " << norm() << "\n";
                        }
                    };
                    int main(){
                        Complex c1(4.3, 5.2), // Constructor - Complex(double,double) 
                        c2(c1),                // Copy Constructor - Complex(const Complex&)
                        c3 = c2;                // Copy Constructor - Complex (const Complex&)
                        c1.print();
                        c2.print();
                        c3.print();
                    } 

        >   Why do we need Copy Constructor?
            Consider the function call mechanisms in C++:
                > Call-by-reference: Set a reference to the actual parameter as a formal parameter Both the formal parameter and the actual parameter share teh same location (Oject). no copy is needed
                > Return-by-reference: Set a reference to the computed value as a return value. Both the compuuted value and the return value share the same location (object). No Copy is needed 
                > Call-by-value: Make a copy or clone of the actual parameter as a formal parameter. This needs a Copy Constructor 
                > Return-by-Value: Make a copy or clone of the computed value as a return value. This needs a Copy Constructor 
            > Copy Constructor is needed for initalizing the data members of a UDT from an existing value 



        > Call by value 
            >   
                >   #include<iostream>
                    #include<cmath>
                    using namespace std;
                    class Complex { double re_, im_; 
                        public: Complex(double re, double im): re_(re),im_(im){
                            cout << "Ctor : ";print();
                        }
                        Complex(const Complex& c) : re_(c.re_),im_(c.im_) { // constructor 
                            cout << "Copy ctor : ";print();
                        }
                        ~Complex(){                 // Copy constructor 
                            cout << "Dtor : ";print();
                        }
                        double norm(){
                            return sqrt(re_*re_ + im_* im_);
                        }
                        void print() {
                            cin>>re_ >>im_;
                            cout << "|" << re_ << "+j"<< im_ << "| = " << norm() << "\n";
                        }
                    };
                    void Display(Complex c_param){ // calle by value 
                        cout << " Display : "; c_param.print();
                    }
                    int main(){
                        Complex c(4.2,5.3);     // Cosntructor - Complex(double, double)
                        Display(c); // Copy constructor called to copy c to c_param
                    }
                        Ctor : |4.2+j5.3| = 6.7624      // Ctor of c in main()
                        Copy ctor : |4.2+j5.3| = 6.7624 // Ctor c_param as copy of c, call Display()
                        Display : |4.2+j5.3| = 6.7624   // c_param
                        Dtor : |4.2+j5.3| = 6.7624     // Dtor c_param on exit from Display()
                        Dtor : |4.2+j5.3| = 6.7624      // Dtor of c on exit from main()

        > Signature
                > Signature of a copy constructor can be one of : 
                    > Myclass(const MyClass& other);        // Common
                                                            // Source cannot be changed 
                    MyClass(MyClass& other);                // Occasional 
                                                            // Source needs to change. Like in smart pointers 
                    MyClass(volatile const MyClass& other); // Rare 
                    MyClass(volatile MyClass& other);       // Rare


                > None of the following are copy constructors, through they can copy:
                    MyClass(MyClass* other);
                    MyClass(const MyClass* other);
                
                > Why the parameter to a copy constructor must be passes as call-by-reference?
                    MyClass(MyClass other);

                    The above is an infinte recursion of copy calls as the call to copy constructor itself needs to make copy for the call-by-value mechanism. 
                
        > Data Members
            > 
            Point and rect Classes: Embedded Objects Default, Copy and Overloaded Constructors 
                        #include<iostream>
                        using namespace std;
                        class Point {
                            int x_; int y_;
                            public: Point(int x, int y): x_(x),y_(y){
                                cout << "Point ctor : "; print();cout << "\n";
                            }
                            Point(): x_(0),y_(0){
                                cout << "Point ctor : ";print();cout << "\n";
                            }
                            Point(const Point& p):x_(p.x_),y_(p.y_){
                                cout << "Point cctor : ";print();cout << "\n";
                            }
                            ~Point(){
                                cout << "Point dtor : ";print();cout << "\n";
                            } 
                            void print(){ // Class point  
                                cout << "(" << x_ << ", " << y_ << ")";
                            }
                        };
                        class Rect {
                            Point TL_; Point BR_;
                            public: Rect(int tlx, int tly, int brx, int bry): TL_(tlx,tly),BR_(brx,bry){ // Ctor of Rect : 4 coords 
                                cout << "Rect ctor : ";print();cout << "\n";                    // USes ctor for point
                            }
                            Rect(const Point& p_tl, const Point& p_br): TL_(p_tl),BR_(p_br){    // Ctor of Rect : 3 Points 
                                cout << "Rect ctor : "; print();cout << "\n";               // USes CCtor for point
                            }
                            Rect(const Point& p_tl, int brx, int bry): TL_(p_tl),BR_(brx, bry){ // Ctor of Rect : Point + 2 coords
                                cout << "Rect ctor : ";print(); cout << "\n";               // Uses CCtor for Point
                            }
                            Rect(){             // Dctor of Rect : // Dctor Point
                                cout << "Rect ctor : ";print();cout << "\n";
                            }
                            Rect(const Rect& r): TL_(r.TL_),BR_(r.BR_){ // CCtor of Rect 
                                cout <<"REct cctor : ";print();cout << "\n";    // Uses cctor for point 
                            }
                            ~Rect(){            // Dtor 
                                cout << "REct dtor : ";print();cout << "\n";
                            }
                            void print(){       // Class Rect 
                                cout << "[";TL_.print();cout << " ";BR_.print();cout << "]";
                            }
                        };
                        int main(){
                            Rect r1(0,2,5,7);
                            // Rect (int, int , int , int);
                            Rect r2(Point(3,5), Point(6,9));
                            // Rect (Point&, Point&)
                            Rect r3(Point(2,2),6,4);
                            // Rect(Point&, int, int)
                            Rect r4;
                            // Rect()
                            return 0;
                        }
                                
                            OutPut                      LifeTime             Remarks 
                        ------------------------------------------------------------------
                        Point ctor : (0, 2)                 Point r1.TL_
                        Point ctor : (5, 7)                 Point r1.BR_
                        Rect ctor : [(0, 2) (5, 7)]         Rect r1
                        -----------------------------------------------
                        Point ctor : (6, 9)                 Point t1      Second Parameter
                        Point ctor : (3, 5)                 Point t2      First Parameter
                        Point cctor : (3, 5)                r2.TL_ = t2   Copy to r2.TL_
                        Point cctor : (6, 9)                r2.BR_ = t1   cOPY TO R2.br_
                        Rect ctor : [(3, 5) (6, 9)]         Rect r2
                        Point dtor : (3, 5)                 ~Point t2      1st parameter
                        Point dtor : (6, 9)                 ~Point t1       2nd Parameter
                        ------------------------------------------------
                        Point ctor : (2, 2)                 Point t3        First parameter 
                        Point cctor : (2, 2)                r3.TL_ = t3     Copy to r.TL_
                        Point ctor : (6, 4)                 Point r3.BR_
                        Rect ctor : [(2, 2) (6, 4)]         Rect r3 
                        Point dtor : (2, 2)                 ~Point t3       First parameter 
                        -------------------------------------------------
                        Point ctor : (0, 0)                 Point r4.TL_
                        Point ctor : (0, 0)                 Point r4.BR_
                        Rect ctor : [(0, 0) (0, 0)]         Rect r4
                        ----------------------------------------------------------------
                        Rect dtor : [(0, 0) (0, 0)]         ~Rect r4
                        Point dtor : (0, 0)                 ~Point r4.BR_
                        Point dtor : (0, 0)                 ~Point r4.TL_
                        ---------------------------------------------------
                        REct dtor : [(2, 2) (6, 4)]         ~Rect r3
                        Point dtor : (6, 4)                 ~Point r3.BR_
                        Point dtor : (2, 2)                 ~Point r3.TL_
                        ---------------------------------------------------
                        REct dtor : [(3, 5) (6, 9)]         ~REct r2
                        Point dtor : (6, 9)                 ~Point r2.BR_
                        Point dtor : (3, 5)                 ~Point r2.TL_
                        ---------------------------------------------------
                        REct dtor : [(0, 2) (5, 7)]         ~Rect r1
                        Point dtor : (5, 7)                 ~Point r1.BR_
                        Point dtor : (0, 2)                 ~Point r1.TL_
                        -------------------------------------------------------------------

        > Free Copy Constructor and Pitfalls 
            > If no copy constructor is provided by the user, the compiler supplies a free one 
            > Free copy constructor cannot initialize the object to proper values. it performs shallow copy
            > Shallow Copy aka bit-wise copy, field-by-field copy, or field copy 
                > An object is created by simply copying the data of all variables of the orignal object 
                > Works well if none of the variables of the object are defined in heap / free store 
                > For dynamically created variables, the copied object refers to to the same memory location
                > Creates ambiguity (changing one changed the copy) and run-time errors (dangline pointer) 
            > Deep Copy or its variants Lazy Copy and Copy-on-Write 
                > An obejct is created by copying data of all variables expect the ones on heap
                > Allocates similar memory resources with the same value to the object 
                > Need to Explicity define the copy constructor and assign dynamic memory as required 
                > Required to dynamically allocate memory to the variable in the other constructors 

                        Shallow Clone                                Deep Clone 
                    orignal Object  -- Cloned Object        orignal Object   -- Cloned object 
                        \                   /                       |                   |
                          \                /                        |                   | 
                          referenced Object                 Referenced Object      Referenced Clone 

        > Pitfalls of Bit-Wise Copy : Shallow Copy 
            > Consider a class : 
                    #include<iostream>
                    using namespace std;
                    class A {
                        int i_;     // Non-pointer data member 
                        int* p_;    // Pointer data member 
                        public: A(int i, int j) : i_(i),p_(new int(j)){ } // init . With pointer to dynamically created object 
                        ~A(){ cout << "Destruct " << this << ": ";                  // object identity 
                            cout << "i_ = " << i_ << " p_ = " << p_ << " *p = " << *p_ << "\n";     // Object state 
                            delete p_;                                          // release resource 
                        }
                    };
            > A no copy Constructor is provided, the implicit copy constructor does a bit-wise copy. So when an A object is copied, p_ is copied and continues to point to the same dynamic int: 
                int main() {
                    A a1(2,3); A a2(a1); // Construct a2 as a copy of a1. Done by bit-wise copy 
                    cout << "&a1 = " << &a1 << " a &a2 = " << &a2 << "\n";
                }
            
            > The output is wrong, as a1.p_ = a2.p_ points to the same int location. Once a2 is destructed, a2.p_ is released, and a1.p_ becomes dangling. The program may print garbage or crash : 
             &a1 = 008FF838 &a2 = 008FF828                      // Identities of objects
             Destruct  008FF828 : i_ = 2 p_ = 00C15440 *p = 3   // Dtor of a2. note that a2.p_ = a1.p_
             Destruct 008FF838: i_ = 2 p_ = 00C15440 *p = -17891602     // Dtor of a1.p_ = a2.p_ points to garbage 
            
            > The bit-wise copy of members is known as Shallow Copy  
        
        > Pitfalls of Bit-wise Copy  : Deep Copy 
            > Now Suppose we provide a user-defined copy constructor : 
                class A {
                    int i_;     // Non-pointer data member 
                    int* p_;    // Pointer data member 
                    public:
                        A(int i, int j) : i_(i), p_(new(j)) { } // init. with pointer to dynamically created object 
                        A(const A& a) : i_(a.i_),       // Copy constructor 
                            p_(new int(*a.p_)) { }      // Allocation done and value copied - Deep Copy 
                        ~A(){
                            cout << "Destruct " << this << ": ";                // object identity 
                            cout << "i_ = " << i_ << p_ << " *p  = " << *p_ << "\n";    // Object state
                            delete p_;                                  // Release resource 
                        }  
                };
            > The output now is correct, as a1.p_ different int locations with the values *a1.p_ = *a2.p_ properly copied: 
                &a1 = 00B8F9E0 &a2  = 00B8F9D0      // Identities of objects 
                Destruct 00B8F9D0: i_ = 2 p_ = 00C95480 *p = 3  // Dtor of a2. a2.p_ is different from a1.p_ 
                Destruct 00B8F9D0: i_ = 2 p_ = 00C95440 *p = 3  // Dtor of a1 Works Correctly! 
            > This is known as Deep Copy where every member is copied properly. Note that: 
                > In every class, provide copy constructor to adopt to deep copy which is always safe 
                > Naturally, Shallow copy is cheaper than deep copy. So some language support variants as Lazy Copy or Copy - on - Write for effiency  
        >
            Complex : Free Copy Constructor 
                #include<iostream>
                #include<cmath>
                using namespace std;
                class Complex {
                    double re_, im_; public: Complex (double re, double im) : re_(re), im_(im){
                        cout << "Ctor : ";print();
                    }
                    Complex(const Complex& c) : re_(c.re_),im_(c.im_){
                        cout << "Copy Ctor : "; print();
                    }
                    ~Complex(){
                        cout << "dtor : ";print();
                    }
                    double norm(){
                        return sqrt(re_*re_ + im_*im_);
                    }
                    void print(){
                        cout << "|" << re_ << "+j" << im_ << "| = " << norm() << "\n"; 
                    }
                };
                void Display(Complex c_param){
                    cout << "Display : ";c_param.print();
                }
                int main(){
                    Complex c(4.3,6.7);             // Constructor - Complex(double, double) 
                    Display(c);                 // Free Copy Constructor called to copy c to c_param
                }

                user-defined CCtor                                              Free CCtor
                Ctor : |4.3+j6.7| = 7.96116                         Ctor : |4.3+j6.7| = 7.96116  
                Copy Ctor : |4.3+j6.7| = 7.96116                    No message from free CCtor 
                Display : |4.3+j6.7| = 7.96116                      Display : |4.3+j6.7| = 7.96116
                dtor : |4.3+j6.7| = 7.96116                         dtor : |4.3+j6.7| = 7.96116   
                dtor : |4.3+j6.7| = 7.96116                         dtor : |4.3+j6.7| = 7.96116
            > USer has provided no copy constructor 
            > Compiler provides free copy constructor 
            > Compiler-provided copy constructor performs bit-wise copy  - hence there is no massage 
            > Correct in this case as members are of built-in type and there is no dynamically allocated data 

        >> String : Free copy constructor 
            > 
                #include<iostream>
                #include<cstdlib>
                #include<cstring>
                using namespace std;
                class String{
                    public:
                    char *str_; size_t len_;
                    String(char *s) : str_(strdup(s)), len_(strlen(str_)){ }    //Ctor 
                    // String(const String& s) : str_(strdup(s.str_)), len_(s.len_) { }    //CCtor : USer provided -- for other result 
                    ~String(){ free(str_); }
                    void print(){
                        cout << "(" << str_ << " : " << len_ << ")" << "\n";
                    }
                };
                void strToUpper(String a) {     // Make the string uppercase 
                    for(int i = 0; i<a.len_; i++){
                        a.str_[i] = toupper(a.str_[i]);
                    }
                    cout << "strToUpper : "; a.print();
                } // a.~String() is invoked releasing a.str_  s.str_ remains intact 
                int main(){
                    String s = "Ankit Dimri"; s.print();strToUpper(s);s.print();
                }
                    Output : 
                    (Ankit Dimri : 11)
                    strToUpper : (ANKIT DIMRI : 11)
                    (Ankit Dimri : 11)

                    > User has provided copy constructor. So Compiler does not provide free copy constructor 
                    > When actual parameter s is copied to formal parameter a, space is allocated for a.str_ and then it is copied from s.str_ On Exit from strToUpper a is 
                        destructed and a.str_ us deallocared. But in main s remains intact and access to s.str_ us valid.
                    > Deep Copy : While copying the object, the pointed object is copied in a fresh allocation. This is safe  


    3. Copy Assignment Operator
            > Copy Assignment Operator  
                > We can copy an existing object to another existing object as
                    Compelx c1 = (4.3, 5.6), c2(5.2,7.5);
                    c2 = c1; // c1 becomes {4.3 , 5.6}

                    This is like normal assignment of built-in types and overwites the old values with the new value
                > It is the Copy Assignment that takes an object of the same type and overwrites into an existing one, and return that object : 
                    Compelx::Complex& operator = (const Complex &); 

            > Complex : Copy Assignment 
                    > #include<iostream>
                    #include<cmath>
                    using namespace std;
                    class Complex {
                        double re_, im_; public:
                        Complex(double re, double im) : re_(re), im_(im) {
                            cout << "ctor : "; print(); // Ctor 
                        }
                        Complex(const Complex& c) : re_(c.re_), im_(c.im_){
                            cout << "Cctor : "; print();    // CCtor 
                        }
                        ~Complex() {
                            cout << "Dtor : "; print();
                        }
                        Complex& operator=(const Complex& c){ // Copy assignment operator 
                            re_ = c.re_; im_ = c.im_;cout << "Copy : "; print(); return *this; // return *this for chainging 
                        }
                        double norm() {
                            return sqrt(re_*re_ + im_*im_);
                        }
                        void print(){
                            cout << "|" << re_ << "+j" << im_ << "| = " << norm() << "\n"; // Class Complex 
                        }
                    };
                    int main(){
                        Complex c1(4.2,5.3),c2(7.9,8.5);Complex c3(c2); // c3 copy assignment from c2
                        c1.print();c2.print();c3.print();
                        c2 = c1; c2.print();        // Copy Assignment operator 
                        c1 = c2 = c3; c1.print();c2.print();c3.print();     // Copy Assignment chain
                    }

                        ctor : |4.2+j5.3| = 6.7624  
                        ctor : |7.9+j8.5| = 11.6043 
                        Cctor : |7.9+j8.5| = 11.6043
                        |4.2+j5.3| = 6.7624
                        |7.9+j8.5| = 11.6043        
                        |7.9+j8.5| = 11.6043        
                        Copy : |4.2+j5.3| = 6.7624  
                        |4.2+j5.3| = 6.7624
                        Copy : |7.9+j8.5| = 11.6043 
                        Copy : |7.9+j8.5| = 11.6043 
                        |7.9+j8.5| = 11.6043
                        |7.9+j8.5| = 11.6043
                        |7.9+j8.5| = 11.6043
                        Dtor : |7.9+j8.5| = 11.6043
                        Dtor : |7.9+j8.5| = 11.6043
                        Dtor : |7.9+j8.5| = 11.6043

                > Copy Assignment operator should return the object to make chain assignment possible 
                
        > Copy Objects
            >  String : Copy Assignment 
                > #include<iostream>
                    #include<cstring>
                    #include<cstdlib>
                    using namespace std;
                    class String {
                        public: char *str_; size_t len_;
                        String(char *s) : str_(strdup(s)), len_(strlen(str_)){ } 
                        String(const String& s) : str_(strdup(s.str_)),len_(s.len_) { }
                        ~String(){ free(str_); }
                        String& operator=(const String& s){
                            free(str_);     // Release existing memory 
                            str_ = strdup(s.str_);  // Perfom deep copy 
                            len_ = s.len_;  // Copy data member of built-in type 
                            return *this;   // Return object for chain assignment 
                        }
                        void print(){
                            cout << "(" << str_ << ": " << len_ << ")" << "\n";
                        }
                    };
                    int main(){
                        String s1 = "Football", s2 = "Cricket";s1.print();s2.print();s2=s1;s2.print();
                    }
                        (Football: 8)
                        (Cricket: 7)
                        (Football: 8)

                        > In Copy Assignment operator , str_ = s.str_ should not be done for two reasons : 
                            1): resource held by str_ will leak 
                            2): Shallow copy will result with its related issues 
                        > What happens if a self-copy s1=s1 is done? 

        > Self-Copy
            > 
                #include<iostream>
                #include<cstring>
                #include<cstdlib>
                using namespace std;
                class String {
                    public: char *str_; size_t len_;
                    String (char *s) : str_(strdup(s)),len_(strlen(str_)){ }
                    String(const String& s) : str_(strdup(s.str_)),len_(s.len_){ }
                    ~String(){ free(str_); }
                    String& operator=(const String& s){
                        free(str_);     // Release existing memory 
                        str_ = strdup(s.str_);  // Perform deep copy 
                        len_ =  s.len_;         // Copy data member of built-in type        For self copy 
                        return *this;       // Return object for chain assignment 
                    }
                    void print(){
                        cout << "(" << str_ << " : " << len_ << ")\n";
                    }
                };
                int main(){
                    String s1 = "Football", s2 = "Cricket"; s1.print();s2.print();s1 = s1;s1.print();
                }
                    (Football : 8)
                    (Cricket : 7)
                    (α→LÖ┼☻ : 8)

                    > Hence, free(str_) first release the memory, and then strdup(s.str_) tries to copy from release memroy 
                    > This may crash or produce garbage value 
                    > Self_copy must be deleted and guarded 

        > String : self copy : safe 
            >
                #include<iostream>
                #include<cstring>
                #include<cstdlib>
                using namespace std;
                class String{
                    public: char *str_; size_t len_;
                    String(char *s) : str_(strdup(s)),len_(strlen(str_)){ }
                    String(const String& s) : str_(strdup(s.str_)), len_(s.len_){ }
                    ~String(){ free(str_); }
                    String& operator=(const String& s){
                        if(this != &s){
                            free(str_);
                            str_ = strdup(s.str_);
                            len_ = s.len_;
                        }
                        return *this;
                    }
                    void print(){
                        cout << "(" << str_ << ": " << len_ << ")\n";
                    }
                };
                int main(){
                    String s1 = "NameThing", s2 = "Formations"; s2.print();s2.print();s1 = s1; s1.print();
                }
                    (Formations: 10)
                    (Formations: 10)
                    (NameThing: 9)
                > In case of self - copy do nothing 


        > Signature
            > Signature and Body of copy Assignment operator 
                > For class MyClass, typical copy Assignment operator will be: 
                    MyClass& operator=(const MyClass& s){
                        if(this != &s){ // Check if the source and destinstion are same 
                                    // Release resources held by *this 
                                    // Copy members of s to members of *this 
                        }
                        return *this;           // REturn object for chain assignment 
                    } 
                > Signature of a  Copy Assignment operator can be one of: 
                    MyClass& operator=(const MyClass& rhs); // Common. NO change in Source
                    MyClass& operator=(MyClass& rhs);   // Occasional. Change in source 
                > The following copy Assignment operators are Occasional used:
                    MyClass& operator=(MyClass rhs);
                    const MyClass& operator=(const MyClass& rhs);
                    const MyClass& operator=(MyClass& rhs);
                    const MyClass& operator=(MyClass rhs);
                    MyClass operator=(const MyClass& rhs);
                    MyClass operator=(MyClass& rhs);
                    MyClass operator=(MyClass rhs);

        > Free Assignment Operator 
            > If no copy assignment operator is provided / Overloaded by the user, the compiler supplies a free one.
            > Free copy assignment operator cannot copy the obejct with proper values. It performs Shallow Copy
            > In every class, provide copy assignment operator to adopt to deep copy which is always safe 

    4. Comparison Of Copy Constructor and Copy Assignment Operator
                Copy Constructor                                                    Copy Assignment operator 
        > An Overloaded constructor                                     >   An operator overloading 
        > Initializes a new obejct with an existing                     > Assigns the value of one existing object to another existing object
        > Used when a new object is created with some existing obejct   > Used when we want to assign existing obejct to another object
        > needed to support call-by-value and return-by-value           
        > Newly created object use new memroy location                  > Memory location of destinstion object is reused with pointer variables being released and reallocated 
                                                                        > Care is needed for self - copy
        > IF not defined in the class, the compiler provides            > If not overloaded. the compiler provides one with bitwise copy   
        one with bitwise copy 

    5. Class as a Data-type
        > We add the copy construction and assignment to a class being a composite data ype in C++ 
        // declare to be of int type                        // Declare c to be of Complex type 
        int i;                                          Complex c;
        //  Initialise i                            // initialise the real and imaginary components of c 
        int i = 5;                                      Complex c = (4,5); 
        int j = i;                                      Complex c1 = c;
        int k(j);                                       Complex c2(c1);
        // print i                                  // print the real and imaginary components of c
        cout << i;                                  cout << c.re << c.im;
                                                    OR c.print(); // Method Complex::print() defined for printing 
                                                    OR cout << c; // operator<<() overloaded for printing 
        // add two ints                             // add two Complex objects 
        int i{5},b{7};                              Complex z{4.3,6.5}, z2{5.4,3.5};
        i+b;                                        z.add(z2); // Method Complex::add() defined to add 
                                                    OR z + z2; // operator+() overloaded to add 
        // Copy value of i to b                     // Copy value of one Complex object to another 
        int i{5},j;                                Complex z{4.3,6.5}, z2{5.4,3.5};
        j = i;                                     z2 = z; // z2.re <- and z2.im <- z.im by copy assignment


    6. Module Summary 
        > Copy Constructor 
            > A new object is created 
            > The new object is initialized with the value of data members of another object 
        > Copy Assignment Operator 
            > An Object is already existing(and initialized)
            > The members of the existing object are replaced by values  of data members of another object
            > Care is needed for self-copy 
        > Deep and shallow copy for Pointer Members 
            > Deep copy Allocates new sapce  for the constents and copies the pointed data 
            > Shallow copy merely copies the pointer value - hence , the new copy and the orignal pointer continue to point to the same data . 

    -----------------------------------Complete-----------------------------------------------