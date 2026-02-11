: Operators & Functions 
    Understand the Operator overloading 

Module Outline
    1. Operators and Functions
            What is the differnce between an operator & a function ?
                unsigned int Multiply(unsigned x, unsigned y){
                    int prod = 0;
                    while(y-- > 0) prod += x;
                    return prod;
                }
                int main(){
                    unsigned int a = 2, b = 3;
                    // Computed by '*' operator 
                    unsigned int c = a*b; // c is 6
                    // Computed by Multiply function 
                    unsigned int d = Multiply(a,b); // d is 6
                    return 0;
                }

                Same computation by an operator and a function 
                    
        : Difference 
             Difference between Operator & Functions
                :  Operator 
                        Usually written in infix notation - at times in prefix or postfix
                        Examples :
                            // Opreator in-between operands
                            Infix : a + b;  a ? b : c;
                            //  Operator before operands
                            Prefix : ++a 
                            //  Operator after operands 
                            Postfix : a++;

                            Operates on one or more operands,
                            typically up to 3 (unary, Binary or Ternary)
                            produces one result
                            Order of operations is decided by precedence and associativity 
                            Operators are pre-defined 

                : Function 
                    Always written in prefix notation
                    Examples:
                        // Operator before operands 

                        Prefix: max(a,b);
                                qsort(int[],int,int,void(*)(void*,void*));
                                
                        Operates on zero or more arguments 
                        Prodeces up to one result 
                        Order of application is decided by depth of nesting 
                        Functions can be defined as needed 

        ---------------------------------------------------------                
    
    2. Operator Functions in C++
        C++ introduces a new keyword: Operator 
        Every operator is associated with an operator function that defines its behaviour 

                Operator Expression                         Operator Function 
                a + b                                       operator+(a, b)
                a = b                                       operator=(a, b)
                c = a + b                                   operator=(c,operator+(a,b))

        Operator functions are implicit for prefefined operators of built-in types and cannot be redefined 
        An operator function may have a signature as : 
            MyType a, b; /// An enum or struct 
            MyType operator+(MyType, MyType); // Operator function 
            a + b /// calls operator+(a,b)
        C++ allows users to define an operator function and overload it 

    3. Operator Overloading 
            Operator Overloading    --> (also called ad hoc polymorphism), is a specific case of Polymorphism, where different operators have different implementations depending on their arguments 
            Operator overloading is generally defined by a programming language, for example, in C (and in C++) , for operator/ , we have: 
                    integer Division                            Flaoting point Division 
                    int i = 5, j = 2;                       double i = 5, j = 2;
                    int k = i/j;                            double k = i / j; // k = 2.5 
                    //k = 2                   
            C does not allow programmers to overload its operators
            C++ allows programmers to overload its operators by using operator functions 
        
        ----------------------------------------
        
        -->     Advantages (1.) and Disadvantages (2.)
            (1.)
                Operator overloading is syntactic sugar, and is used because it allows programming using notation  nearer to the target domain 
                It allows user-defined types a similar level of syntactic support as types built into a language 
                It is common in scientific computing, where it allows computing representations of mathematical objects to be manipulated with the same syntax as on paper 
                For example, if we build a Complex type in C and a,b and c are variables of Complex type, we need to code an expression         a+b *c 
                using functions to add and multiply Complex values as 
                                        Add(a, Multiply(b,c))
                which is clumsy and non-intuitive
                Using operator overloading we can write the expression with operators without having to use the functions 
        --> (2.)  Disadvantages 
                Operator overloading allows programmers to reassign the semantics of operators depanding on the types of their operands. For example, for int a,b, an expression a<<b shifts the bits in the variables a left by b, whereas cout << a << b output values of a and b to standard output (cout)
                As operator overloading allows the programmer to change the usual semantics of an operator, it is a good practice to use operator overloading with care to maintain the semantic Congruity
                With operator overloading asssumed. For example, the commutativity of operator+ (that is, a+b == b+a) is not preserved when we overload it to mean string concatenation as 
                    "run" + "time" = "runtime" doesnot equal "timerun" = "time" + "run"

                    Of course, mathematics too has such deviations as multiplication is commutative for real and complex numbers but not commutative in matrix multiplication 

    4. Examples of operator Overloading 
        string: Concatenation 
            --> Concatenation by string functions 
               #include<iostream>
                #include<cstring>
                using namespace std;
                typedef struct _String {char *str;} String; // S --> s
                int main(){
                    String fname, lname, name;
                    fname.str = strdup("Ankit");
                    lname.str = strdup(" Dimri!");
                    name.str = (char*)malloc( // Allocation 
                        strlen(fname.str) + strlen(lname.str) + 1);
                    strcpy(name.str, fname.str);
                    strcat(name.str,lname.str);
                    cout << "First name : " << fname.str << "\n";
                    cout << "LASt NAme : " << lname.str << "\n";
                    cout << "Full name : " << name.str << "\n";
                    return 0; 
                }
            
            --> Concatenation operator 
                    #include<iostream>
                    #include<cstring>
                    using namespace std;
                    typedef struct _String { char *str;} String;
                    String operator+(const String& s1, const String& s2){
                        String s;
                        s.str = (char *)malloc(strlen(s1.str) + strlen(s2.str) + 1); // Allocation 
                        strcpy(s.str, s1.str); strcat(s.str,s2.str);
                        return s;
                    }
                    int main(){ String fname,lname,name;
                        fname.str =  strdup("Ankit");
                        lname.str = strdup(" Dimri!");
                        name = fname + lname; // Overloaded operator + 
                        cout << "First Name : " << fname.str << "\n";
                        cout << "Last NAme : " << lname.str << "\n";
                        cout << "Full name : " << name.str << "\n";
                    }

        Enum: Changing the meaning of Operator+
            :: A new semantics for operator+ 
                w/o Overloaading +
                    #include<iostream>
                    using namespace std;
                    enum E { C0 = 0, c1 = 1, c2 = 2};
                    int main(){
                        E a = c1, b = c2;
                        int x = -1;
                        x = a + b; // Operator + for int 
                        cout << "Output :: " <<  x << "\n";
                    }
                    Output :: 3

                Implicity converts enum E values to int 
                Add by operator+ of int 
                Result is outside enum E range 

                --> Overloading operator+
                        #include<iostream>
                        using namespace std;
                        enum E { c0 = 0, c1 = 1, c2 = 2}; 
                        E operator+(const E& a, const E& b){ // overloaded operator +
                            unsigned int uia = a, uib = b;
                            unsigned int t = (uia + uib) % 3; // Redefined addition 
                            return (E) t;
                        }
                        int main(){ E a = c1, b =  c2;
                            int x = -1; 
                            x = a + b; // Overloaded operator + for enum E 
                            cout << "output : " << x << "\n";
                        }
                        output : 0

                    operator + is overloaded for enum E 
                    Result is a valid enum E value

            --------------------------------------------------

    5. Operator Overloading Rules 
            --> 
                No new operator such as operator** or operators<> can be defined for overloading 
                Intrinsic properties of the overloaded operator cannot be changed 
                    Preserves arity 
                    Preserves Precedence 
                    Preserves Associativity 
                These operators can be overloaded :
                [] + - * / % ^ & | ~ ! = + += -= *= /= %= ^= &= |= << >> >>= <<= == != < > <= >= && || ++ --, ->* -> () []  
                For unary prefix operators, use : MyType& operator++(MyType& s1)
                For unary postfix operators, use : MyType operator++(MyType& s1, int)
                The operators :: (scope resolution), operator. (member access), operator . * (member accesss through pointer to member), operator sizeof, and operator ?: (ternary conditional) cannot be overloaded 
                The overloads of operators&&, operators||, and operators, (comma) lose their special properties: short-circuit evaluation and sequencing 
                The overload of operators-> must either return a raw pointer or return an object (by reference or value), for which operators -> is in turn overloaded 
                  
    6. Operator Overloading Restrictions
        -->
            Operator                                Reason 
            dot(.)                  It will raise question whether it is for object reference or overloading 
            scope Resolution(::)    It performs a (complie time) scope resolution rather than an expression evaluation 
            Ternary(?:)             Overloading expr1? expr2: expr3 would not guarantee that only one of expr2 and expr3 was exacuted 
            sizeof                  Operator sizeof cannot be overloaded because built-in operations, such as incrementing a pointer into an array implicity depends on it
            && and ||               In evaluation, the second operand is not evaluated if the result can be deduced solely by evaluating the first operand. However, this evaluation is not possible for overloaded versions of these operators
            Comma(,)                This operator guarantees that the first operand is evaluated before the second operand. HOwever,  if the commma operator is overloaded, its operand evaulation depends on C++'s function parameter mechanism, which does not guarantee the order of evaluation 
            Ampersand(&)            The address of an object of incomplete type can be taken, but if the complete type of that object is a class type that declares operator&() as a member function, then the behavior is undefined 

    7. Module Summary
        -> Introduced operator overloading with its advantages and disadvantages 
        -> Explained the rules of operator overloading 
        -------------------------Complete----------------------------------


 