- Module Objectives 
    - Understand how inheritance impacts data members and member functions 
    - Introduce overriding of member function and its inreractions with overloading 

- Module Outline 
    1. Inheritance in C++  : Semantics 
        - Derived ISA - (Instruction Set Architecture (ISA))  Base  - Specialization of the base class
        
        - Data Members 
            - Derived class inherit all data members of Base class 
            - Derived class may add data members of its own
        
        - Members functions
            - Derived class inherit all member functions of Base class 
            - Derived class may override a member function of Base class by redefining it with the same signature 
            - Derived class may overload a member function of Base class by redefining it with the same name; 
            but different signature 

        - Access Specification 
            - Derived class cannot access private members of Base class 
            - Derived class can access protected members of Base class 

        - Construction-Destruction 
            - A Constructor of the Derived class must first call a Constructor of the Base class to Construct the Base class instance of the Derived class 
            - The destructor of the Derived class must call the destructor of the base class to destruct the BAse class instance of the Derived class 

    2. Data Members 
        []
            - Derived ISA BAse 
            - Data Members 
                - Derived class inherits all data members of Base class 
                - Derived class may add data members of its own 
            
            - Object Layout 
                - Derived class Layout contains an instance of the Base class 
                - Further, Derived class Layout will have data members of its own 
                - C++ does not guarantee the relative postion of the Base class instance and Derived class members 

        - Object Layout                         
            []
            class B{ // Base class 
                int deta1B_;
                public:
                int data2B_;
                // .....
            };

            class D: public B{ // Derived class 
                // Inherits B::data1B_
                // Inherits B::data2B_
                int infoD_; // Adds D::infoD_ 
                public: 
                // ... 
            };
            B b; // Base classs Object
            D d; // Derived Class Object 
                _________________________________________________________________________________________________

                    Object Layout 
                        Object d   
                            --------------------
                            |                  |                Object b
                            |   ____________   |                -------------
                            |   | data1B_   |  |                |  data1B_  |
                            |   |-----------|  |                |------------
                            |   | data2B_   |  |                |  data2B_  |
                            |    -----------   |                -------------
                            |------------------|
                            |      infoD_      |        - d cannot access data1B_ even though is a part of d! 
                            --------------------        - d can access data2B_
                _________________________________________________________________________________________________        


    3. Member functions
        []

            - Derived ISA Base
            - Members Functions 
                - Derived class inherits all member functions of Base class 
                    - Note: Derived class does not inherit the Constructors and Destructor of Base class but must have access to them 
                - Derived class may override a member function of Base class by redefining it with the same signature 
                - Derived class may overload a member function of Base class by redefining it with the same name, but different signature 
                - Derived class may add new member functions 

            - Static Members Functions 
                - Derived class does not inherit the Static member functions of Base class 
            
            - Friend Functions 
                - Derived class does not inherit the friend functions of Base class 

        - Overrides and Overloads
            
            - [] 
                Inheritance                            |        Override & Overload 
        ___________________________________________________________________________________________________________
            class B {                                   |   class B { public: // Base class 
                public: // Base Class                           void f(int);
                void f(int i);                          |       void g(int i);
                void g(int i);                          |   };
            };                                          |   class D: public B { public: // Derived class 
            class D: public B { public:                 |       // Inherits B::f(int)
                // Inherits B::f(int)                           void f(int);    // Overrides B::f(int)
                                                        |       void f(string&);   // Overloads B::f(int)
                //  Inherits B::g(int)                          // Inherits B::g(int)
            };                                          |       void h(int i);  // Adds D::h(int)
            B b;                                        |   };
            D d;                                        |   B b;
                                                        |   d d;
            b.f(1); // Calls B::f(int)                      b.f(1);     // Calls B::f(int)
            b.f(2); // Calls B:g(int)                       b.g(2)      // Calls B::g(int)
                                                        |
            d.f(3); // Calls B::f(int)                      d.f(3);     // calls D::f(int)
            d.g(4); // Calls B::g(int)                      d.g(4);     // Calls B::g(int)
                                                        |
            - D::f(int) override B::f(int)              |   d.f("red");     // Calls D::f(string&)
            - D::f(string&) overloads B::f(int)         |   d.h(5);         // Calls D::h(int)
        ___________________________________________________________________________________________________________


    
    4. Comparison 
        [] Overloading vis-a-vis Overloading 
            Basis        |           Function Overloading                |       Function Overriding 
        ________________________________________________________________________________________________________________________
        Name of Function | All overloads have the same function name     | All override have the same function name 
        Signature        | Function signatures must be different         | Function signaturs are same 
        Type of Function | Can be global, friend, Static or non-Static   | Must be a non-Static member function - non- virtual 
                         | member function                               |  or virtual 
        Inheritance      | Can happen with or without inheritance        | Happens only with inheritance 
        Signature        | Function signatures must be different in      | Function signatures are same 
                         | number of parameters and / or their types     |
        Polymorphism     | Static (Compile time)                         | Static (Compile time) or Dynamic (Runtime)
        Scope            | Overloaded functions are in the same Scope    | Functions are in different scopes (base class and 
                         |                                               |  Derived class)
        Purpose          | To have multiple functions with same name that| To perform additional or different tasks than the base 
                         | act differently depending on parameters       |  class function 
        Constructor      | Constructors can be Overloaded                | Constructors cannot be overridden 
        Destructor       | The destructor cannot be overloaded           | The destructor cannot be overridden 
        Usage            | Can be overloaded multiple times              | Can be overridden once in the Derived class 
        ___________________________________________________________________________________________________________________________


    5. Module Summary 
        []
        - Discussed the effect of inheritance on Data Members and Object Layout 
        - Discussed the effect of inheritance on Member Functions with special reference to Overriding and overloading
        ____________________________________________________complete_____________________________________________________________