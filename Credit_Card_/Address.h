#include <iostream>
using namespace std;
#include "String.h"
class Address {
    unsigned int houseNo_; String street_, city_,pin_;
    public:
    Address(unsigned int hn, const char* sn, const char* cn, const char* pin) : houseNo_(hn),street_(sn),city_(cn), pin_(pin) { // uses ctor of string class 
        cout << "Address ctor : ";print();cout << "\n";
    }
    Address(const Address& a) : houseNo_(a.houseNo_),street_(a.street_),city_(a.city_),pin_(a.pin_){ // Uses cctor of string class 
        cout << "Address cctor : "; print();cout << "\n";
    }
    Address& operator=(const Address& a) { // Uses operator=() of string class 
        houseNo_ = a.houseNo_;street_ = (a.street_);city_ = (a.city_);pin_ = (a.pin_);return *this;
    }
    ~Address(){ // USes dtor of string class 
        cout << "Address dtor : ";print();cout << "\n";
    }
    void print()const{ // uses print() of string class 
        cout << houseNo_ << " ";street_.print();cout << " ";
        city_.print();cout << " ";pin_.print();
    }
};
    // > Copy constructor and copy Assignment operator added 
    // > print() made a constant member function 
