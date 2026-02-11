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
    // > Set methods added 
    // > print() made a constant member function 
    