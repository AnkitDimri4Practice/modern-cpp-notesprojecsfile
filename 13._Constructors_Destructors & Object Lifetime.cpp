Module Objectives 
    > Understand Object Contruction (Initialization)
    > Understand Object Destruction (De-Initialization)
    > Understand Object Lifetime
    --------------------------------------------------
    1. Constructor 
        > Contrasting with Member Functions 
        > Parameterized 
            > Default Parameters 
        > Overloaded
    2. Destructor 
        > Contrasting with Member Functions 
    3. Default Constructor 
    4. Object Lifetime 
        > Automatic 
        > Static 
        > Dynamic 
    5. Module Summary 
    --------------------------------------------------
    --------------------------------------------------
    1. Constructor :: A Constructor is a special function. Which has a same name as the class. 
        Stack :: Initialization 
            Public Data                
                #include<iostream>
                using namespace std;
                class Stack{ public:  // VULNERABLE DATA 
                    char data_[10]; int top_;
                    public:
                        int empty() {return (top_==-1); }
                        void push(char x){data_[++top_]=x; }
                        void pop() {--top_; }
                        char top(){ return data_[top_]; }
                };
                int main(){
                    char str[10] = "ABCDE";
                    Stack s; s.top_ = -1; // Exposed initialization 
                    for(int i{0};i<5;++i) s.push(str[i]);
                    // s.top_ = 2; // RISK - CORRUUPTS STACK 
                    while (!s.empty()){
                        cout << s.top(); s.pop();
                    }
                }
                    > Spills data structure codes into application  
                    > public data reveals the internals 
                    > To switch container application needs to change 
                    > Application may corrupt the stack! 

            Private Data 
                #include<iostream>
                using namespace std;
                class Stack{ private:  // PROTECTED DATA 
                    char data_[10]; int top_;
                    public:
                        void init(){ top_ = -1; }
                        int empty() {return (top_ == -1); }
                        void push(char x){data_[++top_] = x; }
                        void pop() {--top_; }
                        char top(){ return data_[top_]; }
                };
                int main(){
                    char str[10] = "ABCDE";
                    Stack s; s.init(); // Clean initialization 
                    for(int i{0};i<5;++i) s.push(str[i]);
                    // s.top_ = 2; // Compile error - SAFE  
                    while (!s.empty()){
                        cout << s.top(); s.pop();
                    }
                }
                    > No code in application, but init() to be called 
                    > Switching container is seamless  
                    > private data protect is seamless 
                    > Application cannot corrupt the stack!     

            > Stack : Initialization 
                Using init()
                    #include<iostream>
                    using namespace std;
                    class Stack{ private:  // PROTECTED DATA 
                        char data_[10]; int top_;
                        public:
                            void init(){ top_ = -1; }
                            int empty() {return (top_ == -1); }
                            void push(char x){data_[++top_] = x; }
                            void pop() {--top_; }
                            char top(){ return data_[top_]; }
                    };
                    int main(){
                        char str[10] = "ABCDE";
                        Stack s; s.init(); // Clean initialization 
                        for(int i{0};i<5;++i) s.push(str[i]);
                        // s.top_ = 2; // Compile error - SAFE  
                        while (!s.empty()){
                            cout << s.top(); s.pop();
                        }
                    }
                        > init() serves no visible purpose - application may forget to call  
                        >  if application misses to call init(). We have a corrupt stack 

            >   Using Constructor 
                    #include<iostream>
                    using namespace std;
                    class Stack{ private:  // PROTECTED DATA 
                        char data_[10]; int top_;
                        public: Stack() : top_(-1) { } // Initialization 
                            int empty() {return (top_ == -1); }
                            void push(char x){data_[++top_] = x; }
                            void pop() {--top_; }
                            char top(){ return data_[top_]; }
                    };
                    int main(){
                        char str[10] = " ";
                        Stack s;  // Init by Stack::Stack() call
                        cin>>str;
                        for(int i{0};i<5;++i) s.push(str[i]);
                        while (!s.empty()){ cout << s.top(); s.pop(); }
                    }
                        > Can initialization be made a part of instantiation?
                        > Yes, Constructor is implicitly called at instantiation as set by the compiler. 

            > Stack Constructor 
                Automatic Array     
                    #include<iostream>
                    using namespace std;
                    class Stack { private:
                        char data_[10]; int top_; // Automatic 
                    public: Stack(); // Constructor 
                        // More Stack methods 
                    }; 
                    Stack::Stack(): // Initialization List 
                        top_(-1) { cout << "Stack::Stack()" << endl; 
                    }
                    int main(){ char str[10] = "ABCDE";
                        Stack s; // Init by Stack::Stack() call 
                        for(int i = 0; i<5; ++i) s.push(str[i]);
                        while(!s.empty()) { cout << s.top(); s.pop(); }
                    }
                        > top_ initialized to -1 in initialization list 
                        > data_[10] initialized by default (automatic)
                        > Stack::Stack() called automatically when control passes Stack s; - Gurarantees initialization 
                
                > Dynamic Array 
                    #include<iostream>
                    using namespace std;
                    class Stack { private:
                        char *data_; int top_; // Dynamic 
                    public: Stack(); // Constructor 
                        // More Stack methods 
                    }; 
                    Stack::Stack(): data_(new char[10]),// Init List 
                        top_(-1) { cout << "Stack::Stack()" << endl; 
                    }
                    int main(){ char str[10] = "ABCDE";
                        Stack s; // Init by Stack::Stack() call 
                        for(int i = 0; i<5; ++i) s.push(str[i]);
                        while(!s.empty()) { cout << s.top(); s.pop(); }
                    }
                        > top_ initialized to -1 in initialization list 
                        > data_ initialized by new char[10] in init list 

        > Contrasting with Member Functions
          ---------------------------------------------------------------------------------------------------------------------------------------
                            Constructor                                     |                                   Member Function 
            > Is a static member function without this pointer - but gets   |   > Has implicit this pointer 
            the pointer to the memory where the object is constructed       |   
            > Name is same as the name of the class                         |   > Any name different from name of class class Stack 
                class Stack { public: Stack(); };                           |           { public: int empty(); }
            > Has no return type - not evan void                            |   > Must have a return type - may be void 
                Stack::Stack(); // Not evan void                                int Stack::empty();
            > Does not return anything. Has no return statement             |   > Must have at least one return statement   
            Stack::Stack(); top_(-1)                                        |   int Stack::empty() {return (top_ == -1); }
            { } // Returns implicitly                                           void pop()
                                                                                { --top_; } // Implicit return for void 
            > Initalizer list to initialize the data members                |   > Not Applicable 
                Stack::Stack(): /// Initializer list                        
                    data_(new char[10]), // Init data_ 
                    top_(-1)            // Init top_ 
                    { }                                                     |   
            > Implicit cal by instantiation / operator new                  |   > Explicit call by the object 
                Stack s; // calls Stack::Stack()                                s.empty(); // Calls Stack::empty(&s)
            > May be public or private                                      |   > May be public or private 
            > May have any number of parameters                             |   > May have any number of parameters  
            > Can be overloaded                                             |   > Can be overloaded 
         ------------------------------------------------------------------------------------------------------------   

        > Parameterized 
                #include<iostream>
                #include<cmath>
                using namespace std;
                class Complex { private: double re_, im_;
                    public: 
                        Complex(double re, double im): // Constructor with parameters 
                        re_(re), im_(im)                // Initializer List: PArameters to initialize  data members 
                    { }
                    double norm(){return sqrt(re_*re_ + im_*im_); }
                    void print() {
                        cout << "|" << re_ << "+j" << im_ << "| = ";
                        cout << norm() << "\n"; 
                    }
                };
                int main(){
                    Complex c(4.3,5.3), d(5.4,6.3);  //Complex::Complex(re,im)
                    c.print();
                    d.print();
                }
                ctice.exe"
                    |4.3+j5.3| = 6.82495
                    |5.4+j6.3| = 8.29759

        > Complex :: Constructor with default parameters 
                #include<iostream>
                #include<cmath>
                using namespace std;
                class complex{ private: double re_, im_; public:
                    complex(double re = 0.0, double im = 0.0) : // constructor with default parameter 
                        re_(re), im_(im)                // Initializer list : parameter to initialize data members 
                    { }
                    double norm() { return sqrt(re_*re_ + im_*im_); }
                    void print() { cout << "|" << re_ << "+j" << im_ << "| = " << norm() << "\n"; }
                };
                int main(){
                    complex c1(4.3,5.3), // Complex::Complex(4.3,5.3) -- both parameters explicit 
                            c2(4.3),    // Complex::Complex(4.3) -- second parameter default 
                            c3;         // Complex::Complex(0.0,0.0) -- both parameters default 
                    c1.print();
                    c2.print();
                    c3.print(); 
                }
                    >    |4.3+j5.3| = 6.82495
                    >    |4.3+j0| = 4.3
                    >    |0+j0| = 0


 ++++       > Default Parameters  ++++
                > Stack :: Constructor with default parameters 
                    #include<iostream>
                    #include<cstring>
                    using namespace std;
                    class Stack { private: char *data_; int top_; 
                    public: Stack(size_t = 10); // Size of data_ defaulted 
                        ~Stack() { delete data_[]; }
                        int empty() { return (top_ == -1); }
                        void push(char x) {data_[++top_] = x; }
                        void pop() {--top_; }
                        char top() { return data_[top_]; }
                    };
                    Stack::Stack(size_t s) : data_(new char[s]), top_(-1) // Array of size s allocated and set to data_ 
                    { cout << "Stack created with max size = " << s << "\n"; }
                    int main() { char str[] = " ABCDE"; int len = strlen(str);
                        Stack  s(len); // Create a Stack large enough for the problem 
                        for(int i = 0; i<len; i++) s.push(str[i]);
                        while(!s.empty()) { cout << s.top(); s.pop(); }
                    }   


            > Complex : Overloaded Constructors 
                #include<iostream>
                #include<cmath>
                using namespace std;
                class complex { private: double re_, im_; public: 
                    complex(double re, double im): re_(re), im_(im) { }
                    complex(double re): re_(re), im_(0.0) { }
                    complex(): re_(0.0), im_(0.0) { }
                    double norm() { return sqrt (re_*re_ + im_*im_); }
                    void print() { cout << "|" << re_ << "+j" << im_ << "| = " << norm() << "\n"; }  
                };
                int main(){
                    complex c1(4.2,5.4), 
                            c2(4.2),
                            c3;
                    c1.print();
                    c2.print();
                    c3.print();
                }
                |4.2+j5.4| = 6.84105
                |4.2+j0| = 4.2      
                |0+j0| = 0

        > Overloaded
          > Rect: Overloaded Constructors 
                #include<iostream>
                using namespace std;
                class Pt { public: int x_, y_; Pt(int x, int y): x_(x), y_(y) { }}; // A point 
                class Rect { Pt LT_, RB_; public: 
                    Rect(Pt lt, Pt rb):
                        LT_(lt), RB_(rb) { }                // Cons 1: points left-top lt and right-bottom rb 
                    Rect(Pt lt, int h, int w):
                        LT_(lt), RB_(Pt(lt.x_+w, lt.y_+h)) { } // Cons 2: points height h & width w 
                    Rect(int h, int w):
                        LT_(Pt(0,0)), RB_(Pt(w,h)) { } // Cons 3: height h, width w,, & point origin as Left-Top 
                    int area() { return (RB_.x_ - LT_.x_) * (RB_.y_ - LT_.y_); }
                }; 
                int main(){ Pt p1(2,5), p2(8,10);
                    Rect r1(p1,p2),             // Cons 1 : Rect::Rect(Pt, Pt)
                        r2(p1,5,6),            // Cons 2: Rect::Rect(Pt, int, int)
                        r3(5,6);               // cons 3: Rect::Rect(int, int)
                    cout << "Area of r1 = " << r1.area() << "\n";
                    cout << "Area of r2 = " << r2.area() << "\n";
                    cout << "Area of r3 = " << r3.area() << "\n";
                }
                  >    Area of r1 = 30
                  >    Area of r2 = 30
                  >    Area of r3 = 30

    2. Destructor 
        -> Stack :: Destructor 
            --> Resource Release by user ::
                    #include<iostream>
                    using namespace std;
                    class Stack{
                        char *data_; int top_; // Dynamic 
                        public: Stack(): data_(new char[10]),top_(-1){
                            cout << "\n\nStack() called\n\n"; // Constructor 
                        } void de_init(){
                            delete[] data_;
                        } // More stack methods
                    };
                    int main(){
                        char str[10]="ABCDE";
                        Stack s; // Init by Stack::Stack() call 
                        // Reverse string using stack
                        s.de_init();
                    }
                    - > data_ leaks unless released within the scope of s 
                    - > When to call de_init()? User may forget to call 
            
            --> Automatic Resource Release 
                    #include<iostream>
                    using namespace std;
                    class Stack{
                        char *data_; int top_; //Dynamic 
                        public: Stack(): data_(new char[10]), top_(-1){
                            cout << "\nStack() called\n"; // Constructor 
                        } ~Stack(){
                            cout << "\n~Stack() called\n";
                            delete [] data_; // destructor 
                        }
                        //  MOre Stack methods
                    };
                    int main(){
                        char str[10] = "ABCDE";
                        Stack s; // Init by Stack::Stack() call 
                        // Reverse string using stack
                        s.~Stack();
                    } // De-init by automatic Stack::~Stack() call 
                    -> Can de-intialization be a part of scope rules?
                    -> Yes. Destructor is implicitly called at end of scope  

        > Contrasting with Member Functions 

            -> Destructor 
                -> Has implicit this pointer 
                -> Name is ~ followed by the name of the class 
                    class Stack {
                        public:
                        ~Stack();
                    };
                -> Has no return type - not evan void 
                    Stack::~Stack(); // Not evan void
                        { } // Returns Implicitly 
                -> Implicitly called at end of scope or by operator delete.May be called explicitly by the object (rare)
                    {
                        Stack s;
                        // ...
                    } // calls Stack::~Stack(&s) implicitly 
                -> May be public or private 
                -> No parameter is allowed - unique for the class 
                -> Cannot be overloaded

            -> member Function
                -> Has implicit this pointer 
                -> Any name different from name of class
                    class Stack{
                        public:
                        int empty();
                    };
                -> Must have a return type - may be void 
                    int Stack::empty();
                -> Must have at least one return statement 
                    int Stack::empty(){
                        return (top_ == -1);
                    }
                -> Explicit call by the object
                    s.empty(); // calls Stack::empty(&s)
                -> May be public or private 
                -> MAy have any number of parameters 
                -> Can be overloaded 

    3. Default Constructor 
        -> Constructor 
            -> A constructor with no parameter is called a default constructor 
            -> If no constructor is provided by the user, the compiler supplies a free default construtor 
            -> Compiler-provided(free default) constructor, understandably, cannot initialize the object to proper values. It has no code in its body
            -> Default constructors(free or user-provided) are required to define arrays of objects 
        
        -> Destructor 
            -> If no destructor is provided by the user, the compiler supplies a free default destructor 
            -> Compiler -provided (free default) destructor has no code in its body 
                -------
    4. Object Lifetime 
        > Automatic 
        > Static 
        > Dynamic 
    5. Module Summary 
    --------------------------------------------------