> Overloading Operator For User-Defined Types: Part 1
    > Module Objectives 
        > Understand how to overload operators for a user-defined type(class)
        > Understand the aspects of overloading by global function and members function 

    > 1. operator Function
            > 
                > We have seen how overloading operator+ a C-string wrapped in struct allows us a compact notation for concatenation of two string (module 09)
                > We have seen how overloading operator= can define the deep / shallow copy for a UDT and / or help with user-defined copy semantics (Module 14)
                > In general, operator overloading helps us to bulid complete algebra for UDT's much in the same line as is available for built-in Types: 
                    > Complex type : Add(+), subtract(-), Multiply(*), Divide(/), Conjugate(!),Compare(==, !=,...) etc.
                    > Fraction type: Add(+), subtract(-), Multiply(*), Divide(/), Normalize(unary *)m Compare(==, !=,...), etc
                    > Matrix type: Add(+),subtract(-), Multiply(*), Divide(/),Invert(!),Compare(==), etc
                    > Set type: Union(+), Difference(-),Intersection(*),Subset(<,<=),Superset(>,>=),Compare(==,!=),etc.
                    > Direct IO: read(<<), and write(>>) for all types 
                > Advanced examples include: 
                    > Smart Pointers: De-reference(unary *), Indirection(->), Copy(=), Compare(==,!=), etc.
                    > Function Objects or Functors: Invocation(()).

            > Operator Functions in C++: RECAP (MODULE 9)
                > Introduces a new keyword: operator
                > Every operator is associated with an operator function that defines its behavior 
                    ________________________________________________________________________________________
                            Operator Expression                     Operator Function
                    ________________________________________________________________________________________
                        a + behavior                    |       operator+(a+b)
                        a = b                           |       operator=(a,b)
                        c = a + b                       |       operator=(c,operator+(a,b))
                    ________________________________________________________________________________________

                > Operator functions are implicit for predefined operators of built-in type s and cannot be redefined 
                > An operator function may have a signature as: 
                    MyType a,b; // An enum or struct 
                    // Operator function 
                    MyType operator+(const MyType&, const MyType&);

                    a + b // calls operator+(a,b)
                > C++ allows users to define an operator function and overload it. 

        > Non-Member Function
            > A Non-member operator function may be a 
                > Global Function 
                > friend Function 

            > Binary Operator: 
                    MyType a, b;  // An enum, struct or class 
                    MyType operator+(const MyType&, const MyType&);     // Global
                    friend MyType operator+(const MyType&, const MyType&);  // friend 

            > Unary Operator: 
                MyType operator++(const MyType&);   // Global
                friend MyType operator++(const MyType&);    // Friend 

            > Note: The parameters may not be constant and may be passed by value. The return may also be by reference and may be constant 
            > examples: 
                ________________________________________________________________________________________
                    Operator Expression                             Operator Function 
                ________________________________________________________________________________________
                        a + b                       |            operator+(a, b)
                        a = b                       |            operator=(a, b)
                        ++a                         |            operator++(a)
                        a++                         |            operator++(a, int) Special Case
                        c = a + b                   |            operator=(c, operator+(a, b))
                ________________________________________________________________________________________
        
        > Member Function 
            > Binary Operator: 
                > MyType a, b;      // MyType is a class  
                MyType operator+(const MyType&);     // Operator function 
            > The left operand is the invoking object - right is taken as a parameter 
            > Unary Operator: 
                MyType operator-();     // Operator function for unary minus
                MyType operator++();    // For Pre- Incrementer 
                MyType operator++(int);
            > The only operand is the invoking object  
            > Note: The parameters may not be constant and may be passed by value. The return may also be by reference and may be constant 
            > examples: 
                ________________________________________________________________________________________
                    Operator Expression                             Operator Function 
                ________________________________________________________________________________________
                        a + b                       |            a.operator+(b)
                        a = b                       |            a.operator=(b)
                        ++a                         |            a.operator++()
                        a++                         |            a.operator++(int) // Special Case
                        c = a + b                   |            c.operator=(a.operator+(b))
                ________________________________________________________________________________________
        
        > Operator Overloading Rules
            > Operator Overloading - Summary of Rules : RECAP MODEULE - 9;

                > No new operator such as **, <> , or &| can be defined for overloading 
                > Intrinsic properties of the overloaded operator cannot be change 
                    > Preserves arity 
                    > Preserves precedence 
                    > Preserves associativity 
                > These operators can be overloaded: 
                    [] + - * / % ^ & | ~ ! = += -= *= /= %= ^= &= |= << >> >>= <<= == != > < <= >= && || ++ -- , ->* -> () [ ]
                > The operators :: (scope resolution), . (member access), .* (member access through pointer to member), sizeof, and ?: (ternary conditional) cannot be overloaded 
                > The overloads of operators && , ||, and, (comma) lose their Special properties: short - circuit evaluation and sequencing 
                > The overlaod of operator-> msut either return a raw pointer or return an object (by reference or by value), for which operand-> is in turn overloaded 
                > For a member operator function, invoking object is passed implicitly as the left operands but the right opereand the passed explicitly 
                > For a non-member operator function (Global / friend) operands are always passed explicitly 

    2. Using Global Function : public data members (Unsafe)

        > public data members 
            >  Overloading  + for Complex addition 

                #include<iostream>
                using namespace std;
                struct Complex {
                    double re,im;
                };
                Complex operator+ (Complex &a, Complex &b){
                    Complex c;
                    c.re = a.re + b.re;
                    c.im = a.im + b.im;
                    return c;
                }
                int main(){
                    Complex c1,c2,c;
                    c1.re=10.5; c1.im=12.25;
                    c2.re=20.5;c2.im=30.25;
                    c = c1 + c2;    // Overload operator + 
                    cout << "\nReal : " << c.re << ", Imag : " << c.im << "\n\n"; 
                }
                    > operator+ is overloaded to perform addition of two Complex numberes which are of struct Complex type 

        > Overloading + for string cat 
                #include<iostream>
                #include<cstdlib>
                #include<cstring>
                using namespace std;
                typedef struct _String { // A typedef can provide a simple name for a complicated type cast.
                //  TYPEDEF CAN BE USED FOR: Types that combine arrays,structs,pointers or functions.
                    char *str;
                }
                String;
                String operator+(const String& s1, const String& s2){
                    String s;
                    s.str = (char *)malloc(strlen(s1.str) + strlen(s2.str) + 1);
                    strcpy(s.str, s1.str); strcat(s.str, s2.str);
                    return s;
                }
                int main(){
                    String fName, lName, name;
                    fName.str = strdup("Ankit ");
                    lName.str = strdup("Dimri");
                    name = fName + lName;   // Overload operator + 
                    cout << "\nFirst Name : " << fName.str;
                    cout << "\nLast Name : " << lName.str;
                    cout << "\nFull Name : " << name.str << "\n\n";
                }
                    First Name : Ankit
                    Last Name : Dimri
                    Full Name : Ankit Dimri
                    > operator+ is overloaded to perform concat of first name and last to from full name. The data type is String.
                                        ________________________________
                                        typedef define in details :- 
                                        ________________________________
                                        struct Vector {
                                                int x;
                                                int y
                                                };
                                                
                                                int main() {
                                                    struct Vector v1 = {4, 5};
                                                
                                                    return 0;
                                                } 
                                                ________________________________
                                                struct Vector {
                                                        int x;
                                                        int y
                                                        };
                                                        
                                                        typedef struct Vector Vector;
                                                        
                                                        int main() {
                                                            Vector v1 = {4, 5};
                                                        
                                                            return 0;
                                                        }
                                                        ________________________________
                                                        typedef struct Vector {
                                                                        int x;
                                                                        int y
                                                                        } Vector;
                                                                        
                                                                        int main() {
                                                                            Vector v1 = {4, 5};
                                                                        
                                                                            return 0;
                                                                        }
                                                                        ________________________________
                    
        > private data members 
            > uisng Global Function : private data members (Safe)

                        #include<iostream>
                        using namespace std;
                        class Complex { // private data members 
                            double re,im; 
                            public: 
                            Complex(double a = 0.0, double b = 0.0): re(a), im(b) { }
                            void display();
                            double real(){ return re; }
                            double imag(){ return im; }
                            double set_real(double r){ re = r; }
                            double set_imag(double i){ im = i; } 
                        };
                        void Complex::display(){
                            cout << re << " +j " << im << "\n";
                        }
                        Complex operator+(Complex &t1, Complex &t2){
                            Complex sum;
                            sum.set_real(t1.real() + t2.real());
                            sum.set_imag(t1.imag() + t2.imag());
                            return sum;
                        }
                        int main(){
                            Complex c1(4.5, 25.25), c2(8.3,10.25),c3;
                            cout << "1st Comple NO : ";c1.display();
                            cout << "2nd Complex NO : "; c2.display();
                            c3 = c1 + c2;   // Overload operator + 
                            cout << "Sum : "; c3.display();
                        }
                                1st Comple NO : 4.5 +j 25.25
                                2nd Complex NO : 8.3 +j 10.25
                                Sum : 12.8 +j 35.5
                                    > Accessing private data members inside operator functions is clumsy 
                                    > Critical data members need to be exposed (get/set) violating encapsulation  
                                    > Solution: member operator function or friend operator function ....
                
    3. Using Member Function 
        
        > operator+
            > 
                #include<iostream>
                using namespace std;
                class Complex {     // private data member 
                    double re, im;
                    public: 
                    Complex(double a = 0.0, double b = 0.0):re(a), im(b) { } 
                    ~Complex() { }
                    void display();
                    Complex operator+(const Complex &t){
                        Complex r;
                        r.re = re + r.re;
                        r.im = im + r.im;
                        return r;
                    } 
                };
                void Complex::display(){
                    cout << re << "+j " << im << "\n";
                }
                int main(){
                    Complex c1(4.5,25.25), c2(8.3, 10.25), c3;
                    cout << "\n1st Complex : ";c1.display();
                    cout << "2nd Complex : ";c2.display();
                    c3 = c1 + c2;       // Overloaded operator +
                    cout << "Sum : ";c3.display();cout << "\n";
                    return 0;
                }
                    1st Complex : 4.5+j 25.25
                    2nd Complex : 8.3+j 10.25
                    Sum : 4.5+j 25.25

                        > performing c1 + c2 is equivalent to c1.operator+(c2)
                        > c1 invokes the operator+ function and c2 is passed as an argument 
                        > Similarly we can implement all binray operators (%,-,*,etc...)
                        > Note: No need of two arguments in overloading
                        
        > operator=
             > Overloading operator=: RECAP(Module 14)
                    #include<iostream>
                    #include<cstdlib>
                    #include<cstring>
                    using namespace std;
                    class String {
                        public: 
                        char *str_; size_t len_;
                        String(char *s) : str_(strdup(s)), len_(strlen(str_)){ }    // ctor 
                        String(const String& s) : str_(strdup(s.str_)), len_(s.len_) { }    // cctor 
                        ~String(){ free(str_); }
                        String& operator=(const String& s){
                            if(this != &s){free(str_); str_ = strdup(s.str_); len_ = s.len_; }
                            return *this;
                        }
                        void print(){
                            cout << "(" << str_ << ": " << len_ << ")\n";
                        }
                    };
                    int main(){
                        String s1 = "Football",s2="Cricket";
                        s1.print();s2.print();
                        s1 = s1;s1.print(); 
                    }
                        (Football: 8)
                        (Cricket: 7)
                        (Football: 8)
                            > Check for self-copy (this != &s)
                            > In case of self-copy, do nothing 

            > Notes on Overloading operator=: RECAP (Module 14)
                > Overloaded operator= may choose between Deep and shallow Copy for Pointer members
                    > Deep copy allocates new space for the contents and copies the pointed data 
                    > Shallow copy merely copies the pointer value - hence, the new copy and the original pointer continue to point to the same data 
                > If operator= can makes only a shallow copy 
                > If the constructor uses operator new, operator= should be overloaded 
                > If there is a need to deine a copy constructor then operator= must be overloaded and vice-versa 
                
                            
        > Unary Operators 
           > Overloading Unary Operators 
                
                #include<iostream>
                using namespace std;
                class MyClass{
                    int data; public:
                    MyClass(int d) : data(d) { }
                    MyClass& operator++() { // Pre-increment: 
                        ++data;         // operate and return the operated object 
                        return *this;
                    }
                    MyClass operator++(int){ // post - increment 
                        MyClass t(data);    // Return the (Copy of) object; operate the object 
                        ++data;
                        return t;
                    }
                    void display(){
                        cout << "Data : " << data << "\n";
                    }
                };
                int main(){
                    MyClass obj1(8); obj1.display();
                    MyClass obj2 = obj1++; obj2.display(); obj1.display();
                    obj2 = obj1++;
                    obj2.display();obj1.display();
                }
                    Data : 8
                    Data : 8
                    Data : 9
                    Data : 9
                    Data : 10

                        > The pre-operator should first perform the operation (increment / decrement/ other) and then return the object. Hence its return type should be MyClass& and it should return *this;
                        > The post-operator should perform the operation (increment / decrement / other) after it returns the original value. Hence it should copy the orignal obejct in a temporay MyClass t; and then return t; Its return type should be MyClass - by value. 

        > Overloading Unary operators 
            Pre-Increment & post Increment 
                #include<iostream>
                using namespace std;
                class MyClass{
                    int data; public:
                    MyClass(int d) : data(d) { }
                    MyClass& operator++() { // Pre-operator 
                        data *= 2;         
                        return *this;
                    }
                    MyClass operator++(int){ // post - operator 
                        MyClass t(data);    // Return the (Copy of) object; operate the object 
                        data /= 3;
                        return t;
                    }
                    void display(){ cout << "Data : " << data << "\n"; }
                };
                int main(){
                    MyClass obj1(12); obj1.display();
                    MyClass obj2 = obj1++; obj2.display(); obj1.display();
                    obj2 = ++obj1;
                    obj2.display();obj1.display();
                }
                    Data : 12
                    Data : 12
                    Data : 4
                    Data : 8
                    Data : 8

                        > The pre-operator and the post-operator need not merely increment / decrement 
                        > They may be used for any other computation as this example shows 
                        > However, it is a good design practice to keep close to the native semantics of the operator                         

    4. Module Summary 
        > introduced operator overloading for user-defined types 
        > Illustrated methods of overloading operators using global functions and members functions  
        > Outlined semantics for overloading binary and unary operators 
    
    __________________________________________________Complete_________________________________________________________________
 