#include<iostream>
using namespace std;
#include "String.h"
class Name { String firstName_, lastName_;
    public: 
    Name(const char* fn, const char* ln) : firstName_(fn), lastName_(ln){ // Uses Ctor of string class 
         cout << "Name ctor : ";print();cout << "\n"; }
    Name(const Name& n) : firstName_(n.firstName_),lastName_(n.lastName_){ // Uses CCtor of string class 
         cout << "Name cctor : ";print(); cout << "\n"; }
    Name& operator=(const Name& n){
        firstName_ = n.firstName_;      // Uses operator=() of string class
        lastName_ = n.lastName_;        // uses operator=() of String class 
        return *this;
    }
    ~Name(){ cout << "Name dtor : ";print();cout << "\n"; } // Uses dtor of string class 
    void print()const // Uses print() of String  class 
    {
        firstName_.print();cout << " ";lastName_.print();      
    }
};
// copy constructor and copy Assignment operator added
//  print() made a constant member function 