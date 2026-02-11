> Understand const-ness of objects in C++ 
> Understand the use of const-ness in class design
Module objects
    1. Constant Objects 
        --> Like objects of built-in type. objects of user-defined types can also be made constant 
            > If an object is constant, none of its Data members can be changed 
            > The type of the this pointer of a constant object of class, say, MyClass is: 
                //  Comst Pointer to const Object 
                const MyClass * const this;
            instead of 
                // const Pointer to non-const Object 
                MyClass * const this;
            as for a non-constant object of the same class 
        > A constant objects cannot invoke normal methods of the class lest these method changed the object
    
        > Simple Example
            >  Non-Constant Objects
                #include<iostream>
                using namespace std;
                class MyClass {
                    int myPrimeMember_;
                    public: int myPubMember_;
                    MyClass(int mPri, int mPub) : myPrimeMember_(mPri),myPubMember_(mPub) { }
                    int getMember() { return myPrimeMember_; }
                    void setMember(int i) { myPrimeMember_ = i; }
                    void print(){
                        cout << myPrimeMember_ << ", " << myPubMember_ << "\n";
                    }
                };
                int main(){
                    MyClass myObj(0,1);cout << myObj.getMember() << "\n";
                    myObj.setMember(2);
                    myObj.myPubMember_ = 3;
                    myObj.print();
                }
                    > It's okay to invoke methods for non-constant object myObj 
                    > It's okay to make changes in non-constant object myObj by method (setMember())
                    > It's okay to make changes in non-constant object myObj directly(myPubMember_)
            
            > Constant Object
                >
                    #include<iostream>
                    using namespace std;
                    class MyClass{
                        int myPrimeMember_; 
                        public: int myPubMember_;
                        MyClass(int mPri, int mPub) : myPrimeMember_(mPri),myPubMember_(mPub) { }
                        int getMember() { return myPrimeMember_; }
                        void setMember(int i) {
                            myPrimeMember_ = i;
                        }
                        void print(){
                            cout << myPrimeMember_ << ",  " << myPubMember_ << "\n";
                        }
                    };
                    int main(){
                        const MyClass myConstObj(5,6); // Constant Object
                        cout << myConstObj.getMember() << "\n";  // Error 1
                        myConstObj.setMember(7);                 // Error 2
                        myConstObj.myPubMember_ = 8;             // Error 3
                        myConstObj.print();                      // Error 4
                    } 

                        > It's not allowed to invoke methods or make changes in constant object myConstObj
                        > Error (1,2 & 4) on method invocation typically is : 
                            cannot convert 'this' pointer from 'const MyClass' tp 'MyClass &'
                        > Error (3) on member update typically is : 
                            'myConstObj' : you cannot assign to a variable that is const 
                        > With const this pointer is const MyClass * const while the methods expects MyClass * cosnt 
                        > Consequently, we cannot print the data member of the class (even without changing it)
                        > Fortunately, constant objects can invoke (select) methods if they are constant member functions.
                        
    
    2. Constant Member Functions
        > Constant Member Function 
            > To declare a constant member function, we use the keyword const between the function header and the body. Like : 
                void print() const {cout << myMember_ << "\n"; }
            
            > A Constant member function expects a this pointer as: 
                const MyClass * const this;

                and hence can be invoked by constant Objects

            >  In a constant member function no data member can be changed. hence , 
                void setMember(int i)const 
                { myMember_ = i; } // data member cannot be changed 
                gives an error 
            
            > Interesting, non-constant objects can invoke constant member functions(by casting- we discuss later)
                and, of course , non-constant member function 
            
            > Constant objects, however, can only invoke constant member Functions

            > All member functions that do not need to change an object must be declared as constant member functions. 


        > Simple Example 
             > Constant Member Functions
                    #include<iostream>
                    using namespace std;
                    class MyClass{
                        int myPrimeMember_; public: int myPubMember_;
                        MyClass(int mPri, int mPub) : myPrimeMember_(mPri),myPubMember_(mPub) { }
                        int getMember()const { return myPrimeMember_; } // const Member Func. 
                        void setMember(int i){ myPrimeMember_ = i; }    // non-const Member Func 
                        void print() const { cout << myPrimeMember_ << ", " << myPubMember_ << "\n"; }      // const Member Func. 
                    };
                    int main(){
                        MyClass myObj(0,1);  // Non=const object
                        const MyClass myConstObj(5,6);  // const object
                        // non-const object can invoke all member functions and update data members 
                        cout << myObj.getMember() << "\n";
                        myObj.setMember(2);
                        myObj.myPubMember_ = 3;
                        myObj.print();
                        // const object cannot allow any change 
                        cout << myConstObj.getMember() << "\n";
                        // myConstObj.setMember(7);         // Cannot invoke non-const member functions 
                        // myConstObj.myPubMember_ = 8;     // Cannot update data member
                        myConstObj.print();
                    }
                            0                               // x * const this;
                            2, 3                            // const x * const this;
                            5
                            5, 6

                        > Now myConstObj can invoke getMember() and print(), but cannot invoke setMember()
                        > Naturally myConstObj cannot update myPubMember_
                        > myObj can invoke all of getMember(), print(), and setMember()


    3. Constant Data Member 
        > Often we need part of an object, that is, one or more data members to be constant (non-changeable after construction) while the rest of the 
            data members should be changeable. For example: 
                > For an Employee: Employee ID and DoB should be non-changeable while designation address salary etc. should changeable 
                > For a Student: roll number and DoB should be non-changeable while year of study, address,gpa etc. should be changeable
                > For a Credit Card: card number and name of holder should be non-changeable while date of issue, date of expiry, address, cvv number etc. Should be changeable
        > We do this by making the non-changeable data members as constant by Putting the const keyword before the declaration of the member in  the class 
        > A constant data member cannot be changed even in a non-constant object
        > A constant data member must be initialized on the initialization list 

            May not hold for a card that changes number on re-issue 
             
        > Simple Example
                > 
                #include<iostream>
                using namespace std;
                class MyClass{
                    int myPrimeMember_; public: int myPubMember_;
                    MyClass(int mPri, int mPub) : myPrimeMember_(mPri),myPubMember_(mPub) { }
                    int getMember()const { return myPrimeMember_; } // const Member Func. 
                    void setMember(int i){ myPrimeMember_ = i; }    // non-const Member Func 
                    void print() const { cout << myPrimeMember_ << ", " << myPubMember_ << "\n"; }      // const Member Func. 
                };
                int main(){
                    MyClass myObj(0,1);  // Non=const object
                    const MyClass myConstObj(5,6);  // const object
                    // non-const object can invoke all member functions and update data members 
                    cout << myObj.getMember() << "\n";
                    myObj.setMember(2);
                    myObj.myPubMember_ = 3;
                    myObj.print();
                    // const object cannot allow any change 
                    cout << myConstObj.getMember() << "\n";
                    // myConstObj.setMember(7);         // Cannot invoke non-const member functions 
                    // myConstObj.myPubMember_ = 8;     // Cannot update data member
                    myConstObj.print();
                }
                        0
                        2, 3
                        5
                        5, 6

                    > Now myConstObj can invoke getMember() and print(), but cannot invoke setMember()
                    > Naturally myConstObj cannot update myPubMember_
                    > myObj can invoke all of getMember(), print(), and setMember() 

                > 
                        #include<iostream>
                        using namespace std;
                        class MyClass {
                            const int cPriMem_; // cosnt data member 
                            int priMem_; public: 
                            const int cPubMem_; // const data member 
                            int pubMem_;
                            MyClass(int cPri, int ncPri, int cPub, int ncPub) : cPriMem_(cPri), priMem_(ncPri), cPubMem_(cPub), pubMem_(ncPub) { }
                            int getcPri() { return cPriMem_; }
                            void setcPri(int i){ cPriMem_ = i; } //  Error 1: Assignment to const data member 
                            int getPri() { return priMem_; }
                            void setPri(int i){ priMem_ = i; }
                        };
                        int main(){
                            MyClass myObj(1,2,3,4);
                            cout << myObj.getcPri() << "\n"; myObj.setcPri(6);
                            cout << myObj.getcPri() << "\n"; myObj.setPri(6);
                            cout << myObj.cPubMem_ << "\n"; 
                            myObj.cPubMem_ = 3; // Error 2 : Assignment to const data member  
                            cout << myObj.pubMem_ << "\n"; myObj.pubMem_ = 3;
                        }
                            > It's not allowed to make changes to constant data members in myObj 
                            > Error 1 : I-value specifies const object 
                            > Error 2 : 'myObj' : you cannot assign to a variable that is const 

        > Credit Card Example : Putting it all together 
            > We now illustrate constant data members with a complete example of CreditCard class with the following supporting classes:
                > String class
                    #include<iostream>
                    #include<cstring>
                    #include<cstdlib>
                    using namespace std;
                    class String {
                        char *str_; size_t len_; public: String(const char *s) : str_(strdup(s)),len_(strlen(str_)) {
                            cout << "String ctor : "; print(); cout << "\n";
                        }
                        String(const String& s) : str_(strdup(s.str_)),len_(strlen(str_)){
                            cout << "String cctor : "; print();cout << "\n";
                        }
                        String& operator=(const String& s){
                            if(this != &s){
                                free(str_);
                                str_ = strdup(s.str_);
                                len_ = s.len_;
                            }
                            return *this;
                        }
                        ~String(){
                            cout << "String Dtor : "; print();cout << "\n";free(str_);
                        }
                        void print()const{
                            cout << str_;
                        }
                    };
                    Copy Constructor and Copy Assignment operator added 
                      print() made a cosntant member function 
 
                > Date class 
                    >
                        #include<iostream>
                        using namespace std;
                        char monthNames[][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
                        char dayNames[][10]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
                        class Date{
                            enum Month{ Jan = 1, Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec };
                            enum Day{ Mon,Tue,Wed,Thr,Fri,Sat,Sun };
                            typedef unsigned int UINT;
                            UINT date_; Month month_; UINT year_;
                        public: Date(UINT d, UINT m, UINT y) : date_(d), month_((Month)m),year_(y){ cout << "Date ctor : ";print();cout << "\n"; }
                            Date(const Date& d) : date_(d.date_),month_(d.month_),year_(d.year_){ cout << "Date cctor : ";print();cout << "\n"; }
                            Date& operator=(const Date& d) { date_ = d.date_;month_ = d.month_;year_ = d.year_;return *this; }
                            ~Date(){ cout << "Date dtor : ";print();cout << "\n"; }
                            void print()const{ cout <<date_ << "/" << monthNames[month_ - 1] << "/" << year_; }
                            bool validDate()const{  // check validity
                                return true; }
                            Day day() const{ //  Compute day from date using time.h
                                return Mon; }
                        };
                         Copy constructor and copy Assignment OPerator added
                         Print(), validDate(), and day() made constant member functions


                > Name class 
                    #include<iostream>
                    using namespace std;
                    #include "String.h"
                    class Name {
                        String firstName_, lastName_;
                        public: Name(const char* fn, const char* ln) : firstName_(fn), lastName_(ln){ cout << "Name ctor : ";print();cout << "\n"; }
                        Name(const Name& n) : firstName_(n.firstName_),lastName_(n.lastName_){ cout << "Name cctor : ";print(); cout << "\n"; }
                        Name& operator=(const Name& n){
                            firstName_ = n.firstName_;      // Uses operator=() of string class
                            lastName_ = n.lastName_;        // uses operator=() of String class 
                            return *this;
                        }
                        ~Name(){ cout << "Name dtor : ";print();cout << "\n"; }
                        void print()const // Uses print() of String  class 
                        {
                            firstName_.print();cout << " ";lastName_.print();      
                        }
                    };
                    // copy constructor and copy Assignment operator added
                    //  print() made a constant member function 
               
                > Address class 
                    #include<iostream>
                    using namespace std;
                    #include "String.h"
                    class Address {
                        unsigned int houseNo_; String street_, city_,pin_;
                        public:
                        Address(unsigned int hn, const char* sn, const char* cn, const char* pin) :  // uses ctor of string class 
                        houseNo_(hn),street_(sn),city_(cn), pin_(pin){
                            cout << "Address ctor : ";print();cout << "\n";
                        }
                        Address(const Address& a) :  // Uses cctor of string class 
                        houseNo_(a.houseNo_),street_(a.street_),city_(a.city_),pin_(a.pin_){
                            cout << "Address cctor : "; print();cout << "\n";
                        }
                        Address& operator=(const Address& a) { // Uses operator=() of string class 
                            houseNo_ = a.houseNo_;street_ = (a.street_);city_ = (a.city_);pin_ = (a.pin_);return *this;
                        }
                        ~Address(){
                            cout << "Address dtor : ";print();cout << "\n";
                        }
                        void print()const{
                            cout << houseNo_ << " ";street_.print();cout << " ";
                            city_.print();cout << " ";pin_.print();
                        }
                    };
                        > Copy constructor and copy Assignment operator added 
                        > print() made a constant member function 

                               
            > CreditClass 
                #include<iostream>
                using namespace std;
                #include "Date.h"
                #include "Name.h"
                #include "Address.h"
                class CreditCard { typedef unsigned int UINT; char *cardNumber_;
                    Name holder_;Address addr_; Date issueDate_, expiryDate_; UINT cvv_;
                    public:
                    CreditCard(const char* cNumber, const char* fn, const char* ln, unsigned int hn, const char* sn, 
                    const char* cn, const char* pin, UINT issueMonth, UINT issueYear,UINT expiryMonth,UINT expiryYear, UINT cvv): holder_(fn,ln), 
                    addr_(hn,sn,cn,pin), issueDate_(1,issueMonth, issueYear),expiryDate_(1,expiryMonth,expiryYear),cvv_(cvv) { // Uses Ctor's of Date,Name,Address
                        cardNumber_ = new char[strlen(cNumber) + 1]; strcpy(cardNumber_, cNumber);
                        cout << "CC ctor : ";print();cout << "\n";
                    }
                    // Uses Dtor's of date, Name, Address
                    ~CreditCard(){ cout << "CC dtor : ";print();cout << "\n"; delete[] cardNumber_; }
                    void setHolder(const Name& h){ holder_ = h; }
                    void setAddress(const Address& a){ addr_ = a; }
                    void setIssueDate(const Date& d){ issueDate_ = d; }
                    void setExpiryDate(const Date& d){ expiryDate_ = d; }
                    void setCVV(UINT v){ cvv_ = v; }
                    void print()const{
                        cout << cardNumber_ << " ";holder_.print();cout << " ";addr_.print();
                        cout << " ";issueDate_.print();cout << " ";expiryDate_.print();cout << " ";cout << cvv_; }
                };
                    > Set methods added 
                    > print() made a constant member function 
                    
            > Credit Card Class Application 
                #include<iostream>
                using namespace std;
                #include "CreditCard.h"
                int main(){
                    CreditCard cc("5321711934640027","Sherlock", "Holmes", 221,"Baker Street", "London","NW1 6XE", "Lane no 6", 7, 2014, 6, 2014, 441);
                    cout << "\n";cc.print();cout << "\n\n";
                    cc.setHolder(Name("David", "Cameron"));
                    cc.setAddress(Address(10,"Downing Street","London","SW1A 2AA"));
                    cc.setIssueDate(Date(1, 7, 2017));
                    cc.setExpiryDate(Date(4,8,2023));
                    cc.setCVV(127);
                    cout << "\n";cc.print();cout << "\n\n";
                }
                    //  Construction of data members  & object 
                    5321711934640027 Sherlock Holmes 221 Baker Street London NW1 6XE 7/Jan/2014 6/Jun/2014 441
                    //  Construction & destruction of temporary objects 
                    same file 
                    // Destruction of data members & object
                        // > We could change address, issue date, expiry date and cvv, this is fine 
                        // > We could change the name of the holder ! This should not be allowed 

            > Credit Card Classs : Constant data members 
                // #include<iostream>
                // #include "String.h"
                // #include "Date.h"
                // #include "Name.h"
                // #include "Address.h"
                class CreditCard { typedef unsigned int UINT; char *cardNumber_;
                   const  Name holder_; // Holder name cannot be changed after construction
                   Address addr_; Date issueDate_, expiryDate_; UINT cvv_;
                    public:
                    CreditCard(....): ... {... } ~CreditCard(){...}
                    void setHolder(const Name& h){ holder_ = h; } // change holder name 
                    //  error c2678: binary '=' : no operator found which takes a left-hand operand 
                    //  of type 'const Name' (or there is no acceptable conversion)
                    void setAddress(const Address& a){ addr_ = a; }
                    void setIssueDate(const Date& d){ issueDate_ = d; }
                    void setExpiryDate(const Date& d){ expiryDate_ = d; }
                    void setCVV(UINT v){ cvv_ = v; }
                    void print()const{... }
                };
                    > We prefix Name holder_ with const. Now the holder name cannot be changed after construction 
                    > In setHolder(), we get a compilation error for hiolder_ = h; in an attempt to change holder_ 
                    > With const prefix Name holder_ becomes constant - unchangeable 
            
            > Credit Card class : Clean 

                // #include<iostream> , "String.h" , "Date.h" , "Name.h" , "Address.h"
                class CreditCard { typedef unsigned int UINT; char *cardNumber_;
                   const  Name holder_; // Holder name cannot be changed after construction
                   Address addr_; Date issueDate_, expiryDate_; UINT cvv_;
                    public:
                    CreditCard(....): ... {... } ~CreditCard(){...}
                    void setHolder(const Name& h){ holder_ = h; } // change holder name 
                    void setAddress(const Address& a){ addr_ = a; }
                    void setIssueDate(const Date& d){ issueDate_ = d; }
                    void setExpiryDate(const Date& d){ expiryDate_ = d; }
                    void setCVV(UINT v){ cvv_ = v; }
                    void print()const{... }
                };
                    > Method setHolder() removed 

            > Credit Card Class Application : Revised 
                      #include<iostream>
                    using namespace std;
                    #include "CreditCard.h"
                    int main(){
                        CreditCard cc("5321711934640027","Sherlock", "Holmes", 221,"Baker Street", "London","NW1 6XE", "Lane no 6", 7, 2014, 6, 2014, 441);
                        cout << "\n";cc.print();cout << "\n\n";
                        // cc.setHolder(Name("David", "Cameron"));
                        cc.setAddress(Address(10,"Downing Street","London","SW1A 2AA"));
                        cc.setIssueDate(Date(1, 7, 2017));
                        cc.setExpiryDate(Date(4,8,2023));
                        cc.setCVV(127);
                        cout << "\n";cc.print();cout << "\n\n";
                    }
                        > Now holder_ cannot be changed .So we are safe 
                        > however it is still possible to replace or edit the card number,This too, should be disallowed 
            > Credit Card Class: cardNumber_ ISsue 
                 // #include<iostream> , "String.h" , "Date.h" , "Name.h" , "Address.h"
                class CreditCard { typedef unsigned int UINT; 
                    char *cardNumber_;  // Card number is editable as well as replaceable 
                   const  Name holder_; // Holder name cannot be changed after construction
                   Address addr_; Date issueDate_, expiryDate_; UINT cvv_;
                    public:
                    CreditCard(....): ... {... } 
                    ~CreditCard(){...}
                    void setAddress(const Address& a){ addr_ = a; }
                    void setIssueDate(const Date& d){ issueDate_ = d; }
                    void setExpiryDate(const Date& d){ expiryDate_ = d; }
                    void setCVV(UINT v){ cvv_ = v; }
                    void print()const{... }
                };
                    > It is still possible to replace or edit the card number 
                    > To make the cardNumber_ non-replaceable  we need to make this constant pointer 
                    > Further to make it non-editable we need to make cardNumber_ point to constant string 
                    > hence we change char *cardNumber_ to const char * const cardNumber_ 
         
            > Credit Card class : cardNumber_ ISsue :
                // #include<iostream>
                using namespace std;
                // #include "Date.h"
                // #include "Name.h"
                // #include "Address.h"
                class CreditCard { typedef unsigned int UINT; 
                    const char * const cardNumber_;
                    const Name holder_;
                    Address addr_; Date issueDate_, expiryDate_; UINT cvv_;
                    public:
                    CreditCard(const char* cNumber, const char* fn, const char* ln, unsigned int hn, const char* sn, 
                    const char* cn, const char* pin, UINT issueMonth, UINT issueYear,UINT expiryMonth,UINT expiryYear, UINT cvv): holder_(fn,ln), 
                    addr_(hn,sn,cn,pin), issueDate_(1,issueMonth, issueYear),expiryDate_(1,expiryMonth,expiryYear),cvv_(cvv) { // Uses Ctor's of Date,Name,Address
                        cardNumber_ = new char[strlen(cNumber) + 1]; strcpy(cardNumber_, cNumber);
                        cout << "CC ctor : ";print();cout << "\n";
                    }
                    // Uses Dtor's of date, Name, Address
                    ~CreditCard(){ cout << "CC dtor : ";print();cout << "\n"; delete[] cardNumber_; } 
                            > cardNumber_ is now a constant pointer to a constant string 
                            > with this the allocation for the C-string fails in the body as constant pointer cannot be assigned 
                            > Further copy if c-string (strcpy()) fails as copy of constant c-string is not allowed 
                            > We need to move these codes to the initialization list 
                
                > Credit card Class : cardNumber_ Issue 
                    #include<iostream>
                    using namespace std;
                    #include "String.h"
                    #include "Date.h"
                    #include "Name.h"
                    #include "Address.h"
                    class CreditCard { typedef unsigned int UINT;  const char * const cardNumber_;
                       const Name holder_; Address addr_; Date issueDate_, expiryDate_; UINT cvv_;
                        public:
                        CreditCard(const char* cNumber, const char* fn, const char* ln, unsigned int hn, const char* sn, 
                        const char* cn, const char* pin, UINT issueMonth, UINT issueYear,UINT expiryMonth,UINT expiryYear, UINT cvv): cardNumber_(strcpy(new char[strlen(cNumber)+1],cNumber)),holder_(fn,ln), 
                        addr_(hn,sn,cn,pin), issueDate_(1,issueMonth, issueYear),expiryDate_(1,expiryMonth,expiryYear),cvv_(cvv) { // Uses Ctor's of Date,Name,Address
                            cout << "CC ctor : ";print();cout << "\n";
                        }
                        // Uses Dtor's of date, Name, Address
                        ~CreditCard(){ cout << "CC dtor : ";print();cout << "\n"; delete[] cardNumber_; }
                        void setHolder(const Name& h){ holder_ = h; }
                        void setAddress(const Address& a){ addr_ = a; }
                        void setIssueDate(const Date& d){ issueDate_ = d; }
                        void setExpiryDate(const Date& d){ expiryDate_ = d; }
                        void setCVV(UINT v){ cvv_ = v; }
                        void print()const{
                            cout << cardNumber_ << " ";holder_.print();cout << " ";addr_.print();
                            cout << " ";issueDate_.print();cout << " ";expiryDate_.print();cout << " ";cout << cvv_; }
                    };             
                        > Note the initialization of cardNumber_ in initialization list 
                        > All constant data members must be initialized in initialization list 

    4. mutable Members
        > While a constant data member is not changeable even in a non-constant object, a mutable data member is changeable in a constant object 
        > mutable is provided to model logical (semantic) const-ness against the default Bit-wise (syntactic) const-ness of C++ 
        > Note that : 
            > mutable is applicable only to data members and not to variables 
            > Reference data members cannot be declared mutable 
            > Static data members cannot be declared mutable 
            > const data members cannot be declared mutable 
        > if a data member is declared mutable, then it is legal to assign a value to it from a const member function 
 
       > Simple Example 
            >   #include <iostream>
                using namespace std;
                class MyClass {
                    int mem_; mutable int mutableMem_;
                    public: 
                    MyClass(int m, int mm) : mem_(m),  mutableMem_(mm){ }
                    int getMem()const { return mem_; }
                    void setMem(int i){ mem_ = i; }
                    int getMutableMem()const{ return mutableMem_; }
                    void setMutableMem(int i)const { mutableMem_ = i; } // Okay to change mutable
                };
                int main(){
                    const MyClass myConstObj(1,2);
                    cout << myConstObj.getMem() << "\n";
                    // myConstObj.setMem(3);       //Error to invoke 
                    cout << myConstObj.getMutableMem() << "\n";
                    myConstObj.setMutableMem(4);
                }
                    1
                    2
                    > setMutableMem() is a constant member function so that constant myConstObj can invoke it 
                    > setMutableMem() can still set mutableMem_ because mutableMem_ is mutable 
                    > in Constant, myConstObj cannot invoke setMem and hence mem_ cannot be changed 

            >  Logical vis-a-vis Bit-wise Const-ness 
                > Const in C++, models bit-wise constant, Once an object is declared const, no part (actually, no bit) of it can be changed after construction(and initialization)
                > however, while programming we often need an object to be logically constant. That is the concept represented by the object should be constant, but if its represented
                 need more data members for computation and modeling, these have no reason to be constant. 
                > mutable allows such surrogate data members to be changeable in a (bit-wise) constant object to model logically const objects

            > To use mutable we shall look for : 
                > A logically constant concept 
                > A need for data members outside the representation of the concept; nut are needed for computation 
                
        > mutable Guidelines
            > When to use mutable Data Members 
                > Typically, when a class represents a constant concept, and 
                > It computes a value first time and caches the result for future use 
                //  Source : http://www.highprogrammer.com/alan/rants/mutable.html
                    #include<iostream>
                    using namespace std;
                    class MathObject {
                        mutable bool piCached_;
                        mutable double pi_;
                        public:
                        MathObject():piCached_(false){ } // Not available at construction
                        double pi() const{          // Can access PI only through this method 
                            if(!piCached_){     // An insanely slow way to calculate PI 
                                pi_ = 4;
                                for(long step = 3; step<1000000000; step+=4){
                                    pi_ += ((-4.0/(double)step) + (4.0/((double)step + 2)));
                                }
                                piCached_ = true;
                            }
                            return pi_;
                        }
                    };
                    int main(){
                        const MathObject mo;cout <<mo.pi() << "\n";
                    }
                        > Here a MathObject is logically constant; but we use mutable members for computation 
        
        > When not to be use mutable Data Members?
            > mutable should be rarely used -  only when it is really needed. A bad example follows: 
                
                    Improper Design (mutable)
                                class Employee {
                                string _name, _id;
                                mutable double _salary;
                                public:
                                Employee(string name = "No Name", string id = "000-00-0000", double salary = 0) : _name(name), _id(id){
                                    _salary = salary;
                                }
                                string getName()const;
                                void setName(string name);
                                string getid()const;
                                void setid(string id);
                                double getSalary()const;
                                void setSalary(double salary);
                                void promote(double salary)const{
                                    _salary = salary;
                                }
                            };

                            const Employee john("JOHN","007",5000.0);
                            john.promote(20000.0);
                
                Proper Design (const)
                        class Employee {
                        const string _name, _id; double _salary;
                        public:
                        Employee(string name = "No Name", string id = "000-00-0000", double salary = 0) : _name(name), _id(id){
                            _salary = salary;
                        }
                        string getName()const;
                        // void setName(string name);
                        string getid()const;
                        // void setid(string id);
                        double getSalary()const;
                        void setSalary(double salary);
                        void promote(double salary){
                            _salary = salary;
                        }
                    };

                        > Employee is not logically constant. If it is, then _salary should also be const 
                        > Design on right makes that explicit 


    5. Module Summary 
        > Studied const-ness in C++ 
        > IN c++, there are three forms of const-ness 
            > Constant Objects 
                > NO change is allowed after construction 
                > Cannot invoke normal member functions 
            > Constant Member Functions 
                > Can be invoked by constant (as well as non-constant) objects 
                > Cannot make changes to the object 
            > Constant Data Members 
                > No change is allowed after construction 
                > must be initialized in the initialization list 
        > Further , learnt how to model logical const-ness over bit-wise const-ness by Proper use of mutable members 
    

 ---------------------------------------------------Compute--------------------------------------------

> 